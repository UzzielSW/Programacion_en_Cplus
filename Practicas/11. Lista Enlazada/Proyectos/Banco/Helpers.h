
#ifndef HELPERS_H
#define HELPERS_H 

#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <fstream>
 #define MAX 999999 
 #define MIN 100000

using namespace std;

struct Datos_Cuenta
{
	double saldo_cuenta;
	long numero_cuenta;
	string tipo_cuenta, 
		   nombre_cuenta;
};

struct Datos_Nodo
{
	struct Datos_Cuenta Dato;
	struct Datos_Nodo *liga;
};

HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);	

typedef Datos_Nodo Nodo;
bool Buscar_Cuenta(Nodo *p, long);
string transform_down(string);
string transformSpace(string);
////////////////	  CREAR CUENTA		/////////////////

Datos_Cuenta Cargar_Datos(Nodo *p);

Nodo *Crea_Final()
{
	char resp;
	Nodo *p, *t, *q;
	// Datos_Cuenta Cargar_Datos(Nodo *p);

	p = new Nodo();
	p->Dato = Cargar_Datos(p);
	p->liga = NULL;
	t = p;

	fflush(stdin);
	cout<<"\n\n Desea crear otra cuenta: (y/n)\n >> ";
	cin>>resp;

	while((resp == 'y') || (resp == 'Y'))
	{
	 	q = new Nodo();
	    q->Dato = Cargar_Datos(p);
		q->liga = NULL;
		t->liga = q;
		t = q;

		fflush(stdin);
	    cout<<"\n\n Desea crear otra cuenta: (y/n)\n >> ";
		cin>>resp;
	}
	
return p;  
} 


Datos_Cuenta Cargar_Datos(Nodo *p)
{
	Datos_Cuenta Dato;
	long generar_numero_cuenta(Nodo *p);

	system("cls");
	fflush(stdin);
	cout<<"\n [+] Creando Cuenta Nueva\n";
	cout<<"\n Ingrese nombre de la cuenta: ";
	getline(cin, Dato.nombre_cuenta);	
	
	fflush(stdin);
	cout<<" Tipo de cuenta: ";
	getline(cin, Dato.tipo_cuenta);	

	cout<<" Saldo: ";
	cin>>Dato.saldo_cuenta;

	Dato.numero_cuenta = generar_numero_cuenta(p);
	cout<<" Numero de cuenta generada:\t N"<< char(167) <<"[ "<< Dato.numero_cuenta << " ]";

return Dato;
}


long generar_numero_cuenta(Nodo *p)
{
	long numero_generado;
	bool veri;
	Nodo *q = p;

	if(p->liga == NULL){ // si es la primera cuenta
		srand(time(NULL));
		numero_generado = MIN + rand() % ((MAX+1) - MIN);
	}else{ // si hay mas buscar si existe
		do{	
			veri = false; //actualizar al repetir el ciclo
			srand(time(NULL));
			numero_generado = MIN + rand() % ((MAX+1) - MIN);

			while((q != NULL) && (veri == false)){ //buscando
				
				if (q->Dato.numero_cuenta  == numero_generado)
					veri = true;

				q = q->liga;
			}

		} while (veri == true);
	}

return numero_generado;
}


Nodo *Inserta_Final(Nodo *p)
{
	Nodo *q, *t;

	for(t = p; t->liga != NULL ; t = t->liga);

	q = new Nodo();
	q->Dato = Cargar_Datos(p);
	q->liga = NULL;
	t->liga = q;

return p;
}



//////////////// DEPOSITAR EN UNA CUENTA //////////////////
void Depositar_Cuenta(Nodo *p)
{
	// bool Buscar_Cuenta(Nodo *p, long);
	void Realizar_Deposito(Nodo *p, long);
	long Ncuenta;

	cout<<"\n Ingrese el numero de la cuenta a realizar el deposito: ";
	cin>>Ncuenta;

	if (Buscar_Cuenta(p, Ncuenta))
	{
		system("cls");
		Realizar_Deposito(p, Ncuenta);
	}else
		cout<<"\n El numero de cuenta [ "<<Ncuenta<<" ] no existe";
}

bool Buscar_Cuenta(Nodo *p, long Ncuenta)
{
	for (Nodo *q = p; q != NULL; q = q->liga)
	{
		if (q->Dato.numero_cuenta == Ncuenta)	return true;
		else if(q->liga == NULL) return false;
	}
}

void Realizar_Deposito(Nodo *p, long Ncuenta)
{
	Nodo *q = p;
	float Deposito;

	for (; q != NULL; q = q->liga)
	{
		if (q->Dato.numero_cuenta == Ncuenta)
		{
			cout<<"\n Realizando Deposito a @"<< q->Dato.nombre_cuenta <<endl;
			cout<<"\n Saldo actual:\t$:[ "<< q->Dato.saldo_cuenta <<" ]";
			cout<<"\n\n Ingrese la cantidad que desea depositar: ";
			cin>>Deposito;

			q->Dato.saldo_cuenta += Deposito; // realizando el deposito

			cout<<"\n---------------------------------------------";
			cout<<"\n Nuevo Saldo:\t$:[ "<< q->Dato.saldo_cuenta <<" ]";

			break;
		}
	}
}




//////////////// RETIRO EN UNA CUENTA //////////////////
void Retirar_Cuenta(Nodo *p)
{
	// bool Buscar_Cuenta(Nodo *p, long);
	void Realizar_Retiro(Nodo *p, long);
	long Ncuenta;

	cout<<"\n Ingrese el numero de la cuenta a realizar el retiro: ";
	cin>>Ncuenta;

	if (Buscar_Cuenta(p, Ncuenta))
	{
		system("cls");
		Realizar_Retiro(p, Ncuenta);
	}else
		cout<<"\n El numero de cuenta [ "<<Ncuenta<<" ] no existe";
}


void Realizar_Retiro(Nodo *p, long Ncuenta)
{
	Nodo *q = p;
	float Retiro;

	for (; q != NULL; q = q->liga)
	{
		if (q->Dato.numero_cuenta == Ncuenta)
		{
			cout<<"\n Realizando Retiro a @"<< q->Dato.nombre_cuenta <<endl;
			cout<<"\n Saldo actual:\t$:[ "<< q->Dato.saldo_cuenta <<" ]";
			cout<<"\n\n Ingrese la cantidad que desea retirar: ";
			cin>>Retiro;

			if (Retiro > q->Dato.saldo_cuenta)
				cout<<"\n Saldo insuficiente para realizar el retiro";
			else
				q->Dato.saldo_cuenta -= Retiro; // realizando el retiro

			cout<<"\n---------------------------------------------";
			cout<<"\n Nuevo Saldo:\t$:[ "<< q->Dato.saldo_cuenta <<" ]";

			break;
		}
	}
}




//////////////////  REALIZAR CONSULTA DE SALDO DE UNA CUENTA ///////////////////
void Consultar_Cuenta(Nodo *p)
{
    Nodo *q = p;
    long Ncuenta;
    
    cout << "\n Ingrese el numero de cuenta: ";
    cin>>Ncuenta;
    
    if(Buscar_Cuenta(p, Ncuenta))
    {
        for(; q != NULL ; q = q->liga)
        {
            if(q->Dato.numero_cuenta == Ncuenta)
            {
                system("cls");
                cout<< "\n Cuenta @"<< q->Dato.nombre_cuenta <<endl;
                cout<< "\n Saldo actual:\t$:[ "<< q->Dato.saldo_cuenta << " ]"<<endl;
            }
            break;
        }
    }else
        cout << "\n El numero de cuenta [ "<< Ncuenta << " ] no existe" <<endl;
}




////////// IMPRIMIR RESPORTE DE TODAS LAS CUENTAS ///////////
void Imprime_Cuentas(Nodo *p, char opc)
{	
	if(p != NULL){
		int pi = 20;
		int lng;
		system("cls");
		cout << setw(63) << "Registro de Cuentas " 
						 << (opc == 'l'? "Activas" : "Eliminadas") <<endl
			 << "               _______________________________________________________________________________"<<endl
			 << setw(15)  	   << "|"
			 << setw(2+10+3)   << "Nombre" << setw((10-3)+2+1) << "|"
			 << setw(2+10+3)   << " Tipo " << setw((10-3)+2+1) << "|"
			 << setw(3+6)      << "Numero" << setw(3+1)        << "|"
			 << setw(3+10)     << "Saldo " << setw(3+1)        << "|"
			 << endl;

		int color = (opc == 'l')? 138 : 140;
		SetConsoleTextAttribute (screen, color);
		for(Nodo *q = p; q != NULL; q = q->liga){
			cout << setw(15)    << "|"
				 << setw(2+pi) 	<< q->Dato.nombre_cuenta  << setw(2+1)<< "|"
				 << setw(2+pi)  << q->Dato.tipo_cuenta    << setw(2+1)<< "|"
				 << setw(3+6)   << q->Dato.numero_cuenta  << setw(3+1)<< "|"
				 << setw(3+10)  << fixed << setprecision( 2 )<< q->Dato.saldo_cuenta  << setw(3+1)<< "|"
				 << endl;
		}			
	}
	else
		printf("\n\t La lista de cuentas esta vacia");
}



///////////////// 	ELIMINAR UNA CUENTA   ///////////////////////
Nodo *Eliminar_Cuenta(Nodo *p, Nodo **c)
{
	Nodo *q = p, *t;
	long Ncuenta;
	bool BAND;
	void Pone_Cola(Nodo **c, Nodo *q);

	cout<<"\n Ingrese el numero de la cuenta a eliminar: ";
	cin>>Ncuenta;
	
	BAND = Buscar_Cuenta(p, Ncuenta);

	while ((q->Dato.numero_cuenta != Ncuenta) && (BAND == true))
	{
		if(q->liga != NULL)
		{
			t = q;
			q = q->liga;
		}
		else 
			BAND = false;   
	}
      
    if (BAND == false)
    	cout<<"\n El numero de cuenta [ "<<Ncuenta<<" ] no existe";
    else
	{
		if (p == q)	
			p = q->liga;
		else			
			t->liga = q->liga;


		cout<< "\n Cuenta {@"<< q->Dato.nombre_cuenta << "} eliminada" <<endl;

		Pone_Cola(c, q);
	}   

return(p);
}


void Pone_Cola(Nodo **c, Nodo *q)
{
	q->liga = NULL;

	if (*c == NULL)
		*c = q;
	else
	{
		Nodo *t = *c;

		for(; t->liga != NULL; t = t->liga);

		t->liga = q;
	}
}




////////////////   GUARDAR LOS DATOS EN UN ARCHIVO	 ////////////////
void Guardar_Cuentas(Nodo *p, Nodo *c)
{
	fstream archivo_cuentas, archivo_cola;
	Nodo *q = NULL;

	//////////// guardando cuentas activas /////////////
	if (p != NULL)
	{
		archivo_cuentas.open("Archivos//Cuentas_Activas_Bank_Ghenos.dat", ios::out);
		if (archivo_cuentas.fail())
			cout<<"\n Error al crear el archivo par almacenar las cuentas activas";
		else{
			for(; p != NULL ; p = p->liga)
	        {
	        	q = p;

	        	q->Dato.nombre_cuenta = transform_down(q->Dato.nombre_cuenta);
	        	q->Dato.tipo_cuenta = transform_down(q->Dato.tipo_cuenta);

				// escribiendo en el archivo
	        	archivo_cuentas <<  setw(20) << q->Dato.nombre_cuenta << " "
	        					<<  setw(20) << q->Dato.tipo_cuenta   << " "  
	        					<<	setw(6)  << q->Dato.numero_cuenta << " " 
	        					<<	setw(10) << fixed << setprecision( 2 ) 
	        					<< q->Dato.saldo_cuenta  << endl;
	            
	            free(q);
	        }

	        cout<<"\n Cuentas activas guardadas correctamente";
	        archivo_cuentas.close();
		}

	}else
		cout<<"\n No se guardo ninguna cuentas activa, Lista vacia";


	//////////// guardando cuentas eliminadas /////////////
	if (c != NULL)
	{
		archivo_cola.open("Archivos//Cuentas_Eliminadas_Bank_Ghenos.dat", ios::out);
		if (archivo_cola.fail())
			cout<<"\n Error al crear el archivo par almacenar las cuentas eliminadas";
		else{
			for(; c != NULL ; c = c->liga)
	        {
	        	q = c;

	        	q->Dato.nombre_cuenta = transform_down(q->Dato.nombre_cuenta);
	        	q->Dato.tipo_cuenta = transform_down(q->Dato.tipo_cuenta);

				// escribiendo en el archivo
	            archivo_cola << setw(20) << q->Dato.nombre_cuenta << " "
	            			 << setw(20) << q->Dato.tipo_cuenta   << " "   
	            			 <<	setw(6)  << q->Dato.numero_cuenta << " " 
	            			 <<	setw(10) << fixed << setprecision( 2 ) 
	            			 << q->Dato.saldo_cuenta  << endl;
	            
	            free(q);
	        }

	        cout<<"\n Cuentas eliminadas guardadas correctamente";
	        archivo_cola.close();
		}

	}else
		cout<<"\n No se guardaron las cuentas eliminadas, lista vacia";
}



//////////// RECUPERACION DE LAS CUENTAS ACTIVAS Y ELIMINADAS ///////////
void Recargar_Cuentas(Nodo **p, Nodo **c)
{
	fstream archivo_cuentas, archivo_cola;
	Nodo *q = NULL, *t = NULL;

	//////////// Leyendo las cuentas activas /////////////
	archivo_cuentas.open("Archivos//Cuentas_Activas_Bank_Ghenos.dat", ios::in);
	if (archivo_cuentas.fail())
		cout<<"\n No se leyo ninguna cuenta activa";
	else
	{
		*p = new Nodo();
		archivo_cuentas >> (*p)->Dato.nombre_cuenta >> (*p)->Dato.tipo_cuenta 
						>> (*p)->Dato.numero_cuenta >> (*p)->Dato.saldo_cuenta;

		(*p)->Dato.nombre_cuenta = transformSpace((*p)->Dato.nombre_cuenta);
		(*p)->Dato.tipo_cuenta = transformSpace((*p)->Dato.tipo_cuenta);

		(*p)->liga = NULL;
        t = *p;

        while(!(archivo_cuentas.eof()))
		{  // leer mientras no llegue al final del archivo
		 	q = new Nodo();
			archivo_cuentas >> q->Dato.nombre_cuenta >> q->Dato.tipo_cuenta
							>> q->Dato.numero_cuenta >> q->Dato.saldo_cuenta;
			
			if ((q->Dato.nombre_cuenta).empty())
				free(q);
			else
			{
				q->Dato.nombre_cuenta = transformSpace(q->Dato.nombre_cuenta);
	        	q->Dato.tipo_cuenta = transformSpace(q->Dato.tipo_cuenta);

				q->liga = NULL;
				t->liga = q;
				t = q;
			}
		}

        cout<<"\n Cuentas activas leidas correctamente";
        archivo_cuentas.close();
	}


	//////////// Leyendo las cuentas eliminadas /////////////
	archivo_cola.open("Archivos//Cuentas_Eliminadas_Bank_Ghenos.dat", ios::in);
	if (archivo_cola.fail())
		cout<<"\n No se leyo ninguna cuenta eliminada";
	else
	{
		*c = new Nodo();
		archivo_cola >> (*c)->Dato.nombre_cuenta >> (*c)->Dato.tipo_cuenta 
					 >> (*c)->Dato.numero_cuenta >> (*c)->Dato.saldo_cuenta;

		(*c)->Dato.nombre_cuenta = transformSpace((*c)->Dato.nombre_cuenta);
    	(*c)->Dato.tipo_cuenta = transformSpace((*c)->Dato.tipo_cuenta);

		(*c)->liga = NULL;
        t = *c;

        while(!(archivo_cola.eof()))
		{  // leer mientras no llegue al final del archivo
		 	q = new Nodo();
			archivo_cola >> q->Dato.nombre_cuenta >> q->Dato.tipo_cuenta 
						 >> q->Dato.numero_cuenta >> q->Dato.saldo_cuenta;
			
			if ((q->Dato.nombre_cuenta).empty())
				free(q);
			else
			{
				q->Dato.nombre_cuenta = transformSpace(q->Dato.nombre_cuenta);
				q->Dato.tipo_cuenta = transformSpace(q->Dato.tipo_cuenta);

				q->liga = NULL;
				t->liga = q;
				t = q;
			}
		}

        cout<<"\n Cuentas eliminadas leidas correctamente";
        archivo_cola.close();
	}
}

// de espacios a rayita abajo
string transform_down(string palabra)
{
	int posicion = palabra.find( " " );
	// reemplaza todos los espacios con un guion bajo
	while ( posicion != string::npos ){
		palabra.replace( posicion, 1, "_" );
		posicion = palabra.find( " ", posicion + 1 );
	}

return palabra;
}

// de rayita abajo a espacio
string transformSpace(string palabra)
{
	int posicion = palabra.find( "_" );
	// reemplaza todos los espacios con un guion bajo
	while ( posicion != string::npos ){
		palabra.replace( posicion, 1, " " );
		posicion = palabra.find( "_", posicion + 1 );
	}

return palabra;
}


#endif
