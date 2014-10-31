#include"functions_asm.h"

int isNumF(char *s){
    int i;
    for (i=0;i<=strlen(s)-1;i++)
        if ((s[i]>='0' && s[i]<='9') || s[i]=='.') return 1;
    return 0;
}

int isNum(char *s){
    int i;
    for (i=0;i<=strlen(s)-1;i++)
        if (s[i]>='0' && s[i]<='9') return 1;
    return 0;
}

void close(FILE* input, FILE* output){
    fclose(input);
    fclose(output);
    remove("output.txt");
    exit(0);
}

void closeD(FILE* input, FILE* output){
    fclose(input);
    fclose(output);
    remove("input.txt");
    exit(0);
}

int stricmp(const char *s1, const char *s2){
    int i, min;
    char a,b;
    if (strlen(s1)>=strlen(s2)) min=strlen(s2); else min=strlen(s1);
    for (i=0;i<=min-1;i++) {a=s1[i]; b=s2[i];
                        if (a>='A' && a<='Z') a=(char)tolower(a);
                        if (b>='A' && b<='Z') b=(char)tolower(b);
                        if (a>b) return 1;
                        else if (a<b) return -1;
    }
    if (strlen(s1)>strlen(s2)) return 1;
    if (strlen(s1)<strlen(s2)) return -1;
    return 0;
}
