/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Thursday 24/03/2022
    
    Factorial recursive program
    This program read a n number and print the factorial for that number using recursive functions
*/
#include "iostream"
using namespace std;

int factorial(int n){
    if(n==1){
        cout<<1;
        return 1;
    }else{
        int calculation=n*factorial(n-1);
        cout<<" * "<<n;
        // cout<<calculation<<" = q \n";
        return calculation;
    }
}

int main(){
    // Clean the console
    system ("clear");

    int n=0, result=0;;
    char aux=' ';
    
    do{
        // Start poster
        cout<<"|=====================================|\n";
        cout<<"|         Numeros factoriales         |\n";
        cout<<"|=====================================|\n\n";
        cout<<"Ingrese un número: ";
        cin>>n;
        cout<<n<<"! = ";
        result=factorial(n);
        cout<<" = "<<result;
        // Request to the user if wants do more lateral pyramids
        cout<<"\n\n¿Desea realizar otra operación factorial? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: La opción ingresada no es válida.\n";
            cout<<"Si desea realizar otro factorial ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }
        // Clean lines since menu
        system ("clear");
    }while(aux!='n');
    cout<<"¡Tenga un excelente día!\n\n";
}