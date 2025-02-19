/****************************************************************************************************************************************
Autores:
- Oscar Alejandro Rodríguez Gómez  
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  

Descripción:
En matemáticas, existen dos diferentes tipos de progresiones: la aritmética y la geométrica. 

- La **progresión aritmética** es la sucesión de números que se genera al sumar un factor constante de forma sucesiva.
  - Ejemplo: 1, 4, 7, 10, 13, 16, ... es una progresión aritmética con factor 3, ya que a cada elemento se le suma 3 para obtener el siguiente.

- La **progresión geométrica** es la sucesión de números que se genera al multiplicar un factor constante de forma sucesiva.
  - Ejemplo: 3, 15, 75, 375, 1875, ... es una progresión geométrica con factor 5, ya que cada elemento se multiplica por 5 para obtener el siguiente.

Se solicita implementar las siguientes funciones:
1. `progresionAritmetica`: Recibe un número de inicio, un factor y un tamaño de progresión, y genera la progresión aritmética.
2. `progresionGeometrica`: Recibe un número de inicio, un factor y un tamaño de progresión, y genera la progresión geométrica.
3. `progresiones`: Recibe los mismos parámetros y genera un único arreglo intercalando ambas progresiones.

Ejemplo:
Con un número de inicio **2**, un factor de **4** y un tamaño de **5**:
- Progresión aritmética: **2, 6, 10, 14, 18**
- Progresión geométrica: **2, 8, 32, 128, 512**
- Intercalado: **2, 2, 6, 8, 10, 32, 14, 128, 18, 512**
*******************************************************************************************************************************************/
#include <iostream>

using namespace std;

/*
Funcion: Se calcula la progresion aritmetica de un numero
Parametros: el numero, el factor de pregresion, el arreglo donde se guardaran los resultados y el tamaño del arreglo
Return: No retorna nada porque los arreglos no se pueden retornar
*/
void progresionAritmetica (int num, int factor, int tamano, int pArit[]);

/*
Funcion: Se calcula la progresion geometrica de un numero
Parametros: el numero, el factor de progresion, el arreglo donde se guardaran los resultados y el tamaño del arreglo
Return: No retorna nada porque los arreglos no se pueden retornar
*/
void progresionGeometrica (int num, int factor, int tamano, int pGeom[]);

/*
Funcion: Se unen las progresiones aritmetica y geometrica en un solo arreglo
Parametros: el numero, el factor de progresion, los dos arreglos donde se guardaron los resultados anteriores y el tamaño del arreglo
Return: No retorna nada porque los arreglos no se pueden retornar
*/
void progresiones (int num, int factor, int tamano, int pArit[], int pGeom[]);

int main ()
{
  // Declaracion 
  int num, tamano, factor, pArit[100], pGeom[100];

  // Se piden todos los datos al usuario
  cout << "Bienvenido al programa que calcula la progresion aritmetica y geometrica" << endl << endl;

  cout << "Ingrese el numero de inicio: ";
  cin >> num;

  cout << "Ingrese el factor de progresion: ";
  cin >> factor;

  cout << "Ingrese el tamano de progresion: ";
  cin >> tamano;

  cout << "\nProgresion Aritmetica: ";
  progresionAritmetica (num, factor, tamano, pArit); // Se llama la funcion que calcula la progresion aritmetica de un numero

  cout << "\nProgresion Geometrica: ";
  progresionGeometrica (num, factor, tamano, pGeom); // Se llama la funcion que calcula la progresion geometrica de un numero

  cout << "\nUnion de Progresiones: ";
  progresiones (num, factor, tamano, pGeom, pArit); // Se llama la funcion que une la progresion aritmetica y geomrtrica de un numero en un mismo arreglo

  return 0;
}

void progresionAritmetica (int num, int factor, int tamano, int pArit[]) {
  for (int i = 0; i < tamano; i++){
      
    if (i == 0){  
	num = num; // Se guarda el numero ingresado por el usuario
	} else {
	  num = num + factor; // Se calcula el numero acumulado mas el factor de progresion las veces que indique el tamaño  
	}
      
    pArit[i] = num; // Se iguala cada posicion del arreglo al numero que se calcule en cada ciclo 
    cout << pArit[i] << " "; // Se le muestra al usuario el valor del arreglo en cada posicion 
    }
} // se cierra la funcion progresionAritmetica

void progresionGeometrica (int num, int factor, int tamano, int pGeom[]) {
  for (int i = 0; i < tamano; i++) {
      
    if (i == 0) {
	  num = num; // Se guarda el numero ingresado por el usuario
	} else {
	  num = num * factor; // Se calcula el numero acumulado multiplicado por el factor de progresion las veces que indique el tamaño
	}
      
    pGeom[i] = num; // Se iguala cada posicion del arreglo al numero que se calcule en cada ciclo 
    cout << pGeom[i] << " "; // Se le muestra al usuario el valor del arreglo en cada posicion 
    }
} // se cierra la funcion progresionGeometrica

void progresiones (int num, int factor, int tamano, int pGeom[], int pArit[]) {
  int Unionprogresiones[100], b = 0; // variables auxiliares
   
  for (int i = 0; i < tamano * 2; i += 2) { // el tamaño se multiplica por 2, ya que al unir los dos arreglos el tamaño se duplica
                                            // se pone i+=2 para que se salte en dos las posiciones y no se sobreescriban elementos en el arreglo    
    Unionprogresiones[i] = pArit[b]; // se iguala en la primera posicion del arreglo progresiones, el primer elemento del arreglo de progresion aritmetica    
    Unionprogresiones[i + 1] = pGeom[b]; // se iguala en la posicion i+1 del arreglo progresiones, el primer elemento del arreglo de progresion geometrica

    cout << Unionprogresiones[i] << " " << Unionprogresiones[i + 1] << " "; // se le muestra al usuario los elementos dentro del arreglo
    b++; // se aumenta la variable b que sirve como contador para los arreglos 
  }
} // se cierra la funcion progresiones
