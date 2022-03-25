/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Thursday 24/03/2022
    
    Product of numbers recursive program
    
    This program calculates the product for 2 numbers with a recursive function
*/
#include "iostream"
using namespace std;

// long long int fibonacciSerie[50];

int product( int n, int m ){
    if(m==1){
        cout<<n;
        return n;
    }else{
        cout<<n<<" + ";
        return n+product(n,m-1);
    }
}

int main(){
    // Clean the console
    system ("clear");

    int first=0, second=0, result=0;
    char aux=' ';

    do{
        // Start poster
        cout<<"|======================================|\n";
        cout<<"|========= Productos en sumas =========|\n";
        cout<<"|======================================|\n\n";

        cout<<"Ingrese el primer número a multiplicar: ";
        cin>>first;
        cout<<"Ingrese el segundo número a multiplicar: ";
        cin>>second;
        
        cout<<"\n"<<first<<" * "<<second<<" = ";
        // Call the function
        result=product(first, second);
        cout<<" = "<<result;

        // Request to the user if wants do more fibonacci series
        cout<<"\n\n¿Desea realizar otro producto? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: La opción ingresada no es válida.\n";
            cout<<"Si desea realizar otro producto ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }

        // Clean lines since menu
        system ("clear");
    }while(aux!='n');
    cout<<"¡Tenga un excelente día BIP BOP!\n\n";
}