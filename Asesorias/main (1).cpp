
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
 
 
    float residue = number % 4;

    if (residue == 0){
        cout<< "El numero " << number << " es multiplo de 4\n";
        
        residue = number % 100;
            
        if (residue == 0){
            cout<< " El numero " << number << " es multiplo de 100\n";
    
            residue = number % 400;

            if (residue == 0){
                cout<< " El numero " << number << " es multiplo de 400\n\n";
                cout<<"Entonces \n\n";
                cout<< "El numero " << number << " es un año bisiesto\n"; 
            }
            else{
                cout<< "El numero " << number << " no es multiplo de 400\n\n";
                cout<<"Entonces \n\n";
                cout<< "El numero " << number << " no es un año bisiesto\n"; 
            }

        }
        else{
            cout<< "El numero " << number << " no es multiplo de 100\n";
            cout<<"Entonces \n\n";
            cout<< "El numero " << number << " es un año bisiesto\n"; 
        }
    }
    else{
        cout<< "El numero " << number << " no es multiplo de 4\n";

        cout<<"Entonces \n\n";
        cout<< "El numero " << number << " no es un año bisiesto\n";
    }


} // Esta es la llave que cierra la funcion principal, si creas algun if recuerda abrirlo {  y cerrarlo }  