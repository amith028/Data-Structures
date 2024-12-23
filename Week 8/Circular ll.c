#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insertatfirst();
void insertatend();
void insertatpos();
void deleteatfirst();
void deleteatend();
void deletele();

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node node;
node *Start = NULL, *new1, *temp = NULL, *last = NULL;

void main() {
    int cho;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. CREATE\n2. DISPLAY\n3. INSERT AT FIRST\n4. INSERT AT END\n5. INSERT AT POSITION\n6. DELETE AT FIRST\n7. DELETE AT END\n8. DELETE ELEMENT\n9. EXIT\n");
        scanf("%d", &cho);
        switch (cho) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertatfirst(); break;
            case 4: insertatend(); break;
            case 5: insertatpos(); break;
            case 6: deleteatfirst(); break;
            case 7: deleteatend(); break;
            case 8: deletele(); break;
            case 9: exit(0); break;
            default: printf("Invalid choice\n");
        }
    }
}

void create() {
    char ch;
    do {
        new1 = (node*)malloc(sizeof(node));
        printf("Enter data for insertion: ");
        scanf("%d", &new1->data);
        if (Start == NULL) {
            Start = new1;
            last = new1;
            last->link = Start;
        } else {
            last->link = new1;
            last = new1;
        }
        printf("Do you want to insert another element? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    last->link = Start;
}

void display() {
    if (Start == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    temp = Start;
    printf("Circular linked list contains: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != Start);
    printf("START\n");
}

void insertatfirst() {
    new1 = (node*)malloc(sizeof(node));
    printf("Enter data for insertion: ");
    scanf("%d", &new1->data);
    if (Start == NULL) {
        Start = new1;
        new1->link = Start;
        return;
    }
    temp = Start;
    while (temp->link != Start) {
        temp = temp->link;
    }
    temp->link = new1;
    new1->link = Start;
    Start = new1;
}

void insertatend() {
    new1 = (node*)malloc(sizeof(node));
    printf("Enter data for insertion: ");
    scanf("%d", &new1->data);
    if (Start == NULL) {
        Start = new1;
        new1->link = Start;
        return;
    }
    temp = Start;
    while (temp->link != Start) {
        temp = temp->link;
    }
    temp->link = new1;
    new1->link = Start;
}

void insertatpos() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    new1 = (node*)malloc(sizeof(node));
    printf("Enter data for insertion: ");
    scanf("%d", &new1->data);
    if (pos == 1) {
        insertatfirst();
        return;
    }
    int i = 1;
    temp = Start;
    while (temp->link != Start && i < pos - 1) {
        temp = temp->link;
        i++;
    }
    if (i != pos - 1) {
        printf("Invalid position\n");
        return;
    }
    new1->link = temp->link;
    temp->link = new1;
}

void deleteatfirst() {
    if (Start == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    if (Start->link == Start) {
        free(Start);
        Start = NULL;
        return;
    }
    temp = Start;
    while (temp->link != Start) {
        temp = temp->link;
    }
    temp->link = Start->link;
    free(Start);
    Start = temp->link;
}

void deleteatend() {
    if (Start == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    if (Start->link == Start) {
        free(Start);
        Start = NULL;
        return;
    }
    node *prev = NULL;
    temp = Start;
    while (temp->link != Start) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = Start;
    free(temp);
}

void deletele() {
    int ele;
    printf("Enter the element you want to delete: ");
    scanf("%d", &ele);
    if (Start == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    if (Start->data == ele) {
        deleteatfirst();
        return;
    }
    node *prev = NULL;
    temp = Start;
    while (temp->data != ele && temp->link != Start) {
        prev = temp;
        temp = temp->link;
    }
    if (temp->data == ele) {
        prev->link = temp->link;
        free(temp);
    } else {
        printf("Element not found\n");
    }
}
