/**************************
Autores:
- Leonardo Velázquez Colin  
- Oscar Alejandro Rodríguez Gómez  
- Juan David Torres Chaparro  

Descripción:
El programa permite al usuario gestionar una red social simulada, donde los usuarios pueden seguir a otros. El programa ofrece las siguientes funcionalidades:

	1.Ingresar datos de los participantes: El usuario puede ingresar los nombres de los participantes y definir a quiénes sigue cada uno.

	2.Mostrar la tabla de seguimiento: Se muestra una matriz que representa las relaciones de seguimiento entre los usuarios.

	3.Identificar tuiteros activos: Un tuitero activo es aquel que tiene un número de relaciones (seguidores + seguidos) igual o mayor al número total de participantes en la red.

	4.Verificar tríos de seguimiento lineal: El programa permite verificar si tres usuarios forman un trío de seguimiento lineal, es decir, si se siguen en una sola dirección (A → B → C → A).

***************************/


#include <iostream>

using namespace std;

const int COLS = 30;

struct datosUsuarios {
	string nombre;
	int cantSeguidos;
	int seguidos[100];
}; // estructura que contiene los datos de cada usuario

struct tuiterosActi {
	string nombreTA;
	int cantRelaciones;
}; // estructura que contiene los datos de los tuiteros activos hallados y su cantidad de relaciones

struct Trios {
	int trio[100];
	bool encontrado = true;
}; // estructura que contiene los datos de los trios de seguimiento a buscar y el indicador de encontrado

// Prototipo
/*
Funcion: permite llenar los datos de los participantes en la red social
Parametros: la cantidad de participantes, un arreglo de datosUsuarios y la tabla
Return: No retorna nada 
*/
void llenarParticipantes (int participantes, datosUsuarios datos[], int tabla[][COLS]);

/*
Funcion: se muestra la tabla de seguimiento al usuario 
Parametros: la cantidad de participantes, un arreglo de datosUsuarios y la tabla
Return: No retorna nada 
*/
void mostrarTabla (int participantes, int tabla[][COLS], datosUsuarios datos[]);

/*
Funcion: verifica que participantes de la red cumplen la condicion de ser tuiteros activos
Parametros: la cantidad de participantes, un arreglo de datosUsuarios, la tabla y un arreglo de tuiterosActi
Return: No retorna nada 
*/
void tuiterosActivos (int participantes, int tabla[][COLS], datosUsuarios datos[], tuiterosActi tActivos[]);

/*
Funcion: verifica si un grupo de 3 personas forman un trio de seguimiento lineal 
Parametros: la cantidad de participantes, un arreglo de datosUsuarios, la tabla y un arreglo de tuiterosActi
Return: una variable de tipo de dato Trios 
*/
Trios trioSeguimiento (int participantes, int tabla[][COLS], datosUsuarios datos[], Trios trioseguimiento);

int main () {
	// Declaracion de variables
	int participantes, estado = 1, opcionMenu, trio[30];
	datosUsuarios datos[100];
	tuiterosActi tActivos[100];
	int tabla[100][COLS];
	bool Repetir = true, verificacion = true;;
	Trios trioseguimiento;

	cout << "\n---------- Twitter ----------" << endl;
	do {
		cout << "\n Participantes en la red social: ";
		cin >> participantes; // se pide la cantidad de participantes presentes en la red social 
		if (participantes <= 1) {
			cout << " Minimo debe haber dos personas en la red social" << endl;
		} // como minimo debe haber 2 personas en la red social 
	} while (participantes <= 1); // en caso de que esto no se cumpla se le pedira al usuario que ingrese una cantidad mayor de participantes
	llenarParticipantes (participantes, datos, tabla); // se llama la funcion que llena los datos de cada participante

	while (Repetir == true) { 
		switch (estado) { // se abre el switch con la variable estado declarada en 1, para que se abra directamente el case 1
			case 1:
				mostrarTabla(participantes, tabla, datos); // se muestra en pantalla la tabla de seguimiento 
				cout << "\n\n\t|| MENU ||" << endl; // se le muestran las opciones del menu al usuario
				cout << "\n 1. Tuiteros Activos" << endl;
				cout << " 2. Trios de seguimiento" << endl;
				cout << " 3. Salir del programa" << endl;
				do {
					cout << "\n Ingrese la opcion que desea: ";
					cin >> opcionMenu; // se le pregunta a cual opcion desea ingresar
					if (opcionMenu < 1 || opcionMenu > 3) {
						cout << " Opcion invalida, repita la operacion" << endl; // si el numero no hace parte de las opciones del menu, se le indicara al usuario
					}
				} while (opcionMenu < 1 || opcionMenu > 3); // en caso de que el numero ingresado no corresponda a una opcion del menu se hara repetir la operacion

				switch (opcionMenu) { // se abre un nuevo switch con la variable opcionMenu, para entrar a cada caso y saltar por el menu 
					case 1:
						estado = 2; // en caso de que se ingrese la opcion 1 del menu la variable estado cambiara a 2
						break;

					case 2:
						estado = 3; // en caso de que se ingrese la opcion 1 del menu la variable estado cambiara a 3
						break;

					default:
						estado = 0; // en caso de que se ingrese la opcion 1 del menu la variable estado cambiara a 4
						break;
				}
				break; // se cierra el case 1 del switch estado


			case 2:
				tuiterosActivos (participantes, tabla, datos, tActivos); // se llama la funcion que muestra los tuiteros activos en la red (quienes entre seguidos y seguidores suman al menos la misma cantidad de participantes en la red social)
				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu; // se le da la opcion al usuario de volver al menu o salir directamente del programa 
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl; // si la opcion ingresada no es valida, se le indica al usuario
					}
				} while (opcionMenu < 1 || opcionMenu > 2); // en caso de que el numero ingresado no corresponda a una opcion valida se hara repetir la operacion
				if (opcionMenu == 1) {
					estado = 1; // si el usuario ingresa la opcion 1 la variable estado se iguala a 1, por lo tanto volvera al menu 
				}
				if (opcionMenu == 2) {
					estado = 0; // si el usuario ingresa la opcion 2 la variable estado se iguala a 0, por lo tanto se ira al default  
				}
				break; // se cierra el case 2 del switch estado

			case 3:
				cout << "\n\n---------- Trios de Seguimiento ----------" << endl;
				if (participantes < 3) {
					cout << "\n No hay participantes suficientes para llevar a cabo la operacion" << endl; // si en la red social no hay al menos 3 participantes no se podra llevar a cabo esta operacion
					verificacion = false;
				}
				if (verificacion == true) {
					cout << "\n Ingrese el numero de los 3 participantes a analizar: " << endl << endl; // se piden los nombres de los 3 participantes a analizar 
					for (int i = 0; i < 3; i++) {
						bool comprobar; // Variable Auxiliar
						do {
							comprobar = true;
							cout << " Ingrese el numero de referencia de algun usuario: ";
							cin >> trioseguimiento.trio[i]; // se pide que se ingrese el numero que identifica al usuario en el programa
							if (trioseguimiento.trio[i] < 0 || trioseguimiento.trio[i] > participantes-1) {
								cout << " El numero de participante ingresado no esta en el sistema" << endl << endl; // si el numero no corresponde a un usuario de la red se le indica al usuario
								comprobar = false;
							}
							if (trioseguimiento.trio[i] == 0 && i == 0 && comprobar == true) {
								comprobar = true; // si el numero ingresado es 0 en la posicion 0 se permitira su entrada directamente para evitar conflictos 
							}
							if (trioseguimiento.trio[i] == 0 && i == 1 && comprobar == true) { // si el numero ingresado es 0 en posicion 1, se entra al if
								if (trioseguimiento.trio[i] != trioseguimiento.trio[i-1]) {
									comprobar = true; // si el 0 es difernte al numero en la posicion anterior se permitira su entrada y se omitira el proceso siguiente con la variable comprobar
								} else {
									cout << " Opcion Invalida, no puede ingresar dos veces la misma persona" << endl << endl;
									comprobar = false; // si no es diferente al numero anterior se pedira que ingrese a otra persona
								}
							}
							if (trioseguimiento.trio[i] == 0 && i == 2 && comprobar == true) { // si el numero ingresado es 0 en posicion 2, se entra al if
								if (trioseguimiento.trio[i] != trioseguimiento.trio[i-1] && trioseguimiento.trio[i] != trioseguimiento.trio[i-2]) {
									comprobar = true; // si el 0 es diferente a los numeros ingresados en la posicion 0 y posicion 1, se permitira su entrada y se omitira el proceso siguiente con la variable comprobar
								} else {
									cout << " Opcion Invalida, no puede ingresar dos veces la misma persona" << endl << endl;
									comprobar = false; // si no es diferente al numero en posicion 0 y posicion 1 se pedira que ingrese a otra persona
								}
							}
							if (trioseguimiento.trio[i] == trioseguimiento.trio[i-1] && trioseguimiento.trio[i] != 0 || trioseguimiento.trio[i] == trioseguimiento.trio[i-2] && trioseguimiento.trio[i] != 0) {
								cout << " Opcion Invalida, no puede ingresar dos veces la misma persona" << endl << endl; // para el caso de los demas numeros, en caso de que se repitan se tiene que repetir la operacion
								comprobar = false;
							}
						} while (comprobar == false); // si la variable comprobar acaba el proceso en false se repite la operacion
					}
					trioseguimiento = trioSeguimiento (participantes, tabla, datos, trioseguimiento); // se llama la funcion que calcula si hay un trio de seguimiento en los usuarios ingresados 
					if (trioseguimiento.encontrado == true) { // si se encuentra el trio de seguimiento se le muestra al usuario
						cout << "\n Los tres participantes de la red social ingresados forman un trio de seguimiento en una sola direccion" << endl; 
					} else { // si no se encuentra el trio de seguimiento se le muestra al usuario
						cout << "\n Los tres participantes de la red social ingresados no forman un trio de seguimiento en una sola direccion" << endl;
					}
				}

				cout << "\n 1. Volver al menu principal" << endl;
				cout << " 2. Salir del programa" << endl;
				do {
					cout << "\n Marque la opcion que desea: ";
					cin >> opcionMenu; // se pregunta si se desea regresar al menu principal 
					if (opcionMenu < 1 || opcionMenu > 2) {
						cout << " Opcion invalida, repita la operacion" << endl;
					}
				} while (opcionMenu < 1 || opcionMenu > 2);
				if (opcionMenu == 1) {
					estado = 1;  // si el usuario ingresa la opcion 1 la variable estado se iguala a 1, por lo tanto volvera al menu 
				}
				if (opcionMenu == 2) {
					estado = 0; // si el usuario ingresa la opcion 2 la variable estado se iguala a 0, por lo tanto se ira al default
				}
				break; // se cierra el case 3 del switch estado

			default: // el default se usa para salir del programa 
				cout << "\n Gracias por acceder a nuestro sistema";
				Repetir = false; // se rompe el while igualando Repetir a false
				break; // se cierra el default
		}
	}
	return 0;
} // se cierra el main

void llenarParticipantes (int participantes, datosUsuarios datos[], int tabla[][COLS]) {
	for (int i = 0; i < participantes; i++) {
		cout << "\n || Participante " << i+1 << " ||";
		cout << "\n Nombre: ";
		cin >> datos[i].nombre; // se piden los datos de cada usuario
	}
	system ("CLS");
	//system ("clear");
	cout << "\n--- Lista integrantes ---" << endl;
	for (int x = 0; x < participantes; x++) {
		cout << " " << x << ". " << datos[x].nombre << endl; // se muestra una lista de las personas en la red social 
	}
	for (int i = 0; i < participantes; i++) {
		do {
			cout << "\n Cuantas personas sigue " << datos[i].nombre << "?: ";
			cin >> datos[i].cantSeguidos; // se pregunta a cuentas personas sigue cada usuario de la red
			if (datos[i].cantSeguidos > participantes - 1) {
				cout << " No puede seguir a mas personas de las que hay en esta red social" << endl << endl; // se restringe el numero de seguidos al numero de personas en la red
			}
		} while (datos[i].cantSeguidos > participantes - 1); // si se imcumplen estas codiciones se repite la operacion

		for(int x = 0; x < datos[i].cantSeguidos; x++) {
			int contador;
			do {
				cout << " Ingrese el numero (No puede seguirse a si mismo): ";
				cin >> contador; // se pide el numero de cada persona que sigue 
				if (contador < 0 || contador >= participantes) {
					cout << " Esa persona no esta en el sistema" << endl << endl; // si el numero ingresado no corresponde a ningun usuario, se repite la operacion
				}
				if (contador == i) {
					cout << " No puede seguirse a si mismo" << endl << endl; // si la persona ingresa su propio numero, se negara la accion, ya que no se puede seguir a si mismo 
				}
			} while (contador < 0 || contador >= participantes || contador == i); // si se incumplen estas condiciones se repite el proceso
			tabla[i][contador] = 1; // si el numero ingresado es valido, en esa posicion se iguala a 1 
		}
	}
} // se cierra la funcion llenarParticipantes

void mostrarTabla (int participantes, int tabla[][COLS], datosUsuarios datos[]) {
	system ("CLS");
	//system ("clear");
	cout << "\n\n---------- TABLA ----------" << endl << endl;
	cout << " || Nombres ||" << endl;
	for (int x = 0; x < participantes; x++) {
		cout << " " << x << ". " << datos[x].nombre << endl; // se muestra la lista de usuarios en la red
	}
	cout << endl;
	cout << "      ";
	for (int j = 0; j < participantes; j++) {
		cout << "[" << j << "] ";
	}
	cout << endl;
	for (int i = 0; i < participantes; i++) {
		cout << "\n [" << i << "]";
		for (int x = 0; x < participantes; x++) {
			cout << " | "<< tabla[i][x];
		}
		cout << " | "<< endl; // se hace el proceso de mostrar la matriz
	}
}

void tuiterosActivos (int participantes, int tabla[][COLS], datosUsuarios datos[], tuiterosActi tActivos[]) {
	bool revisar = false; // Variable auxiliar
	cout << "\n---------- Tuiteros Activos ----------" << endl << endl;
	for (int i = 0; i < participantes; i++) {
		tActivos[i].cantRelaciones = 0;
		for (int x = i; x == i; x++) {
			for (int j = 0; j < participantes; j++) {
				if (tabla[x][j] == 1) {
					tActivos[i].cantRelaciones++;
				} 
				if (tabla[j][x] == 1) {
					tActivos[i].cantRelaciones++;
				} 
			}
		} // se cuentan las personas que sigue y que siguen al usuario
		if (tActivos[i].cantRelaciones >= participantes) { // si el numero de relaciones suman al menos el numero de participantes, se indica al usuario que es un usuario activo
			tActivos[i].nombreTA = datos[i].nombre;
			cout << " " << tActivos[i].nombreTA << " es un tuitero activo, porque tiene relacion con " << tActivos[i].cantRelaciones << " personas" << endl;
			revisar = true;
		}
	}
	if (revisar == false) {
		cout << "\n No hay tuiteros activos en la red" << endl; // si no hay ningun tuitero activo se el emuestra el mensaje al usuario 
	}
} // se cierra la funcion tuiterosActivos

Trios trioSeguimiento (int participantes, int tabla[][COLS], datosUsuarios datos[], Trios trioseguimiento) {
	if (tabla[trioseguimiento.trio[0]][trioseguimiento.trio[1]] == 1 && tabla[trioseguimiento.trio[0]][trioseguimiento.trio[2]] == 0) {
		if (tabla[trioseguimiento.trio[1]][trioseguimiento.trio[2]] == 1 && tabla[trioseguimiento.trio[1]][trioseguimiento.trio[0]] == 0) {
			if (tabla[trioseguimiento.trio[2]][trioseguimiento.trio[0]] == 1 && tabla[trioseguimiento.trio[2]][trioseguimiento.trio[1]] == 0) {
				trioseguimiento.encontrado = true;
				return trioseguimiento; // con if anidados se verifica que el trio sea de seguimiento lineal, si es asi, se retorna un indicador de encontrado
			}
		}
	}
	if (tabla[trioseguimiento.trio[0]][trioseguimiento.trio[2]] == 1 && tabla[trioseguimiento.trio[0]][trioseguimiento.trio[1]] == 0) {
		if (tabla[trioseguimiento.trio[1]][trioseguimiento.trio[0]] == 1 && tabla[trioseguimiento.trio[1]][trioseguimiento.trio[2]] == 0) {
			if (tabla[trioseguimiento.trio[2]][trioseguimiento.trio[1]] == 1 && tabla[trioseguimiento.trio[2]][trioseguimiento.trio[0]] == 0) {
				trioseguimiento.encontrado = true;
				return trioseguimiento; // con if anidados se verifica que el trio sea de seguimiento lineal, si es asi, se retorna un indicador de encontrado
			}
		}
	}
	trioseguimiento.encontrado = false;
	return trioseguimiento;  // si no es un trio de seguimiento lineal se retorna un indicador de encontrado negativo
}
