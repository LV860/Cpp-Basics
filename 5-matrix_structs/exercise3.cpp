/**************************
Autores:
- Leonardo Velázquez Colín  
- Oscar Alejandro Rodríguez Gómez  
- Juan David Torres Chaparro  

Descripción:
Este programa permite gestionar una imagen digital en forma de matriz binaria (0 y 1), 
calcular la proporción de pixeles blancos y negros, y visualizar la imagen generada. 
El usuario puede interactuar mediante un menú para generar una imagen, 
mostrarla o calcular la razón de blancos y negros.
***************************/

#include <iostream>

using namespace std;

const int FILAS = 100;
const int COLUMNAS = 100;

// Estructura para almacenar una imagen digital
struct Imagen{
    string nombre;
    int tam_filas;
    int tam_columnas;
    int Matriz_imagen[FILAS][COLUMNAS];
};

// Estructura para almacenar un patrón dentro de la imagen
struct Patron{
    int tam_filas;
    int tam_columnas;
    int Matriz_patron[FILAS][COLUMNAS];
};

// Prototipo de funciones
Imagen llenar_datos(); // Función para capturar los datos de la imagen
void Imagen_RazonBlancoNegro(Imagen imagen); // Función para calcular la proporción blanco/negro

int main() {
    int opcion_menu, volver_menu;
    bool fin_programa = false;
    Imagen imagen;
    
    cout << "Bienvenido" << endl;
    cout << "Ejercicio 2" << endl;
    
    while (!fin_programa) {
        system("clear"); // Limpiar pantalla en Linux (en Windows usar "CLS")
        
        do {
            cout << "                 MENU" << endl;
            cout << "1. Generar una imagen digital (original)." << endl;
            cout << "2. Mostrar la imagen digital (original)." << endl;
            cout << "3. Calcular la razón blanco/negro de la imagen original." << endl;
            cout << "4. Salir." << endl;
            cin >> opcion_menu;
        } while (opcion_menu < 1 || opcion_menu > 4);
        
        switch (opcion_menu) {
            case 1:
                system("clear");
                cout << "Generar una imagen digital (original)." << endl << endl;
                imagen = llenar_datos();
                break;
            case 2:
                system("clear");
                cout << "Mostrar la imagen digital (original)." << endl << endl;
                if (imagen.tam_filas == 0 && imagen.tam_columnas == 0) {
                    cout << "Actualmente no hay imagen." << endl;
                } else {
                    cout << "Imagen " << imagen.nombre << ":" << endl << endl;
                    for (int i = 0; i < imagen.tam_filas; i++) {
                        for (int j = 0; j < imagen.tam_columnas; j++) {
                            cout << imagen.Matriz_imagen[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;
            case 3:
                system("clear");
                cout << "Calcular la razón blanco/negro de la imagen original." << endl << endl;
                Imagen_RazonBlancoNegro(imagen);
                break;
            case 4:
                system("clear");
                cout << "Gracias por tomar nuestros servicios, hasta pronto." << endl;
                fin_programa = true;
                break;
        }
    }
    return 0;
}

// Función para capturar los datos de la imagen
Imagen llenar_datos() {
    Imagen Datos_imagen;
    cout << "Ingrese el nombre descriptivo de la imagen: ";
    cin >> Datos_imagen.nombre;
    
    do {
        cout << "Ingrese la cantidad de filas de la imagen: ";
        cin >> Datos_imagen.tam_filas;
    } while (Datos_imagen.tam_filas < 0);
    
    do {
        cout << "Ingrese la cantidad de columnas de la imagen: ";
        cin >> Datos_imagen.tam_columnas;
    } while (Datos_imagen.tam_columnas < 0);
    
    for (int i = 0; i < Datos_imagen.tam_filas; i++) {
        for (int j = 0; j < Datos_imagen.tam_columnas; j++) {
            do {
                cout << "Ingrese el valor (1 o 0) del pixel en la fila " << i + 1 << " y en la columna " << j + 1 << ": ";
                cin >> Datos_imagen.Matriz_imagen[i][j];
            } while (Datos_imagen.Matriz_imagen[i][j] != 0 && Datos_imagen.Matriz_imagen[i][j] != 1);
        }
        cout << endl;
    }
    return Datos_imagen;
}

// Función para calcular la proporción de píxeles blancos y negros
void Imagen_RazonBlancoNegro(Imagen imagen) {
    float porcentaje_blanco, porcentaje_negro;
    float total_pixeles = imagen.tam_filas * imagen.tam_columnas;
    float cant_blancas = 0, cant_negras = 0;
    
    for (int i = 0; i < imagen.tam_filas; i++) {
        for (int j = 0; j < imagen.tam_columnas; j++) {
            if (imagen.Matriz_imagen[i][j] == 1) {
                cant_blancas++;
            } else {
                cant_negras++;
            }
        }
    }
    
    porcentaje_blanco = (cant_blancas / total_pixeles) * 100;
    porcentaje_negro = (cant_negras / total_pixeles) * 100;
    
    cout << "\nLa razón blanco/negro de la imagen " << imagen.nombre << " es de: "
         << porcentaje_blanco << "% (blancas) / " << porcentaje_negro << "% (negras)" << endl;
}
