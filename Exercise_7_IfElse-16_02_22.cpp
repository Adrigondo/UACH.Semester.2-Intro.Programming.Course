/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/

#include "iostream"
using namespace std;

int main(){
    cout<<"|''''''''''''''''''''''''''''''''|\n";
    cout<<"|''  VALIDADOR DE HORAS +PLUS  ''|\n";
    cout<<"|''''''''''''''''''''''''''''''''|\n\n";

    int hours, minutes, seconds;
    cout<<"Digite la hora: ";
    cin>>hours;

    cout<<"Digite los minutos: ";
    cin>>minutes;

    cout<<"Digite los segundos: ";
    cin>>seconds;

    bool isHour = (hours>=0)&&(hours<24);
    bool isMinute = (minutes>=0)&&(minutes<60);
    bool isSecond = (seconds>=0)&&(seconds<60);

    cout<<"\n";

    if( isHour && isSecond && isMinute ){
        cout<<"El tiempo ingresado es: "<<hours<<":"<<minutes<<":"<<seconds<<"\n";
    }else{
        cout<<"Ingrese un tiempo valido: \n";
        if(!isHour){
            cout<<"\t- Ingrese una hora valida.\n";
        }
        if(!isMinute){
            cout<<"\t- Ingrese minutos validos.\n";

        }
        if(!isSecond){
            cout<<"\t- Ingrese segundos validos.\n";

        }
    }
    cout<<"\n\n";
}