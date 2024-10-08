#include<iostream>
using namespace std ;

int main()
{
    char a[] = "python two" ;
    cout << a << endl ;
    int j,i ;
    for(j=0;a[j]!=0;j++){

    }
     for(i=0,j=j-1;i<j;i++,j--){
        char temp = a[i] ;
        a[i] = a[j] ;
        a[j] = temp ;
     }
     cout << a ;
}