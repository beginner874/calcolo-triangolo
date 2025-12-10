#include <stdio.h>

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
    float perimetro;
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
        perimetro=L[0]+L[1]+L[2];
        printf("%.3f\n",perimetro);
    }
    return 0;
}