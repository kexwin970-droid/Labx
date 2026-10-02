#include<stdio.h>
int a[50];
int top,size;
void push(int item)
{
    if(top==size-1){
        printf("\n The stack is full");
    }
    else{
        top++;
        a[top]=item;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else{
        printf("Item to be popped is %d",a[top]);
        top--;
    }
}

void display()
{
    int i;
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("the elements are \n");
        for(i=0;i<=top;i++)
        {
            printf("%d\t",a[i]);
        }
    }
}
void main()
{
    int choice,item;
    top=-1;
    printf("Enter the size of the stack:");
    scanf("%d",&size);
    do{
        printf("\n1.PUSH\n2.pop\n3.display\n4.exit");
        printf("\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nEnter the item to push:");
            scanf("%d",&item);
            push(item);
            break;

            case 2:pop();
            break;

            case 3:display();
            break;

            case 4:printf("EXIT");
            break;

            default:printf("Invalid choice\n");

        }
    }while(choice!=4);
    return;
}