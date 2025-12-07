%{
    #include<stdio.h>
    int w=0,n=0,s=0,c=0;
%}
%%
[""]* {s++;}
[\n] {n++;}
[a-zA-Z0-9]+ {w++;c=c+yyleng;}
%%
yywrap(){return 1;}
int main(){
    yyin=fopen("abc.txt","r");
    yylex();
    printf("c=%d,w=%d,n=%d,s=%d",c,w,n,s);
    return 0;
}
