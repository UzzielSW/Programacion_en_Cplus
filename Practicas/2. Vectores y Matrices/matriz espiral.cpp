#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
  /*
    Declare e inicialice las dimensiones de la matriz, luego los indices utilizados para la espiral y nuestra dirección actual.
  */
  int n, m, j = 0, k = 0;
  enum {down, right, up, left} d = down;

  cout << "Ingrese el tamano de fila y columna: " << flush;
  cin >> n >> m;
  cout << endl;

  // Verifique que las dimensiones de la matriz sean razonables y, si no, por defecto sea 5x5.
  if (n < 0 || n > 30)
    n = 5;
  if (m < 0 || m > 30)
    m = 5;

  // inicializando la matriz.
  int ary[30][30];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ary[i][j] = 0;

// Para el numero de celdas en la matriz, almacene el valor y calcule la siguiente celda
  for (int i = 1; i <= n * m; i++) 
  {
    // Almacenar el numero actual en la celda actual.
    ary[j][k] = i;

    /*
      Si nos dirigimos hacia abajo y no hemos llegado al final de la columna o una celda ya rellenada, la siguiente celda esta abajo. De lo contrario, cambie de dirección a la derecha
    */
    if (d == down)
      if (j < (n - 1) && ary[j+1][k] == 0)
        j++;
      else
        d = right;

    // Si nos dirigimos a la derecha y no hemos llegado al final de la fila o a una celda ya rellenada, la siguiente celda es la correcta. De lo contrario, cambie la dirección hacia arriba.
    if (d == right)
      if (k < (m - 1) && ary[j][k+1] == 0)
        k++;
      else
        d = up;

    // Si nos dirigimos hacia arriba y no hemos alcanzado el inicio de la columna o una celda ya rellenada, la siguiente celda está arriba. De lo contrario, cambie de dirección a la izquierda.
    if (d == up)
      if (j > 0 && ary[j-1][k] == 0)
        j--;
      else
        d = left;

    // Si nos dirigimos a la izquierda y no hemos alcanzado el inicio de la fila o una celda ya rellenada, la siguiente celda se deja una. De lo contrario, cambie la dirección hacia abajo y la siguiente celda está hacia abajo una.
    if (d == left)
      if (k > 0 && ary[j][k-1] == 0)
        k--;
      else 
      {
        d = down;
        j++;
      }
  }

  // mostrando matriz.
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < m; j++)
      cout << setw(4) << ary[i][j];
    cout << endl;
  }

  return 0;
}