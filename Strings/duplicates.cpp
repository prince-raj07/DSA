#include<iostream>
using namespace std ;

int main()
{
    char a[] = "python" ;
    int H[26]={0},count = 0 ;
    for(int i = 0;a[i]!=0;i++)
    {
        H[a[i]-97]++ ;
    }
    for(int j=0;j<26;j++)
    {
        if(H[j]>1)
            count++ ;
    }
    cout << "The number of duplicates are " << count << endl ;
    return 0 ;
}