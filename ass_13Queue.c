#include<stdio.h>
#include<stdlib.h>
int arr[50];
int front,rear,cap;
int isFull(){
    return (rear==cap-1);
}

int isEmpty(){
    return (front==-1);
}

void show(){
    if(isEmpty()){
        printf("\nQueue is empty");
        return;
    }
    for (int i=front;i<=rear;i++){
        printf("\n%d,",arr[i]);
    }
}

void enqueue(int item){
    // if(isFull()){
    //     printf("\n Queue is full");
    //     break;
    // }
    rear++;
    arr[rear]=item;
    if(isEmpty())
        front++;
}

int dequeue(){
    if(isEmpty()){
        printf("\n Queue is empty.");
        break;
    }
    int k=arr[front];
    if(front==rear){
        front=rear=-1;
    }
    else
        front++;
    return k;
}

int main(){
front=rear=-1;
printf("\nEnter capacity of queue: ");
scanf("%d",&cap);
while(1){
printf("\n1.Enqueue\n2.Dequeue\n3.Show\nAnything else to exit.");
printf("\nEnter choice:");
int choice;
scanf("%d",&choice);
switch (choice)
{
case 1:{
    if(isFull()){
        printf("\n Queue is full");
        break;
    }
    printf("\nEnter value you want to enter: ");
    int item;
    scanf("%d",&item);
    enqueue(item);
    show();
    break;
}
case 2:{
    int k=dequeue();
    printf("\nThe %d is dequed",k);
    show();
    break;
}
case 3:{
    show();
    break;
}
default:{
    choice=10;
    break;
    }
}
if(choice==10)
    break;
}
}