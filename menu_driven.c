#include<stdio.h>
void main()
{
    int n,size,op,pos,item,i;
    char ch;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int A[size];
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\n Enter the %d th element:",i);
        scanf("%d",&A[i]);
    }
    //choice entering
    printf("\n1)Insertion.\n2)Deletion.\n3)Display\n");
    printf("\n Enter the array operation number:");
    scanf("%d",&op);
    if(op==1)
    {
        if(size==n)
        {
            printf("\n The array is full insertion is not possible..");
        }
        else
        {
            printf("\nARRAY BEFORE INSERTION");
            for(i=0;i<n;i++){
                printf("%d ",A[i]);
            }
            printf("\n Enter the new element for insertion:");
            scanf("%d",&item);
            printf("\n Enter the new item position(0-%d):",n-1);
            scanf("%d",&pos);
            if(pos>size){
                printf("\n Insertion is not possible!..");
            }
            else if(pos>n){
                A[pos]=item;
                n++;
            }
            else{
                for(i=n;i>=pos;i--)
                {
                    A[i]=A[i-1];
                }
                A[pos]=item;
                n++;
            }
            printf("\n After insertion.\n");
            for(i=0;i<n;i++){
                printf("%d ",A[i]);
            }

        }
    }
    else if(op==2)
    {
        for(i=0;i<n;i++)
        {
            printf("%d ",A[i]);
        }
        printf("\n Enter the elements index for deletion(0-%d)",n-1);
        scanf("%d",&item);
        for(i=item;i<n;i++){
            A[i]=A[i+1];
        }
        n--;
        printf("\n ARRAY DELETION\n..");
        for(i=0;i<n;i++)
        {
            printf("%d ",A[i]);
        }
    }
    else
    {
        printf("\nARRAY DISPLAY.\n");
        for(i=0;i<n;i++){
            printf("%d ",A[i]);
        }
    }
}