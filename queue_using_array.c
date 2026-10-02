#include<stdio.h>
int a[50];
int rear,front,size;
void enqueue(int item){
    if(rear==size-1)
    {
        printf("queue is full insertion not possible");
    }
    else if (rear==-1)
    {
        rear=0;
        front=0;
        a[rear]=item;
    }
    else{
        rear++;
        a[rear]=item;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        printf("Deleted item is %d",a[front]);
        front--;
        rear--;
    }
    else{
        printf("Deleted item is %d",a[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue ius empty..");
    }
    else{
        printf("The elements are:");
        for(i=front;i<=rear;i++){
            printf("%d\t",a[i]);
        }
    }
}
void main()
{
    int choice,item;
    front=rear=-1;
    printf("Enter the size of te queue:");
    scanf("%d",&size);
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value to be inserted:");
            scanf("%d",&item);
            enqueue(item);
            break;

            case 2:dequeue();
            break;

            case 3:display();
            break;

            case 4:printf("\nEXIT");
            break;

            default:printf("\n Invalid choice");

        }
    }while(choice!=4);
    return ;
}