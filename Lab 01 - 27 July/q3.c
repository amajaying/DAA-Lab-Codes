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
        check[arr[i]] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                check[arr[i]]=1;
            }
        }
    }

    int count = 0;
    for(int i=0; i<n; i++){
        if(check[arr[i]] == 1){
            // printf("%d ", arr[i]);
            check[arr[i]]=0;
            count++;
        }
    }
    printf("\nTotal number of duplicate values: %d\n", count);

    int repeat[n];
    for(int i=0; i<n; i++){
        repeat[arr[i]] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                repeat[arr[i]]++;
            }
        }
    }

    int max = repeat[arr[0]];
    int maxIndex = arr[0];
    for(int i=0; i<n; i++){
        if(repeat[arr[i]] > max){
            max = repeat[arr[i]];
            maxIndex = arr[i];
        }
    }
    printf("The most repeating element in the array is: %d\n", maxIndex);
}
