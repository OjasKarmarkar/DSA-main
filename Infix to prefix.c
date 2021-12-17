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
      return -1;
    }
    x=p[top];
    top--;
    return x;
}


int peek(char *p){
    if(top==-1){
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

int performEval(int a , int b , char op){
    switch (op) {
    case '+':
      return a+b;
      break;
    case '-':
      return a-b;
      break;
    case '*':
      return a*b;
      break;
    case '/':
      return a/b;
      break;
    // operator doesn't match any case constant
    default:
      return pow(b,a);
  }
}

int eval(char* prefix){
 int a,b,tos=-1;
 int temp[MAX];
 int l = strlen(prefix);
 for(l;l>=0;l--){
    if(isOperator(prefix[l])){
        a=temp[tos];
        b=temp[tos-1];
        tos=tos-1;
        temp[tos]=performEval(b,a,prefix[l]);
    }else{
        tos++;
        temp[tos]=prefix[l]-'0';
    }
 }
    return temp[tos];
}

void revstr(char *str1)
{
    // declare variable
    int i, len, temp;
    len = strlen(str1); // use strlen() to get the length of str string

    // use for loop to iterate the string
    for (i = 0; i < len/2; i++)
    {
        // temp variable use to temporary hold the string
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
    for(i=0;i<len;i++){
        if((str1[i])=='('){
            str1[i]=')';
        }else if(str1[i]==')'){
            str1[i]='(';
        }
    }
}


void main(){

    char inf[MAX] , converted[MAX];
    char st[MAX];
    int x;
    int i=0,j=0,k;
    printf("Enter infix expression : \n");
    gets(inf);
    revstr(inf);
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


                converted[j++]=pop(st);
                push(st , inf[i]);

        }
        else{
            push(st , inf[i]);
        }
       i++;
    }

}
while(peek(st)!=-1){
    converted[j++]=pop(st);
}
converted[j++]=NULL;
revstr(converted);
printf("Prefix : %s\n" , converted);
int y=eval(converted);
printf("Evaluation is %d" , y);
}


