#include<iostream>
using namespace std ;

int main()
{
    char a[] = "WELCOME DE" ;
    for(int i=0;a[i]!=0;i++){
        if(a[i]!=' ')
        a[i] = a[i] + 32 ;
    }
    cout << a << endl ;
    return 0 ;
}