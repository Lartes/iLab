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
