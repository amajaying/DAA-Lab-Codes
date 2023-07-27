#include <stdio.h>

int main(){
    int n;

    FILE *in_file;
    in_file = fopen("q1input.txt", "r");
    fscanf(in_file, "%d, ", &n);
    int arr[n];

    for(int i=0; i<n; i++){
        fscanf(in_file, "%d, ", &arr[i]);
    }

    int minm = arr[0], maxm = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] < minm){
            minm = arr[i];
        }
        if(arr[i] > maxm){
            maxm = arr[i];
        }
    }
    int minm2 = maxm, maxm2 = minm;
    for(int i=0; i<n; i++){
        if(arr[i] < minm2 && arr[i] != minm){
            minm2 = arr[i];
        }
        if(arr[i] > maxm2 && arr[i] != maxm){
            maxm2 = arr[i];
        }
    }

    printf("The second largest number is: %d\nThe second smallest number is: %d", maxm2, minm2);
    fclose(in_file);
}