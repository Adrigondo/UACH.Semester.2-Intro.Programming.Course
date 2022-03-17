/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 16/03/2022
    
    Lateral N-pyramid of points program
    
    This program read a number n and return a lateral pyramid of points with n lines for height like follow:
    n=5
    .
    . .
    . . .
    . . 
    . 
*/
#include "iostream"
using namespace std;

int main(){
    // Clean the console
    system ("clear");

    int height=0, half=0;
    char box[50][50]={' '};
    char aux=0;

    do{
        // Start poster
        cout<<"|=======================================|\n";
        cout<<"|         Piramides-inador 3000         |\n";
        cout<<"|=======================================|\n\n";
        
        cout<<"Ingrese el alto de su piramide lateral (no mayor a 50): ";
        cin>>height;
        while(height>50||height<1){
            cout<<"\nERROR:  La longitud no es valida.\nIngrese una longitud válida: ";
            cin>>height;
        }
        cout<<"\n";

        half=height/2;
        // Growing part of the pyramid
        for(int i=1; i<=half; i++){
            for(int j=1; j<=i; j++){
                box[i][j]='.';
                cout<<box[i][j];
            }
            cout<<"\n";
        }

        // If the number is odd
        if(height%2==1){
            for(int j=1; j<=half+1; j++){
                box[half+1][j]='.';
                cout<<box[half+1][j];
            }
            cout<<"\n";
        }

        // Decreasing part of the pyramid
        for(int i=half; i>=1; i--){
            for(int j=1; j<=i; j++){
                cout<<box[i][j];
            }
            cout<<"\n";
        }

        // Request to the user if wants do more lateral pyramids
        cout<<"\n\n¿Desea realizar otra piramide? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: Se ingresó una opción no válida.\n";
            cout<<"Si desea dibujar otra piramide ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }
        // Clean lines since menu
        system ("clear");
    }while(aux!='n');

    cout<<"¡Gracias por usar el Piramides-inador 3000!\n\n";
}