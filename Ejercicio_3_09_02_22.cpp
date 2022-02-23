/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/

/*
    PROGRAMA DE BURRITOS
    Debe solicitar la cantidad de burritos y el tipo, y cobrar el total de la venta.

    Los tipos de burritos son:
        Rojos, valen $5.50 pesos
        Verdes, valen $10 pesos
        Chicharron, valen $10.5 pesos
    
    Descuentos a mayoreo:
        Más de 10 piezas: 5%
        Más de 20 piezas: 10%

    Solicitar redondeo.
*/
#include "iostream"
#include <bits/stdc++.h>
using namespace std;

struct Burrito {
    /*
        Modelo para los distintos tipos de burrito
    */
    string tipo;
    float precio;
} burritos[100];
int cant_tipos=0;

void definirTiposBurritos(){
    /*
        En esta función se pueden modificar los tipos de burritos disponibles
    */
    cant_tipos=3; // Si agregas o quitas burritos, debes modificar la cantidad de tipos

    burritos[1].tipo="Rojo"; //Los burritos deben de estar en secuencia comenzando por el 1, 2, 3, ...
    burritos[1].precio=5.50;

    burritos[2].tipo="Verde";
    burritos[2].precio=10;

    burritos[3].tipo="Chicharrón";
    burritos[3].precio=10.5;
    
    // burritos[n].tipo="TIPO_DE_BURRITO";
    // burritos[n].precio=PRECIO_BURRITO;
}

int main(){
    definirTiposBurritos();

    /*- - - - CARTEL DE INICIO - - - -*/
    cout<<"|=====================================|\n";
    cout<<"| BIENVENIDOS A LOS BURROS MAS BURROS |\n";
    cout<<"|=====================================|\n\n";


    int cant_burritos=0;
    float total=0;
    cout<<"Ingrese la cantidad de burritos a llevar:";
    cin>>cant_burritos;
    cout<<"\n";


    int eleccion=0;
    for(int i=1; i<=cant_burritos; i++){
        cout<<"¿De qué va a querer su burrito "<<i<<"?\n";
        for(int j=1; j<=cant_tipos; j++){
            cout<<"\t"<<j<<". Burrito de "<<burritos[j].tipo<<" ($"<<burritos[j].precio<<")";
        }
        cout<<"\n";
        cout<<"Ingrese el número del burrito que desea: ";
        cin>>eleccion;
        while(eleccion>cant_tipos||eleccion<1){
            cout<<"Por favor ingrese un numero de burrito válido: ";
            cin>>eleccion;
        }
        cout<<"\n";
        total+=burritos[eleccion].precio;
    }
    

    float descuento=0, cobro=0;
    if(cant_burritos>20){
        descuento=total*0.1;
        cout<<"(En la compra de más de 20 burritos o más se aplica 10% de descuento = $"<<descuento<<")\n";
    }else if(cant_burritos>10){
        descuento=total*0.05;
        cout<<"(En la compra de más de 10 burritos se aplica 5% de descuento = $"<<descuento<<")\n";
    }
    total=total-descuento;
    cout<<"El total a pagar son: $"<<total<<"\n";

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