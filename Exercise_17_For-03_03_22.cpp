/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Tuesday 03/03/2022
    
    Smallest, Greatest and Average Program
    
    This program read an number N, and then N numbers n. The program calculates the greatest number, the smallest number, and the average from the read numbers.
*/
#include "iostream"
using namespace std;

int main(){
    // Clean the console
    system ("clear");

    int amountNumbers;
    double number, sum;
    double min=100000000, max=-100000000, average=0;
    char aux;

    do{
        // Start variables
        amountNumbers=0, min=100000000, max=-100000000, average=0, number=0, sum=0;

        // Start poster
        cout<<"|''''''''''''''''''''''''''''''''''''''''''''''''''''|\n";
        cout<<"|' El menor, el mayor y el feo, ¡UPS! y el promedio '|\n";
        cout<<"|''''''''''''''''''''''''''''''''''''''''''''''''''''|\n\n";
        
        // Read the amount of numbers
        do{
            cout<<"Ingresa la cantidad de números que deseas ingresar: ";
            cin>>amountNumbers;
            if(amountNumbers>0)break;
            cout<<"\n\tERROR: Debe ingresar un número entero positivo mayor a cero.\n\n";
        }while(amountNumbers<=0);

        cout<<"\nAhora ingresa "<<amountNumbers<<" números (Pueden ser decimales y/o negativos).\n";
        for(int i=1; i<=amountNumbers; i++){
            // Read a number
            cout<<"\tIngresa el "<<i<<"° número: ";
            cin>>number;
            if(number<min){
                min=number;
            }
            if(number>max){
                max=number;
            }
            sum+=number;
        }

        average=sum/double(amountNumbers);
        cout<<"\nEl menor número ingresado fue el "<<min;
        cout<<"\nEl mayor número ingresado fue el "<<max;
        cout<<"\nEl promedio de todos los números ingresados es "<<average;

        // Request to the user if wants do more operations
        cout<<"\n\n¿Desea realizar otro calculo? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: Se ingresó una opción no válida.\n";
            cout<<"Si desea realizar otro calculo ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }
        // Clean lines since menu
        system ("clear");
    }while(aux!='n');

    cout<<"¡Tenga un excelente día!\n\n";
}