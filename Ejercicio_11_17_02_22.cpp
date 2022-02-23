/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/

#include "iostream"
using namespace std;

int main(){
    cout<<"°''''''''''''''''''''''''''°\n";
    cout<<"°''     LAS VOCALES      ''°\n";
    cout<<"°''''''''''''''''''''''''''°\n\n";

    char vowel;
    cout<<"Escriba un número: ";
    cin>>vowel;
    cout<<"\n";

    if(vowel=='a'||vowel=='e'||vowel=='i'||vowel=='o'||vowel=='u'){
        cout<<"La "<<vowel<<" en mayuscula es ";
        vowel=toupper(vowel);
        cout<<vowel;
    }else{
        cout<<"La letra ingresada no es una vocal minuscula";
    }
    cout<<"\n\n";
}