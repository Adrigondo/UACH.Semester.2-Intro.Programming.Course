/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 12/05/2022
    
    Invoice managment program

    This program contain the following characteristics:
    1.- A structure for the seasons of the year
    2.- Return the season corresponging to use input
    3.- A structure for a student and the read of its fields
    4.- A structure for date, and a function that calculates the amount of days between 2 dates. 
    
*/
#include <bits/stdc++.h>
using namespace std;

string months_SPANISH[]={
    "", "Enero", "Febrero", "Marzo", "Abril",
    "Mayo", "Junio", "Julio", "Agosto",
    "Septiembre", "Octubre", "Noviembre", "Diciembre"
};
int month_days=30;
int extra_days[]={ 0, 1, -2, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};

struct Address{
    string street="";
    string number="";
    string suburb="";
    string city="";
} null_address={"", "", "", ""};

struct Date{
    int day=0;
    int month=0;
};

struct YearStation{
    string name;
    Date begin;
    Date end;
    string description;
}year_stations[5];

struct Grade{
    string course="";
    int value=0;
};

struct Student{
    string full_name="";
    int age=0;
    Address address=null_address;
    Grade grades[11];
};

/* --------------------------------DECLARATIONS---------------------------------------------*/
void printStartBanner();
void cleanScreen();

string toLowerString(string text);
void initializeYearStations();
void printYearStation();
void searchYearStation();
void notifySave(int status);

Student setNewStudent();

int daysBetween(Date firstDate, Date secondDate);
void getdaysBetweenDates();


/* --------------------------------------MAIN--------------------------------------------------*/

int main(){
    // Clean the console
    system ("clear");

    initializeYearStations();

    int option=0;
    do {
        printStartBanner();

        // Options menu
        cout<<"- Menu de operaciones disponibles -";
        cout<<"\n\t1. Buscar estación del año.";
        cout<<"\n\t2. Ingresar datos de alumno.";
        cout<<"\n\t3. Calcular días entre 2 fechas distintas.";
        cout<<"\n\t0. Salir";

        // Read the option from the user
        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        while (option<0||option>5){
            cout<<"\n\nLa opción ingresada no existe, digite una opción valida: ";
            cin>>option;
        }
        
        if(option==0) break;

        cleanScreen();

        // Perform the chosen operation
        cout<<"\nSeleccionó la opción: ";
        switch (option){
            case 1:
                cout<<"\n\t1. Buscar estación del año.\n\n";
                searchYearStation();
                break;

            case 2:
                cout<<"\n\t2. Ingresar datos de alumno.\n\n";
                setNewStudent();
                break;

            case 3:
                cout<<"\n\t3. Calcular días entre 2 fechas distintas.\n\n";
                getdaysBetweenDates();
                break;

            default:
                break;
        }

        notifySave(1);

        // Clean lines since menu
        system ("clear");
    }while(option!=0);
    cout<<"¡Tenga un excelente día BIP BOP!\n\n";
}

/* --------------------------------IMPLEMENTATIONS---------------------------------------------*/

void printStartBanner(){
    // Start poster
    cout<<"|=======================================================================|\n";
    cout<<"|= .-. Estaciones del año, estudiantes y fechas xD (por Adrigondo) .-. =|\n";
    cout<<"|=======================================================================|\n\n";
}
void cleanScreen(){
    // Clean screen
    system ("clear");
}
void notifySave(int status){
    string aux;
    if(status==0){
        cout<<"\n\nOperación no completada :(";
    }else if(status==1){
        cout<<"\n\n¡Operación exitosa!";
    }
    cout<<"\nPulse [enter] para continuar...";
    cin.ignore();
    getline(cin, aux);
}


void initializeYearStations(){
    YearStation newStation;
    Date date_aux;

    
    newStation.name="Primavera";
    newStation.description="Durante esta época, los árboles comienzan a reverdecer, y las plantas a florecer.";

    date_aux.day=20;
    date_aux.month=3;
    newStation.begin=date_aux;

    date_aux.day=21;
    date_aux.month=6;
    newStation.end=date_aux;

    year_stations[1]=newStation;


    newStation.name="Verano";
    newStation.description="​Se caracteriza porque los días son más largos y las noches más cortas, además de ser la estación más calida.";

    newStation.begin=date_aux;

    date_aux.day=22;
    date_aux.month=9;
    newStation.end=date_aux;

    year_stations[2]=newStation;

    
    newStation.name="Otoño";
    newStation.description="​Durante esta estación la temperatura comienza a descender. Las hojas de los árboles cambian su color a tonos ocres, hasta que se secan y caen ayudadas por el viento que sopla con mayor fuerza.";

    newStation.begin=date_aux;

    date_aux.day=21;
    date_aux.month=12;
    newStation.end=date_aux;

    year_stations[3]=newStation;


    newStation.name="Invierno";
    newStation.description="​Se caracteriza por días más cortos, noches más largas y temperaturas más bajas a medida que nos alejamos de la línea ecuatorial.";

    newStation.begin=date_aux;

    date_aux.day=20;
    date_aux.month=3;
    newStation.end=date_aux;

    year_stations[4]=newStation;

}

string toLowerString(string text){
    for_each(text.begin(), text.end(), [](char &letter){
        letter=towlower(letter);
    });
    return text;
}

void printYearStation(YearStation station){
    cout<<"Estación del año: "<<station.name<<"\n";
    cout<<"\n\tDescrición: "<<station.description;
    cout<<"\n\tInicia: "<<station.begin.day<<" de "<<months_SPANISH[station.begin.month];
    cout<<"\n\tTermina: "<<station.end.day<<" de "<<months_SPANISH[station.end.month];
    cout<<"\n";
}

YearStation* getYearStation(string station_name){
    for(int i=1; i<=4; i++){
        if(station_name==toLowerString(year_stations[i].name)){
            return (year_stations+i);
            // printYearStation(i);
            // response=true;
            break;
        }
    }
    return NULL;
}

void searchYearStation(){
    string station_name;
    bool response=false;
    cout<<"Ingresa el nombre de la estación del año que deseas buscar: ";
    cin>>station_name;
    cout<<"\n";
    station_name=toLowerString(station_name);
    YearStation* station=getYearStation(station_name);
    if(station==NULL){
        cout<<"Escribiste mal el nombre de la estación (checa que esté en español y esrita correctamente).";
    }else{
        printYearStation(*station);
    }
}

Student setNewStudent(){
    Student student;
    cout<<"Ingrese el nombre completo del estudiante [sin pulsar enter hasta terminar]: ";
    cin.ignore();
    getline(cin, student.full_name);
    cout<<"Ingrese la edad del estudiante (en años): ";
    cin>>student.age;
    cout<<"A continuación ingrese los datos de la dirección del estudiante: \n";
    cout<<"  > Ciudad: ";
    cin.ignore();
    getline(cin, student.address.city);
    cout<<"  > Colonia: ";
    getline(cin, student.address.suburb);
    cout<<"  > Calle: ";
    getline(cin, student.address.street);
    cout<<"  > Número de casa: ";
    getline(cin, student.address.number);
    cout<<"A continuación ingrese las calificaciones del estudiante: \n";
    for(int i=1; i<=10; i++){
        cout<<"  > Calificación "<<i<<"\n";
        cout<<"    - Nombre de la asignatura: ";
        cin.ignore();
        getline(cin, student.grades[i].course);
        cout<<"    - Calificación del estudiante en la asignatura: ";
        cin>>student.grades[i].value;
    }

    cout<<"\n|||> Estudiante registrado ";
    cout<<"\nNombre completo: "<<student.full_name;
    cout<<"\nEdad: "<<student.age<<" años";
    cout<<"\nDirección: "<<student.address.city<<", "<<student.address.street<<" #"<<student.address.number<<" Col. "<<student.address.suburb;
    cout<<"\nCalificaciones: ";
    for(int i=1; i<=10; i++){
        cout<<"\n  >"<<student.grades[i].course<<": "<<student.grades[i].value;
    }
    cout<<"\n";
    
    return student;
}


int daysBetween(Date firstDate, Date secondDate){
    Date aux;
    int days;
    int days_month;

    if(firstDate.month>secondDate.month||(firstDate.month==secondDate.month&&firstDate.day>secondDate.day)){
        aux=firstDate;
        firstDate=secondDate;
        secondDate=aux;
    }

    if(firstDate.month==secondDate.month){
        days=secondDate.day-firstDate.day;
        return days;
    }
    days_month=month_days+extra_days[firstDate.month];
    // cout<<"DEV - dias del mes inicial: "<<days_month<<" extra["<<firstDate.month<<"] = "<<extra_days[firstDate.month]<<"\n";
    days=(days_month - firstDate.day) + secondDate.day;

    for(int i=firstDate.month+1; i<secondDate.month; i++){
        days+=(month_days+extra_days[i]);
    }
    return days;
}

void getdaysBetweenDates(){
    Date firstDate;
    Date secondDate;
    cout<<"Ingrese el número de mes de la primer fecha: ";
    cin>>firstDate.month;
    while(  firstDate.month<1  ||  firstDate.month>12  ){
        cout<<"Numero de mes invalido, ingrese un mes valido: ";
        cin>>firstDate.month;
    }
    cout<<"Ingrese el número de día de la primer fecha: ";
    cin>>firstDate.day;
    while(  firstDate.day<1  ||  firstDate.day>(month_days+extra_days[firstDate.month]  )){
        cout<<"Numero de día invalido, ingrese un día valido: ";
        cin>>firstDate.day;
    }

    cout<<"Ingrese el número de mes de la segunda fecha: ";
    cin>>secondDate.month;
    while(  secondDate.month<1  ||  secondDate.month>12  ){
        cout<<"Numero de mes invalido, ingrese un mes valido: ";
        cin>>secondDate.month;
    }
    cout<<"Ingrese el número de día de la segunda fecha: ";
    cin>>secondDate.day;
    while(  secondDate.day<1  ||  secondDate.day>(month_days+extra_days[secondDate.month]  )){
        cout<<"Numero de día invalido, ingrese un día valido: ";
        cin>>secondDate.day;
    }

    int days_between=daysBetween(firstDate, secondDate);

    cout<<"La cantidad de días entre ambas fechas son: "<<days_between<<"\n";
}