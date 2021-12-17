#include<stdio.h>

float pow(float base,int index)
{
    if(index==0)return 1;
    else if(index==1 || base==0)return base;
    return base*pow(base,index-1);
}

void main()
{
    int index;
    float base;
    printf("Enter base (float):");
    scanf("%f",&base);
    printf("Enter power to raise to (int):");
    scanf("%d",&index);
    printf("%.2f",pow(base,index));
}
