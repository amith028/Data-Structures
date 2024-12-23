#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
typedef struct Node node;

node *Start = NULL, *Curr, *new1, *temp;

void create();
void display();
void insertinbeg();
void insertinend();
void insertinpos();
void deleteatfirst();
void deleteatend();
void deletespele();
void main() {
    int cho;
    while (1) {
        printf("\nEnter your choice \n");
        printf("1.CREATE\n2.DISPLAY\n3.INSERT AT THE BEGINNING\n4.INSERT AT THE END\n5.INSERT AT A PARTICULAR POSITION\n6.DELETE AT THE FIRST\n7.DELETE AT THE END\n8.DELETE SPECIFIC ELEMENT\n9.EXIT\n");
        scanf("%d", &cho);
        switch (cho) {
            case 1: create();
                break;
            case 2: display();
                break;
            case 3: insertinbeg();
                break;
            case 4: insertinend();
                break;
            case 5: insertinpos();
                break;
            case 6: deleteatfirst();
                break;
            case 7: deleteatend();
                break;
            case 8: deletespele();
                break;
            case 9: exit(0);

            default: printf("Invalid choice \n");
        }
    }
}

void create() {
    char ch;
    do {
        new1 = (node *)malloc(sizeof(node));
        if (!new1) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data for insertion: ");
        scanf("%d", &new1->data);
        if (Start == NULL) {
            Start = new1;
            Curr = new1;
        } else {
            Curr->link = new1;
            Curr = new1;
        }

        printf("Do you want to insert another element? Enter Y or y for Yes, and N or n for No: ");
        scanf(" %c", &ch); // Note the space before `%c` to consume any leftover newline
    } while (ch == 'Y' || ch == 'y');
}

void display() {
    if (Start == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    temp = Start;
    printf("List elements are: \n");
    while (temp != NULL) { 
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n"); 
}

void insertinbeg() {
    new1 = (node *)malloc(sizeof(node));
    printf("Enter the element: ");
    scanf("%d", &new1->data);
    new1->link = Start; 
    Start = new1;       
}

void insertinend() {
    new1 = (node *)malloc(sizeof(node));
    printf("Enter the element: ");
    scanf("%d", &new1->data);
    new1->link = NULL; 

    if (Start == NULL) { 
        Start = new1;
        return;
    }

    temp = Start;
    while (temp->link != NULL) { 
        temp = temp->link;
    }
    temp->link = new1;
}

void insertinpos() {
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    new1 = (node *)malloc(sizeof(node));
      printf("Enter the element: ");
    scanf("%d", &new1->data);
    new1->link = NULL;
    if (pos == 1) { 
        new1->link = Start;
        Start = new1;
        return;
    }
    temp = Start;
    while (temp != NULL && i < pos - 1) {         temp = temp->link;
        i++;
    }

    if (temp == NULL) { 
        printf("Position exceeds the number of elements\n");
        return;
    }

    new1->link = temp->link;
    temp->link = new1;
}

void deleteatfirst(){
    if(Start==NULL){
        printf("Linked list is empty");
        return;
    }
    else{
        temp=Start;
        Start=Start->link;
        free(temp);
    }
}

void deleteatend(){
    temp=Start;
    node  *previous=NULL, *next= Start; 
    if(Start->link==NULL){
        Start=NULL;
        return;
    }
    while(next->link!=NULL){
        previous=next;
        next=next->link;
    }
    previous->link=NULL;
    free(next);
}

void deletespele(){
    node  *previous=NULL, *next= Start;  
    int ele;
    if(Start==NULL){
        printf("Linked list is empty");
        return;
    }
    printf("Enter the element\t");
    scanf("%d", &ele);
    if(Start->data==ele){
        temp=Start;
        Start=Start->link;
        free(temp);
        return;
    }
    previous=NULL; next=Start;
    while(next->data!=ele&&next->link!=NULL){
        previous=next;
        next=next->link;
    }
    if(next->data==ele){
        previous->link=next->link;
        free(next);
        return;
    }
    else{
        printf("Element not found\n");
    }
}
