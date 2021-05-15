#include <stdio.h>

int main(){
    int edades[] = {18, 23, 27};

    printf("El primer valor es: %d.\n", *(edades));
    printf("El segundo valor es: %d.\n", *(edades + 1));

    printf("La posicion de memoria del primer valor es: %x.\n", &edades);
    printf("La posicion de memoria del primer valor es: %p.\n", &edades[0]);
    printf("La posicion de memoria del segundo valor es: %p.\n", &edades[1]);
    printf("La posicion de memoria del tercer valor es: %p.\n", &edades[2]);
    
    return 0;
}