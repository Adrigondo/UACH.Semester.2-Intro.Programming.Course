/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/

#include "iostream"
using namespace std;

int main(){
    cout<<"°''''''''''''''''''''''''''''''''°\n";
    cout<<"°''     LOS MESES DEL AÑO      ''°\n";
    cout<<"°''''''''''''''''''''''''''''''''°\n\n";

    int month;
    cout<<"Escriba un número: ";
    cin>>month;
    cout<<"\n";

    string months_names[13]={
        "", "Enero", "Febrero", "Marzo", "Abril",
        "Mayo", "Junio", "Julio", "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    switch (month)
    {
    case 1:
        cout<<"Corresponde al mes de "<<months_names[1];
        break;
    case 2:
        cout<<"Corresponde al mes de "<<months_names[2];
        break;
    case 3:
        cout<<"Corresponde al mes de "<<months_names[3];
        break;
    case 4:
        cout<<"Corresponde al mes de "<<months_names[4];
        break;
    case 5:
        cout<<"Corresponde al mes de "<<months_names[5];
        break;
    case 6:
        cout<<"Corresponde al mes de "<<months_names[6];
        break;
    case 7:
        cout<<"Corresponde al mes de "<<months_names[7];
        break;
    case 8:
        cout<<"Corresponde al mes de "<<months_names[8];
        break;
    case 9:
        cout<<"Corresponde al mes de "<<months_names[9];
        break;
    case 10:
        cout<<"Corresponde al mes de "<<months_names[10];
        break;
    case 11:
        cout<<"Corresponde al mes de "<<months_names[11];
        break;
    case 12:
        cout<<"Corresponde al mes de "<<months_names[12];
        break;
    default:
        cout<<"El numero ingresado no corresponde a un mes :(";
        break;
    }
    cout<<"\n\n";
}