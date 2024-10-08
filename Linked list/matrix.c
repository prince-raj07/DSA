#include<stdio.h>

int main(){
    int a[2][2],sum=0;
    printf("Enter first matrix :\n");
    for(int i=0;i<2;i++)
     for(int j=0;j<2;j++){
        printf("Enter %d%d :",i,j);
        scanf("%d",&a[i][j]);
     }
     int b[2][3] = {1,2,3,4,5,6};
     int res[2][3];

        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<2;k++){
                sum += a[i][k] * b[k][j]; 
                }
                res[i][j] = sum ;
                sum = 0 ;
            }
        }

         for(int i=0;i<2;i++){
          for(int j=0;j<3;j++){
            printf("%d \t",res[i][j]);
            }
            printf("\n");
         }
         return 0 ;
}