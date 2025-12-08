#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int n,i,k,j,remove[20]={0},iscnt;
    printf("no. of ex:");
    scanf("%d",&n);
    char op[20][5],arg1[20][10],arg2[20][10],res[20][10];
    printf("enter the 3 address ex:\n");
    for(i=0;i<n;i++){
        scanf("%s %s %s %s",op[i],arg1[i],arg2[i],res[i]);
    }
    for(i=0;i<n;i++){
        iscnt=1;
        for(k=0;arg1[i][k];k++)
        if(!isdigit(arg1[i][k])) iscnt=0;
        if(strcmp(op[i],"=")==0 && iscnt){
            for(j=i+1;j<n;j++){
                if(strcmp(arg1[j],res[i])==0)
                strcpy(arg1[j],arg1[i]);
                if(strcmp(arg2[j],res[i])==0)
                strcpy(arg2[j],arg1[i]);
            }remove[i]=1;
        }

    }
    printf("\noptimized code:\n");
    for(i=0;i<n;i++)
    if(!remove[i])
    printf("%s %s %s %s\n",op[i],arg1[i],arg2[i],res[i]);
    return 0;
    
}