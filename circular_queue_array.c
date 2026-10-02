#include<stdio.h>
int a[20],front,rear,size;
void enqueue(int item){
    if((rear+1)%size==front){
        printf("Queue is full .insertion is not possible");
    }
    else if(rear==-1){
        front=0;
        rear=0;
        a[rear]=item;
    }
    else{
        rear=(rear+1)%size;
        a[rear]=item;
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty");
    }
    else if(front==rear){
        printf("Deleted item is %d",a[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("Deleted item is %d",a[front]);
        front=(front+1)%size;
    }
}

void display(){
    int i;
    if(front==-1){
        printf("Queue is empty");
    }
    else if(front<=rear){
        printf("The elements are\n");
        for(i=front;i<=rear;i++){
            printf("%d\t",a[i]);
        }
    }
    else{
        printf("The elements are\n");
        for(i=front;i<=size-1;i++)
            printf("%d\t",a[i]);
        for(i=0;i<=rear-1;i++)
            printf("%d\t",a[i]);
        }
}

void main(){
    int opt,item;
    front=-1;
    rear=-1;
    printf("Enter the size of the queue:");
    scanf("%d",&size);
    do{
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
        printf("\nEnter the choice:");
        scanf("%d",&opt);
        switch(opt){

            case 1:printf("\nEnter the item to be inserted:");
            scanf("%d",&item);
            enqueue(item);
            break;

            case 2:dequeue();
            break;

            case 3:display();
            break;

            case 4:printf("EXIT");
            break;
            default:printf("Invalid choice");
        }
    }while(opt!=4);
}