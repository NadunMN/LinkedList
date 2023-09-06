#include<stdio.h>
#include<stdlib.h>


struct node {
 int data;
 struct node* next;
};

struct node *head, *newnode, *temp;

struct node *createnode(int data){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    return newnode;
}


struct node* sortLinkedList( struct node *createnode){
    temp = head;
    struct node* previous=0;

    
    while (temp != 0 && temp->data < createnode->data) {
        previous = temp;
        temp = temp->next;
    }

    if (previous == 0) {
        createnode->next =head;
        head = createnode;
    } else {
        previous->next = createnode;
        createnode->next = temp;
    }
    return 0;
}

void printlist(struct node *head){
    temp=head;
    while(temp!=0){
        printf(" %d", temp->data);
        temp=temp->next;
    }
}


// deletes the entire linked list
struct node* deleteLinkedList(struct node* head){
    temp=head;
     struct node *prev;

    if(head==0){
        printf("underflow error\n");
    }else{
       
        while(temp->next!=0){
            prev=head;
            head= temp->next;
            free(temp);
            temp=temp->next;
        }
       
    }
    return 0;
} 

int main() {

    head=0;
    int num;
    int data;
    printf("How many numbers: ");
    scanf("%d", &num);

    for(int i=0; i<num; i++){
        printf("Enter the Element: ");
        scanf("%d", &data);
        sortLinkedList(createnode(data));
    }
    printf("Sorted link list: ");
    printlist(head);
    printf("\n\n");
    
    printf("Deleted All nodes");
    deleteLinkedList(head);
    
 return 0;
}
