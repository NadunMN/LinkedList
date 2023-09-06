#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

node* insertAtBeginning(node* head, int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    if (head == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
    } else {
        newnode->prev = head->prev;
        newnode->next = head;
        head->prev->next = newnode;
        head->prev = newnode;
    }

    return newnode;
}

node* insertAtEnd(node* head, int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    if (head == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
        head = newnode;
    } else {
        newnode->prev = head->prev;
        newnode->next = head;
        head->prev->next = newnode;
        head->prev = newnode;
    }

    return head;
}

node* deleteAtBegin(node* head) {
    if (head == NULL) {
        printf("Underflow Error\n");
        return NULL;
    }

    node* temp = head;
    head = head->next;
    head->prev = temp->prev;
    temp->prev->next = head;
    free(temp);

    return head;
}

node* deleteAtEnd(node* head) {
    if (head == NULL) {
        printf("Underflow Error\n");
        return NULL;
    }

    node* temp = head->prev;
    head->prev = temp->prev;
    temp->prev->next = head;
    free(temp);

    return head;
}

void printlist(node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    node* temp = head;
    do {
        printf(" %d", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void freeallocate(node* head) {
    if (head == NULL)
        return;

    node* current = head;
    do {
        node* temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

int main() {
    int num, data;
    node* head = NULL;

    printf("How many numbers do you want: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("What number: ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    head = insertAtBeginning(head, 23);
    head = insertAtEnd(head, 43);

    head = deleteAtBegin(head);
    head = deleteAtEnd(head);

    printlist(head);
    freeallocate(head);

    return 0;
}
