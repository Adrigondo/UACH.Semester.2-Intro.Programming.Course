/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    This program calculate if the entered year is a leap year or not.
    
    A leap year must be a multiple of 4, but not a multiple of 100 unless it is a multiple of 400.
*/
#include "iostream"
using namespace std;

int main(){
    cout<<"|''''''''''''''''''''''''''|\n";
    cout<<"|'' CALCULO DE BISIESTOS ''|\n";
    cout<<"|''''''''''''''''''''''''''|\n\n";
    
    int year=0;
    cout<<"Ingrese un año: ";
    cin>>year;

    bool isMultiple4=!(year%4); /// Is true if number is multiple of 4
    bool isMultiple100=!(year%100); /// Is true if number is multiple of 100
    bool isMultiple400=!(year%400); /// Is true if number is multiple of 400

    if(  isMultiple4  ){ 
        if(!isMultiple100){
            cout<<"El año "<<year<<" es bisiesto.\n";
        }else if(isMultiple400){
            cout<<"El año "<<year<<" es bisiesto.\n";
        }else{
            cout<<"El año "<<year<<" no es bisiesto.\n";
        }
    }else{
        cout<<"El año "<<year<<" no es bisiesto.\n";
    }
}