#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#define MAX 100

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2;
    else
        return 0;
}

bool isOperator(char o){
if (o == '%' || o == '/' || o == '*' || o == '+' || o == '-'){
return true;
}
else{
return false;
}
}

void push(int *arr , int ele , int n){
    arr[n]=ele;
}

void pop(int *arr , int len, int pos){
    for(int i=pos; i<len; i++){
        arr[i]=arr[i+1];
}
}

void peek(int *arr , int pos , int len){
}

void display(char *arr , int len){
    printf("array is : ");
    for(int i=0; i<len;i++){
        printf("%c " , arr[i]);
    }
}

char* infToPost(char *inf){
    int i=0 , j=0 , top=0;
    char *post = (char *)malloc(strlen(inf+1)*sizeof(char));
    char *st = (char *)malloc(strlen(inf+1)*sizeof(char));
    while(inf[i]!='\0'){
        if(isOperator(inf[i])){
            if(precedence(inf[i]>=st[top])){
                push(st , inf[i] , strlen(st));
                i++;
                top++;
            }else{

                while(precedence(inf[i]<st[top])){
                    pop(st , strlen(st) , st[top]);
                    push(post , st[top] , strlen(post));
                    top--;
                }
               i++;
            }

        }else{
            push(post , inf[i] , strlen(post));
            i++;
            j++;
        }
    }
    while(top!=-1){
        push(post , st[i] , strlen(post));
        top--;
    }

return post;
}


void main(){

    char *infix;
    int TOP=-1;
    infix = (char *)malloc(MAX*sizeof(char));
    printf("Enter infix expression : \n");
    fgets(infix, strlen(infix) , stdin);
    char *postfix = infToPost(infix);
    printf("Postfix is : %s"  , postfix);

}
