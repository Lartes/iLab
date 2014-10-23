#include "rpn.h"

void read(char *s){
    int i;
    for (i=0;i<=9;i++) s[i]=0;
    scanf("%*[ ]");
    scanf("%[0-9.]",s);
    if (s[0]==0) scanf("%c",s);
}

int what_is_input(char *s){
    if (s[0]=='+')  return PLUS;
    if (s[0]=='-')  return MINUS;
    if (s[0]=='*')  return MULT;
    if (s[0]=='/')  return DIV;
    if (s[0]=='\n')  return EXIT;
    int i;
    for (i=0;i<=strlen(s)-1;i++){
        if ((s[i]<'0' || s[i]>'9') && s[i]!='.') return INCORRECT_SYMBOL;
    }
    return NUMBER;
}
