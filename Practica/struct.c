#include <stdio.h>

struct vuelo{
    char origen[5], destino[5];
    int duracion;
    float precio;
};

void cargaVuelo(struct vuelo v[], int d){
    for(int i=0; i<d; i++){
        printf("VUELO %d\n", i+1);
        fflush(stdin);
        printf("Origen: ");
        gets(v[i].origen);
        fflush(stdin);

        printf("Destino: ");
        gets(v[i].destino);
        fflush(stdin);

        printf("Duracion: ");
        scanf("%d", &v[i].duracion);
        fflush(stdin);

        printf("Precio: ");
        scanf("%f", &v[i].precio);
        fflush(stdin);
    }
}

void mostrarVuelo(struct vuelo v[], int d){
    printf("Los vuelos son: \n");
    for(int i=0; i<d; i++){
        printf("\nVUELO %d\n", i+1);
        printf("Origen: %s\n", v[i].origen);
        printf("Destino: %s\n", v[i].destino);
        printf("Duracion: %d\n", v[i].duracion);
        printf("Precio: %.2f\n", v[i].precio);
    }
}

int main(){
    int dim;

    printf("Cantidad de vuelos: ");
    scanf("%d", &dim);

    struct vuelo vuelos[dim];

    cargaVuelo(vuelos, dim);
    mostrarVuelo(vuelos, dim);

    return 0;
}