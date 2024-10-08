#include<iostream>
using namespace std ;

int main()
{
    char A[] = "how are you" ;
    int count = 0 ;
    for(int i = 0;A[i]!=0;i++)
    {
        if(A[i]== 97 || A[i]== 101 || A[i]==105 || A[i]== 111 || A[i]== 117)
        count ++ ;
    }
    cout << count ;
    return 0 ;
}