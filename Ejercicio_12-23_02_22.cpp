/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Halves program  (Programa de mitades)
    
    This program:
    1. Request the user for many numbers, until the user enters 0.
    2. For each number, print it divided in 2.
    3. When the user enters 0, print the amount of numbers entered.
*/
#include "iostream"
using namespace std;

int main(){
    // Start poster
    cout<<"°'''''''''''''''''''''''''°\n";
    cout<<"°''      MIT/\\DES       ''°\n";
    cout<<"°'''''''''''''''''''''''''°\n\n";
    cout<<"(Digite 0 en cualquier momento para terminar)\n\n";

    float number=1;
    int counter=0;

    // The user enters numbers to divide in 2, until enters 0
    while(number!=0){
        counter++;
        
        cout<<"Ingrese un numero: ";
        cin>>number;
        
        cout<<"La mitad de su numero es: "<<number/2<<"\n";
    }

    // If the user enters 0, the counter will add it, but 0 doesn't count
    counter--;

    // Show how many numbers were entered by the user
    if(counter==1){
        cout<<"Gracias, ingresó "<<counter<<" número.";
    }else{
        cout<<"Gracias, ingresó "<<counter<<" números.";
    }
    cout<<"\n\n";
}