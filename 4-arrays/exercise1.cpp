/******************************************************************************  
Autores:
- Oscar Alejandro Rodríguez Gómez  
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  

Descripción:

En el procesamiento de señales, una de las operaciones más comunes es el reescalamiento, donde se obtiene una señal de menor tamaño que la original con la menor pérdida posible de información. Para esto, se escoge un factor de escala (n), y por cada n elementos en la señal original, se genera un único elemento en la nueva señal. Este elemento se calcula como el promedio de los n elementos, aproximado a un número entero.  

Ejemplo con un factor de escala de 3:  
Entrada: [4, 5, 6, 8, 9, 10, 2, 3, 5]  
Salida:  [5, 9, 3]  

Si el tamaño original de la señal no es múltiplo del factor de escala, los elementos sobrantes se descartan.  

Ejemplo con un factor de escala de 4:  
Entrada: [3, 7, 5, 9, 2, 8, 6]  
Salida:  [6]  (El último grupo de tamaño menor a 4 se descarta)  

También se puede calcular una pirámide de escalas, donde la señal se reescala varias veces hasta obtener un único valor como resultado.  

Ejemplo con un factor de escala de 2:  
Entrada: [8, 12, 6, 14]  
Paso 1:  [10, 10]  
Paso 2:  [10]  (Resultado final)  

Objetivo:  
Se requiere desarrollar una aplicación computacional que permita procesar diferentes señales de acuerdo con estas operaciones. Para ello, se implementarán las siguientes funciones:  

1. `Senal_reescalada`: Recibe una señal, su tamaño y un factor de escala, y genera la nueva señal reescalada.  
2. `Piramide_senal_reescalada`: Recibe una señal, su tamaño y un factor de escala, y genera la pirámide de escalas de la señal, haciendo uso de la función anterior.  

*******************************************************************************/



#include <iostream>

using namespace std;

// Protocolo

/*
Funcion: Señal_reescalada, la funcion se encarga de reescalar una sel que el usuario ingresa.
Parametros: int array[],int array_2[], el arreglo que contiene la señal original y el arreglo que contiene la señal reescalada.
            int Tamano, int Factor_escala, tambien contiene el tamaño de la señal que se va a reescalar y el factor de escala.
return: el nuevo tamaño
*/
int Senal_reescalada(int Tamano, int Factor_escala, int array[], int array_2[]);


/*
Funcion: Piramide_señal_reescalada, la funcion se encarga de pedir los votos a los estudiantes.
Parametros: int array[],int array_2[] el arreglo que contiene la señal original y arreglo de la señal reescalada.
            int Tamano, int Factor_escala,  contiene el tamaño de la señal que se va a reescalar  y el factor de escala.
return: Vacio
*/
void Piramide_senal_reescalada(int Tam, int Factor_escala, int array[],int array_2[]);
/*
Funcion: menu, la funcion se encarga de mostar las diferentes opciones que tiene el programa.
Parametros: int Opcion_menu, int array[],int array_2[], el arreglo que contiene la señal original y el arreglo que contiene la señal reescalada.
return: vacio
*/
void menu(int Tamano, int array[],int array_2[]);

int main()
{
    int senal[100];
    int senal_reescalada[100];
    int Opcion_menu, tamano_1;
    cout<<"Bienvenido"<<endl;
    cout<<"Ejericio 1"<<endl<<endl;
   
    cout<<"Ingrese el tamano de la senal original"<<endl;
    cin>> tamano_1;
   
    for (int i=0 ; i<tamano_1;i++){
        cout<<"Ingrese el valor del elemento "<< i+1<<" de la senal original: "<<endl;
        cin>> senal[i];
    }
    
    cout<<"Senal original: "<<endl;
    for (int i=0 ; i<tamano_1;i++){
        cout<< senal[i]<< " ";
    } //Se le meutra al usrio la señal original que ingreso
    cout<<endl;
   
    menu(tamano_1,senal,senal_reescalada); 
    //Se llama a la funcion menu, para que el usrio elija que opciion desea
    return 0;
}
void menu(int Tamano, int senal[],int senal_reescalada[]){
   
    int factor_escala, tamano_2,Opcion_menu;
   
    cout<<endl;
    cout<<"Menu"<<endl;
    cout<<"1. Generar una senal reescalada."<<endl;
    cout<<"2. Generar una piramide de escaladas a una senal."<<endl;
    cout<<"3. Salir del programa"<<endl;
    cout<<"Ingrese la opcion que desea: "<<endl;
    cin>> Opcion_menu;
   
    if (Opcion_menu == 1){
    cout<<"Ingrese el factor de escala para calcular la senal reescalada: "<<endl;
    cin>> factor_escala;
   
    tamano_2 = Senal_reescalada(Tamano,factor_escala,senal,senal_reescalada);
    //Se llama la funcion Senal_reescalada para generar la señal reescalada, y al mismo tiempo se guarda el tamaño de la señal reescalada.
    }
    if (Opcion_menu == 2){
    cout<<"Ingrese el factor de escala para calcular la senal reescalada: "<<endl;
    cin>> factor_escala;
    Piramide_senal_reescalada(Tamano, factor_escala,senal,senal_reescalada);
    // Se llama a la funcion de Piramide_senal_reescalada.
    }
    if (Opcion_menu == 3){
        cout<<"Gracias por sus servicios"<<endl;
        //Se despide al usuario y se acaba el programa
    }
}

int Senal_reescalada(int Tamano, int Factor_escala,int senal[], int senal_reescalada[]){
   
    int num_grupos, promedio = 0, cont = 0, opcion, ta=Tamano, Promedio;
    
    num_grupos = Tamano/Factor_escala; //Se calcula el numero de grupos en la señal a reescalar pasa scar el promedio de cada uno 
    Tamano = num_grupos*Factor_escala; // Se calcula el tamaño de la señal reescalada
   
    for (int i=0 ; i<num_grupos;i++){
        promedio = 0;
        cont =Factor_escala*i;  

      for (int j=cont ; j<cont + Factor_escala;j++){ 
        promedio = promedio + senal[j]; // Se suman los elementos de cada grupo (decidido por el factor escala) en la señal original
    }  
    
    //Se calcula el promedio de los grupos, con la ayuda por las anteriores sumas (decidido por el factor escala) en la señal original
    if (promedio%Factor_escala < 0.5){  
    senal_reescalada[i] = promedio/Factor_escala;
    }//Si el resultado del promedio tuvo decimales menores a 0.5, No se redondea el promedio
   if (promedio%Factor_escala >= 0.5){
    senal_reescalada[i] = (promedio/Factor_escala) + 1;
    }//Si el resultado del promedio tuvo decimales mayores o iguales a 0.5, Se redondea el promedio
    
    }

    cout<<"Senal reescalada: "<<endl;
    for (int i=0 ; i<num_grupos;i++){
        cout<<senal_reescalada[i]<<" ";
    } //Se le muestra al usuario la señal reescalada
    cout<<endl;
     
    return Tamano;
    
}
void Piramide_senal_reescalada(int Tam, int Factor_escala, int senal[], int senal_reescalada[]){
    int repetir, cont = 0, num_grupos = 10, tamano_3 = Tam;
  while ( num_grupos > 1){
      num_grupos = Tam/Factor_escala;
      Tam = num_grupos;
      cont++;
   } //Se crea un contador. El contador servira para determinar cuantas veces se utilizara la funcion de Senal_reescalada, para asi crear la piramide
 
   cout<<endl;
    cout<<"Senal original: "<<endl;
    for (int i=0 ; i<tamano_3;i++){
        cout<< senal[i]<< " ";
    } //Se le recuerda al usuario la señal original.
    cout<<endl;
    for (int i=0 ; i<cont;i++){
       
        tamano_3 = Senal_reescalada(tamano_3,Factor_escala,senal,senal_reescalada);
        //Se llama la funcion de Senal_reescalada, y se gurada el nuevo tamano de la señal reescalada
        for (int j=0 ; j<tamano_3;j++){
           
            senal[j] = senal_reescalada[j];
            //Se guardan los elementos de la señal reescalada en la señal original, para que asi funcione coorectamente la funcion Senal_reescalada, para cuando se vuelva llamar.
        }
        num_grupos = tamano_3/Factor_escala; 
        tamano_3 = num_grupos; // se ajuta el tamaño de la señal, para asi calcular, la siguinte señal reescalada 
    }
   
}
