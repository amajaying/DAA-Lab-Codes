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
    int visited[n];
    for(int i=0;i<n;i++){
        fscanf(myFile,"%d",&arr[i]);
        visited[i]=0;
    }
    

    int most_frequecy=0,count=0,duplicated;
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int frequency=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j] && visited[j]==0){
                visited[j]=1;
                frequency++;
                if(frequency==2){
                    count++;
                }
            }
        }
        if(frequency>most_frequecy){
            most_frequecy=frequency;
            duplicated=arr[i];
        }
    }

    printf("No of duplicates : %d\nMost Repeating :%d",count, duplicated);

    

}
