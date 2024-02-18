# Pilares de la programacion orientada a objetos.

- Abstraccion
- Encapsulamiento
- Herencia
- Polimorfismo

## Conceptos basicos

* Clases

  > Una clase es una abstraccion que hacemos de nuestra experiencia sensible. El ser humano tiende a agrupar seres o cosas con caracteristicas similares en grupos o clases o generos.

* Objeto

  > es una instancia(creacion) de una clase. asociando esto con la realidad es algo con un conjunto de atributos(caracteristicas) unicas, y metodos (acciones) que este objeto realiza.

* Abstraccion

  > Proceso mental de extraccion de las caracteristicas esenciales de algo(lo mas importante o necesario), ignorando los detalles superfluos.

* Encapsulacion

  > proceso por el cual ocultamos(protegemos) los datos producto de la Abstraccion.

* Herencia

  > es donde una clase nueva se crea a partir de una existente, heredando sus atributos y metodos.

* Polimorfismo

  > es aquella cualidad que posees los objetos para responder de una manera diferente ante el mismo metodo(accion).

* Constructores

  > son llamados al momento de instanciar el objeto de la clase. son los inicializadores de los atributos de la clase.

* Instanciar

  > si aun no te ha quedado claro es el proceso de creacion de un objeto… En el momento de programar es cuando le damos **new** a una clase o cuando lo declaramos una variable (dependiendo del lenguaje). es el proceso en el que se reserva la memoria necesaria para comenzar a utilizar ese espacio de memoria.
  >
  > es donde las variables son inicializadas en 0 por asi decirlo. cuando le das vida al objeto de la clase.

* Destructores

  > son llamados despues de crear un objeto para eliminarlo. (elimina el espacio en memoria de la variable).



----

Forma de declarar una clase:

```c++
class ClassName
{
	//atributos y metodos
};
```


> aunque no es obligatorio se recomienda que el nombre de la clase comience con una letra mayuscula y que sea en singular.

Ejemplo de la declaracion de una clase para un circulo.

```c++
class Circulo
{
	private:
    double radio;
    
    public:

    Circulo() //constructor de la clase
    {
        this.radio = 0; //inicializando el valor del radio
    }

    void SetRadio(double r) //establecer el valor del radio
    {
        radio = r;
    }
    
    double GetArea()
    {
        return PI * pow(radio, 2);
    }
    
    //tener presente que PI es una variable de la clase math.h al igual que el metodo pow() que es para calcular el potencial(^).
};
```


Declaracion y uso de la clase en el main()

```c++
Circulo circ1, circ2; //declaracion (instancia)

//estableciendo los valores con el metodo
circ1.SetRadio(1);
circ2.SetRadio(2.5);

//ahora usamos metodo para calcular el area de cada circulo

cout<<"\n Area de circulo 1: "<<circ1.GetArea()
    <<"\n Area de circulo 2: "<<circ2.GetArea();

```

* Definiendo metodos de la clases
> Los metodos se pueden definir dentro o fuera de la declaracion de la clase.
>
> Cuando el cuerpo de un metodo es muy largo, se debe poner un prototipo del metodo en la declaracion de la clase, en lugar de la definicion.
>
> La definicion del metodo se coloca fuera de la declaracion de la clase o en un archivo separado.



Dentro de la declaracion de clase, las funciones serian reemplazadas por los siguientes prototipos:

```c++
void SetRadio(double);
double GetArea();
```

Ubicariamos una seccion de implementacion que contiene las definiciones de los metodos:

```c++
void Circulo::SetRadio(double r)
{
	radio = r;
}
    
double Circulo::GetArea()
{
    return PI * pow(radio, 2);
}
```

* Contructores

    >   Es un miembro publico especial que se llama automaticamente cuando se crea un objeto de clase. Si el programador no escribe un contructor, C++ proporciona uno automaticamente, se ejecuta cada vez que tu programa define un objeto. El contructor debe tener el mismo nombre que la clase, ademas no debe tener ningun tipo de retorno.
    >
    >   El contructor puede escribirse como una funcion en linea (como se escribio en la definicion de la clase del ejemplo anterior) o puede tener solo un prototipo colocado en la declaracion de la clase y definirse fuera de la clase. Ejemplo:

```c++
Demo::Demo()
{
	//incializar atributos...
}

//Cualquier metodo miembro de una clase puede estar sobrecargado,incluido el contructor, siempre que cada contructor tenga una lista de parametros diferentes, el compilador puede diferencialos.

Demo::Demo(int n)
{
    edad = n;
}
```