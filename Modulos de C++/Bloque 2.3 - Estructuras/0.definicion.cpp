/*
	Estructura: es aquella contenedora de datos que tengan que ver con un párentesco (registro de las bases de datos)

	ejemplo: 

	struct Person
	{
		string nombre;
		int edad;
	};

	almacenan un conjunto de datos o informacion de una sola
	cosa.


	- Estructuras anidadas: se pueden declarar estructuras dentro de otra estructuras. Es una mejor forma para agrupar mejor los elementos.

	ejemplo:

	struct Fecha
	{
		int day, mes, year;
	};


	struct Person
	{
		string nombre;
		int edad;
		struct Fecha nacimiento;
	};

	se declara con la palabra struct seguida del nombre de la estructura.

	aunque no es necesariamente obligatorio.

	* dato curioso: Se recomienda poner nombres a las estructuras
	en singular y con la primera letra en mayuscula.
	Esto no es obligacion, solo es buena practica para diferenciar
	los nombres de estructuras con las variables.

	Uniones: una union es como una estructura, excepto
	que todas las variables miembro ocupan el mismo area de memoria, por lo que solo se puede usar un miembro a la vez.

	Una union podria usarse cuando en un programa necesita trabajar con dos o mas valores (de diferentes tipos), pero solo necesita usar uno de los valores a la vez.
*/