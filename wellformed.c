#include <stdio.h>
#define MAX 100
int top=-1;

void push(char *p , char value){
    if(top==MAX-1){printf("Overflow \n");}
    else{
        top++;
        p[top]=value;
    }
}

void pop(char *p){
    char x;
    if(top==-1){
      return -1;
    }
    top--;
}

void checkFormedness(char *exp , char *st){
int i=0;
int isWellFormed = 0;
int exitedEarly=0;
while(exp[i]!='\0'){
   if(exp[i]=='('){
    push(st , '(');
   }else if(exp[i]==')'){
    if(top==-1){
        exitedEarly=1;
        break;
    }else{
         pop(st);
    }

   }
   i++;
 }
if(top!=-1 || exitedEarly){
    printf("Not Well Formed");
}else{
    printf("Well Formed");
}
}

void main(){
char st[MAX] , exp[MAX];
printf("Enter expression : \n");
gets(exp);
checkFormedness(exp , st);

}
