#include <stdio.h>

int main(){

    int vector[4] = {4,3,2,1};

    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            if(vector[i]>vector[j]){
                int aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }

    printf("El array ordenado queda: ");

    for (int i=0; i<4; i++)
    {
        printf("%d ", vector[i]);
    }   

    return 0;
}