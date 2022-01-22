#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void main(){
    int arr[10];
    int i, j , x ;
    int n=10;
    printf("Enter 10 integers : ");
    for(int i = 0; i < n; ++i) {
     scanf("%d", &arr[i]);
  }

   for (i = 0; i < n-1; i++) {
     x=i;
     for (j = i+1; j < n; j++) {
        if (arr[x] > arr[j]){
            x=j;
        }
       }
     swap(&arr[x],&arr[i]);
   }

   printf("Sorted array is : ");
   for (i=0;i <n; i++){
    printf("% d " , arr[i]);
   }

}
