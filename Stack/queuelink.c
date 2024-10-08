#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int data ;
    struct queue * next ;
}queue;

queue* front = NULL;
queue* rear = NULL;

void enqueue(queue * p,int x){
    if(rear==NULL){
        p->data = x;
        rear = p ;
        front = p ;
    }
    else{
        p->data = x ;
        p->next = NULL;
        rear->next = p ;
        rear = p ;
        
    }
}

void dequeue(){
    if(front==NULL){
        printf("Underflow\n");
        return ;
    }
    else if(rear==front){
        rear=front=NULL;
        return ;
    }
    else{
       queue * a = front ;
       front = front->next;
       a->next = NULL ;
    }
}

void display(){
    queue * a = front ;
    while(a!=NULL){
        printf("%d ",a->data);
        a = a->next ;
    }
    printf("\n");
}

int main(){
    queue a,b,c,d,e ;
    dequeue();
    enqueue(&a,1);
    enqueue(&b,2);
    enqueue(&c,3);
    enqueue(&d,4);
    enqueue(&e,5);
    display();   
    dequeue();
    dequeue();
    display();
     enqueue(&a,1);
    enqueue(&b,2);
     display();
    return 0 ;
}