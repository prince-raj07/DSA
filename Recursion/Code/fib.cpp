#include<iostream>
using namespace std;
//Not a good code as same funtion is call 
 int fib(int n){
    if(n<=1)
    return n ;
    else 
    return fib(n-1) + fib(n-2);
 }

 int arr[10]; // global array

 int mfib(int n){
    if(n<=1){
        arr[n] = n;
        return n ;
    }
    else{
        if(arr[n-2]==-1)
        arr[n-2] = mfib(n-2);
        if(arr[n-1]==-1)
        arr[n-1] = mfib(n-1);
        arr[n] = arr[n-2] + arr[n-1] ;
        return arr[n-2] + arr[n-1] ;
    }
 }
int main(){
    printf("%d\n",fib(5));
    for(int i=0;i<10;i++){
        arr[i] = -1 ;
    }
    printf("%d",mfib(6));
    return 0 ;
}