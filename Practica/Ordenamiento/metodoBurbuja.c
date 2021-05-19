#include <stdio.h>

int main(){
    int vector[10] = {10,8,3,4,5,6,7,1,9,2};
    int aux;    

    for(int i=0; i<10; i++){

        for (int j=0; j<10; j++){

            if(vector[j] > vector[j+1]){
                //Intercambiamos los dos elementos
                aux = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
            }
        }
    }  

    for(int i=0; i<10; i++){
        printf("%d\n", vector[i]);
    }   
        
    return 0;
}