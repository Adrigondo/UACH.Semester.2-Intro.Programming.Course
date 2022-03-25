/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Thursday 24/03/2022
    
    M-Power of N-number - recursive program
    
    This program calculates the m power for a n number with a recursive function
*/
#include "iostream"
using namespace std;

long long int power( int n, int m ){
    if(m==1){
        cout<<n;
        return n;
    }else if(m>0){ 
        cout<<n<<" * ";
        return n*power(n,m-1);
    }else{
        return 1;
    }
}

int main(){
    // Clean the console
    system ("clear");

    long long int base=0, exponent=0, result=0;
    char aux=' ';

    do{
        // Start poster
        cout<<"|======================================|\n";
        cout<<"|===     Potenciador de numeros     ===|\n";
        cout<<"|======================================|\n\n";

        cout<<"Ingrese el número base: ";
        cin>>base;
        cout<<"Ingrese el numero exponente: ";
        cin>>exponent;
        
        cout<<"\n"<<base<<" ^ "<<exponent<<" = ";
        // Call the function
        result=power(base, exponent);
        if(result<2){
            cout<<result;
        }else{
            cout<<" = "<<result;
        }
        // Request to the user if wants do more fibonacci series
        cout<<"\n\n¿Desea realizar otro producto? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: La opción ingresada no es válida.\n";
            cout<<"Si desea realizar otro producto ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }

        // Clean lines since menu
        system ("clear");
    }while(aux!='n');
    cout<<"¡Tenga un excelente día BIP BOP!\n\n";
}