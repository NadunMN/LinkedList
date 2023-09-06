#include<stdio.h>
#include<stdlib.h>



struct Node {
 int coefficient;
 int exponent;
 struct Node* next;
};

struct Node* insertTerm(struct Node* head, int coefficient, int exponent){
    struct Node* newTerm;
    newTerm=(struct Node*)malloc(sizeof(struct Node));
    newTerm->coefficient=coefficient;
    newTerm->exponent=exponent;
    newTerm->next=NULL;
    

    if(head==NULL){
       head=newTerm;
    }else{
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next; 
        }
        temp->next=newTerm;
        temp=newTerm;

    }       
    return head;
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2){
    
        struct Node* head;
        struct Node* temp;

    while(poly1!=NULL&&poly2!=NULL){
        struct Node* poly=(struct Node*)malloc(sizeof(struct Node));

        if(poly==NULL){
            printf("Memory not allocaed");
        }

        if(poly1->exponent>poly2->exponent){
            poly->exponent = poly1->exponent;
            poly->coefficient = poly1->coefficient;
            poly1 = poly1->next;
        }else if(poly1->exponent<poly2->exponent){
            poly->exponent = poly2->exponent;
            poly->coefficient = poly2->coefficient;
            poly2 = poly2->next;
        }else{
            poly->exponent = poly1->exponent;
            poly->coefficient = poly1->coefficient+poly2->coefficient;
            poly1 = poly1->next;
            poly2 = poly2->next;

    }
   poly->next=NULL;
    if(head==NULL){
        temp=head=poly;
    }else{
        temp->next=poly;
        temp=temp->next;
    }
    
    }

    return head;
}
struct Node* subPolynomials(struct Node* poly1, struct Node* poly2){
    
        struct Node* head;
        struct Node* temp;

    while(poly1!=NULL&&poly2!=NULL){
        struct Node* polys=(struct Node*)malloc(sizeof(struct Node));

        if(polys==NULL){
            printf("Memory not allocaed");
        }

        if(poly1->exponent>poly2->exponent){
            polys->exponent = poly1->exponent;
            polys->coefficient = poly1->coefficient;
            poly1 = poly1->next;
        }else if(poly1->exponent<poly2->exponent){
            polys->exponent = poly2->exponent;
            polys->coefficient = poly2->coefficient;
            poly2 = poly2->next;
        }else{
            polys->exponent = poly1->exponent;
            polys->coefficient = poly1->coefficient-poly2->coefficient;
            poly1 = poly1->next;
            poly2 = poly2->next;

    }
   polys->next=NULL;
    if(head==NULL){
        temp=head=polys;
    }else{
        temp->next=polys;
        temp=temp->next;
    }
    
    }

    return head;
}

void printpolynomial(struct Node* head){


    struct Node* temp=head;
    while(temp!=NULL){
        printf("(%dx^%d)",temp->coefficient, temp->exponent);
        if(temp->next!=NULL)
        printf("+");
        temp=temp->next;
    }
    printf("\n");
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

    struct Node* poly1 = NULL; // poly1 node
    struct Node* poly2 = NULL; // poly2 node
    struct Node* poly = NULL; // poly node
    struct Node* polys = NULL; // polys node

    poly1 = insertTerm(poly1, 2,4);
    poly1 = insertTerm(poly1, 3,3);
    poly1 = insertTerm(poly1, 3,2);
    poly1 = insertTerm(poly1, 4,1);
    printf("Polynomial1: ");
    printpolynomial(poly1);
    
    poly2 = insertTerm(poly2, 6,4);
    poly2 = insertTerm(poly2, 4,3);
    poly2 = insertTerm(poly2, 6,2);
    poly2 = insertTerm(poly2, 1,1);
    printf("Polynomial2: ");
    printpolynomial(poly2);
    
    
    poly=addPolynomials(poly1, poly2);
    printf("Polynomial(ADD)result: ");
    printpolynomial(poly);
    
    polys=subPolynomials(poly1, poly2);
    printf("Polynomial(SUBTRACTION)result: ");
    printpolynomial(polys);
    
    freeallocate(poly1);
    freeallocate(poly2);
    freeallocate(poly);
    freeallocate(polys);

    return 0;
}
