#include <stdio.h>
#include <math.h>
int control (float L[]) {
    if ((L[0]+L[1]>L[2])&&(L[0]+L[2]>L[1])&&(L[1]+L[2]>L[0])) {
        return 1;
    }
    else {
        return 0;
    }
}
int main () {
    float L [] = {0,0,0};
    float A [] = {0,0,0};
    float perimetro;
    float area;
    for (int i=1;i<4;i++) {
        printf("inserisci i dati del triangolo\n");
        printf("segmento AB\n");
        scanf("%f",&L[0]);
        printf("segmento BC\n");
        scanf("%f",&L[1]);
        printf("segmento CA\n");
        scanf("%f",&L[2]);
        if (1-control(L)) {
            printf("i dati inseriti non possono formare un triangolo, riprova. hai ancora %d° tentativi\n",3-i);
            if (i>=3) {
                printf("non sai la regola di un triangolo sei una capra\n");
            }
        }
        else {
            i+=3;
        }
    }
    if (control(L)) {
        A[0]=acos( ( pow(L[1],2) + pow(L[2],2) - pow(L[0],2) ) / (2*L[1]*L[2]) );
        A[1]=acos( ( pow(L[0],2) + pow(L[2],2) - pow(L[1],2) ) / (2*L[0]*L[2]) );
        A[2]=acos( ( pow(L[0],2) + pow(L[1],2) - pow(L[2],2) ) / (2*L[0]*L[1]) );
        A[0]=A[0]*180/3.1415926;
        A[1]=A[1]*180/3.1415926;
        A[2]=A[2]*180/3.1415926;
        perimetro=L[0]+L[1]+L[2];
        area=(L[0]*L[1]*A[0])/2;
        if (A[0]==90||A[1]==90||A[2]==90) {
            printf("e un triangolo rettangolo\n");
            
        }
        else if (A[0]==A[1]||A[0]==A[2]||A[1]==A[2]&&(A[0]!=45||A[1]!=45)) {
            printf("è un triangolo isoscele\n");
        }
        else if (A[0]==A[1]&&A[0]==A[2]&&A[1]==A[2]) {
            printf("è un triangolo equilatero\n");
        }
        else {
            printf("è un triangolo scaleno\n");
        }
        printf("angolo alfa è: %.3f\n",A[0]);
        printf("angolo beta è: %.3f\n",A[1]);
        printf("angolo gamma è: %.3f\n",A[2]);
        printf("il perimetro del triangolo è: %.3f\n",perimetro);
        printf("l'area del triangolo è: %.3f\n",area);

    }
    return 0;
}