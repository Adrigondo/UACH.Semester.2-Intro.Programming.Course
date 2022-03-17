/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/

#include "iostream"
using namespace std;

int main(){
    cout<<"|''''''''''''''''''''''''''''''''|\n";
    cout<<"|'' CALCULO DE PARES E IMPARES ''|\n";
    cout<<"|''''''''''''''''''''''''''''''''|\n\n";
    
    int number=0;
    cout<<"Ingrese un número: ";
    cin>>number;

    bool residue=number%2; /// residue is false if number is pair, or true if number is odd
    if(residue){ 
        cout<<"El número "<<number<<" es impar.\n";
    }else{
        cout<<"El número "<<number<<" es par.\n";
    }
}