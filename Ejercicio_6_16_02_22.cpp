/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/

#include "iostream"
using namespace std;

int main(){
    cout<<"|''''''''''''''''''''''''''''''''|\n";
    cout<<"|''   VALIDADOR DE SUMAS PRO   ''|\n";
    cout<<"|''''''''''''''''''''''''''''''''|\n\n";

    int num1, num2, sum_user, sum;
    cout<<"Digite los 2 números separados por 1 espacio: ";
    cin>>num1>>num2;

    cout<<"Ahora digite la suma de los números: ";
    cin>>sum_user;

    sum=num1+num2;
    if(sum!=sum_user){
        cout<<"ERRONEO: La suma correcta es "<<sum;
    }else{
        cout<<"CORRECTO: Sigue así! :) ";
    }
    cout<<"\n\n";
}