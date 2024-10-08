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

node *insert(int x,node *head){
    int choice ;
    printf("Enter 1 for begin\n Enter 2 for mid\n Enter 3 for end\n");
    scanf("%d",&choice);
    if(choice==1){
        node * ptr ;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = x ;
        ptr->next = head;
        head = ptr ;
        return head ;
    }
    if(choice==3){
        node * ptr ;
        node * ptr2 = head ;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = x ;
        ptr->next = NULL;
        while(ptr2->next!=NULL){
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr ;
        return head ;
    }

        if(choice==2){
            int a ;
            printf("Enter node number :");
            scanf("%d",&a);
            node *ptr1 = NULL;
            node *ptr2 = NULL;
            node *ptr3 = NULL;
            ptr3 = head ;
            for(int i=1;i<=a;i++){
                if(i==(a-2))
                ptr1 = ptr3->next;
                if(i==(a-1))
                ptr2 = ptr3->next;
                ptr3 = ptr3->next ;
            }
            ptr3 = (node*)malloc(sizeof(node));
            ptr3->data = x ;
            ptr3->next = ptr2;
            ptr1->next = ptr3 ;
            return head ;
        }
    }


int main(){
    int n ;
    printf("Enter how many nodes you want to create :") ;
    scanf("%d",&n);
    node *Head = create(n);
    display(Head);
    Head = insert(7,Head);
    display(Head);
    return 0 ;
}

