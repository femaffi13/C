#include <stdio.h>

int funcion1(char *cMax, float *iMax, float *tFact);
void funcion2(char clase, float imp, int *cCliG, int *cCliP, int *cCliE, float *aImpG, float *aImpP, float *aImpE);

int main(){
    int tCli; //Total de Clientes
    float tFact, iMax; //Total de Facturación, Importe Máximo de facturación
    char cMax; //Categoría con Máxima facturación

    tCli = funcion1(&cMax, &iMax, &tFact);

    printf("Total general de clientes: %d.\n", tCli);
    printf("La categor%ca %c fue la que m%cs factur%c con $%.2f\n", 161, cMax, 160, 162, iMax);
    printf("Total general de facturaci%cn: $%.2f\n", 162, tFact);

    return 0;
}

int funcion1(char *cMax, float *iMax, float *tFact){
    int numCli; //Número de Cliente
    char clase;
    float imp, TFact; //Importe, Total de Facturación
    int cCli = 0; //Cantidad de Clientes
    float iMAX = 0; //Importe Máximo

    float aIG; //Acumulado de Importe de G
    float aIP; //Acumilado de Importe de P
    float aIE; //Acumulado de Importe de E

    for(int i = 0; i<8; i++){
        int cCliG = 0; //Cantidad de clientes de G
        int cCliP = 0; //Cantidad de clientes de P
        int cCliE = 0; //Cantidad de clientes de E

        float aImpG = 0; //Acumulado de importe de G
        float aImpP = 0; //Acumulado de importe de P
        float aImpE = 0; //Acumulado de importe de E

        printf("\nPunto de venta n%cmero %d.\n", 163, i+1);
        printf("(Ingresar 0 en \"N%cmero de Cliente\" si no hay m%cs clientes por ingresar)\n\n", 163, 160);

        do{
            printf("N%cmero de Cliente: ", 163);
            scanf("%d", &numCli);
            fflush(stdin);

            if(numCli > 0){       
                printf("Clase: ");
                scanf("%c", &clase);
                fflush(stdin);

                printf("Importe: ");
                scanf("%f", &imp);
                fflush(stdin);

                funcion2(clase, imp, &cCliG, &cCliP, &cCliE, &aImpG, &aImpP, &aImpE);

                cCli++;  //Sumatoria de número de clientes para mostrar en main()
            }

        } while(numCli > 0);
        
        //Resumen Parcial del Punto de venta
        printf("\nPunto de venta %d - Facturaci%cn:\n", i+1, 162);
        if(aImpG > 0){
            printf("G: $%.2f, %d clientes\n", aImpG, cCliG);
        }else{
            printf("G: $0, 0 clientes\n");
        }

        if(aImpP > 0){
            printf("P: $%.2f, %d clientes\n", aImpP, cCliP);
        } else{
             printf("P: $0, 0 clientes\n");
        }

        if(aImpE > 0){
            printf("E: $%.2f, %d clientes\n", aImpE, cCliE);
        } else{
            printf("E: $0, 0 clientes\n");
        }

        //Acumuladores para mostrar en main() el máximo facturado con la categría correspondiente
        aIG = aIG + aImpG;
        aIP = aIP + aImpP;
        aIE = aIE + aImpE;

        if(aIG > iMAX && aIG > aIP && aIG > aIE){
            *iMax = aIG;
            *cMax = 'G';
        }

        if(aIP > iMAX && aIP > aIG && aIP > aIE){
            *iMax = aIP;
            *cMax = 'P';
        }

        if(aIE > iMAX && aIE > aIG && aIE > aIP){
            *iMax = aIE;
            *cMax = 'E';
        }

        //Cálculo para mostrar en main() la facturación total
        TFact = aImpG + aImpP + aImpE;
        *tFact = *tFact + TFact;
    }

    return cCli;    //Retorno de la sumatoria de clientes totales
}

void funcion2(char clase, float imp, int *cCliG, int *cCliP, int *cCliE, float *aImpG, float *aImpP, float *aImpE){
    switch (clase){
        case 'g':
        case 'G':
            *aImpG = *aImpG + imp;
            (*cCliG)++; 
            break;

        case 'p':
        case 'P':
            *aImpP = *aImpP + imp;
            (*cCliP)++;
            break;
        
        case 'e':
        case 'E':
            *aImpE = *aImpE + imp;
            (*cCliE)++;
            break;
    }
}