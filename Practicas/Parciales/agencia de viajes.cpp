#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/*Definicion de las estructuras */
struct Rutas
{
  char nombre_destino[MAX];
  float tarifa_ruta;
  Rutas *liga;
};

struct Vuelos
{
	char numero_vuelo[MAX];
	char origen_vuelo[MAX];
	Vuelos *liga;
	Rutas *ligarut;
};


FILE *pt1;

// Programa Principal
int main()
{
   Vuelos *crea_vuelo(Vuelos *pv);
   void lista_vuelo(Vuelos *pv);
   Rutas *crearut(Rutas *pr);
   void lista_rut(Rutas *pr);
   Vuelos *liberamemoria(Vuelos *pv);
   void Vuelosrut(Vuelos *pv, char num_vuel[MAX]);
   Vuelos *elimina_vuelo(Vuelos *pv, char num_vuel[MAX]);
   Vuelos *elimina_Vuelosrut(Vuelos *pv, char num_vuel[MAX]);
   Vuelos *agrega_vuelo(Vuelos *pv, char num_vuel[MAX]);
   Vuelos *agrega_Vuelosrut(Vuelos *pv, char num_vuel[MAX]);
   void salvar(Vuelos *pv);
   Vuelos *abrir(void);
   int i;
   Vuelos *pv = NULL;
   Rutas *pr;
   char num_vuel[MAX], rut[MAX], name[8], archivo[15];

   do{
      puts("\n\t\t\t\t MENU DE INICIO\n");
      puts("\t\t 1- CREAR UNA LISTA DE Vuelos. ");
      puts("\t\t 2- VER LISTA DE Vuelos. ");
      puts("\t\t 3- VER UN VUELO Y SUS Rutas. ");
      puts("\t\t 4- BORRAR UN VUELO DE LA LISTA. ");
      puts("\t\t 5- BORRAR UNA RUTA DE LA LISTA. ");
      puts("\t\t 6- AGREGAR UN VUELO A LA LISTA. ");
      puts("\t\t 7- AGREGAR UNA RUTA A UN VUELO. ");
      puts("\t\t 8- SALVAR EL DOCUMENTO.");
      puts("\t\t 9- ABRIR UN ARCHIVO. ");
      puts("\t\t 10- SALIR. ");
      puts("\n\t\t ESCOJA SU OPCION: ");
      scanf("%d",&i);
      fflush(stdin);
      switch(i)
      {
	  case 1:  pv = crea_vuelo(pv); break;
	  case 2:  lista_vuelo(pv);  break;
	  case 3:
		 if (pv != NULL)
		 {
		    lista_vuelo(pv);
		    printf("\nPara ver las Rutas escriba numero del Vuelos:\n");
		    printf("\n\t\t\tVUELO: ");
		    fflush(stdin);
		    gets(num_vuel);
		    Vuelosrut(pv,num_vuel);
		 }
		 else
		    printf("\n\n\n\n\t\t\tNO HAY Vuelos EN MEMORIA");
	 break;

	  case 4:
		 if(pv != NULL)
		 {
		   lista_vuelo(pv);
		   printf("\n¨Que vuelo desea eliminar? ");
		   fflush(stdin);
		   gets(num_vuel);
		   pv = elimina_vuelo(pv,num_vuel);
		 }
		 else
		    printf("\n\n\n\n\t\t\tNO HAY Vuelos EN MEMORIA");
	 break;

	  case 5:
		 if (pv != NULL)
		 {
		   lista_vuelo(pv);
		   printf("\n\t¨La lista de Rutas de cual vuelo desea modificar?\n");
		   printf("\n\t\t\tVUELO:  ");
		   fflush(stdin);
		   gets(num_vuel);
		   Vuelosrut(pv,num_vuel);
		   pv = elimina_Vuelosrut(pv,num_vuel);
		   Vuelosrut(pv,num_vuel);
		 }
		 else
		    printf("\n\n\n\n\t\t\tNO HAY Vuelos EN MEMORIA");
	 break;

	  case 6:
		 if (pv != NULL)
		 {
		    lista_vuelo(pv);
		    printf("\n\t\t¨Que Vuelos desea agregar a la lista?\n");
		    printf("\n\t\t\tVUELO:  ");
		    fflush(stdin);
		    gets(num_vuel);
		    pv = agrega_vuelo(pv,num_vuel);
		 }
		 else
		    printf("\n\n\n\n\t\t\tNO HAY Vuelos EN MEMORIA");
	 break;

	  case 7:
		 if (pv != NULL)
		 {
		   lista_vuelo(pv);
		   printf("\n\t¨A que Vuelos desea agregar un Rutas?\n");
		   printf("\n\t\t\tVUELO:  ");
		   fflush(stdin);
		   gets(num_vuel);
		   Vuelosrut(pv,num_vuel);
		   pv = agrega_Vuelosrut(pv,num_vuel);
		   Vuelosrut(pv,num_vuel);
		 }
		 else
		    printf("\n\n\n\n\t\t\tNO HAY Vuelos EN MEMORIA");
	 break;

	  case 8:
		  if (pv != NULL)
		  {
		    //printf("\n\t\t¨Que nombre le pondr  a su archivo?\n");
		    //printf("\n  **Recuerde especificar la unidad y el tipo de documento");
		    //printf("\n\t\t\tNOMBRE: ");
		    //gets(archivo);
		    pt1 = fopen("a:prueba.dat", "w");
		    salvar(pv);
		    fclose(pt1);
		  }
		  else
		  {
		    printf("\n\n\t\t\tEL DOCUMENTO ESTA VACÖO");
		    
		  }
	  break;

	  case 9:
		  //printf("\n\t\t¨Que archivo desea abrir?\n");
		  //printf("\n**Recuerde especificar la unidad y el tipo de documento\n");
		  //printf("\n\t\t\tNOMBRE: ");
		  //gets(archivo);
            if((pt1 = fopen("a:prueba.dat", "r+")) == NULL)
                printf("ERROR. NO SE PUEDE ABRIR EL ARCHIVO");
            else
            {
                pv = abrir();
                fclose(pt1);
            }
	   break;

	  case 10: pv = liberamemoria(pv); break;

	  default: printf(" OPCION NO VALIDA. PRESIONE ENTER.");
    }
        getch();
    }while(i != 10);
  return 0;
}


//===============FUNCIONES===============
void *creamemoria_v(int n)
{
   void *pv = (int *)malloc(n);
   if(pv == NULL)
   {
      puts("NO HAY MEMORIA");
      getch();
      exit(1);
   }
   return(pv);
}

void *creamemoria_r(int n)
{
   void *pr = (int *)malloc(n);
   if(pr == NULL)
   {
      puts("NO HAY MEMORIA");
      getch();
      exit(1);
   }
   return(pr);
}

Vuelos *creanodo_v()
{
   void *creamemoria_v(int n);
   return((Vuelos *)creamemoria_v(sizeof(Vuelos)));
}

Rutas *creanodo_r()
{
   void *creamemoria_r(int n);
   return((Rutas *)creamemoria_r(sizeof(Rutas)));
}


Vuelos *crea_vuelo(Vuelos *pv)
{
  Rutas *crearut(Rutas *pr);

  int i = 1;
  char num_vuel[MAX];
  char orig_vuel[MAX];
  Vuelos *qv, *tv;

  pv = creanodo_v();

  printf("\n Para terminar introduzca la palabra 'FIN'");
  printf("\n VUELO %d:  ", i);
  gets(num_vuel);
  fflush(stdin);
  if(strcmpi(num_vuel,"FIN"))
  {
     printf("\nORIGEN: ");
     gets(orig_vuel);
     fflush(stdin);
     strcpy(pv->origen_vuelo,orig_vuel);
     strcpy(pv->numero_vuelo,num_vuel);
     pv->liga = pv;
     printf("\n Sus Rutas son: ");
     pv->ligarut = crearut(pv->ligarut);
     tv = pv;
     do
     {
	qv = creanodo_v();
	++i;
	printf("\n VUELO %d:  ", i);
	gets(num_vuel);
	fflush(stdin);
	if(strcmpi(num_vuel,"FIN"))
	{
	   printf("\nORIGEN: ");
	   gets(orig_vuel);
	   strcpy(qv->origen_vuelo,orig_vuel);
	   strcpy(qv->numero_vuelo,num_vuel);
	   qv->liga = pv;
	   printf("\nSus Rutas son: ");
	   qv->ligarut = crearut(qv->ligarut);
	   tv->liga = qv;
	   tv = qv;
	}
	else
	{
	   free(qv);
	   break;
	}
     }while(strcmpi(num_vuel,"FIN"));
   }
   else
     pv = NULL;
 return(pv);
}


Rutas *crearut(Rutas *pr)
{
  char rut[MAX];
  float tar_rut;
  Rutas *qr, *tr;

  pr = creanodo_r();
  printf("\n Destino:  ");
  gets(rut);
  fflush(stdin);
  if(strcmpi(rut,"FIN"))
  {
     printf("\n Tarifa:  ");
     scanf("%f",&tar_rut);
     fflush(stdin);
     pr->tarifa_ruta = tar_rut;
     printf("\n %f",pr->tarifa_ruta);
     strcpy(pr->nombre_destino,rut);
     pr->liga = pr;
     tr = pr;
     do
     {
	qr = creanodo_r();
	printf(" Destino:  ");
	gets(rut);
	fflush(stdin);
	if(strcmpi(rut,"FIN"))
	{
	   printf("\n Tarifa:  ");
	   scanf("%f",&tar_rut);
	   fflush(stdin);
	   qr->tarifa_ruta = tar_rut;
	   strcpy(qr->nombre_destino,rut);
	   qr->liga = pr;
	   tr->liga = qr;
	   tr = qr;
	}
	else
	{
	   free(qr);
	   break;
	}
     }while(strcmpi(rut,"FIN"));
   }
   else
     pr = NULL;
 return(pr);
}


/* Funcion que imprime los Vueloss */
void lista_vuelo(Vuelos *pv)
{
	Vuelos *qv;
	int i = 1;
	int y = 7;

	qv = pv;
	printf("\n\t\t\t\t Vuelos \n\n");
	printf("No. Vuelo");
	printf("Origen");

	if (pv != NULL)
	{
		do{
			printf("%d.  ", i);
			printf("%s",strupr(qv->numero_vuelo));
			printf("%s",strupr(qv->origen_vuelo));
			qv = qv->liga;
			i++;
			y = y + 2;
		}while(qv != pv);
	}
	else
	printf("\n\t\t\tNO HAY VUELOS EN LA MEMORIA");
}


/* Funcion que imprime los Rutas */
void lista_rut(Rutas *pr)
{
 Rutas *qr;
 int i = 1;
 int y = 7;

 qr = pr;

 if (pr != NULL)
   {
    printf("Destino");
    printf("Tarifa");
    do{
	printf("%d.", i);
	printf("%s",(strupr(qr->nombre_destino)));
	printf("%f",qr->tarifa_ruta);
	qr = qr->liga;
	i++;
	y = y + 2;
    }while(qr != pr);
  }
 else
      printf("\n\t\tEL VUELO NO TIENE DESTINO.");
}


Vuelos *liberamemoria(Vuelos *pv)
{
 Vuelos *qv, *rv;

 rv = pv->liga;
 if (pv != NULL)
 {
    while (rv->liga != pv)
      rv = rv->liga;

    if(rv != pv)
    {
       while(rv != pv)
       {
	  qv = pv;
	  pv = pv->liga;
	  free(qv);
	  rv->liga = pv;
	 };
    }
 }
 return(pv);
}


/*Funcion que imprime el Vuelos con sus Rutas*/
void Vuelosrut(Vuelos *pv, char num_vuel[MAX])
{
  Vuelos *qv;

  qv = pv;
  do{
     qv = qv->liga;
  }while(strcmpi(qv->numero_vuelo,num_vuel) && qv != pv);

  if(!strcmpi(qv->numero_vuelo,num_vuel))
  {
     printf("\n\t\t\t\t"); puts(strupr(qv->numero_vuelo)); printf("\n");
     lista_rut(qv->ligarut);
  }
  else
     printf("\n\t\t\tEL VUELO NO FUE ENCONTRADO");
}


/* Funcion que permite borrar un Vuelos */
Vuelos *elimina_vuelo(Vuelos *pv, char num_vuel[MAX])
{
  Vuelos *qv, *tv, *sv;
  int band = 1;

  sv = pv->liga;
  while(sv->liga != pv)
     sv = sv->liga;
  qv = pv;

  while(band == 1 && strcmpi(qv->numero_vuelo,num_vuel))
  {
     if(qv != sv)
     {
	tv = qv;
	qv = qv->liga;
     }
     else
	band = 0;
  }
  if(band == 0)
  {
    if(strcmpi(qv->numero_vuelo,num_vuel)==0)
      tv->liga = pv;
    else
      printf("\n\t\t\tEL VUELO NO FUE ENCONTRADO");
  }
  else
  {
    if(qv == pv)
    {
      pv = qv->liga;
      sv->liga = pv;
      if(pv == sv)
	 pv = NULL;
    }
    else
      tv->liga = qv->liga;
    printf("\n\t\t\tEL POSTRE FUE ELIMINADO");
    free(qv);
  }
  return(pv);
}


/* Funcion que elimina un Rutas de una lista */
Rutas *eliminarut(Rutas *pr, char rut[MAX])
{
  Rutas *qr, *tr, *sr;
  int band = 1;

  sr = pr->liga;
  while(sr->liga != pr)
    sr = sr->liga;
  qr = pr;

  while(band == 1 && strcmpi(qr->nombre_destino,rut))
  {
     if(qr != sr)
     {
	tr = qr;
	qr = qr->liga;
     }
     else
	band = 0;
  }
  if(band == 0)
  {
     if(strcmpi(qr->nombre_destino,rut)==0)
	tr->liga = pr;
     else
	printf("\n\t\t\tLA RUTA NO FUE ENCONTRADA");
  }
  else
  {
     if(qr == pr)
     {
	pr = qr->liga;
	sr->liga = pr;
	if(pr == sr)
	   pr = NULL;
     }
     else
	tr->liga = qr->liga;
      printf("\n\t\t\tLA RUTA FUE ELIMINADA");
      //getch();
      free(qr);
    }
  return(pr);
}


/* Funcion que elimina un Rutas de un Vuelos en especial */
Vuelos *elimina_Vuelosrut(Vuelos *pv, char num_vuel[MAX])
{
  Vuelos *qv;
  char rut[MAX];

    qv = pv;
    do{
       qv = qv->liga;
    }while(strcmpi(qv->numero_vuelo,num_vuel) && qv != pv);

    if(!strcmpi(qv->numero_vuelo,num_vuel))
    {
      if (qv->ligarut != NULL)
      {
	 printf("\n\t\t¨Que Rutas del Vuelos desea eliminar?");
	 printf("\n\t\t\tDestino: ");
	 fflush(stdin);
	 gets(rut);
	 qv->ligarut = eliminarut(qv->ligarut,rut);
      }
    }
    else
	 printf("\n\t\t\tEL VUELO NO FUE ENCONTRADO");

  return(pv);
}


/* Funcion que permite agregar un Vuelos a la lista */
Vuelos *agrega_vuelo(Vuelos *pv, char num_vuel[MAX])
{
   Vuelos *qv, *sv;
   int band;

   qv = pv;
   sv = pv->liga;
   while(sv->liga != pv)
      sv = sv->liga;

   do{
       band = strcmpi(qv->numero_vuelo,num_vuel);
       qv = qv->liga;
   }while(band != 0 && qv != pv);

   if (band == 0)
      printf("\n\t\t\tL VUELO YA EXISTE EN LA LISTA");
   else
   {
      qv = creanodo_v();
      strcpy(qv->numero_vuelo,num_vuel);
      qv->liga = pv;
      sv->liga = qv;
      printf("\nSus Rutas son: (escriba 'FIN' para terminar)\n");
      qv->ligarut = crearut(qv->ligarut);
   }
   return(pv);
}


/* Funcion que permite agregar un Rutas */
Rutas *agregarut(Rutas *pr, char rut[MAX])
{
   Rutas *qr, *sr;
   int band;

   qr = pr;
   sr = pr->liga;
   while(sr->liga != pr)
      sr = sr->liga;

   do{
       band = strcmpi(qr->nombre_destino,rut);
       qr = qr->liga;
   }while(band != 0 && qr != pr);

   if (band == 0)
      printf("\n\t\t\tA RUTA YA EXISTE EN LA LISTA");
   else
   {
      qr = creanodo_r();
      strcpy(qr->nombre_destino,rut);
      qr->liga = pr;
      sr->liga = qr;
   }
   return(pr);
}


/* Funcion que permite agregar un Rutas a un Vuelos en especial*/
Vuelos *agrega_Vuelosrut(Vuelos *pv, char num_vuel[MAX])
{
   Vuelos *qv;
   char rut[MAX];

   qv = pv;
   do{
       qv = qv->liga;
   }while(strcmpi(qv->numero_vuelo,num_vuel) && qv != pv);

   if(!strcmpi(qv->numero_vuelo,num_vuel))
   {
      if (qv->ligarut != NULL)
      {
	 printf("\n\t\t¨Que Rutas desea agregar al Vuelos?\n");
	 printf("\n\t\t\tDestino: ");
	 gets(rut);
	 fflush(stdin);
	 qv->ligarut = agregarut(qv->ligarut,rut);
      }
    }
    else
	 printf("\n\t\t\tEL VUELO NO FUE ENCONTRADO");

  return(pv);
}


/* Funcion que permite grabar en un archivo*/
void salvar(Vuelos *pv)
{
  Rutas *pr;
  Vuelos *qv;
  qv = pv;

  do{
       fprintf(pt1, "\n\n%s", strupr(qv->numero_vuelo));
       pr = qv->ligarut;

       do{
	  fprintf(pt1, "\n%s", strupr(pr->nombre_destino));
	  pr = pr->liga;
	 }while(pr != qv->ligarut);
	fprintf(pt1, "\n%s", "FIN");
	qv = qv->liga;
    }while(qv != pv);
    return;
}


Vuelos *abrir(void)
{
  Rutas *abrirrut(Rutas *pr);

  Vuelos *pv,*qv, *tv;

  pv = creanodo_v();

  fscanf(pt1, "&[^\n]", pv->numero_vuelo);
  if(!feof(pt1))
  {
     //strcpy(pv->numero_vuelo,pv->numero_vuelo);
     pv->liga = pv;
     pv->ligarut = abrirrut(pv->ligarut);
     tv = pv;
     do
     {
	qv = creanodo_v();
	fscanf(pt1, "&[^\n]", qv->numero_vuelo);
	if(!feof(pt1))
	{
	  // strcpy(qv->numero_vuelo,qv->numero_vuelo);
	   qv->liga = pv;
	   qv->ligarut = abrirrut(qv->ligarut);
	   tv->liga = qv;
	   tv = qv;
	}
	else
	{
	   free(qv);
	   break;
	}
     }while(!feof(pt1));
   }
   else
     pv = NULL;
 return(pv);
}


Rutas *abrirrut(Rutas *pr)
{
  Rutas *tr, *qr;

  pr = creanodo_r();
  fscanf(pt1, "&[^\n]", pr->nombre_destino);
  if(strcmpi(pr->nombre_destino,"FIN"))
  {
     //strcpy(pr->nombre_destino,pr->nombre_destino);
     pr->liga = pr;
     tr = pr;
     do
     {
	qr = creanodo_r();
	fscanf(pt1, "&[^\n]", qr->nombre_destino);
	if(strcmpi(qr->nombre_destino,"FIN"))
	{
	   //strcpy(qr->nombre_destino,qr->nombre_destino);
	   qr->liga = pr;
	   tr->liga = qr;
	   tr = qr;
	}
	else
	{
	   free(qr);
	   break;
	}
     }while(strcmpi(qr->nombre_destino,"FIN") && !feof(pt1));
   }
   else
     pr = NULL;
    return(pr);
}