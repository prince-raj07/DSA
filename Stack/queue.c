#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int A[10] ;
    int front ;
    int rear ;
}queue;

void enqueue(queue * p, int x){
    if(p->rear==9){
        printf("overflow\n");
        return ;
    }
    else if(p->rear==-1){
        p->rear++;
        p->front++;
        p->A[p->rear] = x ;
    }
    else{
        p->rear++;
        p->A[p->rear] = x ;
    }
}

void dequeue(queue * p){
    if(p->front==-1){
        printf("Underflow\n");
        return ;
    }
    else if(p->front==p->rear){
        p->front=p->rear=-1;
        return ;
    }
    else{
        p->front++;
    }
}

void display(queue * p){
    int x = p->front ;
    while(x!=p->rear+1){
        printf("%d ",p->A[x]);
         x++;
    }
    printf("\n");
}

int main(){
    queue q;
    q.front=q.rear=-1;
    dequeue(&q);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    dequeue(&q);
    dequeue(&q);
    display(&q) ;
    enqueue(&q,1);
    enqueue(&q,2);
    display(&q) ;
    return 0 ;
}