// Write a program to read ‘n’ integers from a disc file that must contain
// some duplicate values and store them into an array. Perform the following operations on the
// array.

// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.

#include <stdio.h>

int main(){
    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    FILE *myFile;
    myFile = fopen("q3input.txt", "r");
    int arr[n];

    for(int i=0; i<n; i++){
        fscanf(myFile, "%d, ", &arr[i]);
    }
    printf("The content of the array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    int check[n];
    for(int i=0; i<n; i++){
        check[arr[i]] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                check[arr[i]]+=1;
            }
        }
    }

    printf("The duplicate values are: ");
    for(int i=0; i<n; i++){
        printf("%d ", check[arr[i]]);
    }

    int count = 0;
    for(int i=0; i<n; i++){
        if(check[arr[i]] > 1){
            // printf("%d ", arr[i]);
            check[arr[i]]-=1;
            count++;
        }
    }
    printf("\nTotal number of duplicate values: %d\n", count);

    
}