
#include <iostream>

using namespace std;

int main() // Esta es la funcion principal, si checas hasta abajo entenderas pq este comentario
{
    cout<<"----------";
    cout<<" Calcular si es año bisiesto o no ";
    cout<<"----------\n\n";
 
    int number;
 
    cout << "Introduce el año que le interesa: ";
    cin  >> number;
 
    if( number%4==0 && (number%100!=0 || number%400==0) ){
        cout<< "El numero " << number << " es un año bisiesto\n"; 
    }else{
        cout<< "El numero " << number << " no es un año bisiesto\n"; 
    }
} // Esta es la llave que cierra la funcion principal, si creas algun if recuerda abrirlo {  y cerrarlo }  