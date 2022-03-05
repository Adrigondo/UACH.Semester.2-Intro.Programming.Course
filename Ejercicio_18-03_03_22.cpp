/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Tuesday 03/03/2022
    
    The numeric serie Program
    
    This program read calculates the value of 1/(2*1) + 2/(2*2) + 3/(2*3) + 4/(2*4) + ... + n/(2*n) for a number n.
*/
#include "iostream"
using namespace std;

int main(){
    // Clean the console
    system ("clear");

    float n=0;
    float calculation=0;
    char aux=0;

    do{
        // Start variables
        n=0, calculation=0, aux=0;
        // Start poster
        cout<<"|===========================================================================|\n";
        cout<<"| Calculo de la serie 1/(2*1) + 2/(2*2) + 3/(2*3) + 4/(2*4) + ... + n/(2*n) |\n";
        cout<<"|===========================================================================|\n\n";
        cout<<"Ingrese el número n: ";
        cin>>n;
        for(float i=1; i<n; i++){
            cout<<i<<"/(2*"<<i<<") + ";
            calculation+=(i/(2*i));
        }
        cout<<n<<"/(2*"<<n<<") = ";
        calculation+=(n/(2*n));
        cout<<calculation;
        // Request to the user if wants do more operations
        cout<<"\n\n¿Desea realizar otro calculo? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: Se ingresó una opción no válida.\n";
            cout<<"Si desea realizar otro calculo ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }
        // Clean lines since menu
        system ("clear");
    }while(aux!='n');

    cout<<"¡Tenga un excelente día!\n\n";
}