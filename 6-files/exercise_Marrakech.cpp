/***
Grupo: 2
Autores: 
  - Leonardo Velazquez Colin
  - Oscar Rodriguez Gomez
  - Juan David Torres bb
Fecha: 8 de Mayo de 2022
 Version: 1.0
¿Que hace el programa?
- El programa es una representacion del juego de mesa Marroqui llamado "Marrakech" en el cual pueden participar multiples
jugadores. El juego se desarrolla en un tablero elegido por los usuarios (10 x 10 o 20 x 20) en donde cada jugador debe 
mover a Assam en cualquier direccion y colocar alfombras, con el objetivo de ganar prestigio y dinero.
**/
#include <iostream> // esta libreria sirve para usar el namespace std
#include <stdlib.h> // para el contador del random 
#include <time.h> // para el timer del srand 
#include <fstream>
using namespace std; // para no usar el std:: en cada namespace

const int FILAS = 30;	// se declaran las filas de la matriz con una variable entera constante  
const int COLUMNAS = 30; // se declaran las columnas de la matriz con una variable entera constante  

struct Alfombra {
  int coordenadaFila;
  int coordenadaCol;
}; // La estructura Alfombra contiene las variables (coordenadas) que permiten ubicar las alfombras en el tablero de juego. 


struct Jugador {
  Alfombra alfombra[100];
  string nombre;
  int cant_moneda;
  int cant_alfombra;
  int dado;
  bool eliminado;
}; // La estructura Jugador contiene un arreglo de la estrcutura Alfombra, que corresponden a las alfombras de cada jugador. Tambien contiene el nombre del jugador, la cantidades de monedas y la cantidad de alfomabras que contiene.  

struct Tablero {
	int tablero[FILAS][COLUMNAS];
	int Tam_filas;
	int Tam_columnas;
	int PosFila_Asaam;
	int PosCol_Asaam;
	int total_alfombras;
	int guardarPosicion;
	bool verificarGanador;
	
}; // La estructura Tablero contiene la matriz tablero, el tamaño de las filas y columnas de la matriz tablero (en ese momento), las coordenadas (x,y) de la ficha Asaam y el total de las alfombras (de todos los jugadores). 


// Prototipos de las funciones
/*
Funcion: Llenara el arreglo de jugadores con los datos de las personas que participaran en el juego
Parametros: El indice del jugador  
Return: Una estrutura Jugador
*/
Jugador llenar_datos_jugador (int indice_jugador);

/*
Funcion:  Sirve para volver a lanzar los dados cuando hay un empate, y determinar el orden de movie
Parametros: Los dados empatados, sus posiciones, un arrglo tipo Jugador y la cantidad de jugadores 
Return: vacio
*/
void desempateDado (int empatados, int posiciones, Jugador jugador[], int cant_jugadores);

/*
Funcion: Imprime el tablero de juego 
Parametros: la variable tableros de tipo Tablero y la dificultad escogida por el usuario  
Return: Retorna los cambios hechos en la variable tableros
*/
Tablero mostrarTablero(Tablero tableros, int Dificultad, int cant_jugadores);

/*
Funcion: Elimina un jugador de la partida y quita las alfombras de ese jugador  
Parametros: un arreglo de tipo Jugador, una variable tipo Tablero, la cantidad de jugadores que participan en la partida y el indice del jugador que se quiere eliminar
Return: Retorna los cambios realizados a la variable tableros
*/
Tablero eliminarJugador (Jugador jugador[], Tablero tableros, int cant_jugadores, int indice_jugador);

/*
Funcion: Realiza el proceso a llevar a cabo para cada jugador en cada uno de sus turnos
Parametros: una arreglo tipo Jugador, el indice del jugador que realizara su proceso, una variable tipo Tablero, la cantidad de jugadores, una variable alfombras y la dificultad ingresada por el usuario  
Return: Retorna los cambios realizados a la variable tableros
*/
Tablero turnoJugador (Jugador jugador[], int indice_jugador, Tablero tableros, int cant_jugadores, Alfombra alfombras, int dificultad);

/*
Funcion: Determina quien es el ganador de la partida
Parametros: un arreglo de tipo Jugador, la cantidad de jugadores y una variable tipo Tablero  
Return: Retorna un entero
*/
int definirGanador (Jugador jugador[], int cant_jugadores, Tablero tableros);

/*
Funcion: Realizara todo el proceso del juego, desde preguntar la dificultad hasta la ubicacion delas alfombras
Parametros: los arreglos de tipo Jugador y de tipo H_juegos, la dificultad elegida por el jugador y la cantidad de jugadores que participaran en la partida
Return: vacio
*/
void Juego (int dificultad, Jugador jugador[], int cant_jugadores, Tablero tableros, Alfombra alfombras, int contador_partidas);


/*
Funcion: Muestra el historial de juegos, con el nombre de los ganadores
Parametros: los arreglos de tipo Jugador y de tipo H_juegos, y un contador de partidas
Return: No retorna nada 
*/
void Historial_juego (Jugador jugador, int contador_partidas);

/*
Funcion: Muestra al usuario las reglas del juego 
Parametros: no tiene parametros de entrada
Return: no retorna nada 
*/
void Reglas_juego ();

int main (){
    srand(time(NULL));
  // Declaracion 
  int opcion_menu, estado = 1, regresar_menu, CantJugadores, ContadorPartidas = 0, Dificultad;
  bool FinJuego = false; // Se inicializa la variable FinJuego como falsa
  Jugador jugador[100]; // Se hace un arreglo de la estrucutura Jugador
  Alfombra alfombras;
  Tablero tableros; 
  tableros.tablero[FILAS][COLUMNAS] = {0};

  ifstream archivoHistorial_Juegos;
  fstream ArchivoHistorial_Juegos;
  string linea;
          ArchivoHistorial_Juegos.open("Historial.txt",ios::out);
    if (ArchivoHistorial_Juegos.is_open()){
        ArchivoHistorial_Juegos<<"\nHistorial del juego"<<endl; 
    }else{
        cout<<"No se puedo abrir el archivo"<<endl;
    }
  
  while (FinJuego == false) { // Mientras que la variable FinJuego sea falsa, el program continua.
    //system ("CLS");
	  system ("clear"); // limpia el screem del cmd
      switch (estado){ // Se inicia el switch estado.

	    case 1:	// Cuando el usuario ingrese a la opcion 1 del menu podrC! iniciar una nueva partida de Marrakech con varios participantes
        cout << "\n\n\t|| Marrakech ||" << endl;
        cout << "\n---------- Menu Principal ----------" << endl;
        cout << "\n 1. Inicio" << endl;
        cout << " 2. Historial de Juegos." << endl;
        cout << " 3. Reglas del Juego." << endl;
        cout << " 4. Salir del Juego." << endl;
        do {
	        cout << "\nIngrese la opcion: ";
	        cin >> opcion_menu;
	        if (opcion_menu < 1 || opcion_menu > 4){
	          cout << "Opcion invalida, ingrese nuevamente." << endl;
	        }
	      } while (opcion_menu < 1 || opcion_menu > 4);	// Con el do while se verifica que la opcion ingresada este dentro de las opciones del menu

      switch (opcion_menu){
	  case 1:
	    estado = 2; // Si el usuario escoge la opcion 1 del menu (Inicio), el estado se vuelve 2, y pasa al case 2 del switch estado
      break;
    case 2:
      estado = 3; // Si el usuario escoge la opcion 2 del menu (Historial de Juegos.), el estado se vuelve 3, y pasa al case 3 del switch estado
      break;
    case 3:
      estado = 4; // Si el usuario escoge la opcion 3 del menu (Reglas del Juego.), el estado se vuelve 4, y pasa al case 4 del switch estado
      break;
    case 4: 
      estado = 0; // Si el usuario escoge la opcion 4 del menu (Salir del Juego.), el estado se vuelve 0, y pasa al default del switch estado
      break; // falta default
      }
    break; // se ternima el case 1 del switch estado

	case 2:		// Cuando el usuario ingrese a la opcion 1 del menu podra iniciar una nueva partida de Marrakech con varios participantes
	  cout << "\n\n || Marrakech ||" << endl;
	  do{
    	  cout << "\n Ingrese la cantidad de jugadores: ";
    	  cin >> CantJugadores;
    	  if (CantJugadores < 2){
    	     cout << " Como minimo deben participar dos jugadores" << endl;
    	  }
	  }while (CantJugadores < 2);
	  cout << "\n Indique el nombre de cada jugador" << endl;
	  for (int i = 0; i < CantJugadores; i++){
	    jugador[i] = llenar_datos_jugador(i); // Se llenan los datos de todos los jugadores.
	    }
    system ("clear");
    //system ("CLS");
	  cout << "\n---------- Dificultad ----------" << endl;
	  cout << "\n 1. Facil \n 2. Dificil \n 3. Volver al menu principal" << endl;
	  do {
	      cout << "\nMarque la opcion: ";
	      cin >> Dificultad; // pide la variable de dificultad para evaluarla y conocer si es dificil o facil
	      if (Dificultad < 1 || Dificultad > 3) {
		      cout << "Opcion invalida, ingrese nuevamente." << endl;
		    } // mostrará si el valor no corresponde
	  } while (Dificultad < 1 || Dificultad > 3);  // Con el do while se verifica que la opcion ingresada este dentro de las opciones 
    if (Dificultad == 1) {
		tableros.PosFila_Asaam = 4; // se ubica Assam en el centro del tablero
        tableros.PosCol_Asaam = 5;
        tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = CantJugadores+1; // el valor representativo de Assam sera determinado por la cantidad de jugadores + 1
		}
	if (Dificultad == 2) {
	    tableros.PosFila_Asaam = 9; // se ubica Assam en el centro del tablero
      tableros.PosCol_Asaam = 10;
      tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = CantJugadores+1;// el valor representativo de Assam sera determinado por la cantidad de jugadores + 1
		}
    if (Dificultad == 3) {
		  estado = 1; // Si el usurio ingresa la opcion 3 (Volver al menu principal), el estado se vuelve 1.
		  break; // Se termina el case 2
		}
    	ContadorPartidas++;
	  Juego (Dificultad, jugador, CantJugadores,tableros, alfombras, ContadorPartidas); //Se llama a la funcion Inicio_juego

// Seccion de regreso a menu
    do {
	      cout << "\nIngrese la opcion que desea: " << endl;
	      cout << "1. Volver a jugar" << endl;
	      cout << "2. Regresar al menu" << endl;
	      cin >> regresar_menu; // va a pedir la variable para saber si el jugador quiere volver a jugar o regresar al menú
	      if (regresar_menu < 1 || regresar_menu > 2) {
		      cout << "Opcion invalida, ingrese nuevamente." << endl;
		    } // si la opcíon no corresponde a ninguna opcion pedira que ingrese de nuevo el valor
	  }while (regresar_menu < 1 || regresar_menu > 2); // Con el do while se verifica que la opcion ingresada este dentro de las opciones 
	  if (regresar_menu == 1) {
		  estado = 2; // Si el usuario ingresa la opcion 1 (Volver a jugar), el estado se vuelve 2.
		}
		if (regresar_menu == 2) {
		  estado = 1; // Si el usuario ingresa la opcion 2 (Regresar al menu), el estado se vuelve 1.
		}
	  break; // se termina el case 2 del switch estado

	case 3:		// Cuando el usuario ingrese a la opcion 2 del menu podra acceder al historial de los juegos realizados y conocer a los campeones 
   archivoHistorial_Juegos.open("Historial.txt");
    if (archivoHistorial_Juegos.is_open()){
       while(getline(archivoHistorial_Juegos,linea)){
          cout<<linea<<endl;     
       }
        archivoHistorial_Juegos.close();
    }else{
        cout<<"No se puedo abrir el archivo"<<endl;
    }
	  //Historial_juego (jugador, ContadorPartidas);
      do {
	      cout << "Ingrese la opcion que desea: " << endl;
	      cout << "1. Salir del juego" << endl;
	      cout << "2. Regresar al menu" << endl;
	      cin >> regresar_menu;
	      if (regresar_menu < 1 || regresar_menu > 2) {
		      cout << "Opcion invalida, ingrese nuevamente." << endl;
		    }
	    } while (regresar_menu < 1 || regresar_menu > 2);// Con el do while se verifica que la opcion ingresada este dentro de las opciones 
	    if (regresar_menu == 1) {
		    estado = 5; //Si el usuario ingresa la opcion 1 (Salir del juego"), el estado se vuelve 5, se salta al default.
		  }
		  if (regresar_menu == 2) {
		    estado = 1;//Si el usuario ingresa la opcion 2 (Regresar al menu), el estado se vuelve 1.
		  }
	break; // Se termina el case 3 del switch estado

	case 4:		// Cuando el usuario ingrese a la opcion 3 del menu podra acceder a las reglas del juego para conocer las reglas del mismo. 
	
	  Reglas_juego ();	// se llama la funcion Reglas_juego que muestra la normativa del juego al usuario

// Seccion de regreso a menu
    do {
	      cout << "\nIngrese la opcion que desea: "<<endl;
	      cout << "1. Salir del juego"<<endl;
	      cout << "2. Regresar al menu"<<endl;
	      cin >> regresar_menu;
	      if (regresar_menu < 1 || regresar_menu > 2) {
		      cout << "Opcion invalida, ingrese nuevamente." << endl;
		    }
	  } while (regresar_menu < 1 || regresar_menu > 2); // Con el do while se verifica que la opcion ingresada este dentro de las opciones 
	    if (regresar_menu == 1) {
		  estado = 5; // Si el usuario ingresa la opcion 1 (Salir del juego"), el estado se vuelve 5, se salta al default.
		}
		if (regresar_menu == 2) {
		  estado = 1; // Si el usuario ingresa la opcion 2 (Regresar al menu), el estado se vuelve 1.
		}
	  break; // se termina el case 4 del switch estado

	default:	// Cuando el usuario ingrese a la opcion 4 del menu saldra del sistema del juego 
	  FinJuego = true;	// La variable FinJuego se vuelve falso para que se salga del while y se termine el programa 
	  break; // se termina el default del switch estado
	}
  }
  return 0;
}

Jugador llenar_datos_jugador (int indice_jugador){
  Jugador jugador_d;    // Se crea la variable temporal jugador_d tipo Jugador   
  int MonedasInciales = 5, AlfombrasInciales = 24;
  jugador_d.eliminado = false;
  cout << " || Jugador " << indice_jugador + 1 << " ||: ";
  cin >> jugador_d.nombre;
  jugador_d.cant_moneda = MonedasInciales;
  jugador_d.cant_alfombra = AlfombrasInciales;
  return jugador_d; // Se retorna la variable temporal jugador_d tipo Jugador
}

void desempateDado (int empatados, int posiciones, Jugador jugador[], int cant_jugadores){
  const int CANTIDAD_JUGADORES = cant_jugadores;
  int dados_repetidos, aux_repetidos=0;
  int repetidos[CANTIDAD_JUGADORES];
    for (int i = 0; i < cant_jugadores; i++){
      for (int j = i+1; j < cant_jugadores; j++){
        if (jugador[i].dado == jugador[j].dado && repetidos[j-1] != jugador[j].dado){
        repetidos[i] = jugador[i].dado;
        aux_repetidos++;
        for (int  x = dados_repetidos; x < aux_repetidos; x++){
            while (jugador[x].dado == repetidos[x]){
              jugador[x].dado=1+rand()%6; 
            }
        }
       }
      } 
    }
}

Tablero mostrarTablero (Tablero tableros, int Dificultad, int cant_jugadores){
  if (Dificultad == 1){ // si se eligio jugar en modo facil, se muestra la matriz con su tamano respectivo, y la ubicacion de Assam
    tableros.Tam_filas = 10; // Cuando esta en modo facil las columnas son 10 
    tableros.Tam_columnas = 10; // Cuando esta en modo facil las columnas son 10 

    // Se muestra toda la estructura de la tabla 
    cout << "\n\n\tTABLA" << endl << endl;
    cout << "╔";
    for (int i = 0; i < tableros.Tam_filas; i++){
        if (i < tableros.Tam_filas-1){
        cout << "══";
        cout << "╦";
        } else {
        cout << "══";
        }
    }
    cout << "╗" << endl;
	  for (int i = 0; i < tableros.Tam_filas; i++) {
      cout << "║";
		    for (int j = 0; j < tableros.Tam_columnas; j++) {
			    if (tableros.tablero[i][j] >= 0 && tableros.tablero[i][j] <= 9){
			      cout << tableros.tablero[i][j] << " ║";
		      } else {
		         cout << tableros.tablero[i][j] << "║";   
		      }
		    }
		  if (i < tableros.Tam_filas-1){
		    cout << endl << "╠";
		    for (int x = 0; x < tableros.Tam_columnas; x++){
		      cout << "══";
		      if ( x < tableros.Tam_columnas-1){
		        cout << "╬";
		      } else {
		        cout << "╣";     
		      }
		    }
		    cout << endl;
		  } else {
		    cout << endl;
		  }
	  }
    cout << "╚";
    for (int i = 0; i < tableros.Tam_filas; i++){
      if (i < tableros.Tam_filas-1){
        cout << "══";
        cout << "╩";
      } else {
        cout << "══";
      }
    }
    cout << "╝";
  }

  if (Dificultad == 2){ // si se eligio jugar en modo dificil, se muestra la matriz con su tamano respectivo, y la ubicacion de Assam
    tableros.Tam_filas = 20; // si se eligio el modo dificil las filas son 20
    tableros.Tam_columnas = 20; // si se eligio el modo dificil las columnas son 20
    cout << "\n\n\tTABLA "<< endl;
    
    // Se muestra toda la estructura de la tabla    
    cout << "╔";
    for (int i = 0; i < tableros.Tam_filas; i++){
        if (i < tableros.Tam_filas-1){
        cout << "══";
        cout << "╦";
        } else {
        cout << "══";
        }
    }
    cout << "╗" << endl;
    
	  for (int i = 0; i < tableros.Tam_filas; i++) {
      cout << "║";
	    for (int j = 0; j < tableros.Tam_columnas; j++) {
		    if (tableros.tablero[i][j] >= 0 && tableros.tablero[i][j] <= 9){
			    cout << tableros.tablero[i][j] << " ║";
		    } else {
		      cout << tableros.tablero[i][j] << "║";   
		    }
		  }
		  if (i < tableros.Tam_filas-1){
		    cout << endl << "╠";
		    for (int x = 0; x < tableros.Tam_columnas; x++){
		      cout << "══";
		      if ( x < tableros.Tam_columnas-1){
		        cout << "╬";
		      } else {
		        cout << "╣";     
		      }
		    }
		    cout << endl;
		    } else {
		    cout << endl;
		    }
	  }
    cout << "╚";
    for (int i = 0; i < tableros.Tam_filas; i++){
      if (i < tableros.Tam_filas-1){
        cout << "══";
        cout << "╩";
      } else {
        cout << "══";
      }
    }
    cout << "╝";
  }
  return tableros;
}

Tablero eliminarJugador (Jugador jugador[], Tablero tableros, int cant_jugadores, int indice_jugador){
    cout << " El jugador " << jugador[indice_jugador].nombre << " fue eliminado por quedarse sin monedas" << endl;
    jugador[indice_jugador].eliminado = true;
    for (int i = 0; i < tableros.Tam_filas; i++){
    	for (int x = 0; x < tableros.Tam_columnas; x++){
    		if (tableros.tablero[i][x] == indice_jugador+1){
    			tableros.tablero[i][x] = 0;
			}
		}
	}
	return tableros;
}

Tablero turnoJugador (Jugador jugador[], int cant_jugadores, Tablero tableros, int indice_jugador, Alfombra alfombras, int dificultad){
    // Variable auxiliar
    int direccion, pagar = 0, colocarAlfombra;
   fstream ArchivoHistorial_Juegos;
    mostrarTablero (tableros, dificultad, cant_jugadores);
    // Se muestran los datos del jugador que ejercera su turno
    cout << "\n\n || Turno Jugador " << indice_jugador+1 << " ||" << endl;
    cout << "\n Nombre: " << jugador[indice_jugador].nombre << endl;
    cout << " Monedas Restantes: " << jugador[indice_jugador].cant_moneda << endl;
    cout << " Alfombras restantes: " << jugador[indice_jugador].cant_alfombra << endl;
    cout << "\n || Movimiento de Assam ||" << endl;
    cout << " 1. Arriba\n 2. Derecha\n 3. Abajo\n 4. Izquierda" << endl; 
    do{
      cout << "\n Hacia que direccion desea mover a Assam?: ";
      cin >> direccion; // se pregunta en que direccion desea mover a Assam
      if (direccion < 1 || direccion > 4){
        cout << " Opcion invalida, repita la operacion" << endl; 
      }
    } while(direccion < 1 || direccion > 4); // si la opcion ingresada no es valida se repite la operacion
    jugador[indice_jugador].dado = 1+rand()%6; // se lanza un dado para determinar cuantas casillas se movera a Assam
    cout << "\n El dado arroja que debe mover " << jugador[indice_jugador].dado << " casillas";
    switch (direccion){
      int diferencia; // variable usada para contar las casillas que se deben mover cuando se hace el salto de un extremo a otro
			case 1: // Movimiento hacia arriba 
				if(tableros.PosFila_Asaam-jugador[indice_jugador].dado >=0) { // si el movimiento no sobrepasa los limites del tablero el movimiento se da correctamente
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					tableros.PosFila_Asaam -= jugador[indice_jugador].dado; // restamos el valor del dado a la fila en la que se encuentra Assam para movernos hacia arriba 
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    }
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1;
				} else {
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					jugador[indice_jugador].dado -= tableros.PosFila_Asaam;
					tableros.PosFila_Asaam = tableros.Tam_filas-1;
					tableros.PosFila_Asaam -= jugador[indice_jugador].dado-1;
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    }
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1;
				}
				break;
			case 3: // Movimiento hacia abajo
				if(tableros.PosFila_Asaam + jugador[indice_jugador].dado < tableros.Tam_filas) { // si el movimiento no sobrepasa los limites del tablero el movimiento se da correctamente
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]= tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					tableros.PosFila_Asaam += jugador[indice_jugador].dado;
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    }
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1;
				} else {
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					diferencia = tableros.Tam_filas - tableros.PosFila_Asaam;
					jugador[indice_jugador].dado -= diferencia;
					tableros.PosFila_Asaam = 0;
					tableros.PosFila_Asaam += jugador[indice_jugador].dado;
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    }
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1;
				}
				break;
			case 2: // Movimiento hacia la derecha 
				if(tableros.PosCol_Asaam + jugador[indice_jugador].dado < tableros.Tam_columnas) { // si el movimiento no sobrepasa los limites del tablero el movimiento se da correctamente
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					tableros.PosCol_Asaam += jugador[indice_jugador].dado; // sumamos el valor que salio en el dado, a la posicion de la columna en donde se encuentra Assam  
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    } 
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1;
				}else {
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					diferencia = tableros.Tam_columnas - tableros.PosCol_Asaam;
					jugador[indice_jugador].dado -= diferencia;
					tableros.PosCol_Asaam = 0;
					tableros.PosCol_Asaam += jugador[indice_jugador].dado;
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    }
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1; //se posiciona a Assam
				}
				break;
			case 4: // Movimiento hacia la izquierda
			    if (tableros.PosCol_Asaam - jugador[indice_jugador].dado >= 0) { // si el movimiento no sobrepasa los limites del tablero el movimiento se da correctamente
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					tableros.PosCol_Asaam -= jugador[indice_jugador].dado;
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    }
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1;//se posiciona a Assam
				} else {
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = tableros.guardarPosicion; // se guarda la posicion a donde se movera Assam, para que en caso de que haya una alfombra no se pierda
					jugador[indice_jugador].dado -= tableros.PosCol_Asaam;
					tableros.PosCol_Asaam = tableros.Tam_columnas - 1;
					tableros.PosCol_Asaam -= jugador[indice_jugador].dado - 1; 
					for (int i = 0; i < cant_jugadores; i++){
					    if (tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] > 0){
					        pagar = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam]; // En la variable pagar se guarda el valor que se encuentra en la posicion a donde se movera Assam, para posteriormente analizar si ese valor corresponde a una alfombra
					    }
					}
					tableros.guardarPosicion = tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam];
					tableros.tablero[tableros.PosFila_Asaam][tableros.PosCol_Asaam] = cant_jugadores+1;//se posiciona a Assam
				}
				break;
			default: 
				break;
        }
        mostrarTablero (tableros, dificultad, cant_jugadores);
        
        // Verificar si Assam cayo en una posicion donde hay alfombra
        if (pagar == indice_jugador+1){ // si Assam cae en una posicion donde se encuentre una de las alfombras de propiedad dle
            cout << "\n No debe pagar diezmo porque Assam cayo en una alfombra de su propiedad" << endl;
        }
        if (pagar == 0){
            cout << "\n No debe pagar diezmo porque Assam cayo en una casilla sin alfombra" << endl;
        }
        for (int i = 0; i < cant_jugadores; i++){
            int cant_pagar = 1;
            if (pagar-1 == i && pagar != 0 && pagar != indice_jugador+1){
                cout <<"\n Debe pagar un diezmo al jugador " << jugador[i].nombre << " por la cantidad de ";
                for (int j = 0; j < tableros.Tam_filas; j++){
                    for (int x = 0; x < tableros.Tam_columnas; x++){
                        if (tableros.tablero[j][x] == i+1){
                            cant_pagar++;
                        }
                    }
                }
                cout << cant_pagar << " monedas" << endl;
                if (jugador[indice_jugador].cant_moneda-cant_pagar < 0){
                  int monedasInsuficientes;
                  cout << "\n El jugador no tiene las monedas suficientes para pagar " << endl;
                  cout << " Debe pagar " << cant_pagar << " monedas, pero solo tiene " << jugador[indice_jugador].cant_moneda << " monedas" << endl;
                  monedasInsuficientes = cant_pagar-jugador[indice_jugador].cant_moneda;
                  cant_pagar -= monedasInsuficientes;
                  jugador[indice_jugador].cant_moneda = 0;
                  jugador[i].cant_moneda += cant_pagar;
                  cout << " Monedas Restantes: " << jugador[indice_jugador].cant_moneda << endl;
                }
                if (jugador[indice_jugador].cant_moneda-cant_pagar >= 0){
                  jugador[indice_jugador].cant_moneda -= cant_pagar;
                  jugador[i].cant_moneda += cant_pagar;
                  cout << " Monedas Restantes: " << jugador[indice_jugador].cant_moneda << endl;
                }
                
                if (jugador[indice_jugador].cant_moneda <= 0){
                  tableros = eliminarJugador (jugador, tableros, cant_jugadores, indice_jugador);
                  //mostrarTablero (tableros, dificultad);
                }
            }
        }
        // Declarar ganador en caso de que lo haya
        int ganador = 0;
        for (int j = 0; j < cant_jugadores; j++){
        	if (jugador[j].eliminado == false){
        		ganador++;
        	}
   	 	}
        if (ganador > 0 && ganador < 2){
       		for (int i = 0; i < cant_jugadores; i++){
      			if (jugador[i].eliminado == false){ //Se anuncia al ganador  
        			cout << "\n || GANADOR ||: " << jugador[i].nombre << endl;
			        cout << " Monedas Totales: " << jugador[i].cant_moneda << endl;
				    cout << " Alfombras Restantes: " << jugador[i].cant_alfombra << endl;
			        tableros.verificarGanador = false; 
              //Se guarda el ganador de esta partida en el archivo
              ArchivoHistorial_Juegos.open("Historial.txt",ios::out|ios::app);
                    if (ArchivoHistorial_Juegos.is_open()){
                    ArchivoHistorial_Juegos<<"Ganador : "<<endl;
                     ArchivoHistorial_Juegos<<jugador[i].nombre<<endl; 
                     ArchivoHistorial_Juegos<<"Monedas:"<<jugador[i].cant_moneda<<endl; 
                     ArchivoHistorial_Juegos<<"Alfombras:"<<jugador[i].cant_alfombra<<endl;
                        }else{
                        cout<<"No se puedo abrir el archivo"<<endl;
                        }
              
				}
			}
		}
        
        // Colocar alfombra
        if (tableros.verificarGanador == true){
        	if (jugador[indice_jugador].eliminado == false){
	            cout << "\n || Poner Alfombra ||" << endl;
	            cout << "\n 1. Arriba de Assam\n 2. A la derecha de Assam\n 3. Abajo de Assam\n 4. A la izquierda de Assam" << endl;
	            do {
	                cout << "\n Donde desea colocar la alfombra?: ";
	                cin >> colocarAlfombra;
	                if (colocarAlfombra < 1 || colocarAlfombra > 4){
	                    cout << " Opcion invalida, repita la operacion" << endl;
	                }
	            } while(colocarAlfombra < 1 || colocarAlfombra > 4);
	            alfombras.coordenadaFila = tableros.PosFila_Asaam;
	            alfombras.coordenadaCol = tableros.PosCol_Asaam;
            
	            switch (colocarAlfombra){// Se colocan las alfombras segun escogio el usuario
	                case 1: 
	                    if (alfombras.coordenadaFila-1 >= 0){
	                        alfombras.coordenadaFila -= 1;
	                        tableros.tablero[alfombras.coordenadaFila][tableros.PosCol_Asaam] = indice_jugador+1;//Se cambia la casilla de arriba de assam por el numero del jugador
	                    } else {
	                        alfombras.coordenadaFila = tableros.Tam_filas-1;
	                        tableros.tablero[alfombras.coordenadaFila][tableros.PosCol_Asaam] = indice_jugador+1;//Se cambia la casilla de arriba de assam por el numero del jugador
	                    }
	                    jugador[indice_jugador].cant_alfombra--;
	                    break;  
	                case 2: 
	                    if (alfombras.coordenadaCol+1 < tableros.Tam_columnas){
	                        alfombras.coordenadaCol += 1;
	                        tableros.tablero[tableros.PosFila_Asaam][alfombras.coordenadaCol] = indice_jugador+1;//Se cambia la casilla de la derecha de assam por el numero del jugador
	                    } else {
	                        alfombras.coordenadaCol = 0;
	                        tableros.tablero[tableros.PosFila_Asaam][alfombras.coordenadaCol] = indice_jugador+1;//Se cambia la casilla de la derecha de assam por el numero del jugador
	                    }
	                    jugador[indice_jugador].cant_alfombra--;
	                    break;
	                case 3: 
	                    if (alfombras.coordenadaFila+1 < tableros.Tam_filas){
	                        alfombras.coordenadaFila += 1;
	                        tableros.tablero[alfombras.coordenadaFila][tableros.PosCol_Asaam] = indice_jugador+1;//Se cambia la casilla de abajo de assam por el numero del jugador
	                    } else {
	                        alfombras.coordenadaFila = 0;
	                        tableros.tablero[alfombras.coordenadaFila][tableros.PosCol_Asaam] = indice_jugador+1;//Se cambia la casilla de abajo de assam por el numero del jugador
	                    }
	                    jugador[indice_jugador].cant_alfombra--;
	                    break; 
	                case 4: 
	                    if (alfombras.coordenadaCol-1 >= 0){
	                        alfombras.coordenadaCol -= 1;
	                        tableros.tablero[tableros.PosFila_Asaam][alfombras.coordenadaCol] = indice_jugador+1;//Se cambia la casilla de la izquierda de assam por el numero del jugador
	                    } else {
	                        alfombras.coordenadaCol = tableros.Tam_columnas-1;
	                        tableros.tablero[tableros.PosFila_Asaam][alfombras.coordenadaCol] = indice_jugador+1;//Se cambia la casilla de la izquierda de assam por el numero del jugador
	                    }
	                    jugador[indice_jugador].cant_alfombra--; // se quita una alfombra del total de alfombra que tenia el jugador
	                    break;
	                default:
	                    break;
            	}
       	 	}
		}
    return tableros;
}

// Definir un ganador
int definirGanador (Jugador jugador[], int cant_jugadores, Tablero tableros){
	int ganador = 0, cant_casillas, cant_casillasGanador = 0, contadorGanadores[30];
	bool unicoGanador;
  fstream ArchivoHistorial_Juegos;

	for (int j = 0; j < cant_jugadores; j++){
		cant_casillas = 0;
		if (jugador[j].eliminado == false){
			for (int x = 0; x < tableros.Tam_filas; x++){
				for (int z = 0; z <tableros.Tam_columnas; z++){
					if (tableros.tablero[x][z] == j+1 || tableros.tablero[x][z] == tableros.guardarPosicion){
						cant_casillas++;
					}
				}
			}
			if (cant_casillas > cant_casillasGanador){
				ganador = j;
				cant_casillasGanador = cant_casillas;
				unicoGanador = true;
			}
			if (cant_casillas == cant_casillasGanador){
				if (jugador[j].cant_moneda > jugador[ganador].cant_moneda){
					ganador = j;
					unicoGanador = true;
				}
				if (jugador[j].cant_moneda == jugador[ganador].cant_moneda){
					unicoGanador = false;
				}
			}
		}
	}
	if (unicoGanador == true){
		cout << "\n || GANADOR ||: " << jugador[ganador].nombre << endl;
		cout << " Monedas Totales: " << jugador[ganador].cant_moneda << endl;
		cout << " Alfombras Restantes: " << jugador[ganador].cant_alfombra << endl;

ArchivoHistorial_Juegos.open("Historial.txt",ios::out|ios::app);
    if (ArchivoHistorial_Juegos.is_open()){
        ArchivoHistorial_Juegos<<"Ganador : "<<endl;
        ArchivoHistorial_Juegos<<jugador[ganador].nombre<<endl; 
        ArchivoHistorial_Juegos<<"Monedas:"<<jugador[ganador].cant_moneda<<endl; 
        ArchivoHistorial_Juegos<<"Alfombras:"<<jugador[ganador].cant_alfombra<<endl;
    }else{
        cout<<"No se puedo abrir el archivo"<<endl;
    }
    
	}
	if (unicoGanador == false){
		cout << "\n Hubo un empate multiple, pueden jugar una revancha ;)" << endl;
	}
  return cant_casillas;
}

// Juego
void Juego (int dificultad, Jugador jugador[], int cant_jugadores, Tablero tableros, Alfombra alfombras, int contador_partidas){
    system("clear");
    //system ("CLS");
    tableros.verificarGanador = true;
    string seguir;
    int empatados = 0, posiciones[30], menuRonda;
    Jugador jugador_I; // Se crea la variable temporal jugador_I tipo Jugador
  fstream ArchivoHistorial_Juegos;
     ArchivoHistorial_Juegos.open("Historial.txt",ios::out|ios::app);
    if (ArchivoHistorial_Juegos.is_open()){
        ArchivoHistorial_Juegos<<"\nPartida "<< contador_partidas<<endl;
    }else{
        cout<<"No se puedo abrir el archivo"<<endl;
    }
    cout << "\n---------- Orden de Movimiento ----------" << endl;
    cout << "\n Lanzamiento de dado" << endl;
    for (int i = 0; i < cant_jugadores; i++){
        jugador[i].dado = 1+rand()%6;
    }
    for (int i = 0; i < cant_jugadores; i++){
        Jugador auxJugador;
        for (int x = 0; x < cant_jugadores; x++){
            if (jugador[i].dado > jugador[x].dado){
                auxJugador = jugador[i];
                jugador[i] = jugador[x];
                jugador[x] = auxJugador;
            }
        }
    }
    for (int i = 0; i < cant_jugadores; i++){
        cout << i+1 << ". " << jugador[i].nombre << ": " << jugador[i].dado << endl;
    }

    cout << "\n Presione c y despues enter para continuar: ";
    cin >> seguir;
    for (int i = 0; i < 24; i++){
			tableros = mostrarTablero (tableros, dificultad, cant_jugadores);
        for(int indice_jugador = 0; indice_jugador < cant_jugadores; indice_jugador++){
            if (tableros.verificarGanador == true){
            	if (jugador[indice_jugador].eliminado == false){
                system ("clear");
                //system ("CLS");
                cout << "\n ---------- Ronda " << i+1 << " ----------" << endl;
                tableros = turnoJugador (jugador, cant_jugadores, tableros, indice_jugador, alfombras, dificultad);
                mostrarTablero (tableros, dificultad,cant_jugadores); 
            	}	
			      }
        }
        if (tableros.verificarGanador == true && i < 23){
        	cout << "\n 1. Siguiente ronda\n 2. Ver datos de ronda " << i+1 << endl;
        	do{
	            cout << "\n Marque la opcion que desea: ";
	            cin >> menuRonda;
	            if (menuRonda < 1 || menuRonda > 2){
	                cout << " Opcion invalida, repita la operacion" << endl;
	            }
        	} while (menuRonda < 1 || menuRonda > 2);
        	if (menuRonda == 1){
        	}
        	if (menuRonda == 2){
	            system ("clear");
	            //system ("CLS");
	            cout << "\n---------- Resultados Ronda " << i+1 << " ----------" << endl;
	            for (int x = 0; x < cant_jugadores; x++){
	                cout << "\n || Jugador " << jugador[x].nombre << " ||" << endl;
	                cout << " Monedas Pagadas: " << endl;
	                cout << " Monedas restantes: " << endl;
	                cout << " Alfombras restantes: " << endl;
	                cout << "\n Presione c y despues enter para continuar: ";
	                cin >> seguir;
	            }
        	}	
		} else {
			break;
		}
		  if (i == 23){
			cout << definirGanador (jugador, cant_jugadores, tableros);
		  }
    }

 Jugador jugador_historial;
  
   for (int k = 0; k < cant_jugadores; k++){
	    if (jugador[k].eliminado == false){
        //Se llama a  la funcion Historial_juego por cada jugador 
	       jugador_historial = jugador[k];
	       Historial_juego (jugador_historial, contador_partidas);
	    }
	    
	}
  
} // acaba la funcion

void Historial_juego (Jugador jugador, int contador_partidas){
  fstream ArchivoHistorial_Juegos;
  //Se pone en el archivo, el nombre, monedas y alfombras de los juagdores sin ellimanr de la partida
 ArchivoHistorial_Juegos.open("Historial.txt",ios::out|ios::app);
    if (ArchivoHistorial_Juegos.is_open()){
        ArchivoHistorial_Juegos<<"Jugadores sin eliminar: "<<endl;
        ArchivoHistorial_Juegos<<jugador.nombre<<endl; 
        ArchivoHistorial_Juegos<<"Monedas:"<<jugador.cant_moneda<<endl; 
        ArchivoHistorial_Juegos<<"Alfombras:"<<jugador.cant_alfombra<<endl;
    } else{
        cout<<"No se puedo abrir el archivo"<<endl;
    }
    
}

void Reglas_juego (){
  cout << "\n---------- Reglas de Juego ----------" << endl;
  cout << "\n 1. Se requiere un minimo de 2 personas para jugar" << endl;
  cout << " 2. Cada jugador recibe 30 monedas y 24 alfombras" << endl;
  cout << " 3. La ficha Assam se coloca en el centro del tablero" << endl;
  cout << " 4. Cada jugador lanza un dado para determinar su turno (en caso de empate se repite)" << endl;
  cout << " 5. En su turno cada jugador debe elegir la direccion de desplazamiento de Asaam antes de lanzar el dado" << endl;
  cout << " 6. Se lanza el dado, y Assam se mueve el numero de casillas que detemino el dado en la direccion en que anteriormente se especifico" << endl;
  cout << " 7. Si Assam sale del mercado entonces pasa al comienzo o al final de la fia_columna dependiendo de la orientacion de Assam" << endl;
  cout << " 8. El jugador puede colocar una de sus alfombras en las cuatro casillas que se encuentran al lado de Assam" << endl;
  cout << " 9. Si un jugador cae en la alfombra de un jugador contrario, el jugador debera pagarle al dueño de la alfombra la cantidad de monedas correspondiente a la cantidad de alfombras que tiene el jugador contrario en el mercado, incluyendo la que esta pisando" << endl;
  cout << " 10. Si un jugador se queda sin monedas, queda eliminado del juego, y las casillas que poseia quedan vacias." << endl;
  cout << " 11. El juego termina cuando se coloca la ultima alfombra, gana el juagdor que tenga mas alfombras. En caso de empate gana el que tenga mas monedas." << endl;
  
}
