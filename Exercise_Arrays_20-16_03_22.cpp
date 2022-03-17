/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 16/03/2022
    
    Alphabet pyramid alphabet
    
    This program print all the alfabeth in a pyramid down. The first line has all the letters beginning with 'Z'; and the last line has only the letter 'Z'.
*/
#include "iostream"
using namespace std;

int main(){
    // Clean the console
    system ("clear");

    int n=0;
    char alphabet[50]={' '};

    // Save the alphabet on an arrya
    for(char i='Z',j=1; i>='Z'-26,j<=26; i--,j++){
        alphabet[j]=i;
        // cout<<alphabet[j]<<" ";
    }

    // Start poster
    cout<<"|==============================================|\n";
    cout<<"|  ◘>#)↑#-A↓→  Piramide alfabetica ←↓A-#↑)#>◘  |\n";
    cout<<"|==============================================|\n\n";
    
    // cout<<"Ingrese la longitud de su cuadrado (no mayor a 50): ";
    for(int i=26; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<alphabet[j];
        }
        cout<<"\n";
    }

    cout<<"\n¡Tenga un excelente día!\n\n";
}