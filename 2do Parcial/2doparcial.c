#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 4     // Defino 4 sucursales
#define COLUMNAS 6  // Defino los 6 meses

// Definición de Sucursales
struct sucursales{
    int idS;                // ID Sucursal
    char c[30];             // Ciudad
    float vdm[30];          // Ventas del mes
    float tvdm;             // Total ventas del mes
    float imv;              // Importe Mayor Venta
};

// Definición de Gerentes
struct ceos{
    int idC;                // ID Ceo
    int idS;                // ID Sucursal
    char ap[30];            // Apellido
};

// Prototipos de funciones
void cargaSucursal(struct sucursales s[]);
void cargaCeo(struct ceos c[]);
void cargaVP(float vp[][COLUMNAS]);
void sumatoria(struct sucursales s[]);
void mayorVenta(struct sucursales s[], float vp[][COLUMNAS]);
int cantidad(struct sucursales s[], int ve[]);
void muestraCant(struct sucursales s[], struct ceos c[], int ve[], int cant);
void ordenamiento(struct sucursales s[]);
void muestra(struct sucursales s[], struct ceos c[], float vp[][COLUMNAS]);

// Inicio función principal
int main(){
    int cant;
    // Punto 1 - Definición y Carga de Sucursales
    struct sucursales sucursal[FILAS];
    cargaSucursal(sucursal);
    // Punto 2 - Definición y Carga de CEO'S
    struct ceos ceo[FILAS];
    cargaCeo(ceo);
    // Punto 3 - Definición de Array Auxiliar
    int vEnteros[FILAS]={-1, -1, -1, -1};
    // Punto 4 - Declaración y Carga de Array Bidimensional
    float ventasPasadas[FILAS][COLUMNAS];
    cargaVP(ventasPasadas);
    // Requerimiento 1 - Sumatoria del array *Ventas del mes*
    printf("\n\n*** Requerimiento 1 ***\n\n");
    sumatoria(sucursal);
    getchar();
    // Requerimiento 2 - Mayor venta pasada de cada sucursal
    printf("\n*** Requerimiento 2 ***\n\n");
    mayorVenta(sucursal, ventasPasadas);
    getchar();
    // Requerimiento 3 - Cantidad de Sucursales donde el *Total ventas del mes* no supere al *Importe Mayor Venta*
    cant = cantidad(sucursal, vEnteros);
    // Requerimiento 4 - Muestra de las sucursales del requerimiento anterior
    printf("\n*** Requerimiento 4 ***\n\n");
    muestraCant(sucursal, ceo, vEnteros, cant);
    getchar();
    // Requerimiento 5 - Ordenamiento de Sucursales en forma descendente
    ordenamiento(sucursal);
    // Muestra final de datos
    muestra(sucursal, ceo, ventasPasadas);
    return 0;
}
// Fin función principal

/* -------------------------  Declaración de Funciones  ------------------------- */
// Punto 1 - Carga de Sucursales
void cargaSucursal(struct sucursales s[]){
    int i, j;
    for(i=0; i<FILAS; i++){
        s[i].idS=i+1;
        printf("\nSucursal n%cmero %d: \n", 163, s[i].idS);
        printf("Ciudad: ");
        gets(s[i].c);
        fflush(stdin);
        printf("\nCantidad de ventas del mes: \n");
        for(j=0; j<30; j++){
            printf("D%ca %d: ", 161, j+1);
            scanf("%f", &s[i].vdm[j]);
            fflush(stdin);
        }
    }
}

// Punto 2 - Carga de CEO's
void cargaCeo(struct ceos c[]){
    int i;
    for(i=0; i<FILAS; i++){
        c[i].idC=i+1;
        c[i].idS=i+1;
        printf("\nCEO de la sucursal %d\n", c[i].idS);
        printf("Apellido: ");
        gets(c[i].ap);
        fflush(stdin);
    }
}

// Punto 4 - Carga de Array Bidimensional 
void cargaVP(float vp[][COLUMNAS]){
    int i,j;
    printf("\n*---------------------------------------------*\n\n");
    for(i=0; i<FILAS; i++){
        printf("\nSucursal n%cmero %d\n\n", 163, i+1);
        printf("Total de ventas pasadas. \n");
    for(j=0; j<COLUMNAS; j++){
        printf("Mes %d: ", j+1);
        scanf("%f", &vp[i][j]);
        fflush(stdin);
         }
     }
}

// Requerimiento 1 - Sumatoria del array *Ventas del mes*
void sumatoria(struct sucursales s[]){
    int i, j;
    float sum;
    for(i=0; i<FILAS; i++){
        printf("Sucursal n%cmero %d\n", 163, i+1);
        sum=0;
        for(j=0; j<30; j++){
            sum+=s[i].vdm[j];
        }
        s[i].tvdm=sum;
        printf("Suma total de descuentos: %.2f\n\n", s[i].tvdm);
    }
}

// Requerimiento 2 - Mayor venta pasada de cada sucursal
void mayorVenta(struct sucursales s[], float vp[][COLUMNAS]){
    int i, j, max;
    float prom;
    for(i=0; i<FILAS; i++){
        printf("Sucursal n%cmero %d\n", 163, i+1);
        max=-9999;
        for(j=0; j<COLUMNAS; j++){
            if(vp[i][j]>max){
                max=vp[i][j];
            }
        }
        s[i].imv=max;
        printf("Importe de mayor venta: %.2f\n\n", s[i].imv);
    }
}

// Requerimiento 3 - Cantidad de Sucursales donde el *Total ventas del mes* no supere al *Importe Mayor Venta*
int cantidad(struct sucursales s[], int ve[]){
    int i, j, c=0;
    for(i=0; i<FILAS; i++){
        if(s[i].tvdm < s[i].imv){
            ve[c]=i;
            c++;
        }
    }
    return c;
}

// Requerimiento 4 - Muestra de las sucursales del requerimiento anterior
void muestraCant(struct sucursales s[], struct ceos c[], int ve[], int cant){
    int i, j;
    printf("Sucursales donde el Total de ventas del mes no supera al Importe de mayor venta pasada:\n\n");
    for(i=0; i<cant; i++){
        for(j=0; j<FILAS; j++){
            if(s[ve[i]].idS == c[j].idS){
                printf("Ciudad: %s  -  Apellido del CEO: %s\n", s[ve[i]].c, c[ve[i]].ap);
            }
        }
    }
    printf("\n");
}

// Requerimiento 5 - Ordenamiento de Sucursales en forma descendente
void ordenamiento(struct sucursales s[]){
    int i, j, flag;
    struct sucursales aux;

    for(i=0; i<FILAS-1; i++){           
        for(j=0; j<FILAS-(i+1); j++){   
            if(strcmp(s[j].c, s[j+1].c) < 0){
                aux=s[j];
                s[j]=s[j+1];
                s[j+1]=aux;
            }
        }
    }
}

// Muestra final de datos
void muestra(struct sucursales s[], struct ceos c[], float vp[][COLUMNAS]){
    int i, j;
    printf("\n*--------------------------------------------------*\n\n");
    printf("Muestra final:\n\n");
    printf("Sucursales: \n\n");
    for(i=0; i<FILAS; i++){
        printf("Ciudad: %s\n", s[i].c);
        printf("Sucursal n%cmero %d\n", 163, s[i].idS);
        
        printf("\nVentas del mes: \n");
        for(j=0; j<30; j++){
            printf("D%ca %d: %.2f\n", 161, j+1 ,s[i].vdm[j]);
        }
        printf("\n");
        printf("Total de ventas del mes: %.2f\n", s[i].tvdm);
        printf("Importe de mayor venta pasada: %.2f\n\n", s[i].imv);
    }
    getchar();
    printf("\n*--------------------------------------------------*\n\n");
    printf("CEOS: \n\n");
    for(i=0; i<FILAS; i++){
        printf("ID CEO: %d\n", c[i].idC);
        printf("ID Sucursal: %d\n", c[i].idS);
        printf("Apellido: %s\n", c[i].ap);
        printf("\n");
    }
    getchar();
    printf("\n*--------------------------------------------------*\n\n");
    printf("Cantidad de ventas realizadas los 6 meses anteriores: \n");
    for(i=0; i<FILAS; i++){
        for(j=0; j<COLUMNAS; j++){
            printf("%.2f  -  ", vp[i][j]);
        }
        printf("\n");
    }
    printf("\n*--------------------------------------------------*\n\n");
}