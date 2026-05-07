/**
 * PhishShield — dashboard.js
 * Final Version with URL Analysis + Proper Subject/Sender Extraction
 */

document.addEventListener("DOMContentLoaded", () => {
  // ── Session timer ─────────────────────────────────────────────────────────
  const sessionEl = document.getElementById("sessionTime");
  let seconds = 0;
  setInterval(() => {
    seconds++;
    const h = String(Math.floor(seconds / 3600)).padStart(2, "0");
    const m = String(Math.floor((seconds % 3600) / 60)).padStart(2, "0");
    const s = String(seconds % 60).padStart(2, "0");
    if (sessionEl) sessionEl.textContent = `${h}:${m}:${s}`;
  }, 1000);

  // ── Close button ──────────────────────────────────────────────────────────
  const closeBtn = document.getElementById("closeDashBtn");
  if (closeBtn) closeBtn.addEventListener("click", () => window.close());

  // ── Search ────────────────────────────────────────────────────────────────
  const searchInput = document.getElementById("searchInput");
  if (searchInput) searchInput.addEventListener("input", filterHistory);

  // ── Clear All ─────────────────────────────────────────────────────────────
  const clearBtn = document.getElementById("clearAllBtn");
  const confirmOverlay = document.getElementById("confirmOverlay");
  const confirmCancel = document.getElementById("confirmCancel");
  const confirmOk = document.getElementById("confirmOk");
  const confirmCountEl = document.getElementById("confirmCount");

  if (clearBtn && confirmOverlay) {
    clearBtn.addEventListener("click", () => {
      chrome.storage.local.get("scan_history", (res) => {
        const count = (res.scan_history || []).length;
        if (confirmCountEl) confirmCountEl.textContent = count;
        confirmOverlay.classList.add("confirm-visible");
      });
    });
  }
  if (confirmCancel) confirmCancel.addEventListener("click", () => confirmOverlay.classList.remove("confirm-visible"));
  if (confirmOk) {
    confirmOk.addEventListener("click", () => {
      chrome.storage.local.set({ scan_history: [] }, () => {
        confirmOverlay.classList.remove("confirm-visible");
        loadDashboardData();
        showToast("All scan history cleared successfully", "success");
      });
    });
  }
  if (confirmOverlay) {
    confirmOverlay.addEventListener("click", (e) => {
      if (e.target === confirmOverlay) confirmOverlay.classList.remove("confirm-visible");
    });
  }

  // ── Initial load ──────────────────────────────────────────────────────────
  loadDashboardData();

  chrome.storage.onChanged.addListener((changes, area) => {
    if (area === "local" && changes.scan_history) loadDashboardData();
  });

  // ── URL ANALYZE FEATURE (FINAL FIXED VERSION) ─────────────────────────────
  const analyzeUrlBtn = document.getElementById("analyzeUrlBtn");
  const urlInput = document.getElementById("urlInput");
  const urlResult = document.getElementById("urlAnalysisResult");

  if (analyzeUrlBtn && urlInput && urlResult) {
    analyzeUrlBtn.addEventListener("click", async () => {
      const url = urlInput.value.trim();

      if (!url) {
        showUrlResult("Please enter a valid Gmail or Outlook URL", "error");
        return;
      }
      if (!url.includes("mail.google.com") && !url.includes("outlook")) {
        showUrlResult("Please enter a valid Gmail or Outlook URL", "error");
        return;
      }

      analyzeUrlBtn.disabled = true;
      analyzeUrlBtn.innerHTML = `Analyzing...`;

      try {
        const tab = await chrome.tabs.create({ url: url, active: false });

        // Wait for page load
        await new Promise((resolve) => {
          const listener = (tabId, changeInfo) => {
            if (tabId === tab.id && changeInfo.status === "complete") {
              chrome.tabs.onUpdated.removeListener(listener);
              resolve();
            }
          };
          chrome.tabs.onUpdated.addListener(listener);
        });

        // Extra wait for Gmail to render email
        await new Promise(r => setTimeout(r, 1800));

        let emailData;
        try {
          emailData = await chrome.tabs.sendMessage(tab.id, { action: "extractEmail" });
        } catch {
          // Improved fallback
          const [result] = await chrome.scripting.executeScript({
            target: { tabId: tab.id },
            func: () => {
              let sender = "";
              const senderEl = document.querySelector("span.gD") || 
                              document.querySelector(".gD") || 
                              document.querySelector("span[email]");
              if (senderEl) {
                sender = senderEl.getAttribute("email") || senderEl.innerText || "";
              }

              let subject = document.querySelector("h2.hP")?.innerText || 
                           document.querySelector("[data-testid='subject']")?.innerText || 
                           document.title;

              return {
                body: document.body.innerText.slice(0, 4000),
                subject: subject || "No Subject",
                sender: sender || ""
              };
            }
          });
          emailData = result.result;
        }

        // Analyze
        const res = await fetch("http://localhost:8000/analyze", {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify(emailData)
        });

        if (!res.ok) throw new Error("Analysis failed");
        const data = await res.json();

        // Save with correct subject & sender
        chrome.storage.local.get("scan_history", (res) => {
          const history = res.scan_history || [];
          const record = {
            ...data,
            subject: emailData.subject || "No Subject",
            sender: emailData.sender || "Unknown",
            timestamp: Date.now(),
            source: "url"
          };
          history.unshift(record);
          chrome.storage.local.set({ scan_history: history.slice(0, 100) });
        });

        showUrlResult(`
          <strong>✅ Analysis Complete</strong><br>
          <strong>Risk:</strong> ${data.risk_level} (${data.risk_score}/10)<br>
          <strong>Sender:</strong> ${emailData.sender || "Unknown"}<br>
          <strong>Subject:</strong> ${emailData.subject || "No Subject"}
        `, "success");

        loadDashboardData();
        setTimeout(() => chrome.tabs.remove(tab.id), 1500);

      } catch (err) {
        console.error(err);
        showUrlResult("❌ Failed to analyze. Make sure backend is running.", "error");
      } finally {
        analyzeUrlBtn.disabled = false;
        analyzeUrlBtn.innerHTML = `
          <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.5">
            <circle cx="11" cy="11" r="8"></circle>
            <line x1="21" y1="21" x2="16.65" y2="16.65"></line>
          </svg>
          Analyze URL
        `;
      }
    });

    urlInput.addEventListener("keypress", (e) => {
      if (e.key === "Enter") analyzeUrlBtn.click();
    });
  }
});

// ── Core Functions ──────────────────────────────────────────────────────────
let currentHistory = [];

function loadDashboardData() {
  chrome.storage.local.get("scan_history", (res) => {
    currentHistory = res.scan_history || [];
    updateStats(currentHistory);
    updateThreatBreakdown(currentHistory);
    renderHistoryTable(currentHistory);
  });
}

function updateStats(history) {
  const total = history.length;
  const phishing = history.filter(h => h.is_phishing === true || (h.risk_level && (h.risk_level.toLowerCase().includes("high") || h.risk_level.toLowerCase().includes("medium")))).length;
  const safe = total - phishing;
  const avg = total > 0 ? (history.reduce((sum, h) => sum + (parseFloat(h.risk_score) || 0), 0) / total).toFixed(1) : "—";

  document.getElementById("totalScans").textContent = total || "—";
  document.getElementById("phishingCount").textContent = phishing || "—";
  document.getElementById("safeCount").textContent = safe || "—";
  document.getElementById("avgScore").textContent = avg;

  const barTotal = document.getElementById("barTotal");
  const barPhish = document.getElementById("barPhish");
  const barSafe = document.getElementById("barSafe");
  const barAvg = document.getElementById("barAvg");

  if (total > 0) {
    if (barTotal) barTotal.style.width = "100%";
    if (barPhish) barPhish.style.width = `${Math.round((phishing / total) * 100)}%`;
    if (barSafe) barSafe.style.width = `${Math.round((safe / total) * 100)}%`;
    if (barAvg) barAvg.style.width = `${Math.round((parseFloat(avg) / 10) * 100)}%`;
  }
}

function updateThreatBreakdown(history) {
  const total = history.length || 1;
  const critical = history.filter(h => h.risk_level && h.risk_level.toLowerCase().includes("high")).length;
  const medium = history.filter(h => h.risk_level && h.risk_level.toLowerCase().includes("medium")).length;
  const low = history.filter(h => h.risk_level && h.risk_level.toLowerCase().includes("low")).length;
  const safe = history.filter(h => !h.risk_level || h.risk_level.toLowerCase().includes("safe")).length;

  const pCritical = Math.round((critical / total) * 100);
  const pMedium = Math.round((medium / total) * 100);
  const pLow = Math.round((low / total) * 100);
  const pSafe = Math.round((safe / total) * 100);

  document.getElementById("bdCritical").style.width = `${pCritical}%`;
  document.getElementById("pctCritical").textContent = `${pCritical}%`;
  document.getElementById("bdMedium").style.width = `${pMedium}%`;
  document.getElementById("pctMedium").textContent = `${pMedium}%`;
  document.getElementById("bdLow").style.width = `${pLow}%`;
  document.getElementById("pctLow").textContent = `${pLow}%`;
  document.getElementById("bdSafe").style.width = `${pSafe}%`;
  document.getElementById("pctSafe").textContent = `${pSafe}%`;
}

function renderHistoryTable(history, searchTerm = "") {
  const tbody = document.getElementById("historyBody");
  const emptyState = document.getElementById("emptyState");
  const countBadge = document.getElementById("countBadge");
  if (!tbody || !emptyState || !countBadge) return;

  tbody.innerHTML = "";
  let filtered = history;
  if (searchTerm) {
    const term = searchTerm.toLowerCase();
    filtered = history.filter(h =>
      (h.subject || "").toLowerCase().includes(term) ||
      (h.sender || "").toLowerCase().includes(term)
    );
  }
  countBadge.textContent = `${filtered.length} records`;

  if (filtered.length === 0) {
    emptyState.style.display = "flex";
    return;
  } else {
    emptyState.style.display = "none";
  }

  filtered.forEach((record) => {
    const tr = document.createElement("tr");
    const dateStr = record.timestamp ? new Date(record.timestamp).toLocaleString("en-US", { month: "short", day: "numeric", hour: "numeric", minute: "2-digit", hour12: true }).replace(",", " •") : "—";
    const riskLevel = record.risk_level || "Safe";
    const score = record.risk_score !== undefined ? record.risk_score : "—";
    const subject = record.subject || "—";
    const sender = record.sender || "—";

    let riskClass = "risk-safe";
    const rl = riskLevel.toLowerCase();
    if (rl.includes("high")) riskClass = "risk-high";
    else if (rl.includes("medium")) riskClass = "risk-medium";
    else if (rl.includes("low")) riskClass = "risk-low";

    let scoreClass = riskClass === "risk-high" ? "score-high" : riskClass === "risk-medium" ? "score-medium" : riskClass === "risk-low" ? "score-low" : "score-safe";

    tr.innerHTML = `
      <td style="font-family: var(--font-mono); font-size: 11.5px; color: var(--slate-400);">${dateStr}</td>
      <td title="${subject}">${subject.length > 42 ? subject.slice(0,42)+"…" : subject}</td>
      <td title="${sender}">${sender.length > 28 ? sender.slice(0,28)+"…" : sender}</td>
      <td><span class="risk-badge ${riskClass}">${riskLevel}</span></td>
      <td><span class="score-val ${scoreClass}">${score}/10</span></td>
    `;
    tr.addEventListener("click", () => {
      const detail = `Subject: ${subject}\nSender: ${sender}\nRisk: ${riskLevel} (${score}/10)`;
      navigator.clipboard?.writeText(detail).then(() => showToast("Details copied!", "success"));
    });
    tbody.appendChild(tr);
  });
}

function filterHistory() {
  const term = document.getElementById("searchInput")?.value || "";
  renderHistoryTable(currentHistory, term);
}

function showToast(message, type = "success") {
  const toast = document.getElementById("toast");
  if (!toast) return;
  toast.textContent = message;
  toast.className = `toast toast-visible toast-${type}`;
  setTimeout(() => toast.classList.remove("toast-visible"), 2400);
}

function showUrlResult(message, type = "success") {
  const urlResult = document.getElementById("urlAnalysisResult");
  if (!urlResult) return;
  urlResult.innerHTML = message;
  urlResult.style.display = "block";
  urlResult.className = `url-analysis-result ${type}`;
  if (type === "success") {
    setTimeout(() => { urlResult.style.display = "none"; }, 8000);
  }
}