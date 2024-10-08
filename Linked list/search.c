#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data ;
    struct node * next ;
}node ;

 node * create(int n){
    node * head = NULL;
    node * temp = NULL;
    node * p = NULL;

    for(int i=0;i<n;i++){
        temp = (node*)malloc(sizeof(node));
        printf("Enter data in node number %d : ",(i+1));
        scanf("%d",&(temp->data));
        temp->next = NULL;

        if(i==0){
            head = temp ;
        }

        else{
            p = head ;
            while(p->next!=NULL)
            p = p->next;
            p->next = temp ;
        }
    }
    return head ;
 }

 int search(int key,node* head){
     node * p = head ;
     while(p!=NULL){
        if(p->data==key)
        return 1 ;
        p = p->next;
     }
    return 0 ;
 }
int main(){
    int n ;
    printf("Enter how many nodes you want to create ");
    scanf("%d",&n);
   node * head = create(n);
   int b ;
   printf("Enter element you want to search : ");
   scanf("%d",&b);
   int a = search(b,head);
   printf("%d ",a);
   return 0 ;
}