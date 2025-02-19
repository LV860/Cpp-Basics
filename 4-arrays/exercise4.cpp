/******************************************************************************  
Autores:
- Oscar Alejandro Rodríguez Gómez  
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  


*******************************************************************************/


#include <iostream>

using namespace std;

/*
Funcion: Inserta un nuevo paciente a la base de datos del hospital
Entrada: los arreglos, el tamaño de los mismos y los datos que se le piden al usuario para llenar dichos arreglos
Return: se retorna la variable entera del tamaño
*/
int insertarPaciente (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], 
    string nombre, string apellido, char genero, float estatura, int edad, int peso, int tamano, int b);

/*
Funcion: Muestra los datos de los pacientes registrados en el sistema
Entrada: los arreglos y el tamaño de los mismos
Return: no retorna nada, porque no se esta cambiando una variable 
*/
void mostrarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], 
    int tamano);

/*
Funcion: Organiza los pacientes presentes en el sistema segun lo indique el usuario
Entrada: los arreglos, el tamaño de los mismos y el metodo de organizacion que elige el usuario
Return: no retorna nada, porque no se esta cambiando una variable 
*/    
void organizarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], 
    int tamano, int menu5);

/*
Funcion: Edita los datos de los pacientes que indique el usuario
Entrada: los arreglos, su tamaño respectivo y el dato que el usuario desea editar
Return: ni retorna nada, porque no se esta cambiando una variable
*/    
void editarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], 
    int tamano, int numPaciente, int editar);

/*
Funcion: Busca al paciente que el usuario desea ver y le muestra los datos registrados en el sistema  
Entrada: los arreglos, su tamaño respectivo, el nombre y el apellido que desea buscar el usuario
Return: No retorna nada, porque no se esta cambiando una variable 
*/    
void buscarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], 
    int tamano, int menu4, string nomPaciente, string apePaciente);

/*
Funcion: Elimina de la base de datos el paciente que indique el usuario
Entrada: los arreglos, su tamaño respectivo, el nombre y el apellido que desea buscar el usuario
Return: Se retorna la variable entera del tamaño
*/   
int eliminarPaciente (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], 
    int tamano, int menu2, string nomPaciente, string apePaciente);

int main(){
	// 	Declaracion
    int menu, menu1, menu2, menu3, menu4, menu5, menu6, menu7, edades[100], pesos[100], tamano = 0, edad, peso, agregar, b = 0, editar, numPaciente, buscar, eliminar;
    string nombres[100], apellidos[100], nombre, apellido, nomPaciente, apePaciente;
    char generos[100], genero; 
    float estaturas[100], estatura;
    bool regresar = true, repetir;
    
    // Menu principal
	cout << "Base de datos - Hospital" << endl;
    while (regresar == true){
    repetir = true;
    cout << "\n----------------------------------------" << endl;
	cout << "     || MENU PRINCIPAL ||" << endl;
	cout << "1. Ingresar un nuevo paciente" << endl;
    cout << "2. Eliminar un paciente" << endl;
    cout << "3. Editar datos del paciente" << endl;
    cout << "4. Mostrar informacion de un paciente" << endl;
    cout << "5. Organizar los pacientes" << endl;
    cout << "6. Mostrar todos los pacientes" << endl;
    cout << "7. Salir" << endl;
    
    do {
    cout << "\nMarque la opcion que desea: ";
    cin >> menu;
        if (menu < 1 || menu > 7){
            cout << "Opcion invalida, repita la operacion" << endl;
        }
    } while (menu < 1 || menu > 7); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu
    
    if (menu == 1){
        while (repetir == true){
        	// Se piden los datos del nuevo paciente que se quiere agregar a la base de datos
            cout << "\nIngrese el nombre del nuevo paciente: ";
            cin >> nombre; 
            
            cout << "Ingrese el apellido del nuevo paciente: ";
            cin >> apellido;
            
            cout << "Ingrese la edad del nuevo paciente: ";
            cin >> edad;
            
            cout << "Ingrese el genero del nuevo paciente: ";
            cin >> genero;
            
            cout << "Ingrese la estatura del nuevo paciente: ";
            cin >> estatura;
            
            cout << "Ingrese el peso del nuevo paciente: ";
            cin >> peso;
            
            insertarPaciente (nombres, apellidos, pesos, edades, generos, estaturas, nombre, apellido, genero, estatura, edad, peso,  tamano, b); // se llama la funcion para que agregue el paciente a la base de datos
                tamano++;  // se aumenta el tamaño de los arreglos por cada vez que se ingrese un paciente nuevo
                b++;
            do {
                cout << "\n1. Agregar otro paciente " << endl;
                cout << "2. Volver al menu principal" << endl;
                
                cout << "\nMarque la opcion que desea: ";
                cin >> agregar;
                    if (agregar < 1 || agregar > 2){
                        cout << "\nOpcion invalida, repita la operacion" << endl;
                    }
            } while (agregar < 1 || agregar > 2); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu
            
            if (agregar == 2){
                repetir = false;
                regresar = true;
            } // si el usuario elige la opcion 2 regresa al menu principal
            if (agregar == 1){
                repetir = true;  // si el usuario elige la opcion 1 puede añadir otro paciente a la base de datos  
            } else {
                repetir = false;
            }
        }
        } // se cierra la opcion 1 del menu principal
        
    if (menu == 2){
        if (tamano == 0){
            cout << "\nNo hay pacientes en el sistema" << endl;
            cout << "Vuelva al menu principal" << endl;
            repetir = false;
        } // si no hay pacientes en el sistema se evita hacer toda la operacion y se envia de nuevo al menu principal
        while (repetir == true){
			do {
            	cout << "\n1. Eliminar por nombre" << endl;
            	cout << "2. Eliminar por apellido" << endl;
				cout << "3. Volver al menu principal" << endl;        
            	cout << "\nMarque la opcion que desea: ";
            	cin >> menu2; // se pregunta al usuario como desea hacer la eliminacion, si por nombre o por apellido
            	
                if (menu2 < 1 || menu2 > 3){
                cout << "\nOpcion invalida, repita la operacion" << endl;
                }
            } while (menu2 < 1 || menu2 > 3); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu
            
        if (menu2 == 1 || menu2 == 2){
            if (menu2 == 1){
				cout << "\nIngrese el nombre del paciente que desea eliminar: ";
				cin >> nomPaciente; // se pide el nombre del paciente que se desea eliminar
			}
			if (menu2 == 2){
				cout << "\nIngrese el apellido del paciente que desea eliminar: ";
				cin >> apePaciente; // se pide el apellido del paciete que se desea eliminar 
			}
			eliminarPaciente (nombres, apellidos, pesos, edades, generos, estaturas, tamano, menu2, nomPaciente, apePaciente); // se llama la funcion que elimina al paciente de la base de datos 
			tamano = tamano - 1; // se disminuye el tamaño de los arreglos para borrar asi el paciente
			
		do{
			cout << "\n1. ¿Desea eliminar otro paciente?" << endl;
			cout << "2. Regresar al menu principal" << endl;
			cout << "\nMarque la opcion que desee: ";
			cin >> eliminar; // se da la opcion de eliminar otro paciente o regresar al menu principal 
			
			if (eliminar < 1 || eliminar > 2){
				cout << "\nOpcion invalida, repita la operacion" << endl;
			}
		} while (eliminar < 1 || eliminar > 2); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu
    		
			if (eliminar == 1){
    			repetir = true;
			} // si el usuario ingresa la opcion 1, puede eliminar otro paciente de la base de datos
			if (eliminar == 2){
				repetir = false;
				regresar = true;
			} // si el usuario elije la opcion 2, regresa al menu principal 
		}
		if (menu2 == 3){
			repetir = false;
			regresar = true;		
		}
        } // si su respuesta en el menu fue la opcion 3, regresa al menu principal 
   	} // se cierra la opcion 2 del menu principal
    
    if (menu == 3){
        if (tamano == 0){
            cout << "\nNo hay pacientes para editar" << endl;
            cout << "Vuelva al menu principal" << endl;
            repetir = false;
        } // si no hay pacientes en el sistema se evita hacer toda la operacion y se envia de nuevo al menu principal
    	while (repetir == true){
    	for (int i = 0; i < tamano; i++){
    		cout << "\n|| Paciente " << i << " ||   " << nombres[i] << " " << apellidos[i] << endl;
		} // Se muestran los pacientes en el sistema, para que el usuario pueda elegir el numero del paciente que desea editar
		do {
                cout << "\nIngrese el numero del paciente que desea editar: ";
                cin >> numPaciente; // se pide al usuario el numero del paciente que desea editar 
                    if (numPaciente < 0 || numPaciente > tamano - 1){
                        cout << "\nOpcion invalida, repita la operacion" << endl;
                    }
            } while (numPaciente < 0 || numPaciente > tamano - 1); // Con el do while nos aseguramos que el digito ingresado este dentro de los pacientes presentes en el sistema    
            
        for (int i = 0; i < tamano; i++){
            if (i == numPaciente){
            	// se muestran todos los datos del paciente que eligio el usuario
                cout << "\nEdite los datos del paciente " << i << endl;
                cout << "1. Nombre: " << nombres[i] << endl;
			    cout << "2. Apellido: " << apellidos[i] << endl;
        		cout << "3. Edad: " << edades[i] << endl;
        		cout << "4. Genero: " << generos[i] << endl;
        		cout << "5. Estatura: " << estaturas[i] << endl;
        		cout << "6. Peso: " << pesos[i] << endl;
        		cout << "\nMarque la opcion que desea: ";
        		cin >> editar; // se le pide al usuario que marque el numero del dato que sea editar 
        	}
        }
        editarPacientes (nombres, apellidos, pesos, edades, generos, estaturas, tamano, numPaciente, editar); // se llama la funcion que permite editar los datos de un paciente
		do{
			cout << "\n1. ¿Desea editar otro paciente?" << endl;
			cout << "2. Regresar al menu principal" << endl;
			cout << "\nMarque la opcion que desee: ";
			cin >> menu3; // se pregunta al usuario si desea editar otro paciente o si desea regresar al menu principal
			
			if (menu3 < 1 || menu3 > 2){
				cout << "\nOpcion invalida, repita la operacion" << endl;
			}
		} while (menu3 < 1 || menu3 > 2); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu    
    		
		if (menu3 == 1){
    		repetir = true;
		} // si el usuario elige la opcion 1 puede editar otro dato al paciente que decida 
		if (menu3 == 2){
			repetir = false;
			regresar = true;
		} // si el usuario elige la opcion 2 regresa al menu principal 
    }
} // se cierra la opcion 3 del menu principal
     
    if (menu == 4){
        if (tamano == 0){
            cout << "\nNo hay pacientes en el sistema" << endl;
            cout << "Vuelva al menu principal" << endl;
            repetir = false; 
        } // si no hay pacientes en el sistema se evita hacer toda la operacion y se envia de nuevo al menu principal    
        while (repetir == true){
			do {
            	cout << "\n1. Busqueda por nombre" << endl;
            	cout << "2. Busqueda por apellido" << endl;
				cout << "3. Volver al menu principal" << endl;        
            	cout << "\nMarque la opcion que desea: ";
            	cin >> menu4; // se pregunta al usuario por cual opcion desea realizar la busqueda, nombre o apellido 
            	
                if (menu4 < 1 || menu4 > 3){
                cout << "\nOpcion invalida, repita la operacion" << endl;
                }
            } while (menu4 < 1 || menu4 > 3); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu    
            
        if (menu4 == 1 || menu4 == 2){
            if (menu4 == 1){
				cout << "\nIngrese el nombre del paciente que desea buscar: ";
				cin >> nomPaciente;
			} // si el usuario elije la opcion 1, se le pregunta el nombre del paciente que desea ver 
			if (menu4 == 2){
				cout << "\nIngrese el apellido del paciente que desea buscar: ";
				cin >> apePaciente;
			} // si el usuario elije la opcion 2, se le pregunta el apellido del paciente que desea ver 
			buscarPacientes (nombres, apellidos, pesos, edades, generos, estaturas, tamano, menu4, nomPaciente, apePaciente); // se llama la funcion que busca los datos de un paciente por nombre o apellido		
		do{
			cout << "\n1. ¿Desea buscar otro paciente?" << endl;
			cout << "2. Regresar al menu principal" << endl;
			cout << "\nMarque la opcion que desee: ";
			cin >> buscar; // se pregunta al usuario si desea buscar otro paciente o si desea regresar al menu principal
			
			if (buscar < 1 || buscar > 2){
				cout << "\nOpcion invalida, repita la operacion" << endl;
			}
		} while (buscar < 1 || buscar > 2); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu   
    		
		if (buscar == 1){
    		repetir = true;
		} // si el usuario elige la opcion 1, se repite el proceso de busqueda
		if (buscar == 2){
			repetir = false;
			regresar = true;
		} // si el usuario elige la opcion 2, regresa al menu principal	
		}
			if (menu4 == 3){
			repetir = false;
			regresar = true;		
		} // si en el menu inicial elige opcion 3, regresa directamente a
        }
    } // se cierra la opcion 4 del menu principal   
    
    if (menu == 5){
        do{
    	cout << "\n¿Como desea organizar los pacientes?" << endl;
    	cout << "1. Alfabeticamente por apellido" << endl;
    	cout << "2. Por orden de estatura" << endl;
    	cout << "3. Por edad" << endl;
		cout << "\nMarque la opcion que desea: ";
    	cin >> menu5; // se pregunta al usuario la forma en que desea ordenar los pacientes
    	
    	if (menu5 < 1 || menu5 > 3){
    		cout << "\nOpcion invalida, repita la operacion" << endl;	
		}
	} while (menu5 < 1 || menu5 > 3); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu  
	
	organizarPacientes (nombres, apellidos, pesos, edades, generos, estaturas, tamano, menu5); // se llama la funcion que organiza los pacientes segun lo indique el usuario
	cout << "\nPara ver los pacientes ordenados de la forma pedida, en el menu principal elija opcion 6" << endl; // para ver los pacientes organizados el usuario debe marcar la opcion 6 en el menu principal
} // se cierra la opcion 5 del menu principal 

    if (menu == 6){
    	if (tamano == 0){
    	cout << "\nNo hay pacientes en el sistema" << endl;
    	cout << "Vuelva al menu principal" << endl;
		} // si no hay pacientes en el sistema se evita hacer toda la operacion y se envia de nuevo al menu principal
		while(repetir == true){
		mostrarPacientes (nombres, apellidos, pesos, edades, generos, estaturas, tamano);	
		do{
			cout << "\n1. ¿Desea ver de nuevo los pacientes?" << endl;
			cout << "2. Regresar al menu principal" << endl;
			cout << "\nMarque la opcion que desee: ";
			cin >> menu6; // se pregunta al usuario si desea ver de nuevo los pacientes o si desea volver al menu principal
			
			if (menu6 < 1 || menu6 > 2){
				cout << "\nOpcion invalida, repita la operacion" << endl;
			}
		} while (menu6 < 1 || menu6 > 2); // Con el do while nos aseguramos que el digito ingresado este dentro de las opciones del menu      
    		
		if (menu6 == 1){
    		repetir = true;
		} // si elige la opcion 1, se vuelven a mostrar los pacientes en el sistema
		if (menu6 == 2){
			repetir = false;
			regresar = true;
		} // si elige la opcion 2, regresa al menu principal
	}
} // se cierra la opcion 6 del menu principal

    if (menu == 7){
    
    cout << "\nGracias por acceder a nuestro sistema";
    return 0;    // si el usuario elige la opcion 7 del menu principal, se cierra el programa 
    }
	}
} // se cierra el main

int insertarPaciente (string nombres[], string apellidos[], int pesos[], int edades[], char generos[],
    float estaturas[], string nombre, string apellido, char genero, float estatura, int edad, int peso, int tamano, int b){
    tamano++;
    for (int i = b; i < tamano; i++){ // se insertan los datos de un nuevo paciente al final de cada uno de los arreglos
        nombres[i] = nombre;
        apellidos[i] = apellido;
        pesos[i] = peso;
        edades[i] = edad;
        generos[i] = genero;
        estaturas[i] = estatura;
    }
    return tamano; // se retorna el nuevo valor del tamaño 
} // se cierra la funcion insertarPaciente

void mostrarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], int tamano){
    	for (int i = 0; i < tamano; i++){
    		cout << "\n|| PACIENTE " << i << " ||";
			cout << "\nNombre: " << nombres[i] << endl;
			cout << "Apellido: " << apellidos[i] << endl;
			cout << "Edad: " << edades[i] << endl;
			cout << "Genero: " << generos[i] << endl;
			cout << "Estatura: " << estaturas[i] << endl;
			cout << "Peso: " << pesos[i] << endl;
		} // se hace un recorrido por cada uno de los pacientes en el sistema, y se muestran sus datos 
	} // se cierra la funcion mostrarPacientes

void organizarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], int tamano, int menu5){   	
   	// Variables Auxiliares
	float auxEstatura = 0;
   	string auxNombre, auxApellido; 
   	int auxPeso, auxEdad;
   	char auxGenero;
	   if (menu5 == 1){ // Orden alfabetico
   		for (int i = 0; i < tamano; i++){
    		apellidos[i];
			for  (int x = 0; x < tamano; x++){
				if (apellidos[i] < apellidos[x]){ 
					auxEstatura = estaturas[i];
					estaturas[i] = estaturas[x];
					estaturas[x] = auxEstatura;
					
					auxNombre = nombres[i];
					nombres[i] = nombres[x];
					nombres[x] = auxNombre;
					
					auxApellido = apellidos[i];
					apellidos[i] = apellidos[x];
					apellidos[x] = auxApellido;
					
					auxEdad = edades[i];
					edades[i] = edades[x];
					edades[x] = auxEdad;
					
					auxGenero = generos[i];
					generos[i] = generos[x];
					generos[x] = auxGenero;
					
					auxPeso = pesos[i];
					pesos[i] = pesos[x];
					pesos[x] = auxPeso;	
				}
			
			}	
		}
	} // se cierra la opcion de organizar los pacientes en orden alfabetico
	   
	if (menu5 == 2){ // De mayor a menor estatura
		for (int i = 0; i < tamano; i++){
    		estaturas[i];
			for (int x = 0; x < tamano; x++){
				if (estaturas[i] > estaturas[x]){ 
					auxEstatura = estaturas[i];
					estaturas[i] = estaturas[x];
					estaturas[x] = auxEstatura;
					
					auxNombre = nombres[i];
					nombres[i] = nombres[x];
					nombres[x] = auxNombre;
					
					auxApellido = apellidos[i];
					apellidos[i] = apellidos[x];
					apellidos[x] = auxApellido;
					
					auxEdad = edades[i];
					edades[i] = edades[x];
					edades[x] = auxEdad;
					
					auxGenero = generos[i];
					generos[i] = generos[x];
					generos[x] = auxGenero;
					
					auxPeso = pesos[i];
					pesos[i] = pesos[x];
					pesos[x] = auxPeso;
			}
			}	
		}	
	} // se cierra la opcion de organizar los pacientes en orden de estatura
	
	if (menu5 == 3){ // De mayor a menor edad
		for (int i = 0; i < tamano; i++){
    		edades[i];
			for (int x = 0; x < tamano; x++){
				if (edades[i] > edades[x]){ 
					auxEstatura = estaturas[i];
					estaturas[i] = estaturas[x];
					estaturas[x] = auxEstatura;
					
					auxNombre = nombres[i];
					nombres[i] = nombres[x];
					nombres[x] = auxNombre;
					
					auxApellido = apellidos[i];
					apellidos[i] = apellidos[x];
					apellidos[x] = auxApellido;
					
					auxEdad = edades[i];
					edades[i] = edades[x];
					edades[x] = auxEdad;
					
					auxGenero = generos[i];
					generos[i] = generos[x];
					generos[x] = auxGenero;
					
					auxPeso = pesos[i];
					pesos[i] = pesos[x];
					pesos[x] = auxPeso;
			}
		  }	
		}	
	} // se cierra la opcion de organizar los pacientes en orden de edad 
		
} // se cierra la funcion mostrarPacientes 

void editarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], int tamano, int numPaciente, int editar){
       if (editar == 1){
    		cout << "Ingrese el nuevo nombre del paciente: ";
			cin >> nombres[numPaciente];	
	   } // si el usuario elije editar el nombre, se reemplaza el nombre registrado en el sistema por el nuevo que ingrese el usuario
	   if (editar == 2){
    		cout << "Ingrese el nuevo apellido del paciente: ";
			cin >> apellidos[numPaciente];	
	   } // si el usuario elije editar el apellido, se reemplaza el apellido registrado en el sistema por el nuevo que ingrese el usuario
	   if (editar == 3){
    		cout << "Ingrese la nueva edad del paciente: ";
			cin >> edades[numPaciente];	
	   } // si el usuario elije editar la edad, se reemplaza la edad registrada en el sistema por la nueva que ingrese el usuario
	   if (editar == 4){
    		cout << "Ingrese el nuevo genero del paciente: ";
			cin >> generos[numPaciente];	
	   } // si el usuario elije editar el genero, se reemplaza el genero registrado en el sistema por el nuevo que ingrese el usuario
	   if (editar == 5){
    		cout << "Ingrese la nueva estatura del paciente: ";
			cin >> estaturas[numPaciente];	
	   } // si el usuario elije editar la estatura, se reemplaza la estatura registrada en el sistema por la nueva que ingrese el usuario
	   if (editar == 6){
    		cout << "Ingrese el nuevo peso del paciente: ";
			cin >> pesos[numPaciente];	
	   } // si el usuario elije editar el peso, se reemplaza el peso registrado en el sistema por el nuevo que ingrese el usuario
} // se cierra la funcion editarPacientes

void buscarPacientes (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], int tamano, int menu4, string nomPaciente, string apePaciente){
    bool x = true; // variable auxiliar 
	for (int i = 0; i < tamano; i++){ // con el for se recorre el arreglo en busca del paciente que busca el usuario
		if (menu4 == 1){ // si el usuario busca al paciente por nombre se compara ese nombre ingresado con los registrados en el sistema y se le muestran los datos de ese paciente
			if (nomPaciente == nombres[i]){
	    		cout << "\n|| PACIENTE " << i << " ||";
				cout << "\nNombre: " << nombres[i] << endl;
				cout << "Apellido: " << apellidos[i] << endl;
				cout << "Edad: " << edades[i] << endl;
				cout << "Genero: " << generos[i] << endl;
				cout << "Estatura: " << estaturas[i] << endl;
				cout << "Peso: " << pesos[i] << endl;
				x = false;	
			} 
		}
		if (menu4 == 2){ // si el usuario busca al paciente por apellido se compara ese apellido ingresado con los registrados en el sistema y se le muestran los datos de ese paciente
			if (apePaciente == apellidos[i]){
	    		cout << "\n|| PACIENTE " << i << " ||";
				cout << "\nNombre: " << nombres[i] << endl;
				cout << "Apellido: " << apellidos[i] << endl;
				cout << "Edad: " << edades[i] << endl;
				cout << "Genero: " << generos[i] << endl;
				cout << "Estatura: " << estaturas[i] << endl;
				cout << "Peso: " << pesos[i] << endl;
				x = false;	
			} 
		}	
	} 
	if (x == true){
		cout << "\nNo hay resultados en el sistema" << endl; // si el nombre o apellido ingresado no esta en el sistema se le indica al usuario
	}          
}

int eliminarPaciente (string nombres[], string apellidos[], int pesos[], int edades[], char generos[], float estaturas[], int tamano, int menu2, string nomPaciente, string apePaciente){
	bool x = true;
	for (int i = 0; i < tamano; i++){
		if (menu2 == 1){
			if (nomPaciente == nombres[i]){
	    		for (int x = i; x < tamano; x++){
	    			nombres[x] = nombres[x + 1];
	    			apellidos[x] = apellidos[x + 1];
	    			edades[x] = edades[x + 1];
	    			generos[x] = generos[x + 1];
	    			estaturas[x] = estaturas[x + 1];
	    			pesos[x] = pesos[x + 1];
				}
				x = false;
				tamano = tamano - 1;
			} 
		}
		if (menu2 == 2){
			if (apePaciente == apellidos[i]){
	    		for (int x = i; x < tamano; x++){
	    			nombres[x] = nombres[x + 1];
	    			apellidos[x] = apellidos[x + 1];
	    			edades[x] = edades[x + 1];
	    			generos[x] = generos[x + 1];
	    			estaturas[x] = estaturas[x + 1];
	    			pesos[x] = pesos[x + 1];
				}
				x = false;
				tamano = tamano - 1;
			} 
		}	
	} 
	if (x == false){
		cout << "\nSe elimino el paciente correctamente" << endl; 
	}
	if (x == true){
		cout << "\nNo hay resultados en el sistema" << endl;
	}
	return tamano;
}
