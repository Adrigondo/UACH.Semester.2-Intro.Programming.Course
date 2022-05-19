#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    FILE *archivo;
    archivo = fopen("./Notas/Archivos_Prueba/hola.txt", "w");
    if(archivo==NULL){
        cout<<"ERROR: El archivo no existe.";
    }else{
        cout<<"Archivo creado";
    }
    fclose(archivo);
}