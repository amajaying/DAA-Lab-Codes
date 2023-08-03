#include <stdio.h>
#include <stdlib.h>

int main(int args, char* argv[]){
    int n = atoi(argv[1]);
    int arr[n];
    char *inpfile = argv[2];
    char *outfile = argv[3];

    FILE *fp;
    fp=fopen("inDec.dat","r");
    for(int i=0;i<n;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    
    fclose(fp);
}