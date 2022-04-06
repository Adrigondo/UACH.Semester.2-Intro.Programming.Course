/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesdayb 06/04/2022
    
    14 procedures and functions in 1 program

    This program do the follow procedures/funtions:
    1.- A procedure that shows a greeting on the screen.
    2.- A function that calculates the square of any number and displays it on the screen
    3.- A procedure that shows on the screen the numbers from 1 to 100
    4.- A function that performs the average of two numbers, use a function.
    5.- A procedure that asks for the name, surname and a place and that shows a small history using the requested data
    6.- A procedure that asks for a number from 1 to 10 and that shows the number written in letters
    7.- Ask for a temperature in degrees Celsius on the screen, show a menu to convert them to Fahrenheit or Kelvin and show the equivalent on the screen, use functions
    8.- Show on the screen if a number is even or odd, use a function
    9.- To fill an array from 1 to 20, use a procedure
    10.- That shows the content of the previous array through a procedure
    11.- Show a multiplication table of any number on the screen, the number will be requested in the main program
    12.- Show 3 numbers ordered ascending and descending, use a procedure for each operation
    13.- Verify that a character entered is a number, use functions
    14.- Transform a number from 0 to 999 into Roman numerals, use functions.
*/
#include <bits/stdc++.h>
using namespace std;

int arr[21];

/* 1 */ void printGreeting();
/* 2 */ float square(float n);
/* 3 */ void numbers1To100();
/* 4 */ float mean2Numbers(float a, float b);
/* 5 */ void story();
/* 6 */ void nameNumber();
/* 7 */ float celciusToFahrenheit(float celcius);
/* 7 */ float celciusToKelvin(float celcius);
/* 7 */ void convertTemperature();
/* 8 */ string isPairOrOdd(int n);
/* 9 */ void numbersArray1To20(int *arr);
/* 10 */ void printNumbersArray1To20(int *arr);
/* 11 */ void multiplicationTable(int n);
/* 12 */ void sortAscending(int first, int second, int third);
/* 12 */ void sortDescending(int first, int second, int third);
/* 12 */ void sort3Numbers();
/* 13 */ string characterIsNumber(char character);
/* 14 */ string romanHundreds(int hundreds);
/* 14 */ string romanTens(int tens);
/* 14 */ string romanUnits(int units);
/* 14 */ string numberToRomanNumerals(int number);
 
int main(){
    // Clean the console
    system ("clear");

    int option=0;
    char aux=' ', character=' ';
    float number,a,b;
    string romanNumber;
    do{
        // Start poster
        cout<<"|===============================================|\n";
        cout<<"|=== .-.-.-. EL MULTIFUNCIONAL 14000 .-.-.-. ===|\n";
        cout<<"|===============================================|\n\n";

        // Options menu
        cout<<"- Menu de procedimientos disponibles -";
        cout<<"\n\t1. Saludar.";
        cout<<"\n\t2. Número al cuadrado.";
        cout<<"\n\t3. Números del 1 al 100.";
        cout<<"\n\t4. Media de 2 números.";
        cout<<"\n\t5. Cuenta cuentos.";
        cout<<"\n\t6. ¿Como se llama el número?.";
        cout<<"\n\t7. Conversor de temperaturas.";
        cout<<"\n\t8. ¿Es par, o impar?.";
        cout<<"\n\t9. Rellenar arreglo del 1 al 20.";
        cout<<"\n\t10. Mostrar arreglo de la opción 9.";
        cout<<"\n\t11. Tabla de multiplicar de un número.";
        cout<<"\n\t12. Ordenar 3 números.";
        cout<<"\n\t13. ¿Es número?.";
        cout<<"\n\t14. Conversor a números romanos.";
        cout<<"\n\t0. Salir";

        // Read the option from the user
        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        while (option<0||option>14){
            cout<<"\n\nLa opción ingresada no existe, digite una opción valida: ";
            cin>>option;
        }
        
        if(option==0) break;

        // Perform the chosen operation
        cout<<"\nSeleccionó la opción "<<option<<": ";
        switch (option){
            case 1:
                cout<<"\n\t1. Saludar.\n\n";
                printGreeting();
                break;

            case 2:
                cout<<"\n\t2. Número al cuadrado.\n\n";
                cout<<"Ingrese el número: ";
                cin>>number;
                cout<<number<<" * "<<number<<" = "<<square(number);
                break;

            case 3:
                cout<<"\n\t3. Números del 1 al 100.\n\n";
                numbers1To100();
                break;

            case 4:
                cout<<"\n\t4. Media de 2 números.\n\n";
                
                cout<<"Ingrese los números separados por espacio: ";
                cin>>a>>b;
                cout<<"( "<<a<<" + "<<b<<" ) / "<<2<<" = "<<mean2Numbers(a, b);
                break;

            case 5:
                cout<<"\n\t5. Cuenta cuentos.\n\n";
                story();
                break;

            case 6:
                cout<<"\n\t6. ¿Como se llama el número?.\n\n";
                nameNumber();
                break;

            case 7:
                cout<<"\n\t7. Conversor de temperaturas.\n\n";
                convertTemperature();
                break;

            case 8:
                cout<<"\n\t8. ¿Es par, o impar?.\n\n";
                
                cout<<"Ingrese el número: ";
                cin>>number;
                cout<<isPairOrOdd(int(number));
                break;

            case 9:
                cout<<"\n\t9. Rellenar arreglo del 1 al 20.\n\n";
                numbersArray1To20(arr);
                break;

            case 10:
                cout<<"\n\t10. Mostrar arreglo de la opción 9.\n\n";
                printNumbersArray1To20(arr);
                break;

            case 11:
                cout<<"\n\t11. Tabla de multiplicar de un número.\n\n";
                
                cout<<"Ingrese el número: ";
                cin>>number;
                multiplicationTable(int(number));
                break;

            case 12:
                cout<<"\n\t12. Ordenar 3 números.\n\n";
                sort3Numbers();
                break;

            case 13:
                cout<<"\n\t13. ¿Es número?.\n\n";
                
                cout<<"Ingrese solo 1 caracter para comprobar si es un número: ";
                cin>>character;
                cout<<characterIsNumber(character);
                break;

            case 14:
                cout<<"\n\t14. Conversor a números romanos.\n\n";
                
                cout<<"Ingrese el número a convertir (entre 1 y 999): ";
                cin>>number;
                romanNumber=numberToRomanNumerals(int(number));
                cout<<"\tEl numero en romano es: "<<romanNumber;
                break;

            default:
                break;
        }

        // Request to the user if wants do more procedures
        cout<<"\n\n¿Desea realizar otra operación? (s/n): ";
        cin>>aux;
        while(aux!='s'&&aux!='n'){
            cout<<"\nERROR: La opción ingresada no es válida.\n";
            cout<<"Si desea realizar otro procedimiento ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
            cin>>aux;
        }

        // Clean lines since menu
        system ("clear");
    }while(aux!='n'&&option!=0);
    cout<<"¡Tenga un excelente día BIP BOP!\n\n";
}

/* 1 */void printGreeting(){
    int a=rand() % 10 + 1;
    if(a<=3){
        cout<<"Hola extraño ._.";
    }else if(a>7){
        cout<<"¡Saludos, el fin se acerca!";
    }else{
        cout<<"Olá, ¿tudo bem?";
    }
}
/* 2 */float square(float n){
    return n*n;
}
/* 3 */void numbers1To100(){
    for(int i=1; i<=100; i++){
        cout<<i<<" ";
    }
}
/* 4 */float mean2Numbers(float a, float b){
    return (a+b)/2;
}
/* 5 */void story(){
    string name, lastname, place;
    cout<<"Ingrese el nombre de su personaje: ";
    cin>>name;
    cout<<"Ingrese el apellido de su personaje: ";
    cin>>lastname;
    cout<<"Ingrese el lugar de su historia: ";
    cin>>place;

    string storyText="Cuentan las historias que en un lugar muy muy lejano de las tierras mexicanas, haya en el antiguo reino de "+place+" existió alguna vez el rey o la reina "+name+" "+lastname+", aquella persona que fue hasta los confines de la tierra en busca de la paz, pero solo encontró";
    cout<<storyText<<"... (el redactor se quedó sin tiempo ni ideas, ¿deseas continar la historia? (s/n): ";

    char aux;
    // Request to the user if wants continue the story
    cin>>aux;
    while(aux!='s'&&aux!='n'){
        cout<<"\nERROR: La opción ingresada no es válida.\n";
        cout<<"Si desea continuar la historia ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
        cin>>aux;
    }
    string extraStory;
    if(aux=='s'){
        cout<<"\nContinue después del texto (para terminar pulse enter):\n";
        cout<<storyText;
        cin.ignore();
        getline(cin, extraStory);

        cout<<"\nAl continuar se borrará la historia, si desea guardarla copie el texto.\nPulse cualquier tecla para continuar... ";
        cin>>aux;
    }
}
/* 6 */void nameNumber(){
    int number;
    cout<<"Ingrese un numero del 1 al 10: ";
    cin>>number;
    while(number<1||number>10){
        cout<<"\nERROR: Debe ser un número entre el 1 al 10. Vuelva a intentarlo: ";
        cin>>number;
    }
    
    cout<<"\nSe ingresó el numero ";
    switch (number)
    {
    case 1:
        cout<<"uno";
        break;
    case 2:
        cout<<"dos";
        break;
    case 3:
        cout<<"tres";
        break;
    case 4:
        cout<<"cuatro";
        break;
    case 5:
        cout<<"cinco";
        break;
    case 6:
        cout<<"seis";
        break;
    case 7:
        cout<<"siete";
        break;
    case 8:
        cout<<"ocho";
        break;
    case 9:
        cout<<"nueve";
        break;
    case 10:
        cout<<"diez";
        break;
    default:
        break;
    }
}
/* 7 */void convertTemperature(){
    float celcius, fahrenheit, kelvin;
    char option;
    cout<<"Ingrese una temperatura en grados celcius (sin el °C): ";
    cin>>celcius;

    // Options menu
    cout<<"\n- Conversor de grados celcius -";
    cout<<"\n1. A fahrenheit (°F).";
    cout<<"\n2. A kelvin (K)";
    cout<<"\n0. Volver al menú principal";

    // Read the option from the user
    cout<<"\n\nDigite el número de la conversión que desea realizar: ";
    cin>>option;
    while (option<48||option>50){
        cout<<"\n\nLa opción ingresada no existe, digite una opción valida: ";
        cin>>option;
    }
    cout<<"\n\t";
    if(option=='0'){
        return;
    }else if(option=='1'){
        cout<<"La temperatura en °F es: ";
        cout<<celciusToFahrenheit(celcius);
    }else if(option=='2'){
        cout<<"La temperatura en K es: ";
        cout<<celciusToKelvin(celcius);
    }
    // Request to the user if wants do more procedures
    cout<<"\n\n¿Desea realizar otra conversión de temperatura? (s/n): ";
    cin>>option;
    while(option!='s'&&option!='n'){
        cout<<"\nERROR: La opción ingresada no es válida.\n";
        cout<<"Si desea realizar otro conversión ingrese \'s\' o en caso contrario, ingrese \'n\' : ";
        cin>>option;
    }
    if(option=='s'){
        cout<<"\n";
        convertTemperature();
    }

}
/* 7 */float celciusToFahrenheit(float celcius){
    float fahrenheit = celcius*1.8 + 32;
    return fahrenheit;
}
/* 7 */float celciusToKelvin(float celcius){
    float kelvin=celcius+273.15;
    return kelvin;
}

/* 8 */string isPairOrOdd(int n){
    string answer;
    if(n%2==0){
        answer="El número "+to_string(n)+" es par.";
    }else{
        answer="El número "+to_string(n)+" es impar.";
    }
    return answer;
}

/* 9 */void numbersArray1To20(int *arr){
    for(int i=1; i<=20; i++){
        *(arr+i)=i;
    }
    cout<<"Operación completada exitosamente (Si desea imprimir el arreglo seleccione la opción 10).";
}

/* 10 */void printNumbersArray1To20(int *arr){
    for(int i=1; i<=20; i++){
        cout<<*(arr+i)<<" ";
    }
}

/* 11 */void multiplicationTable(int n){
    for(int i=1; i<=10; i++){
        cout<<n<<" * "<<i<<" = "<<n*i<<"\n";
    }
}

/* 12 */void sortDescending(int first, int second, int third){
    if(first>=second&&second>=third){
        cout<<first<<" "<<second<<" "<<third;
    }else if(first>=second&&first>=third){
        cout<<first<<" "<<third<<" "<<second;
    }else if(first>=second){
        cout<<third<<" "<<first<<" "<<second;
    }else if(second>=third&&first>=third){
        cout<<second<<" "<<first<<" "<<third;
    }else if(second>=third){
        cout<<second<<" "<<third<<" "<<first;
    }else{
        cout<<third<<" "<<second<<" "<<first;
    }
}
/* 12 */void sortAscending(int first, int second, int third){
    if(first>=second&&second>=third){
        cout<<third<<" "<<second<<" "<<first;
    }else if(first>second){
        cout<<second<<" "<<third<<" "<<first;
    }else if(first==second){
        cout<<first<<" "<<second<<" "<<third;
    }else if(second>third&&first>=third){
        cout<<third<<" "<<first<<" "<<second;
    }else if(second>=third){
        cout<<first<<" "<<third<<" "<<second;
    }else{
        cout<<first<<" "<<second<<" "<<third;
    }
}
/* 12 */void sort3Numbers(){
    int first, second, third;
    cout<<"Ingrese los 3 números separados por un espacio: ";
    cin>>first>>second>>third;
    cout<<"\n\tOrden ascendente: "; sortAscending(first,second,third);
    cout<<"\n\tOrden descendente: "; sortDescending(first,second,third);
}

/* 13 */string characterIsNumber(char character){
    if(character<48||character>57){
        return "El caracter no es un número";
    }else{
        return "El caracter sí es un número";
    }
}

string romanUnits(int units){
    switch (units)
    {
    case 1: 
        return "I";
        break;
    case 2: 
        return "II";
        break;
    case 3: 
        return "III";
        break;
    case 4: 
        return "IV";
        break;
    case 5: 
        return "V";
        break;
    case 6: 
        return "VI";
        break;
    case 7: 
        return "VII";
        break;
    case 8: 
        return "VIII";
        break;
    case 9:
        return "IX";
        break;
    default:
        return "";
        break;
    }
}
string romanTens(int tens){
    switch (tens)
    {
    case 1: 
        return "X";
        break;
    case 2: 
        return "XX";
        break;
    case 3: 
        return "XXX";
        break;
    case 4: 
        return "XL";
        break;
    case 5: 
        return "L";
        break;
    case 6: 
        return "LX";
        break;
    case 7: 
        return "LXX";
        break;
    case 8: 
        return "LXXX";
        break;
    case 9:
        return "XC";
        break;
    default:
        return "";
        break;
    }
}
string romanHundreds(int hundreds){
    switch (hundreds)
    {
    case 1: 
        return "C";
        break;
    case 2: 
        return "CC";
        break;
    case 3: 
        return "CCC";
        break;
    case 4: 
        return "CD";
        break;
    case 5: 
        return "D";
        break;
    case 6: 
        return "DC";
        break;
    case 7: 
        return "DCC";
        break;
    case 8: 
        return "DCCC";
        break;
    case 9: 
        return "CM";
        break;
    default:
        return "";
        break;
    }
}
/* 14 */string numberToRomanNumerals(int number){

    while(number<1||number>999){
        cout<<"\nERROR: El número ingresado está fuera de rango.\n";
        cout<<"Ingrese un número entre 1 y 999: ";
        cin>>number;
    }

    int units = number % 10;
    number/=10;

    int tens = number % 10;
    number/=10;

    int hundreds = number % 10;
    number/=10;

    string answer = romanHundreds(hundreds);
    answer+=romanTens(tens);
    answer+=romanUnits(units);
    
    return answer;
}