#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define GREEN      "\x1b[32m"

#define MAX 20

#define VACIO 0
#define ACTIVO 1
#define BORRADO 2

////
int main()
{
    agend respaldo[1];
    agend agenda[MAX];
    inicio(agenda);

    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        system("cls");
        printf(GREEN"Menu agenda tp2:\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                carga(agenda);

                break;
            case 2:
                system("cls");
                baja(agenda);
                getch();
                break;
            case 3:
                system("cls");
                ordenarNombre(agenda);
                getch();
                break;
            case 4:
                system("cls");
                imprimirGrafico(agenda);
                getch();
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
////
void inicio(agend agenda[MAX]){
    for(int i = 0 ; i < MAX ; i++){

       strcpy(agenda[i].apellido,"---");
       strcpy(agenda[i].nombre,"---");
       agenda[i].edad = 0;
       agenda[i].documento = 0;

       agenda[i].estado = VACIO;
    }
}
////
void carga(agend agenda[MAX]){
    printf("Ingrese los datos: \n");
    for(int i = 0 ; i < MAX ; i++){
        if(agenda[i].estado == VACIO){


            printf("apellido : "  );
            scanf("%s" , agenda[i].apellido);

            printf("nombre : "  );
            scanf("%s" , agenda[i].nombre);

            printf("edad : "  );
            scanf("%d" , &agenda[i].edad);
            printf("documento : "  );
            scanf("%d" , &agenda[i].documento);


            agenda[i].estado = ACTIVO;
            break;

        }
    }

}

////
void baja(agend agenda[MAX]){
    printf("Baja \n");
    int posicion = buscar(agenda);

    if(posicion != -1 ){
      agenda[posicion].estado = BORRADO;
    }else{
        printf("No se encontro la direccion");
    }
}
////
int buscar(agend agenda[MAX]){
    int posicion = -1;


    int documento2;

    printf("documento a buscar : ");
    scanf("%d",&documento2);

    for(int i = 0 ; i < MAX ; i++)
    {
        if(agenda[i].estado == ACTIVO &&
                agenda[i].documento == documento2)
        {
            posicion = i;
            break;
        }
    }

}
////
void busqueda(agend agenda[MAX]){
    printf("1.busqueda \n");

    int posicion = buscar(agenda);
    int i = posicion;
    if(posicion != -1 ){
        printf("%s %s %d %d %d\n",
               agenda[i].apellido,
               agenda[i].nombre,
               agenda[i].edad,
               agenda[i].documento,

               agenda[i].estado
               );
    }else{
        printf("No se encontro los datos");
    }

}

////
void ordenarNombre(agend agenda[MAX]){
    printf("Listado de todas las personas\n");
    for(int i = 0 ; i < MAX ; i++){

int x,y,z,temp,copia,p=0,w=0;

agend respaldo[1];

char patron[53];
char letra;

z=0;
patron[0]='A';patron[1]='a';patron[2]='B';patron[3]='b';patron[4]='C';patron[5]='c';patron[6]='D';patron[7]='d';patron[8]='E';patron[9]='e';
patron[10]='F';patron[11]='f';patron[12]='G';patron[13]='g';patron[14]='H';patron[15]='h';patron[16]='I';patron[17]='i';patron[18]='J';
patron[19]='j';patron[20]='K';patron[21]='k';patron[22]='L';patron[23]='l';patron[24]='M';patron[25]='m';patron[26]='N';patron[27]='n';

patron[30]='O';patron[31]='o';patron[32]='P';patron[33]='p';patron[34]='Q';patron[35]='q';patron[36]='R';patron[37]='r';patron[38]='S';
patron[39]='s';patron[40]='T';patron[41]='t';patron[42]='U';patron[43]='u';patron[44]='V';patron[45]='v';patron[46]='W';patron[47]='w';
patron[48]='X';patron[49]='x';patron[50]='Y';patron[51]='y';patron[52]='Z';patron[53]='z';

for(x=0;x<MAX;x++)
{
 p=0;
 w=0;
 letra=agenda[x].apellido[0];

   while(patron[p]!=letra)
  {
	p=p+1;
  };

temp=p;
p=0;

for (y=z;y<MAX;y++)
	{
	letra=agenda[y].apellido[0];
		while(patron[p]!=letra)
         {
	       p=p+1;
         };
		w=p;

	    if(temp>=w)
	    {
	     temp=w;
	     respaldo[0]=agenda[y];
	     copia=y;
	    }
         p=0;
	}
	 agenda[copia]=agenda[x];
	 agenda[x]=respaldo[0];
	z=z+1;
}

for (y=0;y<MAX;y++)
{
       printf("%s %s %d %d %d\n",
               agenda[y].apellido,
               agenda[y].nombre,
               agenda[y].edad,
               agenda[y].documento,

               agenda[y].estado
               );

}

return 0;
}

    }

////
void imprimirGrafico(agend agenda[MAX]) {

    int menores = 0;
    int adultos = 0;
    int mayores = 0;

    for( int i = 0 ; i < MAX ; i++ ) {
        if(agenda[i].estado == ACTIVO){
            if(agenda[i].edad <= 18) {
                menores++;
            } else if(agenda[i].edad > 18 && agenda[i].edad <= 35) {
                adultos++;
            } else if(agenda[i].edad > 35) {
                mayores++;
            }
        }
    }

  ////
    int graficoDatos[MAX][3];
    for(int i=0; i<MAX; i++) {
        if(i < menores) {
            graficoDatos[i][0] = 1;
        } else {
            graficoDatos[i][0] = 0;
        }
        if(i < adultos) {
            graficoDatos[i][1] = 1;
        } else {
            graficoDatos[i][1] = 0;
        }
        if(i < mayores) {
            graficoDatos[i][2] = 1;
        } else {
            graficoDatos[i][2] = 0;
        }

    }
////

        for(int i = 19 ; i >= 0; i--){
            for(int j = 0 ; j < 3 ; j++){
                printf("       %d        " , graficoDatos[i][j]);



            }
            printf(" \n");
        }
      printf(" \n");
      printf("menores a 19    entre 19 a 35     mayores a 35");



      }
