#include<stdio.h>

int binarySearch(int * arr , int l , int h , int x){

    int mid = (l+h)/2;
    if (arr[mid] == x){
       return mid;
    }else if(arr[mid]<x){
        return binarySearch(arr , mid+1 , h , x);
    }else{
         return binarySearch(arr , l , mid-1 , x);
    }

    return -1;
}

int bin_search(int *a, int x, int l, int u)
{
     int mid = (l+u)/2;
    if(l<=u)
    {

        if(a[mid] == x){
          return mid;
        }
        else if(x < a[mid]){
            return (bin_search(a, x, l, mid-1));
        }else{
             return bin_search(a, x, mid+1, u);
        }

    }
    else return -1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void main(){
    int arr[10];
    int i, j , x , result;
    int n=10;
    printf("Enter 10 integers : ");
    for(int i = 0; i < n; ++i) {
     scanf("%d", &arr[i]);
  }

   for (i = 0; i < n-1; i++) {
     for (j = 0; j < n-i-1; j++) {
        if (arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);
        }

       }
   }
   printf("Sorted array is : ");
   for (i=0;i <n; i++){
    printf("% d " , arr[i]);
   }

    printf("\nEnter value to be searched : ");
    scanf("%d" , &x);

    result = bin_search(arr , x , 0 , n-1);

    if(result==-1){
        printf("item not found");
    }else{
        printf("Value %d found at position : %d" , x ,result+1);
    }

}
