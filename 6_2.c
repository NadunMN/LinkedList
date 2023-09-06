#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head, *newnode, *temp;

node *createclist(int data){

    int num;
        newnode=(node*)malloc(sizeof(node));
            newnode->data=data;
            newnode->next=head;

        if(head==NULL){
           temp = head = newnode;
        }else{
            temp->next = newnode;
          
            temp=newnode;
        }
        
        return temp;
    }

node *instertBeg(node **head, int data){
    newnode=(node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=*head;
        *head =newnode;
        temp->next=*head;

        
        return temp;
}

node *insertAtEnd(node **head, int data){
    node* ptr;
     newnode=(node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=NULL;
        temp=*head;
        while(temp->next!=*head){
          ptr=temp;
            temp=temp->next;
        }

        newnode->next=*head;
        ptr->next=newnode;

        
        return *head;
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("No Elements in this list now\n");
    } else {
        temp = head;

        
        if (temp->next == head) {
            head = NULL; 
        } else {
            node *lastNode = temp;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }

            head = head->next; 
            lastNode->next = head;
        }

        free(temp);
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("No Elements in this list now\n");
    } else {
        temp = head;

        
        if (temp->next == head) {
            head = NULL; 
        } else {
            node *lastpNode = temp;
            while (temp->next != head) {
                lastpNode = temp;
                temp=temp->next;
            }

          
            lastpNode->next = head;
        }

        free(temp);
    }
}


void printCurcular(node *head){
    if(head==NULL){
        printf("List is Empty\n");

    }else{
        temp=head;
        do{
            printf(" %d", temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}


void freememory(node* head){

    if (head == NULL) {
        printf("The linked list is already empty.\n");
        return;
    }
    temp=head;
    do{
        node* current=temp;
        temp=temp->next;
        free(current);
    }while(temp!=head);

    head=NULL;
}


int main(){
    head=NULL;
  

    createclist(23);
    createclist(32);    
    createclist(45);    
    createclist(76);

instertBeg(&head,44);
insertAtEnd(&head,67);

deleteAtBegin();
deleteAtEnd();

printCurcular(head);

freememory(head);


    return 0;
}


