#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node * prev ;
    struct node * next ;
}*head = NULL;

 int count ;

void create(int A[],int n){
    struct node * t , * last ;
    if(head==NULL)
    {
        head = (struct node *) malloc(1*sizeof(struct node));
        head->prev = NULL ;
        head->data = A[0];
        head->next = NULL;
        last = head ;
        count++ ;
    }
    for(int i=1;i<n;i++){
         t = (struct node *) malloc(1*sizeof(struct node));
         t->data = A[i];
         last->next = t ;
         t->prev = last ;
         t->next = NULL;
         last = t ;
         count++ ;
    }
}

 void display(){
    struct node * p = head ;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next ;
    }
    printf("\n");
 }

 void insert(int x){
    struct node * t, * q, *p ;
    int choice ;
     printf("Enter position from 0 to 5\n");
    scanf("%d",&choice);
    if(choice==0){
        t = (struct node *) malloc(1*sizeof(struct node));
        t->data = x ;
        t->prev = NULL;
        t->next  = head ;
        head->prev = t ;
        head = t ;
        count++;
    }
    else{
        p = head ;
        for(int i = 1;i<=choice-1;i++){
            p = p->next ;
        }
            q = p->prev ;
        t = (struct node *) malloc(1*sizeof(struct node));
        t->data = x ;
        t->next = p->next ;
        t->prev = p ;
        if(p->next){
            p->next->prev = t ;
        }
        p->next = t;
        count++;
    }
 }

 void delete(){
    struct node * t, * q, *p ;
    int choice ;
     printf("Enter position from 1 to %d\n",count);
    scanf("%d",&choice);
    if(choice==1){
        p = head ;
        head = head->next;
        free(p);
       
        if(head){
             head->prev = NULL;
        }
        count--;
    }
    else{
        p = head ;
        for(int i =1 ;i<=choice-1;i++){
            p = p->next ;
        }
        p->prev->next = p->next;
        if(p->next)
        p->next->prev = p->prev ;
        free(p);
        count--;
    }
 }

 int main(){
    int b[] = {1,2,3,4,5} ;
    create(b,5);
    display();
    insert(8);
    display();
    delete();
    display();
    return 0 ;
 }