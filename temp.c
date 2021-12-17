/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
void insert(int *p,int x,int pos,int n){
    int i;
    for(i=n-1;i>=pos-1;i--){
        p[i+1]=p[i];
    }
    p[pos-1]=x;
}
void delete(int *p,int pos,int n){
    int i;
    for(i=pos-1;i<n-1;i++){
        p[i]=p[i+1];
    }
}
void display(int *p,int n){
    int i;
    printf("The elements are :\n");
    for(i=0;i<n;i++){
        printf("%d\t\n",p[i]);
    }
}
void main(){
    int max,choice,n=0;
    scanf("%d",&max);
    int *p;
    p=(int*)malloc(max*sizeof(int));
    do{
        printf("1.Insert\n2.Delete\n3.Get element at index\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int x,pos;
                printf("Enter element to be inserted:");
                scanf("%d",&x);
                printf("position:");
                scanf("%d",&pos);
                if(n==max){
                    printf("overflow\n");
                }
                else if(pos>n+1){
                    printf("out of range\n");
                }
                else{
                insert(p,x,pos,n);
                n++;
                }
                break;
            }
            case 2:{
                int pos;
                printf("position:");
                scanf("%d",&pos);
                if(pos>n){
                    printf("out of range\n");
                }
                else{
                    delete(p,pos,n);
                    n--;
                }
            }
            case 4:{
                if(n==0){
                    printf("Array is empty\n");
                }
                else{
                    display(p,n);
                }
                break;
            }
            case 5:{
                break;
            }
            default:{
                printf("Invalid choice");
            }
        }
    }while(choice!=5);
}


