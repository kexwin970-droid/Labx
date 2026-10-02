#include<stdio.h>
int a[20],size,front,rear;
void push_dq(int item){
    if(front==0 && rear==size-1){
        printf("Dequeue is full. Insertion not possible!!!!!!!");
    }
    else if(rear==-1){
        front=0;
        rear=0;
        a[front]=item;
    }
    else if(front>0){
        front--;
        a[front]=item;
    }
    else{
        for(int i=rear;i>=front;i--){
            a[i+1]=a[i];
        }
        a[front]=item;
        rear++;
    }
}

void inject_dq(int item){
    if(front==0 && rear==size-1){
        printf("Dequeue is full. Insertion not possible");
    }
    else if(rear==-1){
        front=0;
        rear=0;
        a[rear]=item;
    }
    else if(rear<size-1){
        rear++;
        a[rear]=item;
    }
    else{
        for(int i=front;i<=rear;i++){
            a[i-1]=a[i];
            a[rear]=item;
            front--;
        }
    }
}

void pop_dq(){
    if(front==-1 && rear==-1){
        printf("Dequeue is %d",a[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("Deleted item is %d",a[front]);
        front++;
    }
}

void eject_dq(){
    if(rear==-1){
        printf("Dequeue is empty");
    }
    else if(front==rear){
        printf("Deleted item is %d",a[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("Deleted item is %d",a[rear]);
        rear--;
    }
}

void display_dq(){
    int i;
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else{
        printf("The elements in the queue are \n");
        for(i=front;i<=rear;i++){
            printf("%d\t",a[i]);
        }
    }
}

int main(){
    int item,opt;
    front=-1;
    rear=-1;
    printf("Enter the size of the dequeue:");
    scanf("%d",&size);
    do
    {
        printf("\n1.PUSH\n2.POP\n3.INJECT\n4.EJECT\n5.DISPLAY\n6.EXIT");
        printf("\n Enter your choice:");
        scanf("%d",&opt);
    
    switch(opt){
        
        case 1:printf("Enter the item to be inserted:");
        scanf("%d",&item);
        push_dq(item);
        break;

        case 2:pop_dq();
        break;

        case 3:printf("Enter the item to be inserted:");
        scanf("%d",&item);
        inject_dq(item);
        break;

        case 4:eject_dq();
        break;

        case 5: display_dq();
        break;

        case 6:
        default:printf("Invalid option!!!!!!!");
        break;
    }
   }while(opt!=6);
   return 0;
}