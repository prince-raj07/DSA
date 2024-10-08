#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node * next ;
}*head=NULL;

 int count ;

 void create(int A[],int n){
    struct node * t , *last;
    if(head==NULL){
      head = (struct node *) malloc(1 * sizeof(struct node));
      head->data = A[0];
      head->next = head ;
      last = head ;
      count++;
    }
     for(int i = 1 ;i<n;i++)
     {
        t = (struct node *) malloc(1 * sizeof(struct node));
        t->data = A[i] ;
        t->next = last->next ;
        last->next = t ;
        last = t ;
        count++ ;
     }
 }
    
  void display(){
        struct node * p = head ;
        do{
            printf("%d ",p->data);
            p = p->next ;
        }while(p!=head) ;
        printf("\n");
  }

  void insert(int x){
    int n = count ;
    struct node * p , * q ,* t;
    int choice ;
    printf("Enter position from 0 to 5\n");
    scanf("%d",&choice);
    if(choice==0){
         t = (struct node *)malloc(1*sizeof(struct node));
        t->data = x ;
        p = head ;
        do{
            p = p->next ;
        }while(p->next!=head);
        t->next = head ;
        p->next = t ;
        head = t ;
        count++;
    }
    else{
         p = head ;
        for(int i = 1;i<=(choice-1);i++)
        {
            p = p->next ;
        }
           t = (struct node *)malloc(1*sizeof(struct node));
           t->data = x ;
           t->next = p->next ;
           p->next = t ;
           count++;
    }
    
  }

  void delete(){
        struct node * p , *q ;
         int choice ;
        printf("Enter position from 1 to 5\n");
        scanf("%d",&choice);
        if(choice==1){
            p = head ;
        for(int i = 1;i<count;i++){
            p = p->next ;
        }
            p->next = head->next ;
            free(head);
            head = p->next ;
            count--;
        }
        else{
            p = head ;
             for(int i = 1;i<=choice-2;i++){
            p = p->next ;
        }
            q = p->next ;
            p->next = q->next;
            free(q);
            count--;
        }
        
  }

  int main(){
    int b[] = {1,2,3,4,5};
        create(b,5);
        display();
        insert(8);
        display();
        delete();
        display();
        return 0 ;
  }
