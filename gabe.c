#include <stdio.h>
int l[2]={-1,1};
a(char *B){int m[30000];int p=0;
for(int c=0;B[c]!='\0';c++){m[p]+=l[B[c]%2];p+=B[c]%2;}for(int g;g<p;g++){putchar(m[g]);}}
b(char *B){int m[30000];int p=0;FILE *o=fopen("output.s","w");
fprintf(o,"main:\n\tpush rbp\n\tmov rbp, rsp\n");for(int i=0;B[i]!='\0';i++){m[p]+=l[B[i]%2];p+=B[i]%2;}for(int g;g<p;g++){fprintf(o,"\tmov edi, %i\n\tcall putchar\n", (int)m[g]);}fprintf(o,"\tmov eax, 0\n\tleave\n\tret");fclose(o);}
main(int argc, char**argv){if(argc){FILE*y;y=fopen(argv[1],"r");
if(y){char B[30000];fgets(B, 30000, y);b(B);} 
else{a(argv[1]);}return 0;fclose(y);}return 1;}
