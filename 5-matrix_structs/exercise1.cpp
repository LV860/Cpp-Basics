/******************************************************************************  
Autores:
- Oscar Alejandro Rodríguez Gómez  
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  

Descripción:
El programa permite al usuario definir una matriz de tamaño personalizado (hasta 30 columnas y un número de filas definido por el usuario). Luego, ofrece un menú con varias opciones para realizar operaciones sobre la matriz, como imprimirla, insertar valores, sumar filas o columnas, encontrar el valor máximo en filas o columnas, y buscar un valor específico en la matriz.

*******************************************************************************/

#include <iostream>

using namespace std;

const int COLS = 30;

void imprimirMatriz (int Matriz[][COLS], int filas, int cols);
void insertarValorFila (int Matriz[][COLS], int filas, int cols);
void insertarValorMatriz (int Matriz[][COLS], int filas, int cols);
void insertarValoresFila (int Matriz[][COLS], int filas, int cols);
void insertarValoresMatriz (int Matriz[][COLS], int filas, int cols);
void sumaValoresFila (int Matriz[][COLS], int filas, int cols);
void sumaValoresColumnas (int Matriz[][COLS], int filas, int cols);
void valorMayorFilasColumnas (int Matriz[][COLS], int filas, int cols);
void buscarDato (int Matriz[][COLS], int filas, int cols);

int main() {
	int estado = 1, opcionMenu, Matriz[30][COLS] = {0}, filas, cols;
	bool regresar = true;
	cout << "\n Ingrese la cantidad de filas de la matriz: ";
	cin >> filas;
	cout << " Ingrese la cantidad de columnas de la matriz: ";
	cin>> cols;
	while (regresar == true){
		switch (estado){
			case 1: 
				system ("CLS");
				//system ("clear");
				cout << "\n ---------- MENU PRINCIPAL ----------" << endl;
				cout << "\n 1. Imprimir la matriz" << endl;
				cout << " 2. Inicializar toda una fila de la matriz con un valor" << endl;
				cout << " 3. Inicializar toda la matriz con un valor deseado" << endl;
				cout << " 4. Inicializar cada elemento de una fila de la matriz" << endl;
				cout << " 5. Inicializar cada elemento de la matriz" << endl;
				cout << " 6. Sumar los valores de una fila de la matriz" << endl;
				cout << " 7. Mostrar la suma de cada una de las columnas de la matriz" << endl;
				cout << " 8. Encontrar el elemento mas grande de cada fila y de cada columna" << endl;
				cout << " 9. Buscar un elemento en la matriz" << endl;
				do{
					cout << "\n Marque la opcion deseada: ";
					cin >> opcionMenu; 
					if (opcionMenu < 1 || opcionMenu > 9){
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 9);
				switch (opcionMenu){
					case 1:
						estado = 2;
						break;
					case 2: 
						estado = 3;
						break;	
					case 3:
						estado = 4;
						break;						
					case 4: 
						estado = 5;
						break;						
					case 5: 
						estado = 6;
						break;						
					case 6:
						estado = 7;
						break;					
					case 7: 
						estado = 8;
						break;					
					case 8: 
						estado = 9;
						break;						
					default:
						estado = 10;
						break;	
				}
				break;
				
			case 2: 
				imprimirMatriz (Matriz, filas, cols);
				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
						}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
						
			case 3: 
				insertarValorFila (Matriz, filas, cols);
				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
			
			case 4:
				insertarValorMatriz (Matriz, filas, cols);
				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
				
			case 5:
				insertarValoresFila (Matriz, filas, cols);
				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
				
			case 6: 
				insertarValoresMatriz (Matriz, filas, cols);
				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
				
			case 7: 
				sumaValoresFila (Matriz, filas, cols);
				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
				
			case 8: 
				sumaValoresColumnas (Matriz, filas, cols);
				cout << "\n\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
				
			case 9: 
				valorMayorFilasColumnas (Matriz, filas, cols);
				cout << "\n\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
				
			case 10: 
				buscarDato (Matriz, filas, cols);
				cout << "\n\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu;
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;
				}
				if (opcionMenu == 2) {
					estado = 0;
				}
				break;
						
			default: 
				regresar = false;
				break;
		}
	}
	return 0;
}
void imprimirMatriz (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	cout << "\n\n---------- TABLA ----------" << endl << endl;
	cout << "      ";
	for (int i = 0; i < cols; i++) {
		cout << "[" << i << "] ";
	}
	cout << endl;
	for (int i = 0; i < filas; i++) {
		cout << "\n [" << i << "]";
		for (int x = 0; x < cols; x++) {
			cout << " | "<< Matriz[i][x];
		}
		cout << " | "<< endl;
	}
}
void insertarValorFila (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	int filaCambio, valorCambio;
	do{
		cout << "\n Cual fila desea cambiar?(Hay hasta " << filas << " disponibles): " ;
		cin >> filaCambio;
		if (filaCambio < 0 || filaCambio >= filas){
			cout << " Esa fila no hace parte de la matriz" << endl;
		}
	} while (filaCambio < 0 || filaCambio >= filas);
	cout << " Que valor desea ingresar?: ";
	cin >> valorCambio;
	for (int i = 0; i < filas; i ++){
		if(i == filaCambio){
			for (int x = 0; x < cols; x++){	
				Matriz[i][x] = valorCambio;
			}	
		}	
	}
}
void insertarValorMatriz (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	int valorCambio;
	cout << "\n Que valor desea ingresar a toda la matriz?: ";
	cin >> valorCambio;
	for (int i = 0; i < filas; i ++){
		for (int x = 0; x < cols; x++){	
			Matriz[i][x] = valorCambio;
		}	
	}
}
void insertarValoresFila (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	int filaCambio, valorCambio;
	do{
		cout << "\n Cual fila desea cambiar?(Hay de 0 - " << filas-1 << " disponibles): " ;
		cin >> filaCambio;
		if (filaCambio < 0 || filaCambio >= filas){
			cout << " Esa fila no hace parte de la matriz" << endl;
		}
	} while (filaCambio < 0 || filaCambio >= filas);
	for (int i = 0; i < filas; i++){
		for (int x = 0; x < cols; x++){	
			if (i == filaCambio){
				cout << " Que valor desea ingresar en la posicion (" << i << ", " << x << ")?: ";
				cin >> valorCambio;	
				Matriz[i][x] = valorCambio;
			}
		}
	}
}
void insertarValoresMatriz (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	int valorCambio;
	for (int i = 0; i < filas; i++){
		for (int x = 0; x < cols; x++){	
			cout << " Que valor desea ingresar en la posicion (" << i << ", " << x << ")?: ";
			cin >> valorCambio;	
			Matriz[i][x] = valorCambio;
		}
	}
}
void sumaValoresFila (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	int filaCambio, suma = 0;
	do{
		cout << "\n De cual fila desea sumar los valores?(Hay de 0 - " << filas-1 << " disponibles): " ;
		cin >> filaCambio;
		if (filaCambio < 0 || filaCambio >= filas){
			cout << " Esa fila no hace parte de la matriz" << endl;
		}
	} while (filaCambio < 0 || filaCambio >= filas);
	for (int i = 0; i < filas; i++){
		for (int x = 0; x < cols; x++){	
			if (i == filaCambio){	
				suma = suma + Matriz[i][x];
			}
		}
	}
	cout << "\n La suma de los valores de la fila seleccionada es: " << suma << endl;
}
void sumaValoresColumnas (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	int suma = 0;
	for (int i = 0; i < cols; i++){
		for (int x = 0; x < filas; x++){	
			suma = suma + Matriz[x][i];
		}
		cout << "\n La suma de los valores de la columna " << i << " es: " << suma;
		suma = 0;
	}
}
void valorMayorFilasColumnas (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	for (int i = 0; i < filas; i++){
		int numMayorFilas = 0, numMayorCols = 0;
		for (int x = 0; x < cols; x++){
			if (Matriz[i][x] > numMayorFilas){
				numMayorFilas = Matriz[i][x];
			} 
			if (Matriz[x][i] > numMayorCols){
				numMayorCols = Matriz[x][i];
			}
		}
		cout << "\n El mayor valor en la fila " << i << " es: " << numMayorFilas << endl;
		cout << " El mayor valor en la columna " << i << " es: " << numMayorCols << endl;
	}
}
void buscarDato (int Matriz[][COLS], int filas, int cols){
	system ("CLS");
	//system ("clear");
	bool encontrado = false;
	int buscarDato;
	cout << "\n Ingrese el dato que desea buscar en la matriz: ";
	cin >> buscarDato;
	cout << endl;
	for (int i = 0; i < filas; i++){
		for (int x = 0; x < cols; x++){
			if (Matriz[i][x] == buscarDato){
				cout << " El dato se encuentra en la fila " << i << " y columna " << x << endl;
				encontrado = true;
			}
		}
	}
	if (encontrado == false){
		cout << " El dato no se encontro en la matriz" << endl;
	}
}
