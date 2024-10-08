#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data ;
    struct node * next;
}node;

node *create(int n){
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    for(int i=0;i<n;i++){
        temp = (node*)malloc(sizeof(node));
        printf("Enter data in node number %d :",(i+1));
        scanf("%d",&(temp->data));
        temp->next = NULL;

        if(i==0){
            head = temp ;
        }
        else{
             p = head ;
             while(p->next!=NULL)
              p = p->next;
              p->next = temp ;
        }
    }
    return head ;
}

void display(node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
        }
}

node *deletion(node *head){
int choice ;
printf("Enter 1 for begin\n Enter 2 for end\n Enter 3 for between\n");
scanf("%d",&choice);
if(choice==1){
    node * ptr ;
    ptr = head ;
    head = head->next ;
    free(ptr);
    return head ;
}

if(choice==2){
    node *ptr1 = head->next ;
    node *ptr2 = head ;
    while(ptr1->next!=NULL){
        ptr1=ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next=NULL;
    free(ptr1);
    return head ;
}
}

int main(){
    int n ;
    printf("Enter how many nodes you want to create :") ;
    scanf("%d",&n);
    node *Head = create(n);
    display(Head);
    deletion(Head);
    display(Head);
    return 0 ;
}

