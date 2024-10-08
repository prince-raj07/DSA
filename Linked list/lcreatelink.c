#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data ;
    struct node * next;
}node;

node *create(int n){
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    for(int i=0;i<n;i++){
        temp = (node*)malloc(sizeof(node));
        printf("Enter data in node number %d :",(i+1));
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

void display(node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
        }
}

int main(){
    int n ;
    printf("Enter how many nodes you want to create :") ;
    scanf("%d",&n);
    node *Head = create(n);
    display(Head);
    return 0 ;
}