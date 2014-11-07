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

void close(FILE* input, FILE* output, char output_name[20]){
    if (input!=NULL)
        fclose(input);
    if (output!=NULL)
        fclose(output);
    remove(output_name);
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

int addres_label(struct label *mas_label, int size, char input_data_str[10]){
    int i;
    for (i=0;i<=size-1;i++){
        if (strcmp((mas_label[i]).name, input_data_str)==0) return (mas_label[i]).addres;
    }
    return -1;
}

char* label_addres(struct label *mas_label, int size, int addres){
    int i;
    for (i=0;i<=size-1;i++){
        if ((mas_label[i]).addres==addres) return (mas_label[i]).name;
    }
    return "-1";
}

int jumpASM(FILE* input, FILE* output, struct label *mas_label, int size){
    double input_data_doub;
    char input_data_str[10];

    fscanf(input,"%*[ ]");
    if (fscanf(input,"%[:]",input_data_str)==1){  //if JMP with label     почему при считывании * fscanf выдаёт 0 вместо 1???
        if (fscanf(input,"%s",input_data_str)!=EOF){
            if ((input_data_doub=addres_label(mas_label,size,input_data_str))==-1)
                {printf("Incorrect command argument in JMP_label\n"); return 0;}
            fwrite(&input_data_doub,sizeof(double),1,output);
        }
    } else{                                    //if JMP without label
        if (fscanf(input,"%lf",&input_data_doub)>0)
            fwrite(&input_data_doub,sizeof(double),1,output);
        else
            {printf("Incorrect command argument in JMP\n"); return 0;}
    }
    return 1;
}

int jumpDISASM(FILE* input, FILE* output, struct label *mas_label, int size){
    double input_data_d;

    if (fread(&input_data_d,sizeof(double),1,input)>0)
        if (strcmp(label_addres(mas_label,size,(int)input_data_d),"-1"))
            fprintf(output,":%s\n",label_addres(mas_label,size,(int)input_data_d));
        else
            fprintf(output,"%lf\n",input_data_d);
    else
        {printf("Incorrect command argument\n"); return 0;}
    return 1;
}
