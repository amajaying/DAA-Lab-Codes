#include <stdio.h>
#include <stdlib.h>

void gcd(FILE *ofp, FILE * fp){
    int a, b;
    fscanf(fp, "%d %d", &a, &b);
    if(b==0){
        fprintf(ofp, "%d\n", a);
        return ;
    }
    gcd(ofp, fp);
    fprintf(ofp, "%d\n", b);
}
int main(int args, char* argv[]){
    char *inpfile = argv[1];
    char *outfile = argv[2];
    FILE *fp, *ofp;
    fp=fopen(inpfile,"r");
    ofp=fopen(outfile,"w");

}