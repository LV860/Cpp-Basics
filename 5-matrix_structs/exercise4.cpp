/**************************
Autores:
- Leonardo Velázquez Colín  
- Oscar Alejandro Rodríguez Gómez  
- Juan David Torres Chaparro  

Descripción:
Tres estudiantes enfrentan un desafío académico: necesitan obtener la calificación perfecta (5.0/5.0) en el examen final de Programación Avanzada para aprobar la materia con la nota mínima requerida por la universidad (3.0/5.0). Su difícil situación se debe a una carga académica exigente de 22 créditos, incluyendo matemáticas, física, programación avanzada y un curso de billar a tres bandas, indispensable para costear fotocopias en el Paisa Copión.

En su búsqueda de una solución, los estudiantes se reúnen en Cuatro Parques, un punto icónico de encuentro. Entre los vapores y charlas del lugar, se les aparece un genio, quien, aunque no sabe programar, les entrega un rompecabezas que los guiará hasta un gurú experto en programación, cocina asiática, periodismo digital y lectura de la mente de los profesores de ingeniería de sistemas.

El rompecabezas consiste en una tabla con coordenadas que indican un camino específico a seguir. La ruta se construye siguiendo las instrucciones contenidas en la tabla, partiendo desde Cuatro Parques y visitando varios lugares clave hasta llegar a Unilago, donde podrán encontrar al gurú que les dará acceso a los secretos de los parciales.

Misión:
1. Diseñar una estructura de datos que represente el rompecabezas.
2. Implementar una función en C++ que cargue la ruta correcta en un arreglo para encontrar al gurú.
***************************/

#include <iostream>

// Estructura que representa cada punto del rompecabezas
struct Rompecabezas {
    std::string nombre;  // Nombre del lugar
    int coordenada_x;    // Desplazamiento en X hacia el siguiente destino
    int coordenada_y;    // Desplazamiento en Y hacia el siguiente destino
};

// Función que resuelve el rompecabezas y almacena la ruta en un arreglo
void resolver_rompecabezas(Rompecabezas matriz_rompecabezas[][3], std::string solucion[], int x, int y);

int main() {
    Rompecabezas matriz_rompecabezas[3][3];
    std::string solucion[20];
    int punto_inicio, x, y;
    
    // Inicialización de la matriz del rompecabezas
    matriz_rompecabezas[0][0] = {"La Luis Ángel", 0, 2};
    matriz_rompecabezas[0][1] = {"Parque de la 93", 0, 2};
    matriz_rompecabezas[0][2] = {"Plaza del Bolívar", -1, 0};
    matriz_rompecabezas[1][0] = {"Unilago", 0, 0};
    matriz_rompecabezas[1][1] = {"Chía", 1, 1};
    matriz_rompecabezas[1][2] = {"Cuatro Parques", -1, 0};
    matriz_rompecabezas[2][0] = {"Cuadra Alegre", 0, -1};
    matriz_rompecabezas[2][1] = {"Unicentro", -1, -2};
    matriz_rompecabezas[2][2] = {"La 82", 0, -2};
    
    // Solicitar al usuario el punto de partida
    std::cout << "Ingrese el parque de partida:";
    std::cout << "\n1) La Luis Ángel \n2) Parque de la 93 \n3) Plaza del Bolívar ";
    std::cout << "\n4) Unilago \n5) Chía \n6) Cuatro Parques ";
    std::cout << "\n7) Cuadra Alegre \n8) Unicentro \n9) La 82" << std::endl;
    std::cout << "INGRESE LA OPCIÓN QUE DESEA: ";
    std::cin >> punto_inicio;
    
    // Definir las coordenadas iniciales según la elección del usuario
    switch (punto_inicio) {
        case 1: x = 0; y = 0; break;
        case 2: x = 0; y = 1; break;
        case 3: x = 0; y = 2; break;
        case 4: x = 1; y = 0; break;
        case 5: x = 1; y = 1; break;
        case 6: x = 1; y = 2; break;
        case 7: x = 2; y = 0; break;
        case 8: x = 2; y = 1; break;
        case 9: x = 2; y = 2; break;
        default: std::cout << "Error: opción inválida."; return 1;
    }
    
    // Resolver el rompecabezas desde el punto inicial
    resolver_rompecabezas(matriz_rompecabezas, solucion, x, y);
    return 0;
}

// Función que genera la secuencia de lugares a visitar hasta encontrar al gurú
void resolver_rompecabezas(Rompecabezas matriz_rompecabezas[][3], std::string solucion[], int x, int y) {
    int aux;
    
    for (int i = 0; i < 9; i++) {
        solucion[i] = matriz_rompecabezas[x][y].nombre;
        aux = x;
        x = x + matriz_rompecabezas[x][y].coordenada_y;
        y = y + matriz_rompecabezas[aux][y].coordenada_x;
    }
    
    // Imprimir la solución
    for (int j = 0; j < 9; j++) {
        std::cout << solucion[j] << std::endl;
        if (solucion[j] == "Unilago") {
            return; // Terminar si se llega al destino final
        }
    }
}
