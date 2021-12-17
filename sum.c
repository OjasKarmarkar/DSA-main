#include <stdio.h>

int findSum(int num){
    if(num == 0) return 0;
    int rem=num%10;
    return (rem + findSum(num/10));
}

int main(){
    int num;
    printf("Enter a number \n");
    scanf("%d", &num);
    printf("Sum of digits is %d" , findSum(num));
    return 0;
}

