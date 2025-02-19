/******************************************************************************  
Autores:
- Oscar Alejandro Rodríguez Gómez  
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  

Descripción:
Este programa gestiona un torneo de fútbol, permitiendo registrar equipos, calcular puntajes, organizar posiciones y mostrar un historial de campeones por temporada.

*******************************************************************************/



#include <iostream>

using namespace std;

struct Equipos {
    string nombreE;
    int golesF, golesC, partidosG, partidosE, partidosP, diferenciaG, puntos, anios[100];
};

// Funciones
void llenarEquipos (Equipos equipos[], int cantEquipos);

void datosEquipo (Equipos equipos[], int cantEquipos);

void puntaje (Equipos equipos[], int cantEquipos);

void organizar (Equipos equipos[], int cantEquipos, int contador);

void imprimir (Equipos equipos[], int cantEquipos);

int main()
{
    // Declaracion
    Equipos equipos[100];
    int cantEquipos, contador;
    bool x = true;
    
    // Se preguntan datos relevantes para los calculos del torneo
    do{
        cout << "¿Desde que año desea calcular los datos del torneo?(Hay datos desde la temporada 1): ";
        cin >> contador;
        if (contador < 1){
            cout << "No hay informacion en el sistema de esa temporada" << endl << endl;
        }
    } while (contador < 1);
    cout << "\n¿Cuantos equipos participan en el torneo?: ";
    cin >> cantEquipos;
    llenarEquipos (equipos, cantEquipos); // se llama la funcion que llena el arreglo de equipos
    while (x == true){
        cout << "\n----------------------------------" << "\n\t  Temporada " << contador << endl;
    
        datosEquipo (equipos, cantEquipos); // se llama la funcion en que se piden los datos de cada equipo
        puntaje (equipos, cantEquipos); // se llama la funcion en que se calcula el puntaje de cada equipo 
        organizar (equipos, cantEquipos, contador); // se llama la funcion que organiza los equipos de mayor a menor puntaje
        imprimir (equipos, cantEquipos); // se llama la funcion que imprime la tabla de posiciones
    
        cout << "\n¿Desea conocer los resultados de la siguiente temporada? (1 = Si, 0 = No): "; // se pregunta si desea conocer los resultados de la temporada siguiente
        cin >> x;
        contador++;
        if (x == false){ // en caso de que no quiera calcular las posiciones para otra temporada, se muestran los años en que cada equipo fue campeon  
            cout << "\n|| Historial de equipos campeones ||" << endl;
            for (int i = 1; i <= cantEquipos; i++){
                cout << "\n" << equipos[i].nombreE << ": ";
                for (int x = 1; x <= 100; x++){
                    if (equipos[i].anios[x] == 0){
                        break;
                    } else {
                        cout << equipos[i].anios[x] << " ";
                    }
                }
            }
            cout << "\n\nGracias por acceder al sistema";
            return 0;
    }
    }
}

void llenarEquipos (Equipos equipos[], int cantEquipos){
    for (int i = 1; i <= cantEquipos; i++){
        cout << "\n|| Equipo " << i << " ||" << endl;;
        cout << "Ingrese el nombre del equipo: ";
        cin >> equipos[i].nombreE;
    }
} // se llenan los nombres de los equipos participantes del torneo

void datosEquipo (Equipos equipos[], int cantEquipos){
    for (int i = 1; i <= cantEquipos; i++){
        cout << "\n|| " << equipos[i].nombreE << " ||" << endl;
        cout << "Ingrese los goles a favor: ";
        cin >> equipos[i].golesF;
        cout << "Ingrese los goles en contra: ";
        cin >> equipos[i].golesC;
        cout << "Ingrese los partidos ganados: ";
        cin >> equipos[i].partidosG;
        cout << "Ingrese los partidos empatados: ";
        cin >> equipos[i].partidosE;
        cout << "Ingrese los partidos perdidos: ";
        cin >> equipos[i].partidosP;
    }
} // se llenan los datos de cada equipo para la temporada correspondiente 

void puntaje (Equipos equipos[], int cantEquipos){
    for (int i = 1; i <= cantEquipos; i++){
        equipos[i].diferenciaG = equipos[i].golesF - equipos[i].golesC;
        equipos[i].puntos = (equipos[i].partidosG * 3) + (equipos[i].partidosE * 1) + (equipos[i].partidosP * 0);
    }
} // se calcula el puntaje de cada equipo basados en los partidos ganados, empatados y perdidos

void organizar (Equipos equipos[], int cantEquipos, int contador){
    Equipos aux;
    string auxNombre;
    int auxDiferenciaG, auxPuntos, b = 1;
    for (int i = 1; i <= cantEquipos; i++){
        for (int x = 1; x <= cantEquipos; x++){
            if (equipos[i].puntos > equipos[x].puntos){ // se organiza de mayor a menor 
                aux = equipos[i];
                equipos[i] = equipos[x];
                equipos[x] = aux;
            }
            if (equipos[i].puntos == equipos[x].puntos){ // en caso de empate en puntos de dos equipos, se define la posicion por quien tenga la mayor diferencia de gol
                if (equipos[i].diferenciaG > equipos[x].diferenciaG){
                    aux = equipos[i];
                    equipos[i] = equipos[x];
                    equipos[x] = aux;
                }
            }
        }
    }
    for (int i = 1; i <= 100; i++){ // se guarda el año en el cual el equipo salio campeon en el arreglo 
        if (equipos[1].anios[i] == 0){
            equipos[1].anios[i] = contador;
            break;
        } 
    }
}

void imprimir (Equipos equipos[], int cantEquipos){
    cout << "\n\t ---------------------" << "\n\t| Tabla de Posiciones |" << "\n\t ---------------------" << endl;
    for (int i = 1; i <= cantEquipos; i++){
        cout << "\n|| Posicion " << i << " ||" << endl;
        cout << "Nombre: " << equipos[i].nombreE << endl;
        cout << "Puntos: " << equipos[i].puntos << endl;
        cout << "Diferecia de Gol: " << equipos[i].diferenciaG << endl;
    }
} // se imprime la tabla de posiciones de cada temporada