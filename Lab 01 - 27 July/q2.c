#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int prefixSum[n];
    for(int i=0; i<n; i++){
        prefixSum[i] = 0;
        for(int j=0; j<=i; j++){
            prefixSum[i] += arr[j];
        }
    }
    
    printf("The prefix sum array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", prefixSum[i]);
    }

}