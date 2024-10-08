#include<iostream>
using namespace std ;

int main()
{
    char a[] = "how are   you" ;
    int i ,words = 1 ;
    for(i=0;a[i]!=0;i++){
        if(a[i]==' ' && a[i-1]!=' ')
        words++ ;
    }
    cout << words << endl ;
}