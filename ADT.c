#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 40

void insert(int *arr , int pos , int ele , int len){
    for(int i=len; i>=pos; i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=ele;

}

void del(int *arr , int pos,  int len){
    for(int i=pos; i<len; i++){
        arr[i]=arr[i+1];
}
}

void peek(int *arr , int pos , int len){
}

void display(int *arr , int len){
    printf("array is : ");
    for(int i=0; i<len;i++){
        printf("%d " , arr[i]);
    }
}


void main(){

    int *p , ele , pos , n=0 , choice;
    p = (int *)malloc(MAX*sizeof(int));
    do{
      printf("\nSelect Choice \n 1.Insert\n 2.Delete \n 3.Get element at\n 4.Display \n 5.Exit \n Make your choice.");
      scanf("%d" , &choice);
      switch(choice){
        case 1:
            printf("Enter position and value:\n");
            scanf("%d %d" , &pos , &ele);
            insert(p , pos , ele, n);
            n++;
            display(p , n);
            break;
        case 2:
            printf("Enter position:\n");
            scanf("%d" , &pos);
            del(p,pos ,n);
            n--;
            break;
        case 3:
            printf("Enter position:\n");
            scanf("%d" , &pos);
            peek(p,pos ,n);
            break;
        case 4:
            display(p , n);
            break;
        case 5:
            break;
      }
    }while(choice!='\n');


}
