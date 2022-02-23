/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/

/*
    Burritos program v2.0
*/
#include "iostream"
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Burrito {
    /*
        Burritos kind model
    */
    string kind;
    float price;
} burritos[100];
int amount_kinds=0;

void defineKindsBurritos(){
    /*
        In this function you can modify the kind of burritos
    */
    amount_kinds=6; // If you add or remove burritos, you must change this variable for the exact number of burritos

    burritos[1].kind="Deshebrada rojo"; //Burritos must be on sequence starting by [1], [2], [3], ..., [n]
    burritos[1].price=1;

    burritos[2].kind="Deshebrada verde";
    burritos[2].price=2;

    burritos[3].kind="Chicharron";
    burritos[3].price=3;

    burritos[4].kind="Mole";
    burritos[4].price=4;

    burritos[5].kind="Discada";
    burritos[5].price=5;

    burritos[6].kind="Chile relleno";
    burritos[6].price=6;
    
    // burritos[n].kind="TIPO_BURRITO";
    // burritos[n].price=PRECIO_BURRITO;
}

int main(){
    system ("clear");
    defineKindsBurritos();

    int amount_burritos=0, total_amount_burritos=0;
    // int lines_clean;
    float total=0;
    int option=1;
    float discount=0;
    char aux;
    
    // Program while
    while(option!=0){
        /*- - - - START POSTER - - - -*/
        cout<<"|=========================================|\n";
        cout<<"| BIENVENIDOS A LOS BURROS MAS BURROS 2.0 |\n";
        cout<<"|=========================================|\n\n";


        // Print Menu
        cout<<"\t- MENU -\t\t      - PRECIO -\n";
        for(int i=1; i<=amount_kinds; i++){
            printf("(%d) Burrito de %-25s $%.2f\n",i, burritos[i].kind.c_str(), burritos[i].price);
        }
        cout<<"(0) Salir y/o pagar por su orden\n\n";

        // Read the option of the user
        cout<<"Ingrese una opción: ";
        cin>>option;
        while(option>amount_kinds||option<0){
            cout<<"Por favor ingrese una opción válida: ";
            cin>>option;
        }


        if(option!=0){
            cout<<"¿Cuantos burritos de "<<burritos[option].kind<<" quiere? ";
            cin>>amount_burritos;
            while(amount_burritos<1){
                cout<<"Ingresa una cantidad válida: ";
                cin>>amount_burritos;
            }
            total_amount_burritos+=amount_burritos;
            // Print count
            total+=(burritos[option].price*amount_burritos);
            cout<<"La cuenta al momento es: $"<<total<<"\n";
            cout<<"Pulse alguna tecla para continuar... ";
            cin>>aux;
            // Clean lines since menu
            system ("clear");
        }
    }
    
    cout<<"La cuenta por todo son: $"<<total<<"\n";
    if(total_amount_burritos>20){
        discount=total*0.1;
        cout<<"(En la compra de más de 20 burritos se aplica 10% de descuento) -$"<<discount<<"\n";
    }else if(total_amount_burritos>10){
        discount=total*0.05;
        cout<<"(En la compra de más de 10 burritos se aplica 5% de descuento) -$"<<discount<<"\n";
    }
    total=total-discount;
    cout<<"El total a pagar con descuento es: $"<<total<<"\n";

    int redondeo=ceil(total);
    if(redondeo!=total){
        char siRedondea;
        cout<<"¿Desea redondear los centavos? (s/n): ";
        cin>>siRedondea;
        if(siRedondea=='s'){
            cout<<"¡Gracias :D! \n";
            cout<<"El total a pagar son: $"<<redondeo<<"\n";
        }
    }
    cout<<"¡Gracias por su compra! \n";

}