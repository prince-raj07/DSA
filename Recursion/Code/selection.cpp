#include<iostream>
using namespace std ;

    void selection(int * arr,int n){
        int min ;
        for(int i=0;i<=n-2;i++){
            min = i;
            for(int j=i;j<n;j++){
                if(arr[j]<arr[min])
                min = arr[j] ;
            }
        }
    }
int main(){
    int n;
    cout << "Enter n " << endl ;
    cin >> n;
    int arr[n];
    cout << "Enter elements "<< endl;
    for(int i=0;i<n;i++){
        cin >> arr[i] ;
    }
    selction(arr,n);
    print(arr,n);
}