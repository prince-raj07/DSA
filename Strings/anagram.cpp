#include<iostream>
using namespace std ;

int main()
{
    char A[] = "decimal" ;
    char B[] = "medical" ;
    int H[26]={0} ;
    for(int i=0;A[i]!=0;i++)
    {
        H[A[i]-97]++ ;
    }
    int i = 0;
    for(i=0;B[i]!=0;i++)
    {
        H[B[i]-97]-- ;
        if(H[B[i]-97]<0){
            cout << "Not an anagram" ;
                break ;
        }
    }
     if(B[i]==0)
     cout << "Anagram" ;
     return 0 ; 
}