#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de Clientes
struct clientes{
  int id;
  char apellido[30];
  char nombre[30];
  char categoria;
  float facturacion;
  int activo;
};

// Función Menú principal
void menu(){
  printf("\n\t========= MEN%c =========\n", 233);
  printf("\n1. Crear el archivo clientes.dat");
  printf("\n2. Cargar datos de un cliente");
  printf("\n3. Listar los datos por pantalla");
  printf("\n4. Buscar datos de un cliente");
  printf("\n5. Modificar categor%ca y facturaci%cn de un cliente", 161, 162);
  printf("\n6. Actualizar facturaciones");
  printf("\n7. Dar de baja l%cgica a un cliente", 162);
  printf("\n8. Dar la baja f%csica de los clientes inactivos", 161);
  printf("\n9. Salir del programa");
  printf("\nIngrese una opcion [ ]\b\b");
}

// Prototipos de funciones
void crearArch(FILE *pA,char *nom);
void altaDeDatos(FILE *pA,char *nom);
void mostrarDatos(FILE *pA, char *nom);
void buscarcliente(FILE *pA, char *nom);
void modificarcliente(FILE *pA,char *nom);
void actualizarfacturacions(FILE *pA,char *nom);
void bajaLogica(FILE *pA,char *nom);
void bajaFisica(FILE *pA,char *nom);
// Funciones adicionales
int busqueda(FILE* pA,int leg);
void cabeceras();;

// Inicio función principal
int main(void) {
  char nom[30];
  int opc = 0;
  FILE* pArch;
  strcpy(nom,"clientes.dat");
  do{
    system("cls");
    menu();
    scanf("%d",&opc);
    switch(opc){
      case 1: crearArch(pArch,nom); break;
      case 2: altaDeDatos(pArch,nom);  break;
      case 3: mostrarDatos(pArch,nom); break;
      case 4: buscarcliente(pArch,nom); break;
      case 5: modificarcliente(pArch,nom); break;
      case 6: actualizarfacturacions(pArch,nom); break;
      case 7: bajaLogica(pArch,nom); break;
      case 8: bajaFisica(pArch,nom); break;
      case 9: break;
      default: printf("\nN%cmero mal ingresado", 163); break;
    }
  }while(opc != 9);

  return 0;
}
// Fin función principal

// Punto a - Crear el archivo
void crearArch(FILE *pA,char *nom){
  pA=fopen(nom,"wb");
  struct clientes cli={0, "-", "-", '-', 0, 0};

  if(pA!=NULL){
    printf("\nArchivo creado correctamente");
    fseek(pA, 0, SEEK_SET);
    for(int i=0; i<10; i++){
      fwrite(&cli,sizeof(struct clientes),1,pA);
    }
    fclose(pA);
  } else{
    printf("No se ha podido crear el archivo\n");
  }
  printf("\n\nPresione una tecla para continuar.. ");
  getchar();
}

// Punto b - Alta de clientes
void altaDeDatos(FILE *pA,char *nom){
  struct clientes cli;
  struct clientes aux={0, "-", "-", '-', 0, 0};
  char opc;
  pA=fopen(nom, "r+b");
  if(pA!=NULL){
    do{
        system("cls");
        printf("\nIntroduzca el n%cmero de ID: ", 163);
        scanf("%d",&cli.id);
        fflush(stdin);
        if(cli.id > 0 && busqueda(pA, cli.id)==1){
          printf("Ingrese el Apellido: ");
          gets(cli.apellido);
          fflush(stdin);
          printf("Ingrese el Nombre: ");
          gets(cli.nombre);
          fflush(stdin);
          printf("Ingrese la Categor%ca: ", 161);
          scanf("%c",&cli.categoria);
          fflush(stdin);
          printf("Ingrese la Facturaci%cn: ", 162);
          scanf("%f",&cli.facturacion);
          fflush(stdin);
          printf("Est%c activo? 1-Si / 0-No : ", 160);
          scanf("%d",&cli.activo);
          fflush(stdin);
          if(cli.id==1){
            fseek(pA, 0, SEEK_SET);
            fwrite(&cli, sizeof(struct clientes), 1, pA);
          } else{
            fseek(pA, 0, SEEK_SET);
            fseek(pA, (cli.id-1)*sizeof(struct clientes), SEEK_SET);
            fwrite(&cli, sizeof(struct clientes), 1, pA);
          }
        }
        else if(cli.id>0){
          printf("\nEl registro con ID %d ya esta creado..\n",cli.id);
        }else printf("\nEl ID tiene que ser mayor a 0");

    printf("\nSi desea cargar otro cliente digite 1, de lo contrario presione cualquier tecla.. ");
    scanf("%c",&opc);
    fflush(stdin);
    }while(opc == '1');

  }else{
    printf("\nError al abrir el archivo %s",nom);
  }

  fclose(pA);
}

// Punto c - Listar los datos 
void mostrarDatos(FILE *pA, char *nom){
  int opc=0,i=0;
  pA = fopen(nom,"rb");

  if(pA != NULL){
    fseek(pA, 0, SEEK_END);
    int cantReg = ftell(pA)/sizeof(struct clientes),i=0;
    printf("\n1. Mostrar todos los clientes");
    printf("\n2. Mostrar los clientes activos");
    printf("\nElija una opcion [ ]\b\b");
    scanf("%d",&opc);
    fflush(stdin);

    if(opc==1 || opc==2){
      struct clientes cli;
      fseek(pA, 0, SEEK_SET);
      cabeceras();

      while(i<cantReg){
        fread(&cli, sizeof(struct clientes), 1, pA);
        if(opc==1 && cli.id>0){
          printf("\n%6d | %14s | %13s | %9c | %13.2f | %5d",cli.id,cli.apellido,cli.nombre,cli.categoria,cli.facturacion,cli.activo);
        }else if(opc == 2 && cli.activo == 1){
          printf("\n%6d | %14s | %13s | %9c | %13.2f | %5d",cli.id,cli.apellido,cli.nombre,cli.categoria,cli.facturacion,cli.activo);
        }
       i++;
      }
    }else{
      printf("\nOpci%cn incorrecta", 162);
    }
    fclose(pA);
  }else{
    printf("\nError al abrir el archivo");
  }
  printf("\n\nPresione una tecla para continuar.. ");
  getchar();
}

// Punto d - Buscar cliente
void buscarcliente(FILE *pA, char *nom){
  pA = fopen(nom,"rb");
  struct clientes cli;
  int opc;
  if(pA != NULL){
     fseek(pA,0,SEEK_END);
     int cantReg = ftell(pA)/sizeof(struct clientes),i=0;
     printf("\n1. Buscar un cliente por ID");
     printf("\n2. Buscar un cliente por Apellido");
     printf("\nElija una opcion [ ]\b\b");
     scanf("%d",&opc);
     fflush(stdin);
     if(opc==1){
       int id;
       printf("\nIntroduzca el n%cmero de ID: ", 163);
       scanf("%d",&id);
       fflush(stdin);
       fseek(pA,0,SEEK_SET);
       if(id>0){
         fseek(pA, (id-1)*sizeof(struct clientes), SEEK_SET);
         fread(&cli, sizeof(struct clientes), 1, pA);
         if(cli.id>0){
           cabeceras();
           printf("\n%6d | %14s | %13s | %9c | %13.2f | %5d",cli.id,cli.apellido,cli.nombre,cli.categoria,cli.facturacion,cli.activo);
         }else printf("\nNo existe el ID solicitado");
       }else printf("ID mal ingresado");

     } else if(opc==2){
       char apellido[30];
       int flag=0, i=0;
       printf("\nIntroduzca un Apellido: ");
       gets(apellido);
       fflush(stdin);
       fseek(pA,0,SEEK_SET);
       while(i<cantReg){
         fread(&cli,sizeof(struct clientes),1,pA);
         if(strcmp(cli.apellido, apellido)==0){
           cabeceras();
           printf("\n%6d | %14s | %13s | %9c | %13.2f | %5d",cli.id,cli.apellido,cli.nombre,cli.categoria,cli.facturacion,cli.activo);
           flag=1;
         }
         i++;
       }
       if(flag==0){
         printf("\nNo existe registro con el apellido solicitado");
       }

     } else printf("\nOpci%cn incorrecta", 162);

    fclose(pA);

  }else printf("\nError al abrir el archivo");
  printf("\n\nPresione una tecla paa continuar.. ");
  getchar();
}

// Punto e - Modificar cliente
void modificarcliente(FILE *pA, char *nom){
  pA = fopen(nom,"r+b");
  struct clientes cli;
  int opc;
  char categoria;
  float facturacion;

  if(pA!=NULL){
    fseek(pA,0,SEEK_END);
    int nReg = ftell(pA)/(sizeof(struct clientes));
    fseek(pA,0,SEEK_SET);
    printf("\n1. Buscar cliente por ID");
    printf("\n2. Buscar cliente por apellido");
    printf("\nElija una opcion [ ]\b\b");
    scanf("%d",&opc);
    fflush(stdin);

    if(opc==1){
      char opc2;
      int id;
      printf("\nIntroduzca el ID del cliente: ");
      scanf("%d",&id);
      fflush(stdin);
      printf("\nEst%c seguro que desea modificar los datos del ID n%cmero %d? Presione 1, de lo contrario presione cualquier tecla: ", 160, 163, id);
      scanf("%c",&opc2);
      fflush(stdin);
      if(opc2=='1'){
          fseek(pA, 0, SEEK_SET);
          fseek(pA, (id-1)*sizeof(struct clientes), SEEK_SET);
          fread(&cli, sizeof(struct clientes), 1, pA);
          printf("\nIntroduzca una categoria: ");
          scanf("%c", &categoria);
          fflush(stdin);
          cli.categoria=categoria;
          printf("Introduzca la facturacion: ");
          scanf("%f",&facturacion);
          fflush(stdin);
          cli.facturacion = facturacion;
          fseek(pA,-sizeof(struct clientes),SEEK_CUR);
          fwrite(&cli,sizeof(struct clientes),1,pA);
          printf("\nSe ha modificado los datos del cliente correctamente");
      }
    }
    else if(opc==2){
      char apellido[30];
      int flag=0, i=0;
      char opc2;
      printf("\nIngrese el apellido del cliente: ");
      gets(apellido);
      fflush(stdin);
      fseek(pA, 0, SEEK_SET);
      while(i<nReg){
        fread(&cli, sizeof(struct clientes), 1, pA);
        if(strcmp(cli.apellido, apellido)==0){
          flag = 1;
          break;
        }
      }
      if(flag==1){
        printf("\nEst%c seguro que desea modificar los datos de %s? Presione 1, de lo contrario presione cualquier tecla: ",160, cli.apellido);
        scanf("%c", &opc2);
        if(opc2=='1'){
            fflush(stdin);
            printf("\nIntroduzca una categoria: ");
            scanf("%c",&categoria);
            fflush(stdin);
            cli.categoria = categoria;
            printf("Introduzca la facturacion: ");
            scanf("%f", &facturacion);
            fflush(stdin);
            cli.facturacion = facturacion;
            fseek(pA, 0, SEEK_SET);
            fseek(pA, (cli.id-1)*sizeof(struct clientes), SEEK_SET);
            fwrite(&cli, sizeof(struct clientes), 1, pA);
            printf("\nSe ha modificado los datos del cliente correctamente");
            flag = 1;
          }
        }else
        printf("\nNo se encontr%c en el registro el apellido solicitado", 162);

    }else printf("\nOpci%cn incorrecta", 162);

    fclose(pA);
  }else printf("\nError al abrir el archivo");

  printf("\n\nPresione una tecla para continuar.. ");
  getchar();
}

// Punto f - Actualizar facturaciones
void actualizarfacturacions(FILE *pA,char *nom){
  pA=fopen(nom, "r+b");
  char categoria[10];
  float porcentaje[10];
  int nReg, cont=0, opc, i=0;
  struct clientes cli;

  if(pA!=NULL){
    do{
      printf("\nIngrese la categoria: ");
      fflush(stdin);
      scanf("%c",&categoria[cont]);
      fflush(stdin);
      printf("\nIngrese el porcentaje de facturaci%cn: ", 162);
      scanf("%f",&porcentaje[cont]);
      fflush(stdin);
      cont++;
      printf("\nPresione cualquier tecla si desea seguir cargando mas datos, 0 para finalizar: ");
      scanf("%d", &opc);

    }while(opc!=0);

    fseek(pA,0,SEEK_END);
    nReg = ftell(pA)/(sizeof(struct clientes));

    while(i<nReg){
      fseek(pA, 0, SEEK_SET);
      fseek(pA, i*sizeof(struct clientes), SEEK_SET);
      fread(&cli, sizeof(struct clientes), 1, pA);
      for(int j=0; j<cont; j++){
        if(cli.categoria==categoria[j]){
          double adicional=cli.facturacion*porcentaje[j]/100;
          cli.facturacion+=adicional;
        }
      }
      fseek(pA, 0, SEEK_SET);
      fseek(pA, i*sizeof(struct clientes), SEEK_SET);
      fwrite(&cli, sizeof(struct clientes), 1, pA);
      i++;
    }
    printf("\nFacturaciones actualizadas correctamente");
    fclose(pA);
  }else printf("\nError al abrir el archivo");
  printf("\n\nPresione una tecla para continuar.. ");
  getchar();
}

// Punto g - Baja lógica
void bajaLogica(FILE *pA, char *nom){
  pA=fopen(nom, "r+b");
  int id;
  struct clientes cli;
  char opc;
  if(pA!=NULL){
    printf("\nIngrese el ID del cliente que quiere dar la baja l%cgica: ", 162);
    scanf("%d", &id);
    fflush(stdin);
    fseek(pA, 0, SEEK_SET);
    fseek(pA, (id-1)*sizeof(struct clientes), SEEK_SET);
    fread(&cli, sizeof(struct clientes), 1, pA);

    if(cli.id>0){
        if(cli.activo==1){
          printf("\nID: %d\nApellido: %s\nNombre: %s\nCategoria: %c\nFacturacion: %.2f\nActivo: %d\n\nPara confirmar la baja presione 1, para cancelar presione cualquier tecla [ ]\b\b",cli.id,cli.apellido,cli.nombre,cli.categoria,cli.facturacion,cli.activo);
          scanf("%c",&opc);
          fflush(stdin);
        if(opc=='1'){
          cli.activo = 0;
          fseek(pA, -sizeof(struct clientes), SEEK_CUR);
          fwrite(&cli, sizeof(struct clientes), 1, pA);
          printf("\nEl cliente %s fue dado de baja",cli.nombre);
          printf("\n\n\t======== Listado de clientes activos ========");
          fseek(pA,0,SEEK_END);
          int nReg = ftell(pA)/(sizeof(struct clientes));
          int i=0;
          cabeceras();
          fseek(pA,0,SEEK_SET);

          while(i<nReg){
            fread(&cli, sizeof(struct clientes), 1, pA);
            if(cli.activo==1){
              printf("\n%6d | %14s | %13s | %9c | %13.2f | %5d",cli.id,cli.apellido,cli.nombre,cli.categoria,cli.facturacion,cli.activo);
            }
            i++;
          }
          printf("\n");

        }else printf("\nBaja cancelada");
        }else printf("\nEl cliente seleccionado ya esta dado de baja");

    }else printf("\nEse legajo no existe");
    fclose(pA);
  }else printf("\nError al abrir el archivo");
  printf("\n\nPresione una tecla para continuar.. ");
  getchar();
}

// Punto h - Baja física
void bajaFisica(FILE *pA,char *nom){
  pA=fopen(nom,"rb");
  struct clientes cli;
  if(pA != NULL){
    FILE* pAux = fopen("tcli.dat","wb");
    if(pAux != NULL){
      fseek(pA,0,SEEK_END);
      int nReg = ftell(pA)/(sizeof(struct clientes));
      int i=0;
      fseek(pA,0,SEEK_SET);
      while(i<nReg){
        fread(&cli,sizeof(struct clientes),1,pA);
        if(cli.activo==1){
          fseek(pAux, 0, SEEK_SET);
          fseek(pAux, (cli.id-1)*sizeof(struct clientes), SEEK_SET);
          fwrite(&cli, sizeof(struct clientes), 1, pAux);
        }
        i++;
      }
      printf("\nSe ha creado el archivo tcli.dat con los clientes activos exitosamente..");
      fclose(pA);
      fclose(pAux);
    }else printf("\nError al abrir el archivo tcli.dat");
  }else printf("\nError al abrir el archivo %s", nom);
  printf("\n\nPresione una tecla para continuar.. ");
  getchar();
}

// Funciones adicionales
int busqueda(FILE *pA,int leg){
  struct clientes aux;
  fseek(pA, 0, SEEK_SET);
  fread(&aux, sizeof(struct clientes), 1, pA);
  if(aux.id==leg){
    return -1;
  }
  else{
    while(!feof(pA)){
      fread(&aux, sizeof(struct clientes),1,pA);
      if(aux.id == leg){
        return -1;
      }
    }
    return 1;
  }
}

void cabeceras(){
  char headers[6][30] = {"ID", "Apellido", "Nombre", "Categoria", "Facturacion", "Activo"};
  printf("\n\n%6s | %10s\t| %10s\t| %7s |  %7s  | %7s",headers[0], headers[1], headers[2], headers[3], headers[4], headers[5]);
    printf("\n-------+----------------+---------------+-----------+---------------+---------");
}
