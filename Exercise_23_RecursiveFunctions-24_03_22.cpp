/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Thursday 24/03/2022
    
    Fibonacci series recursive program
    
    This program calculates the fibonacci series for a n number received from the user. 
*/
#include "iostream"
using namespace std;

long long int fibonacciSerie[50];

int fibonacci(int n){
    if(fibonacciSerie[n]!=0){
        // Position n was already visited, so it doesn't need to be visited again
        return fibonacciSerie[n];
    }else if(n==0){
        // If n=0, it returns the first value of the serie(2)
        return 0;
    }else if(n==1){
        // If n=1, it returns the second value of the serie (1)
        fibonacciSerie[1]=1;
        // cout<<"0 1 ";
        return 1;
    }else{
        // If position n is not yet visited, save the value of the sum of the previous two elements in the array
        fibonacciSerie[n]=fibonacci(n-1)+fibonacci(n-2);
        // cout<<fibonacciSerie[n];
        return fibonacciSerie[n];
    }
}

int main(){
    // Clean the console
    system ("clear");

    int n=0, result=0;;
    char aux=' ';

    do{
        // Start poster
        cout<<"|======================================|\n";
        cout<<"| ?¿?¿?¿?¿ LA SERIE FIBONACCI ?¿?¿?¿?¿ |\n";
        cout<<"|======================================|\n\n";

        cout<<"Ingrese el número de elementos para su serie: ";
        cin>>n;

        cout<<"\nLa serie de fibbonacci con "<<n<<" elementos es: ";

        // Call the function
        fibonacci(n-1);
        // The fibonacci series is stored in the array up to the number n, so we can print it with a for
        for(int i=0; i<n; i++){
            cout<<fibonacciSerie[i]<<" ";
        }

        // Request to the user if wants do more fibonacci series
        cout<<"\n\n¿Desea realizar otra serie de fibonacci? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: La opción ingresada no es válida.\n";
            cout<<"Si desea realizar otra serie de fibonacci ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }

        // Clean lines since menu
        system ("clear");
    }while(aux!='n');
    cout<<"¡Tenga un excelente día JUAS JUAS JUAS!\n\n";
}