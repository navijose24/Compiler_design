#include<stdio.h>
#include<string.h>
int main(){
    char exp[30],op1,op2,temp ='t';
    int i,j;
    printf("exp:");
    scanf("%s",exp);
    printf("\nIntermediate Code\tExpression\n");
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='*' || exp[i]=='/')
        {
            op1=exp[i-1];
            op2=exp[i+1];
            printf("%c=%c%c%c\t\t",temp,op1,exp[i],op2);
            exp[i-1]=temp;
            exp[i]='$';
            exp[i+1]='$';
            for(j=0;exp[j]!='\0';j++)
            if(exp[j]!='$')
            printf("%c",exp[j]);
            printf("\n");temp++;
        }
    }
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='-' || exp[i]=='+')
        {
            op1=exp[i-1];
            op2=exp[i+1];
            printf("%c=%c%c%c\t\t",temp,op1,exp[i],op2);
            exp[i-1]=temp;
            exp[i]='$';
            exp[i+1]='$';
            for(j=0;exp[j]!='\0';j++)
            if(exp[j]!='$')
            printf("%c",exp[j]);
            printf("\n");temp++;
        }
    }
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='=')
        printf("%c=%c\n",exp[0],exp[i+1]);
    }
    return 0;
}