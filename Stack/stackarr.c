#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int a[5];
    int top  ;
}stack;

void push(stack *s,int x){
    if(s->top==4){
        printf("overflow\n") ;
        return ;
    }
     s->top += 1;
     s->a[s->top] = x ;
} 

void pop(stack *s){
    if(s->top==-1){
        printf("underlow\n");
        return  ;
    }
    s->top = s->top-1;
}

void display(stack *s){
    int x = s->top ;
    while(x!=-1){
        printf("%d ",s->a[x]);
        x-- ;
    }
    printf("\n");
}

int main(){
    stack p;
    p.top = -1 ;
    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);
    push(&p,5);
    display(&p);
    pop(&p);
    pop(&p);
    display(&p);
    return 0 ;
}