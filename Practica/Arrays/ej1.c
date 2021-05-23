#include <stdio.h>

void CargaVector(int vec[], int m);
void SumaVector(int vec[], int m, int *sumatoria);

int main(){
    int m;
    int sumatoria = 0;

    printf("Cantidad de elementos del vector: ");
    scanf("%d", &m);
    fflush(stdin);

    int vector[m];

    CargaVector(vector, m);
    SumaVector(vector, m, &sumatoria);   

    return 0;
}

void CargaVector(int vec[], int m){
    for(int i=0; i<m; i++){
        printf("Valor de la posicion %d: ", i);
        scanf("%d", &vec[i]);
    }
    printf("El vector quedo formado como: ");
    for(int i=0; i<m; i++){
        printf("%d ", vec[i]);
    }
}

void SumaVector(int vec[], int m, int *sumatoria){
    for(int i=0; i<m; i++){
        *sumatoria += vec[i];
    }
    printf("\nLa sumatoria es: %d\n", *sumatoria);
}