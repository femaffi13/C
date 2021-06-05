#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *p, i=0;
    printf("Cantidad de elementos en el vector: ");
    scanf("%d", &n);

    int vector[n];
    p = &vector[0];

    //Asigno valores aleatorios al vector
    while(i<n){
        *(p+i) = rand() %11;
        i++;
    }

    //Vector en orden normal
    printf("\nVector en orden normal: \n");
    for(int j=0; j<n; j++){
        printf("Vector [%d]: %d\n", j, *(p+j));
    } 

    //Vector en orden inverso
    printf("\nVector en orden inverso: \n");
    i=0;
    for(int j=(n-1); j>=0; j--){
        printf("Vector [%d]: %d\n", i, *(p+j));
        i++;
    }

    return 0;
}
