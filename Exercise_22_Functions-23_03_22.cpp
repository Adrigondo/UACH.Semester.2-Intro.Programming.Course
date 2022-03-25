/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 23/03/2022
    
    Factorial program
    This program read a n number and print the factorial for that number using functions.
*/
#include "iostream"
using namespace std;

void factorial(int n){
    cout<<"\n"<<n<<"! = ";
    int result=n;
    for(int i=1; i<n; i++){
        cout<<i<<" * ";
        result*=i;
    }
    cout<<n<<" = "<<result;
}

int main(){
    // Clean the console
    system ("clear");

    int n=0;
    char aux=' ';
    
    do{
        // Start poster
        cout<<"|=====================================|\n";
        cout<<"|         Numeros factoriales         |\n";
        cout<<"|=====================================|\n\n";
        cout<<"Ingrese un número: ";
        cin>>n;
        factorial(n);
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