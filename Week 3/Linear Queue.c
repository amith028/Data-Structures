
#include<stdio.h>
#include<stdlib.h>
int size=3;
int lqueue[3];
int rear=-1,front=-1;
void enqueue(int data);
int dequeue();
void display();
int main(){
int choice;
while(1){
    printf("\n the choices are: ");
     printf("\n 1.insert an element  ");
      printf("\n 2.delete an element ");
       printf("\n 3.display the element ");
        printf("\n 4.exit ");
         printf("\n enter the choice: ");
        scanf("%d",&choice);
    switch(choice){
    case 1: {
        int data;
    printf("\n enter the element ");
    scanf("%d",&data);
    enqueue(data);
    break;
            }
    case 2: {
       int ele=dequeue();
       if(ele!=-1){
        printf("\n the deleted element is : %d",ele);
       }
       break;
            }
    case 3:{
           display();
           break;
           }
    case 4: exit(0);
    default: printf("\n enter valid choice");
    }
}
return 0;
}
void enqueue(int data){
if(rear==size-1){
    printf("\n queue overflow. ");
    return;
}
else if(rear==-1&&front==-1){
    front=0;
    lqueue[++rear]=data;
}
else{
    lqueue[++rear]=data;
}
}

int dequeue(){
if(front==-1){
    printf("\n the queue is empty");
    return -1;
}
else if (front==rear){
    int ele=lqueue[front];
    front=-1;
    rear=-1;
    return ele;
}
else{
    int ele=lqueue[front++];
    return ele;
}
}

void display(){
if(front==-1){
    printf("\n the queue is empty.");
}
else {
        printf("\n the queue elements are:.");
        int i=front;
    while(i<=rear){
        printf("\n %d",lqueue[i]);
        i++;
    }
}
}
