#include<stdio.h>
#include<stdlib.h>



struct Node {
 int data;
 struct Node* next;
};

struct Node* insert(struct Node* head, int data){
    struct Node* newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;

    if(head==NULL){
        head=(struct Node*)malloc(sizeof(struct Node));
        head->data=0;
        head->next =NULL;
    }
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next; 
        }
        temp->next=newnode;
        head->data++;

    return head;
}

struct Node* delete(struct Node* head, int key){
    if(head==NULL){
        printf("List is Empty You cannot Delete any data");
    }
    struct Node* temp=head;
    struct Node* current=temp->next;

    while(current!=NULL){

        if(current->data==key){

            temp->next=current->next;
            free(current);
            head->data--;
        }

        temp=current;
        current=current->next;

        }
    return head;
}

void printlist1(struct Node* head){

    printf("Before The Deletion:size(%d)", head->data);

    struct Node* temp=head->next;
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printlist2(struct Node* head){

    printf("After The Deletion:size(%d)", head->data);

    struct Node* temp=head->next;
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
}


void freeallocate(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        struct Node* ptr =temp;
        temp=temp->next;
        free(ptr);
    }
}

int main(){

    struct Node* head = NULL; // head node
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    
    printlist1(head);

   
    head = delete(head, 30);
    printlist2(head);


    freeallocate(head);

    return 0;
}
