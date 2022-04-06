/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Thursday 31/03/2022
    
    4 procedures in 1 program

    This program do the follow procedures:
    1. Read an array from the user
    2. Print the last array
    3. Print the memory addres of the last array
    4. Increase in 1 all the elements of the last array, and saves it
*/
#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int n;

void printAdvise();
void getData();
void printData();
void printDataMemoryAddress();
void increaseData(int *arr);

int main(){
    // Clean the console
    system ("clear");

    char option=' ';
    char aux=' ';

    do{
        // Start poster
        cout<<"|==========================================|\n";
        cout<<"|===     Procedimientos en arreglos     ===|\n";
        cout<<"|==========================================|\n\n";

        // Options menu
        cout<<"- Menu de procedimientos disponibles -";
        cout<<"\n1. Ingresar un nuevo arreglo.";
        cout<<"\n2. Imprimir el arreglo más reciente.";
        cout<<"\n3. Imprimir las direcciones de memoria del arreglo más reciente.";
        cout<<"\n4. Incrementar en 1 los valores del arreglo más reciente.";
        cout<<"\n0. Salir";

        // Read the option from the user
        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        while (option<48||option>52){
            cout<<"\n\nLa opción ingresada no existe, digite una opción valida: ";
            cin>>option;
        }
        
        if(option=='0') break;

        // Perform the chosen operation
        cout<<"\nSeleccionó la opción "<<option<<": ";
        switch (option){
            case '1':
                cout<<"Ingresar un nuevo arreglo.\n\n";
                getData();
                break;

            case '2':
                cout<<"Imprimir el arreglo más reciente.\n\n";
                printData();
                break;

            case '3':
                cout<<"Imprimir las direcciones de memoria del arreglo más reciente.\n\n";
                printDataMemoryAddress();
                break;

            case '4':
                cout<<"Incrementar en 1 los valores del arreglo más reciente.\n\n";
                increaseData(arr);
                break;

            default:
                break;
        }

        // Request to the user if wants do more procedures
        cout<<"\n\n¿Desea realizar otro procedimiento? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: La opción ingresada no es válida.\n";
            cout<<"Si desea realizar otro procedimiento ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }

        // Clean lines since menu
        system ("clear");
    }while(aux!='n');
    cout<<"¡Tenga un excelente día BIP BOP!\n\n";
}

void printAdvise(){
    cout<<"AVISO: El arreglo no tiene elementos aún, primero ingrese elementos y luego use esta opción.";
}
void getData(){
    cout<<"\nIngrese 'n' (n indica la cantidad de elementos del arreglo): ";
    cin>>n;

    cout<<"\nIngrese "<<n<<" elementos separados por un espacio: ";
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
}
void printData(){
    if(n!=0){
        cout<<"Actualmente tiene almacenados los siguientes elementos:\n ";
        for(int i=1; i<=n; i++){
            cout<<"\tElemento "<<i<<": "<<arr[i]<<"\n";
        }
    }else{
        printAdvise();
    }
}
void printDataMemoryAddress(){
    if(n!=0){
        cout<<"La direccion de memoria de los elementos almacenados es:\n  ";
        for(int i=1; i<=n; i++){
            cout<<"Elemento "<<i<<": "<<&arr[i]<<"\n";
        }
    }else{
        printAdvise();
    }
}
void increaseData(int *arr){
    if(n!=0){
        cout<<"Incrementando en 1 todos los elementos...\n  ";
        for(int i=1; i<=n; i++){
            // *(arr+i)
            cout<<"Elemento "<<i<<": "<<*(arr+i)<<" + 1 = "<<*(arr+i)+1<<"\n";
            *(arr+i)+=1;
        } 
    }else{
        printAdvise();
    }
}