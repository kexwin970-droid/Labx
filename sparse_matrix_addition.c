#include<stdio.h>
void print_sparse(int x[20][3]){
    int i,j;
    printf("\n Tuple representation of sparse matrix\n");
    for(i=0;i<=x[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }

}

void sparse(int a[10][10],int m,int n,int s[20][3]){
    int i,j,k=1;
    s[0][0]=m;
    s[0][1]=n;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
            }
        }
    }
    s[0][2]=k-1;
    print_sparse(s);
}

void add_sparse(int s[20][3],int t[20][3]){
    int r1,r2,c1,c2,m,n,i,j,k,a[20][3];
    r1=s[0][0];
    c1=s[0][1];
    r2=t[0][0];
    c2=t[0][1];
    if(r1!=r2 || c1!=c2)
    {
        printf("Incompatible matrix size....\n");
    }
    else{
        a[0][0]=s[0][0];
        a[0][1]=s[0][1];
        m=1;
        n=1;
        k=1;
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                if(s[m][0]==i && s[m][1]==j && t[n][0]==i && t[n][1]==j){
                    a[k][0]=s[m][0];
                    a[k][1]=s[m][1];
                    a[k][2]=s[m][2]+t[n][2];
                    m++;
                    n++;
                    k++;
                }
                else if(s[m][0]==i && s[m][1]==j){
                    a[k][0]=s[m][0];
                    a[k][1]=s[m][1];
                    a[k][2]=s[m][2];
                    m++;
                    k++;
                }
                else if(t[n][0]==i && t[n][1]==j){
                    a[k][0]=t[n][0];
                    a[k][1]=t[n][1];
                    a[k][2]=t[n][2];
                    n++;
                    k++;
                }

            }
        }
    }
    a[0][2]=k-1;
    printf("sum of the matrix is :\n");
    for(i=0;i<=a[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int i,j,a[10][10],b[10][10],m1,n1,m2,n2,s[20][3],t[20][3];
    printf("Enter the no of raws and columns of the 1st matrix:");
    scanf("%d%d",&m1,&n1);
    printf("Enter the matrix elements:");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Matrix1:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    sparse(a,m1,n1,s);
    
    //second matrix

     printf("Enter the no of raws and columns of the 2nd matrix:");
    scanf("%d%d",&m2,&n2);
    printf("Enter the matrix elements:");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("Matrix2:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    sparse(b,m2,n2,t);
    add_sparse(s,t);

}