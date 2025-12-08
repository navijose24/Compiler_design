#include<stdio.h>
#include<string.h>
int main(){
    int n,i;
    printf("no.of instruc:");
    scanf("%d",&n);
    char op[5],a1[5],a2[5],r[5];
    printf("intsruction in op a1 a2 r form:");
    for(i=0;i<n;i++){
        scanf("%s%s%s%s",op,a1,a2,r);
        printf("assembly code \n");
        printf("MOV RO,%s\n",a1);
        if(strcmp(op,"+")==0)
        printf("ADD RO,%s\n",a2);
        else if(strcmp(op,"-")==0)
        printf("SUB RO,%s\n",a2);
        else if(strcmp(op,"*")==0)
        printf("MUL RO,%s\n",a2);
        else if(strcmp(op,"/")==0)
        printf("DIV RO,%s\n",a2);
        printf("MOV %s,Ro",r);
    } return 0;
}