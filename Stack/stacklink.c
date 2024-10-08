#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int data ;
    struct stack * next ;
}stack;


 stack * top = NULL;
 stack * top1 = NULL ;

 void push(stack *p,int x){
    stack * t ;
     if(top==NULL){
        p->data = x ;
        p->next = NULL ;
        top =  p ;
        top1 = p ;
     }
     else{
        p->data = x ;
        p->next = top ;
        top1 = top ;
        top = p ;
     }
 }

 void pop(){
    if(top==NULL){
        printf("underflow") ;
    }
    else if(top->next==NULL){
        top = NULL ;
        top1 = NULL;
    }
    else{
        top = top->next ;
        if(top->next){
            top1 = top->next ;
        }
    }
 }

 void display(){
    stack * t = top ;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
 }

 int main(){
    stack s,q,r,t,u ;
    pop();
     push(&s,1);
    push(&q,2);
    push(&r,3);
    push(&t,4);
    push(&u,5);
    display();
    pop();
    pop();
    display();
 }