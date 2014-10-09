#include"function.h"

void weighing(){
    int number, ability=CAN;
    scanf("%d",&number);
    while (number!=0){
        if (number%4==2){
            ability=CANNOT;
            break;
        }else
            if (number%4==3) number=number/4+1;
            else number=number/4;
    }
    if (ability==CAN) printf("YES"); else printf("NO");
    return 0;
}

double fact(int x){
    int i;
    double y=1;
    for (i=1;i<=x;i++) y=y*i;
    return y;
}

void good_words(){
    int i,j,n;
    double a;
    scanf("%d", &n);
    printf("1\n");
    for (i=1;i<=n;i++){
        for (j=0;j<=n;j++){
            a=fact(i-j+1)/(fact(j)*fact(i-2*j+1));
            if ((int)a!=0) printf("%d ",(int)a); else {break;}
        }
        printf("\n");
    }

}

void four_square(){
    int x, j, i, ostalos;
    int razlogeniye[5];
    scanf("%d",&x);

    j=0;
    do{
        razlogeniye[1]=(floor(sqrt(x)+0.5)-j)*(floor(sqrt(x)+0.5)-j);
        ostalos=x-razlogeniye[1];
        for (i=2;i<=4;i++){
        razlogeniye[i]=pow(floor(sqrt(ostalos)+0.5),2);
        ostalos=ostalos-razlogeniye[i];
        }

        j++;
    }
    while (ostalos!=0);
    for (i=1;i<=4;i++) printf("%d ",razlogeniye[i]);
}
