#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>

using namespace std;

struct Datos
{
	char nombre[50];
	char cedula[20];
	int noches;
	int numHabitacion;
	float precio;

	int Tpago;
	char tarjeta[30];
	char banco[30];	
};

struct Cliente
{
	Datos info;
	Cliente *sig;
	Cliente *ant;
};


Datos Cargar();
Cliente *registro_cliente(Cliente *Final, Cliente **Principio, Datos info);

void view(Datos);
void mostrar_reservaciones(Cliente *);

void buscar_reservacion(const Cliente *, const Cliente *, int);

Cliente *cancelar_reservacion(Cliente *, Cliente **, int);
void guardar_registro(Cliente *);
Cliente *leer_registro(Cliente *, Cliente **);

int main()
{
	Cliente *Principio = NULL;
	Cliente *Final = NULL;
	int opc, id;
	
	do{
		system("cls");	 
		printf("\t\t\tBIENVENIDOS AL HOTEL ---------- \n");
		printf("\t\t1.Registrar cliente \n");
		printf("\t\t2.Consultar reservacion al inicio \n");
		printf("\t\t3.Consultar reservacion al final \n ");
		printf("\t\t4.Cancelacion de reservacion \n");
		printf("\t\t5.Buscar reservacion \n");
		printf("\t\t6.Cerrar el sistema \n");
		printf("\t\topcion: ");
		scanf("%d",&opc);
		
		switch(opc)
		{
			case 1:	
				Final = registro_cliente(Final, &Principio, Cargar());
			break;

			case 2:
				if (Principio != NULL)
					view(Principio->info);
				else
					printf("\n NO hay reservacion al inicio");
			break;
			
			case 3:
				if (Final != NULL)
					view(Final->info);
				else
					printf("\n NO hay reservacion al final");
			break;

			case 4:
				if (Principio != NULL)
				{
					printf("\n ingrese numero de habitacion: ");
					scanf("%d",&id);
					Principio = cancelar_reservacion(Principio, &Final, id);
				}else
					printf("\n No hay lista de reservacion");
			break;

			case 5:
				if (Principio != NULL)
				{
					printf("\n ingrese numero de habitacion: ");
					scanf("%d",&id);
					buscar_reservacion(Principio, Final, id);
				}else
					printf("\n No hay lista de reservacion");
			break;

			case 6: guardar_registro(Principio); break;

			default: mostrar_reservaciones(Principio);
		}
		fflush(stdin);
		printf("\n\n");
		system("pause");
	}while(opc != 6);

 return 0;
}

Datos Cargar()
{
	Datos info;

	fflush(stdin);
	printf("\n ingrese el nombre del cliente: ");
    scanf("%[^\n]",&info.nombre);
	fflush(stdin);
	
	printf(" Cedula: ");
	scanf("%[^\n]",&info.cedula);
	fflush(stdin);
	
	printf(" ingrese cuantas noches ocupara en la habitacion: ");
	scanf("%d",&info.noches);

	printf(" Numero habitacion: ");
	scanf("%d",&info.numHabitacion);

	printf(" Precio de la habitacion: ");
	scanf("%f",&info.precio);
	fflush(stdin);

	printf("\n Tipo de pago\n [1.efectivo]\n [2.tarjeta de credito]\n: ");
	scanf("%d",&info.Tpago);
	

	if (info.Tpago == 2)
	{
		fflush(stdin);
		printf("\n Tipo de tarjeta: ");
		scanf("%[^\n]",&info.tarjeta);

		fflush(stdin);		
		printf(" Nombre del Banco: ");
		scanf("%[^\n]",&info.banco);
	}else info.Tpago = 1;

	return info;
}


Cliente *registro_cliente(Cliente *Final, Cliente **Principio, Datos info)
{
	if (Final != NULL) // almenos una reservacion
	{
		Cliente *q = new Cliente();
		q->info = info;
		Final->sig = q;
		q->ant = Final;
		Final = q;

		// -------------------
		q->sig = *Principio;
		(*Principio)->ant = q;
	}
	else // en caso no aya ninguna reservacion
	{
		Final = new Cliente();
		Final->info = info;
		Final->sig = Final->ant = NULL;
		*Principio = Final; 
	}

	return Final;
}

void view(Datos info)
{
	printf("\n\n Nombre del cliente: %s\t\tCed: %s",info.nombre, info.cedula);
	printf("\n habitacion N.%d\t\tNoches: %d\t\tPrecio: %.2f",info.numHabitacion, info.noches, info.precio);
	printf("\n Tipo de pago: ");
	if (info.Tpago == 2)
	{
		printf("tarjeta");
		printf("\n Tipo de tarjeta: %s\t\tBanco: %s",info.tarjeta, info.banco);
	}else
		printf("efectivo$");
}

void mostrar_reservaciones(Cliente *p)
{
	if (p != NULL)
	{
		register Cliente *q = p;
		int i = 1;
		do
		{	
			printf("\n\n Reservacion [#%d]",i);
			view(q->info);
			// -----------------------------
			q = q->sig;
			++i;
		}while(q != p && q != NULL);
	}
	else
		printf("\n\t Registro vacio");
}


void buscar_reservacion(const Cliente *p,const Cliente *f, int id)
{
	const Cliente *q = p, *t = f;
	bool ver = false;

	do
	{
		if (q->info.numHabitacion == id)
		{
			view(q->info);
			ver = true;
			break;
		}
		else if(t->info.numHabitacion == id)
		{
			view(t->info);
			ver = true;
			break;
		}
		else if(q == t)
			break;
		

		q = q->sig;
		t = t->ant;
	} while (q != p);
	
	if (ver == false)
		printf("\n No se encontro el registro");
}


Cliente *cancelar_reservacion(Cliente *p, Cliente **f, int id)
{	

	Cliente *q = p,
		*t, *r;

	while(q != *f && q->info.numHabitacion != id)
		q = q->sig;


	if (q->info.numHabitacion == id)
	{
		if (p == q && q == *f) //solo un nodo
			p = *f = NULL;
		else if (p == q) // primer nodo
		{
			p = p->sig;
			
			if(p == *f) //si solo queda un nodo
				p->ant = p->sig = NULL;
			else
			{
				p->ant = *f;
				(*f)->sig = p;
			}
		}
		else if (q == *f) // ultimo nodo
		{
			*f = (*f)->ant;
			
			if(*f == p) //si solo queda un nodo
				p->ant = p->sig = NULL;
			else
			{
				(*f)->sig = p;
				p->ant = *f;
			}
		}
		else // intermedio [][x][]
		{
			t = q->ant;
			r = q->sig;
			t->sig = r;
			r->ant = t;
		}

		free(q);
		printf("\n Reservacion de habitacion N.%d fue cancelada",id);
	}else
		printf("\n La reservacion no se encontro en la lista");
	

	return p;
}


void guardar_registro(Cliente *p)
{
	ofstream archivo;
	Cliente *q = NULL;

	if (p != NULL)
	{
		archivo.open("Archivos//registroHotel.txt", ios::out | ios::app);
		if (archivo.fail())
			cout<<"\n Error al crear el archivo de registros";
		else
		{
        	q = p;
	        
	        do
	        {
				// escribiendo en el archivo
	        	archivo <<"\n Nombre del cliente: " << q->info.nombre 
	        			<<"\t Cedula: " << q->info.cedula  
    					<<"\t Noches: " <<q->info.noches 
    					<<"\t Habitacion: " << q->info.numHabitacion 
    					<<"\t Precio: " << q->info.precio 
    					<<"\n Tipo de pago: ";

				if (q->info.Tpago == 2)
				{
	        		archivo <<"tarjeta" 
	        				<<"\t Tipo de tarjeta: " <<q->info.tarjeta
	        				<<"\t Banco: "<< q->info.banco <<endl; 
				}else
					archivo << "efectivo$" << endl;
	            	            
	            q = q->sig;

	        }while(q != p && q != NULL);

	        cout<<"\n registro guardando correctamente";
	        archivo.close();
		}
	}
}

Cliente *leer_registro(Cliente *p, Cliente **f)
{
	ifstream archivo;
	Cliente *q = NULL, *t = NULL;
	Datos info;

	//////////// Leyendo las cuentas activas /////////////
	archivo.open("Archivos//registroHotel.txt",ios::out | ios::in);
	if (archivo.fail())
		cout<<"\n Sin registro";
	else
	{
		// archivo.getline(info.nombre,50,'\n');
		// fflush(stdin);
		// archivo.getline(info.cedula,20,'\n');
		// fflush(stdin);
		
		// archivo >> info.noches >> info.numHabitacion
		// 		>> info.precio >> info.Tpago;

		// if (info.Tpago == 2)
		// {
		// 	fflush(stdin);
		// 	archivo.getline(info.tarjeta,30,'\n');
		// 	fflush(stdin);
		// 	archivo.getline(info.banco,30,'\n');
		// }

		// // // en caso que no lea nada
		// // else if(info.Tpago == 0)
		// // {
		// // 	archivo.close();
		// // 	return p;
		// // }	

		// p = registro_cliente(p, &(*f), info);

        
        while(!archivo.eof())
		{  // leer mientras no llegue al final del archivo
			fflush(stdin);
			archivo.getline(info.nombre,50,'\n');
			fflush(stdin);
			archivo.getline(info.cedula,20,'\n'); 
			
			archivo >> info.noches >> info.numHabitacion
					>> info.precio >> info.Tpago;
			fflush(stdin);

			if (info.Tpago == 2)
			{
				fflush(stdin);
				archivo.getline(info.tarjeta,30,'\n');
				fflush(stdin);
				archivo.getline(info.banco,30,'\n');
			}

			// en caso que no lea nada
			// else if(info.Tpago == 0)
			// {
			// 	archivo.close();
			// 	return p;
			// }	

			p = registro_cliente(p, &(*f), info);
			mostrar_reservaciones(p);
			getchar();
		}

		printf("\n Registro de reservaciones leidas");
        archivo.close();
	}

	return p;
}




Cliente *nuevo = LISTA;

while(q-)