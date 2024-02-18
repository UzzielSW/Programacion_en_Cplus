#include <iostream>
#include <list>
#include <ostream>
using namespace std;

struct Libro
{
    string nombre;
    string codigo;
    bool disp;
};

list<Libro> libro;

Libro insertarlibro()
{
    string nombre;
    string codigo;
    bool disp = true;

    cout << "\nIngrese el nombre del libro: ";
    getline(cin, nombre);
    cout << "\nIngrese el codigo: ";
    getline(cin, codigo);

    return {nombre, codigo, disp};
}

std::ostream &operator<<(std::ostream &o, const Libro &l)
{
    return o << l.nombre << ' ' << l.codigo << ' ' << l.disp;
}

void mostrarlibros(const list<Libro> &sList)
//                  ~~~~~ <--- La lista es de solo lectura
{
    for (const auto &libro : sList)
    //       ~~~~~~~~~~~~~ <--- por cada Libro en sList...
    {
        cout << libro << '\n';
    }
}

int main()
{
    libro.push_back(insertarlibro());
    libro.push_back(insertarlibro());
    libro.pop_back();

    mostrarlibros(libro);

    return 0;
}
