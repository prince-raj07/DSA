#include<stdio.h>

    int insert(int *arr,int x){
        int p,v;
        scanf("%d",&p);
        scanf("%d",&v);
        for(int i=x+1;i<p;i--){
            arr[i]=arr[i-1];
        }
        arr[p]=v;
        x = x +1 ;
        return x ;
    }

int main(){
    int a[5] = {1,2,3,4,5};
   int b = insert(a,5);
   for(int i=0;i<b;i++)
   printf("%d",a[i]);
    return 0 ;
}