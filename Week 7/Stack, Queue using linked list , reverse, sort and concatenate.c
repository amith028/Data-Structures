//Linked Implementation of Stack 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
typedef struct Node node;

node *top = NULL, *Curr, *new1, *temp;

void display();
void push();
int pop();
void main() {
    int cho, ele;
    while (1) {
        printf("\nEnter your choice \n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &cho);
        switch (cho) {
            case 1: push();
                break;
            case 2: ele=pop();
                    if(ele==-1){
                        printf("Stack is empty\n");
                    }
                    else{
                        printf("Popped element= %d", ele);
                    }
                break;
            case 3: display();
                break;
            case 4: exit(0);

             default: printf("Invalid choice \n");
        }
    }
}

void push(){
    new1 = (node *)malloc(sizeof(node));
    printf("Enter the element: ");
    scanf("%d", &new1->data);
    new1->link = top;
    top = new1;       
}

int pop(){
    if(top==NULL){
        return(-1);
    }
    else{
        int element;
        element=top->data;
        temp=top;
        top=top->link;
        free(temp);
        return(element);
    }
}

void display(){
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Stack elements are: \n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

//Linked Implementation of  Queue
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
typedef struct Node node;

node *front = NULL, *rear = NULL, *new1, *temp;

void insert();
int delete(int *element);
void display();

void main() {
    int cho, ele, status;
    while (1) {
        printf("\nEnter your choice \n");
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &cho);
        switch (cho) {
            case 1: insert();
                break;
            case 2: 
                status = delete(&ele);
                if (status  == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Deleted element: %d\n", ele);
                }
                break;
            case 3: display();
                break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

void insert() {
    new1 = (node *)malloc(sizeof(node));
    printf("Enter the element: ");
    scanf("%d", &new1->data);
    new1->link = NULL; 

    if (front == NULL && rear == NULL) { 
        front = new1;
        rear = new1;
    } else { 
        rear->link = new1;
        rear = new1;
    }
}

int delete(int *element) {
    

    if (front == NULL) { 
        return -1;
    }

    *element = front->data;
    temp = front;
    front = front->link;
    free(temp); 

    if (front == NULL) { 
        rear = NULL; 
    }

    return 1;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        while (temp != NULL) { 
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}

//Reversal and sorting of linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* link;
} node;


node *Start = NULL, *Curr, *new1, *temp;

void create(node**n);
void display(node**n);
void reverse(node**no);
void sort(node**n);
void main() {
    int cho;
    while (1) {
        printf("Enter your choice \n");
        printf("1.CREATE 1\n2.DISPLAY\n3.REVERSE\n4.SORT AND DISPLAY\n6.EXIT\n");
        scanf("%d", &cho);
        switch (cho) {
             case 1: create(&Start); break;
            case 2: display(&Start); break;
            case 3: reverse(&Start); break;
            case 4: sort(&Start); break;
            case 5: exit(0); break;
        default: printf("Invalid choice \n");
        }
    }
}

void create(node**n) {
    char ch;
    do {
        new1 = (node*)malloc(sizeof(node));
        printf("Enter data for insertion: ");
        scanf("%d", &new1->data);
        if (*n == NULL) {
            *n = new1;
            Curr = new1;
        }
        else {
            Curr->link = new1;
            Curr = new1;
        }

        printf("Do you want to insert another element? Enter Y or y for Yes, and N or n for No: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
        Curr->link=NULL;
}

void display(node**n) {
    if (*n == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    temp = *n;
    printf("List elements are: \n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void reverse(node** no) {
    if (*no == NULL) {
        printf("Linked list is empty \n");
    } else {
        node *a = NULL, *b = NULL, *c = NULL;
        a = *no;
        while (a != NULL) {
            c = b;
            b = a;
            a = a->link;
            b->link = c;
        }
        *no = b;
        printf("Displaying the reversed list\n");
        display(no);
    }
}

void sort(node **n) {
    if (*n == NULL) {
        printf("List is empty, nothing to sort\n");
        return;
    }

    node *i, *j;
    int tempData;
    for (i = *n; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("List sorted successfully.\n");
    display(n);
}


//Concatenation of two Linked Lists
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* link;
} node;


node *Start1 = NULL, *Start2 = NULL, *Curr, *Start=NULL, *new1, *temp;

void create(node**n);
void display(node**n);
void concatenate(node**n1, node**n2);
void reverse(node**no);
void sort(node**n);
void main() {
    int cho;
    while (1) {
        printf("Enter your choice \n");
        printf("1.CREATE 1\n2.DISPLAY 1\n3.CREATE 2\n4.DISPLAY 2\n5.CONCATENATE\n6.DISPLAY CONCATENATED LIST\n7.EXIT\n");
        scanf("%d", &cho);
        switch (cho) {
            case 1: create(&Start1); break;
            case 2: display(&Start1); break;
            case 3: create(&Start2); break;
            case 4: display(&Start2); break;
            case 5: concatenate(&Start1, &Start2); break;
            case 6: display(&Start); break;
            case 7: exit(0); break;

            default: printf("Invalid choice\n");
        }
    }
}


void create(node**n) {
    char ch;
    do {
        new1 = (node*)malloc(sizeof(node));
        printf("Enter data for insertion: ");
        scanf("%d", &new1->data);
        if (*n == NULL) {
            *n = new1;
            Curr = new1;
        }
        else {
            Curr->link = new1;
            Curr = new1;
        }

        printf("Do you want to insert another element? Enter Y or y for Yes, and N or n for No: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
        Curr->link=NULL;
}

void display(node**n) {
    if (*n == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    temp = *n;
    printf("List elements are: \n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void concatenate(node**n1, node**n2){
    if(*n1==NULL && *n2==NULL){
        printf("Both linked lists are empty\n");
    }
    if(*n1==NULL){
        Start=*n2;
    }
    if(*n2==NULL){
        Start=*n1;
    }
    else{
        Start=*n1;
        temp=*n1;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        if(temp->link==NULL){
            temp->link=*n2;
        }
        return;
    }
}
