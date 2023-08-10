#include <stdio.h>
#include <stdlib.h>

void gcd(int a, int b, FILE *ofp){
    if(a>b)
        a=a-b;
    else
        b=b-a;
    
    if(a==0){
        fprintf(ofp, "%d\n", b);
        return;
    }
    else if(b==0){
        fprintf(ofp, "%d\n", a);
        return;
    }
    else
        gcd(a, b, ofp);
}

int main(int args, char* argv[]){
    char *inpfile = argv[1];
    char *outfile = argv[2];
    FILE *fp, *ofp;
    fp=fopen(inpfile,"r");
    ofp=fopen(outfile,"w");
    while(!feof(fp)){
        int a, b;
        fscanf(fp, "%d %d", &a, &b);
        fprintf(ofp, "The GCD of %d & %d is: ", a,b);
        gcd(a, b, ofp);
    }
}