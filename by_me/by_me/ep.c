#include<stdio.h>
#include<string.h>
int closure[20],epsilon[10][10],ns,nt,from,to;
char sym[10];

void findclo(int state){
    int i;
    if(closure[state]) return;
    closure[state]=1;
    for(i=0;i<ns;i++)
    if(epsilon[state][i] && !closure[i])
    findclo(i);
}

int main()
{
    int i,j;
    printf("no.of states & trans");
    scanf("%d %d",&ns,&nt);
    for(i=0;i<ns;i++)
    for(j=0;j<ns;j++)
    epsilon[i][j]=0;
    printf("transitions from sym to");
    for(i=0;i<nt;i++){
        scanf("%d %s %d",&from,sym,&to);  
        if(strcmp(sym,"e")==0)
        epsilon[from][to]=1;  
    }
    for(i=0;i<ns;i++){
        for(j=0;j<ns;j++) closure[j]=0;
        findclo(i);
        printf("e-closure (q%d)-> {",i);
        for(j=0;j<ns;j++)
        if(closure[j]) printf("q%d",j);
        printf("}\n");
    }
    return 0;
}
