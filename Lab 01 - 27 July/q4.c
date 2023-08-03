#include<stdio.h>

void rotate(int *arr , int p){
    int temp=arr[p-1];
    for(int i=p-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}

int main(){
    int n;
    printf("Number of array elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    rotate(arr,5);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


}