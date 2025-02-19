/******************************************************************************  
Autores:
- Oscar Alejandro Rodríguez Gómez  
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  

Descripción:
Autores:
- Oscar Alejandro Rodríguez Gómez  
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  

Descripción:
Este programa gestiona la producción anual de una cooperativa de productores de naranja en N parcelas (1 ≤ N ≤ 50). 
Cada parcela puede contener dos tipos de naranjas:
- Para jugo  
- Para consumo directo  

La información de producción se almacena en un arreglo donde:
- Primero se registra la cantidad de toneladas de naranjas para jugo.
- Luego se registra la cantidad de toneladas de naranjas para comer.
- Si en una parcela no se ha cosechado un tipo de naranja, el valor correspondiente será 0.

Ejemplo de almacenamiento:  
Si tenemos la siguiente producción:
- Parcela 1: 100 toneladas de naranjas para jugo, 500 toneladas para comer.
- Parcela 2: 600 toneladas de naranjas para jugo, 0 toneladas para comer.
- Parcela 3: 800 toneladas de naranjas para jugo, 700 toneladas para comer.

El arreglo se verá así:  
`[100, 500, 600, 0, 800, 700]`
*******************************************************************************/

#include <iostream>

void parcelas (int num_parcelas[],int tam_parcelas);
/*
Función: organiza las parcelas en un arreglo
Parametros: el arreglo de las parcelas y su tamaño
No retorna nada
*/
void suma_parcelas (int num_parcelas[],int tam_parcelas, int sumas[]);
/*
Función: Suma las naranjas de comer y de jugo y las organiza en una casilla de otro arreglo
Parametros: el arreglo de las parcelas su tamaño y el arreglo de las sumas 
No retorna nada
*/
int eliminar_parcela (int num_parcelas[],int tam_parcelas, int indice_eliminar);
/*
Función: Elimina una parcela y mantiene el orden del mismo 
Parametros: el arreglo de las parcela su tamaño y el indice que se quiere eliminar
Retorna el tamaño nuevo del arreglo de las parcela
*/
int cero (int sumas[],int tam_parcelas);
/*
Función: Se encarga de ver si alguna parcela no tiene CULTIVOS
Parametros: el arreglo de las sumas de las parcelas y su tamaño
Retorna un entero, en este caso -1 si todo esta ocupado o el indice donde no hay nada
*/
int main(){
    //arreglo y variables de entrada
    int num_parcelas[98],sumas[49];
    int tam_parcelas, indice_eliminar;
    
    //un ciclo que se encarga de que introduzcan un valor correcto
    while(tam_parcelas>50 || tam_parcelas<=0 ){
    std::cout<<"\n Ingrese la cantidad de parcelas que va a ocupar: ";
    std::cin>>tam_parcelas;
    if (tam_parcelas>50 || tam_parcelas<=0){
    std::cout<<"\n INGRESE UNA CANTIDAD DE PARCELAS DE 1 A 50";}
    }
    
    //Se llama a la función parcela para que junte los datos
    parcelas (num_parcelas,tam_parcelas);
    
    //Se genera un ciclo para mostrar el vector de las parcelas
    std::cout<<std::endl;
        int indice=1;
    for (int i=0; i<tam_parcelas*2; i++){
        if (i%2 == 0){
        std::cout<<" (PARCELA "<<indice<<" )";
        indice++;
        }
        std::cout<<"| "<<num_parcelas[i]<<" | ";
    }
     
    std::cout<<std::endl;
    std::cout<<"\n LA SUMA DE LAS PARCELAS" << std::endl; 
    
    //Se llama la función suma_parcelas para que con los datos infresados sume y los vuelva a organizar
    suma_parcelas (num_parcelas,tam_parcelas,sumas);
 
        int indice2=1;
        for (int j=0; j<tam_parcelas; j++){
        std::cout<<" (PARCELA "<<indice2<<" )"<<"| "<<sumas[j]<<" | ";
        indice2++;
        }
    
    std::cout<<std::endl;
    
    //un ciclo que se encarga de que introduzcan un valor correcto
     while(indice_eliminar>tam_parcelas || indice_eliminar<=0 ){
    std::cout<<"\n DESEA ELIMINAR ALGUNA PARCELA ";
    std::cin>>indice_eliminar;
    if (indice_eliminar<=0 || indice_eliminar>tam_parcelas){
    std::cout<<"\n INGRESE UNA PARCELAS EXISTENTE DE 1 A "<<tam_parcelas;}
    }
    indice_eliminar=((indice_eliminar*2)-2);
    
    // Se llama la función eliminar_parcela para que si el usuario lo desea borre alguna parcela
    eliminar_parcela (num_parcelas, tam_parcelas, indice_eliminar);
    tam_parcelas=eliminar_parcela (num_parcelas, tam_parcelas, indice_eliminar);
    //std::cout<<tam_parcelas;
        std::cout<<std::endl;
        indice=1;
    for (int i=0; i<tam_parcelas*2; i++){
        if (i%2 == 0){
        std::cout<<" (PARCELA "<<indice<<" )";
        indice++;
        }
        std::cout<<"| "<<num_parcelas[i]<<" | ";
    }
    
    //Se muestra si el usuario tiene parcelas sin producir
    if (cero (sumas, tam_parcelas) == -1 || cero (sumas, tam_parcelas) == 0){
    std::cout<<"\n EN TODAS LAS PARCELAS HAY CULTIVOS " << cero (sumas, tam_parcelas);
    } else {
    std::cout<<"\n EN EL CULTIVO " << cero (sumas, tam_parcelas) <<" NO HAY CULTIVOS";
    }
    
    return 0;
}

void parcelas (int num_parcelas[],int tam_parcelas){
    int indice=1;
    //std::cout<<tam_parcelas;
    for (int i=0; i<tam_parcelas*2; i+=2){
        std::cout<<"\n (PARCELA "<<indice<<" )\n Ingrese las toneladas de naranjas para comer y jugo de la parcela: ";
         std::cin>>num_parcelas[i];
         std::cin>>num_parcelas[i+1];
         indice++;
    }
}

void suma_parcelas (int num_parcelas[],int tam_parcelas, int sumas[]){
    int i=0;
    for (int j=0; j<tam_parcelas*2; j+=2){
        sumas[i]=num_parcelas[j]+num_parcelas[j+1];
        i++;
    }
}

int eliminar_parcela (int num_parcelas[],int tam_parcelas, int indice_eliminar){
    
        for (int i=indice_eliminar; i<tam_parcelas; i=i+2){
        num_parcelas[i]=num_parcelas[i+2];
        num_parcelas[i+1]=num_parcelas[i+3];
        i+=2;
        std::cout<<i;
        }
     return tam_parcelas-1;
}

int cero (int sumas[],int tam_parcelas){
    
     for (int j=0; j<tam_parcelas; j++){
     if (sumas[j] == 0){
         if (j == 0){
            return -1;
         }
         return j;
     }
    }
    return -1;
}







