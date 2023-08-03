#include <stdio.h>
#include <stdlib.h>

void decToBin(int n, FILE *ofp){
    if(n==0){
        fprintf(ofp, "\n");
        return ;
    }
    int x = n % 2;
    n = n/2;
    decToBin(n, ofp);
    fprintf(ofp, "%d", x);
}

int main(int args, char* argv[]){
    int n = atoi(argv[1]);
    int arr[n];
    char *inpfile = argv[2];
    char *outfile = argv[3];

    FILE *fp, *ofp;
    fp=fopen(inpfile,"r");
    ofp=fopen(outfile,"w");
    for(int i=0;i<n;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    for(int i=0; i<n; i++){
        fprintf(ofp,"\nThe binary equivalent of %d is ",arr[i]);
        decToBin(arr[i], ofp);
    }
    
    fclose(fp);
}