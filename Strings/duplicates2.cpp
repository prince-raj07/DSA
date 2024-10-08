#include<iostream>
using namespace std ;

int main()
{
    char A[] = "finding" ;
      long int h = 0, x = 0 ; 
    for(int i=0;A[i]!=0;i++){
        x = 1 ;
        x = x<<(A[i]-97) ;
        if((x & h) > 0){
            cout << A[i] << " is duplicate" << endl ;
        }
        else
        h = h | x ;
    }
    return 0 ;
}