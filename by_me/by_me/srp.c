#include<stdio.h>
#include<string.h>
char stack[50],input[50];
int top=-1,i=0;

int reduce(){
    if(top >=1 && stack[top]=='d' && stack[top-1]=='i'){
        stack[top-1]='E';
        top--;
        stack[top+1]='\0';
        printf("\treduce:E->id");
        return 1;
    }
    if(top >=2 && stack[top]==')' && stack[top-1]=='E' && stack[top-2]=='('){
        stack[top-2]='E';
        top-=2;
        stack[top+1]='\0';
        printf("\treduce:E->(E)");
        return 1;
    }
    if(top >=2 && stack[top]=='E' && stack[top-1]=='+' && stack[top-2]=='E'){
        stack[top-2]='E';
        top-=2;
        stack[top+1]='\0';
        printf("\treduce:E->E+E");
        return 1;
    }
    if(top >=2 && stack[top]=='E' && stack[top-1]=='*' && stack[top-2]=='E'){
        stack[top-2]='E';
        top-=2;
        stack[top+1]='\0';
        printf("\treduce:E->E*E");
        return 1;
    }
    return 0;
}

int main(){
    printf("input string:");
    scanf("%s",input);
    printf("stack\t\tinput\t\taction");
    while(i<strlen(input)){
        stack[++top]=input[i++];
        stack[top+1]='\0';
        printf("\n%-20s%-20sShift",stack,input+i);
        while(reduce());
    }
    while(reduce());
    if(strcmp(stack,"E")==0)
    printf("\naccept\n");
    else printf("\nreject\n");
}