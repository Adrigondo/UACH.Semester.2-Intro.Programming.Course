/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 03/02/2022
    
    Succesor numbers program 
    
    This program print a menu for do the follow operations:
    1. Print numbers from 0 to 100
    2. Print the squares of numbers from 1 to 10
    3. Print the numbers from 1 to 10000 in steps of 10 in 10
*/
#include "iostream"
using namespace std;

void printRange(int startRange, int endRange, int jumpRange, string operation){
    for(int i=startRange; i<=endRange; i+=jumpRange){
        if(operation=="square"){
            cout<<i<<"^2 = "<<i*i<<"\n";
        }else{
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}

int main(){
    int option=-1;
    int startRange=1;
    int jumpRange=1;
    int a=0, b=0, x=0;
    char aux;

    while(option!=0){
        // Start poster
        cout<<"!''''''''''''''''''''''''''''''''!\n";
        cout<<"!''     SUCESOR DE NÚMEROS     ''!\n";
        cout<<"!''''''''''''''''''''''''''''''''!\n\n";

        // Options menu
        cout<<"- Operaciones disponibles en el sucesor de números -";
        cout<<"\n1. Mostrar los números del 0 al 100";
        cout<<"\n2. Mostrar los cuadrados de los primeros 10 números naturales";
        cout<<"\n3. Mostrar los números del 0 al 10000 en saltos de 10";
        cout<<"\n0. Salir";

        // Read the option from the user
        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        if(option==0) break;

        
        // Perform the chosen operation
        cout<<"\nSeleccionó la opción "<<option<<": ";
        switch (option){
            case 1:
                cout<<"Mostrar los números del 0 al 100\n\n";
                printRange(0,100,1,"");
                break;

            case 2:
                cout<<"Mostrar los cuadrados de los primeros 10 números naturales\n\n";
                printRange(1,10,1,"square");
                break;

            case 3:
                cout<<"Mostrar los números del 0 al 10000 en saltos de 10\n\n";
                printRange(0,10000,10,"");
                break;

            default:
                break;
        }
        cout<<"\n";

        // Request to the user if wants do more operations
        cout<<"¿Desea realizar otra operación? (s/n) : ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: Se ingresó una opción no válida.\n";
            cout<<"Si desea realizar otra peración ingrese \'s\' o en caso contraro, ingrese \'n\' : ";
            cin>>aux;
        }

        // If the user entered 'n' the loop will end
        if(aux=='n') break;

        // Clean lines since menu
        system ("clear");
    }
    cout<<"\n¡Gracias por utilizar el sucesor de números!\n\n";
}