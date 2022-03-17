/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 03/02/2022
    
    Body Mass Index program 
    
    This program reads the weight and height from the user and calculates his BMS
    If the BMS is:
    - Less than 20 print underweight warning
    - Between 20 and 25 print congratulations for his weight
    - Between 25 and 30 print overweight warning
    - Between 30 and 35 print obesity warning
    - Greater than 35 print morbid obesity warning
*/
#include "iostream"
using namespace std;

int main(){
    // Clean the console
    system ("clear");

    float weight=0, height=0;
    float BMI=0;
    int rangeCounter[6]={0};
    char aux;

    do{
        
        // Start poster
        cout<<"!'''''''''''''''''''''''''''''''''''''!\n";
        cout<<"!''     INDICE DE MASA CORPORAL     ''!\n";
        cout<<"!'''''''''''''''''''''''''''''''''''''!\n\n";

        // Read the weight of the user
        do{
            cout<<"Por favor digite su peso en kilogramos: ";
            cin>>weight;
            if(weight>0)break;
            cout<<"\n\tERROR: Se ingresó un peso nulo o negativo. Debe ingresar su peso real.\n\n";
        }while(weight<=0);

        // Read the height of the user
        do{
            cout<<"Por favor digite su estatura en metros: ";
            cin>>height;
            if(height>0)break;
            cout<<"\n\tERROR: Se ingresó una estatura nula o negativa. Debe ingresar su estatura real.\n\n";
        }while(height<=0);
        cout<<"\n";

        // Calculation of the BMI
        BMI=weight/(height*height);

        if(BMI<20){
            cout<<"Peligro, estas bajo de peso";
            rangeCounter[1]++;
        }else if(BMI>=20&&BMI<25){
            cout<<"Felicidades estas en tu peso";
            rangeCounter[2]++;
        }else if(BMI>=25&&BMI<30){
            cout<<"Tienes sobrepeso";
            rangeCounter[3]++;
        }else if(BMI>=30&&BMI<35){
            cout<<"Tienes obesidad";
            rangeCounter[4]++;
        }else if(BMI>=35){
            cout<<"Tienes obesidad morbida";
            rangeCounter[5]++;
        }
        cout<<"\n\n";

        // Request to the user if wants do more operations
        cout<<"¿Desea realizar otro indice de masa corporal? (s/n) : ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: Se ingresó una opción no válida.\n";
            cout<<"Si desea realizar otro diagnostico ingrese \'s\' o en caso contraro, ingrese \'n\' : ";
            cin>>aux;
        }
        // Clean lines since menu
        system ("clear");
    }while(aux!='n');

    // Print the registry of calculations of BMI
    cout<<"A continuación se muestran la cantidad de diagnosticos realizados:\n";
    cout<<"\n\t- Personas bajas de peso: "<<rangeCounter[1];
    cout<<"\n\t- Personas en peso ideal: "<<rangeCounter[2];
    cout<<"\n\t- Personas con sobrepeso: "<<rangeCounter[3];
    cout<<"\n\t- Personas con obesidad: "<<rangeCounter[4];
    cout<<"\n\t- Personas con obesidad morbida: "<<rangeCounter[5];

    cout<<"\n\n¡Tenga un excelente día!\n\n";
}