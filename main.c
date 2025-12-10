#include <stdio.h>

int main () {
    float L [] = {0,0,0};
    float perimetro;
    printf("inserisci i dati del triangolo\n");
    printf("segmento AB\n");
    scanf("%f",&L[0]);
    printf("segmento BC\n");
    scanf("%f",&L[1]);
    printf("segmento CA\n");
    scanf("%f",&L[2]);
    perimetro=L[0]+L[1]+L[2];
    printf("%.3f\n",perimetro);
    return 0;
}