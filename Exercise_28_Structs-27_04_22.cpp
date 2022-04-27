/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 27/04/2022
    
    Structures program
*/
#include <bits/stdc++.h>
using namespace std;

struct Direccion{
    string calle;
    int numero;
    string colonia;
    string ciudad;
};

struct Fecha{
    int dia;
    int mes; 
    int anio;
};

struct Hora{
    int horas;
    int minutos;
    int segundos;
};

struct Cliente{
    string nombre;
    string apellido_paterno;
    string apellido_materno;
};

struct Factura{
    Direccion direccion;
    Fecha fecha;
    Hora hora;
    Cliente cliente;
    int numero_factura;
};
 
int main(){
    // Clean the console
    system ("clear");

    
}