#include <stdio.h>

int main(){
    int array[3] = {};
    int suma = 0;

    for(int i=0; i<3; i++){
        printf("Ingresar el valor %d del array: ", i+1);
        scanf("%d", &array[i]);

        suma += array[i];
    }

    printf("El array es: \n");

    for(int i=0; i<3; i++){
        if(i != 2){
            printf("%d, ", array[i]);
        } else{
            printf("%d", array[i]);
        }
    }

    printf("\nLa sumatoria da: %d", suma);

    return 0;
}


