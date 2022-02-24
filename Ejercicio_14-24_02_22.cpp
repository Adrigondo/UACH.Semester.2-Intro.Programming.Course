/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Thursday 02/24/2022
    
    Multiplier Program

    This program:
    - Read 2 numbers from the input console and return the multiplication.
    - The input only must be numbers between 10 and 20 including them.
    - After the multiplication, request to the user if wants multiplicate more numbers, else, the program ends.
*/
#include "iostream"
using namespace std;

int main(){
    float a=0, b=0;
    char aux='s';

    while(aux=='s'){
        // Start poster
        cout<<"°'''''''''''''''''''''''''''''''''''''''°\n";
        cout<<"°====      MULTIPLIC/\\DOR 3000      ====°\n";
        cout<<"°'''''''''''''''''''''''''''''''''''''''°\n\n";
        cout<<"|    Multiplicamos todos sus numeros    |\n| siempre que estén entre el 10 y el 20 |\n\n";

        // Make sure the input is correct
        cout<<"Ingrese 2 números a multiplicar (separados por espacio): ";
        cin>>a>>b;
        while(a<10||b<10||a>20||b>20){
            cout<<"\nERROR: Uno o ambos números no se encuentran entre el 10 y el 20.\n";
            cout<<"Por favor ingrese 2 números validos :";
            cin>>a>>b;
        }

        // Print the multiplication
        cout<<"\n\t|==============================|";
        cout<<"\n\t| El resultado de "<<a<<"x"<<b<<" es "<<a*b<<" |";
        cout<<"\n\t|==============================|\n\n";
        // printf("El resultado de %.2fx%.2f es %.2f", a, b, (a*b));

        // Request to the user if wants multiplicate more numbers
        cout<<"¿Desea multiplicar otros números? (s/n) : ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: Se ingresó una opción no válida.\n";
            cout<<"Si desea realizar otra multiplicación ingrese \'s\' o en caso contraro, ingrese \'n\' : ";
            cin>>aux;
        }
        // If the user entered 'n' the loop will end

        // Clean lines since menu
        system ("clear");
    }

    // Fired message
    cout<<"\n¡Gracias por utilizar el MULTIPLIC/\\DOR 3000!\n\n";
}