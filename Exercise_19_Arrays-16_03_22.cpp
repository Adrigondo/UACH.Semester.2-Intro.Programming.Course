/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 16/03/2022
    
    Array of numbers program
    
    This program read a number n and return a box with n*n points
*/
#include "iostream"
using namespace std;

int main(){
    // Clean the console
    system ("clear");

    int n=0;
    char box[50]={0};
    char aux=0;

    do{
        // Start poster
        cout<<"|==================================|\n";
        cout<<"|    Creador de cuadrados-punto    |\n";
        cout<<"|==================================|\n\n";
        
        cout<<"Ingrese la longitud de su cuadrado (no mayor a 50): ";
        cin>>n;
        while(n>50||n<1){
            cout<<"\nERROR:  La longitud no es valida.\nIngrese una longitud válida: ";
            cin>>n;
        }
        cout<<"\n";
        for(int i=1; i<=n; i++){
            box[i]='.';
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout<<box[j]<<" ";
            }
            cout<<"\n";
        }

        // Request to the user if wants do more squares of points
        cout<<"\n\n¿Desea realizar otro cuadrado-punto? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: Se ingresó una opción no válida.\n";
            cout<<"Si desea realizar otro cuadrado ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }
        // Clean lines since menu
        system ("clear");
    }while(aux!='n');

    cout<<"¡Tenga un excelente día!\n\n";
}
