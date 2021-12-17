#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#define MAX 100
int top=-1;



void push(char *p , int value){
    if(top==MAX-1){printf("Overflow \n");}
    else{
        top++;
        p[top]=value;
    }
}

int pop(char *p){
    int x;
    if(top==-1){
      printf("Underflow \n");
      return -1;
    }
    x=p[top];
    top--;
    return x;
}

int assoc(char x){
if(x=='^') {return 0;}
return 1;
}


int peek(char *p){
    if(top==-1){
        printf("Stack Empty : \n");
        return -1;
    }
    return top;
}

int precedence(char ch){
    if(ch=='^'){
        return 4;
    }
    else if(ch == '*' || ch=='/'){
      return 3;
    }

    else if(ch == '+' || ch=='-'){
        return 2;
    }

    else{
      return 0;
    }

}


bool isOperator(char o){
if (o == '%' || o == '/' || o == '*' || o == '+' || o == '-' || o=='^' || o=='(' || o==')'){
return true;
}
else{
return false;
}
}

int calc(char o , int a , int b){
int result;
switch (o) {
    case '+':
      result=a+b;
      break;
    case '-':
      result=a-b;
      break;
    case '*':
      result=a*b;
      break;
    case '/':
      result=a/b;
      break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct");
  }
return result;
}

void evaluate(char *str){
top=-1;
char calSt[MAX];
printf("%s" , calSt);
int a,b,result,i=0,j=-1;
while(str[i]!='\0'){
    calSt[j++]=str[i];
    i++;

}
calSt[j++]=NULL;
printf("\nresult : %s" , calSt);
}


void main(){

    char inf[MAX] , converted[MAX];
    char st[MAX];
    int x;
    int i=0,j=0;
    printf("Enter infix expression : \n");
    gets(inf);
   while(inf[i]!='\0'){
    if(!isOperator(inf[i])){
         converted[j++]=inf[i];
            i++;
    }else{
        if(inf[i]=='(' || precedence(inf[i])>precedence(st[peek(st)]) || top==-1){
            push(st , inf[i]);
        }else if(inf[i]==')'){
            while(st[top]!='('){
            converted[j++]=pop(st);
        }
        x=pop(st);

        }else if(precedence(inf[i])<precedence(st[top])){
            converted[j++]=pop(st);
            if(peek(st)!=-1) continue;
            push(st , inf[i]);
        }else if(precedence(inf[i])==precedence(st[top])){

             if(assoc(inf[i])){
                converted[j++]=pop(st);
                push(st , inf[i]);
            }else{
                 push(st , inf[i]);
            }
        }
        else{
            push(st , inf[i]);
        }
       i++;
    }
    printf("Stack %s : " , st);
    printf(" Postfix : %s \n" , converted);

}
while(peek(st)!=-1){
    converted[j++]=pop(st);
}
converted[j++]=NULL;
printf("Postfix : %s" , converted);
evaluate(converted);
}


