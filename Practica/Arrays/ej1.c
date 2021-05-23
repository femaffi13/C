/* 1. Escribe un programa con un menú que defina las siguientes funciones y emita los resultados:  
a. Cargar un vector de m elementos por teclado. Debes considerar que no podrá superar el máximo de elementos de vector (m=dimensión).  
b. Calcular y emitir la suma de sus elementos.  
c. Calcular y emitir el mínimo del vector.  
d. Calcular y emitir el promedio de los valores del vector.  
e. Emitir los valores de aquellos que superaron ese promedio.  
f. Emitir los valores del vector que son múltiplos del último número ingresado en el mismo.  
g. Emitir el valor máximo e indicar la cantidad de veces que apareció y el número de orden en que fue ingresado.  
h. Emitir los valores que son pares.  
i. Emitir los valores que están en posiciones impares.  
j. Emitir aquellos que estén ubicados en posición par.  
k. Recorrer los elementos del vector hasta encontrar el número entero a. Deberá retornar el número de elementos que ha leído hasta encontrar a.  
l. Dado un elemento y dado un vector de enteros, realice una función que devuelva el número de apariciones del elemento en el vector. Utiliza el ciclo while para esta función.  
m. Invertir los elementos del vector sin utilizar otro vector. Por ejemplo, el vector formado por los enteros: 1 2 3, debe quedar 3 2 1.  */

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