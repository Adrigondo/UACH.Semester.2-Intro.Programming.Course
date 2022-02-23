/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 02/23/2022
    
    Halves program  (Programa de mitades)
    
    This program print a menu for do the follow operations:
    1. Print the numbers from 0 to 100
    2. Print pair numbers from 0 to 100
    3. Print odd numbers from 0 to 100
    4. Print the amount of odd numbers from 0 to 100
    5. Request 2 numbers, then print the numbers between them and print the amount of numbers between
    6. Request a number and print the multiplication table for that number
*/
#include "iostream"
using namespace std;

void printRange(int startRange, int endRange, int jumpRange ){
    for(int i=startRange; i<=endRange; i+=jumpRange){
        cout<<i<<" ";
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
        cout<<"°'''''''''''''''''''''''''''''''°\n";
        cout<<"°''     EL MULTIFUNCIONES     ''°\n";
        cout<<"°'''''''''''''''''''''''''''''''°\n\n";

        // Options menu
        cout<<"- Operaciones disponibles en \"EL MULTIFUNCIONES\" -";
        cout<<"\n1. Mostrar los números del 0 al 100";
        cout<<"\n2. Mostrar los números pares del 0 al 100";
        cout<<"\n3. Mostrar los números impares del 0 al 100";
        cout<<"\n4. ¿Cuántos números impares hay del 0 al 100?";
        cout<<"\n5. Mostrar los números que hay entre 2 números a y b";
        cout<<"\n6. Tabla de multiplicar para un número x";
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
                printRange(0,100,1);
                break;


            case 2:
                cout<<"Mostrar los números pares del 0 al 100\n\n";
                printRange(0,100,2);
                break;


            case 3:
                cout<<"Mostrar los números impares del 0 al 100\n\n";
                printRange(1,100,2);
                break;


            case 4:
                cout<<"¿Cuántos números impares hay del 0 al 100?\n\n";
                cout<<"Hay 50 números impares\n";
                break;


            case 5:
                cout<<"Mostrar los números que hay entre 2 números a y b\n\n";
                cout<<"Ingrese a y b separados por espacio: ";
                cin>>a>>b;
                cout<<"\n";
                cout<<"Los números entre a y b son: ";
                printRange(a+1,b-1,1);
                cout<<"Hay "<<abs(a-b)-1<<" numeros entre "<<a<<" y "<<b<<"\n";
                break;

                
            case 6:
                cout<<"Tabla de multiplicar para un número x\n\n";
                cout<<"Ingrese el numero x: ";
                cin>>x;
                cout<<"\n";
                for(int j=1; j<=10; j++){
                    cout<<" "<<x<<"x"<<j<<"="<<x*j<<"\n";
                }
                break;


            default:
                break;
        }
        cout<<"\n";

        // Wait for lecture time
        cout<<"Pulse alguna tecla para continuar... ";
        cin>>aux;
        if(aux=='0')break;
        
        // Clean lines since menu
        system ("clear");
    }
    cout<<"\n¡Gracias por utilizar \"EL MULTIFUNCIONES\"!\n\n";
}