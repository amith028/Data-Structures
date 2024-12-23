#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};
typedef struct Node node;
    node *Start=NULL, *Curr, *new1, *temp;


void create();
void display();
void insertinbeg();
void insertinend();
void insertinpos();
void deleteinbeg();
void deleteinlast();
void deletespele();

void main(){
    int cho;
    while(1){
        printf("\nEnter your choice \n");
        printf("1.CREATE\n2.DISPLAY\n3.INSERT AT THE BEGINNING\n4.INSERT AT THE END\n5.INSERT AT A PARTICULAR POSITION\n6.DELETE FIRST\n7.DELETE END\n8.DELETE ELEMENT\n9.EXIT\n");
        scanf("%d", &cho);
        switch(cho){
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
                case 6: deleteinbeg();
                    break;
                case 7: deleteinlast();
                    break;
                case 8: deletespele();
                    break;
                case 9: exit(0);

                default: printf("Invalid choice \n");
        }
    }
}

void create()
{
            char ch;
            new1=(node*)malloc(sizeof(node));
            printf("Enter data for insertion \t");
            scanf("%d", &new1->data);
            if(Start==NULL){
                new1->prev=NULL;
                Start=new1;
                Curr=new1;
            }
            while(1){
                printf("Do you want to insert another node? Enter Y or y for Yes and N or n for no\n");
                scanf("%s", &ch);
                if(ch=='Y'||ch=='y'){
                    new1=(node*)malloc(sizeof(node));
                    printf("Enter data for insertion \t");
                    scanf("%d", &new1->data);
                    new1->prev=Curr;
                    Curr->next=new1;
                    Curr=new1;
                }
                else{
                    Curr->next = NULL;
                    break;
                }
            }
}

void display(){
    if(Start==NULL){
        printf("Linked list is empty\n");
        return;
    }
    temp= Start;
    while(temp!=NULL){
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertinbeg(){
    new1=(node*)malloc(sizeof(node));
    printf("Enter data for insertion \t");
    scanf("%d", &new1->data);
    if(Start==NULL){
        new1->prev=NULL;
        new1->next=Start;
        Start=new1;
        return;
    }
    else{
        new1->prev=NULL;
        Start->prev=new1;
        new1->next=Start;
        Start = new1;
    }
}

void insertinend(){
    new1=(node*)malloc(sizeof(node));
    printf("Enter data for insertion \t");
    scanf("%d", &new1->data);
    if(Start==NULL){
        new1->prev=NULL;
        new1->next=Start;
        Start=new1;
    }
    temp=Start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new1;
    new1->prev=temp;
    new1->next=NULL;
}

void insertinpos(){
    int pos;
    new1=(node*)malloc(sizeof(node));
    printf("Enter data for insertion \t");
    scanf("%d", &new1->data);
    printf("Enter the position\t");
    scanf("%d", &pos);
    if(pos==1){
        new1->prev=NULL;
        new1->next=Start;
        Start=new1;
        return;
    }
    int i=1;
    temp = Start;
    while(i<pos-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    if(i==pos-1){
        new1->prev=temp;
        new1->next=temp->next;
        temp->next->prev=new1;
        temp->next=new1;
    }
    if(temp==NULL){
        printf("Invalid position");
    }
}

void deleteinbeg(){
    if(Start == NULL){
        printf("Linked list is empty\n");
        return;
    }
    else{
        temp = Start;
        Start=Start->next;
        Start->prev=NULL;
        free(temp);
        return;
    }
}

void deleteinlast(){
    if(Start == NULL){
        printf("Linked list is empty\n");
        return;
    }
    else if(Start->next==Start){
        temp = Start;
        Start=Start->next;
        Start->prev=NULL;
        free(temp);
        return;
    }
    else{
        temp = Start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}

void deletespele() {
    int ele;
    if (Start == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    printf("Enter the element you want to delete: ");
    scanf("%d", &ele);

    temp = Start;
    if (Start->data == ele) {
        temp = Start;
        Start = Start->next;
        if (Start != NULL) {
            Start->prev = NULL;
        }
        free(temp);
        printf("Element %d deleted from the beginning.\n", ele);
        return;
    }
    while (temp != NULL && temp->data != ele) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", ele);
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("Element %d deleted successfully.\n", ele);
}
