/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 28/04/2022
    
    Invoice managment program

    This program do the follow operations through a menu:
    1.- Catch a new invoice
    2.- Edit an existen invoice
    3.- Delete an existent invoice
    4.- List the invoices (only the number of each invoice)
    5.- Show an especific invoice
    
*/
#include <bits/stdc++.h>
using namespace std;



struct Address{
    string calle="";
    int numero=0;
    string colonia="";
    string ciudad="";
};
struct Date{
    int dia=0;
    int mes=0; 
    int anio=0;
};
struct Time{
    int horas=0;
    int minutos=0;
    int segundos=0;
};
struct Customer{
    string nombre="";
    string apellido_paterno="";
    string apellido_materno="";
};
struct Invoice{
    Address address;
    Date date;
    Time time;
    Customer customer;
    int invoice_number;
};


/* --------------------------------DECLARATIONS---------------------------------------------*/

Invoice invoice_empty;
Invoice invoices_list[11];
int amount_invoices=0;

Address getAddressData();
Date getDateData();
Time getTimeData();
Customer getCustomerData();
Invoice getInvoiceData();
/*1*/ void catchInvoice();

void editCustomer(Invoice &invoice);
void editAddress(Invoice &invoice);
void editDateTime(Invoice &invoice);
/*2*/ void editInvoice();

/*3*/ void deleteInvoice();
/*4*/ void listInvoices();
/*5*/ void showInvoice();

bool areThereInvoices();
int searchInvoice(Invoice &invoice, int invoice_number);
void printInvoiceData(Invoice invoice);
void cleanScreen();
void notifySave();

/* --------------------------------------MAIN--------------------------------------------------*/

int main(){
    // Clean the console
    system ("clear");

    int option=0;
    do {
        // Start poster
        cout<<"|=====================================================|\n";
        cout<<"|= .-.-. FACTURADOR AUTOMÁTICO (por Adrigondo) .-.-. =|\n";
        cout<<"|=====================================================|\n\n";

        // Options menu
        cout<<"- Menu de operaciones disponibles -";
        cout<<"\n\t1. Capturar nueva factura.";
        cout<<"\n\t2. Editar factura existente.";
        cout<<"\n\t3. Eliminar factura existente.";
        cout<<"\n\t4. Listar facturas (numeros de facturas).";
        cout<<"\n\t5. Ver factura por su número.";
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
                cout<<"\n\t1. Capturar nueva factura.\n\n";
                catchInvoice();
                break;

            case 2:
                cout<<"\n\t2. Editar factura existente.\n\n";
                editInvoice();
                break;

            case 3:
                cout<<"\n\t3. Eliminar factura existente.\n\n";
                deleteInvoice();
                break;

            case 4:
                cout<<"\n\t4. Listar facturas (numeros de facturas).\n\n";
                listInvoices();
                break;

            case 5:
                cout<<"\n\t5. Ver factura por su número.\n\n";
                showInvoice();
                break;

            default:
                break;
        }

        notifySave();

        // Clean lines since menu
        system ("clear");
    }while(option!=0);
    cout<<"¡Tenga un excelente día BIP BOP!\n\n";
}

/* --------------------------------IMPLEMENTATIONS---------------------------------------------*/

void cleanScreen(){
    // Clean screen
    system ("clear");
}
void notifySave(){
    string aux;
    cout<<"\n\n¡Operación exitosa!";
    cout<<"\nPulse [enter] para continuar...";
    cin.ignore();
    getline(cin, aux);
}
bool areThereInvoices(){
    if(amount_invoices==0){
        cout<<"[No hay facturas registradas]";
        return false;
    }
    return true;
}

Customer setCustomerData(){
    Customer customer;

    cout<<"\nIngrese sus datos personales:\n";
    cout<<"  Nombre: ";
    cin>>customer.nombre;
    cout<<"  Apellido paterno: ";
    cin>>customer.apellido_paterno;
    cout<<"  Apellido materno: ";
    cin>>customer.apellido_materno;

    return customer;
}
Address setAddressData(){
    Address address;

    cout<<"\nIngrese los datos de su dirección:\n";
    cout<<"  Ciudad: ";
    cin>>address.ciudad;
    cout<<"  Colonia: ";
    cin>>address.colonia;
    cout<<"  Calle: ";
    cin>>address.calle;
    cout<<"  Número: ";
    cin>>address.numero;

    return address;
}
Date setDateData(){
    Date date;

    cout<<"\nIngrese la fecha:\n";
    cout<<"  Dia: ";
    cin>>date.dia;
    cout<<"  Mes: ";
    cin>>date.mes;
    cout<<"  Año: ";
    cin>>date.anio;

    return date;
}
Time setTimeData(){
    Time time;

    cout<<"\nIngrese la hora:\n";
    cout<<"  Hora: ";
    cin>>time.horas;
    cout<<"  Minuto: ";
    cin>>time.minutos;
    cout<<"  Segundo: ";
    cin>>time.segundos;

    return time;
}
Invoice setInvoiceData(){
    Invoice invoice;
    invoice.customer=setCustomerData();
    invoice.address=setAddressData();
    invoice.date=setDateData();
    invoice.time=setTimeData();

    cout<<"\nIngrese número de factura: ";
    cin>>invoice.invoice_number;

    return invoice;
}
/*1*/
void catchInvoice() {
    Invoice invoice=setInvoiceData();
    invoices_list[++amount_invoices]=invoice;
    cout<<"\nGuardando factura nueva...";
}

void editCustomer(Invoice &invoice) {
    //Customer customer;
    int option;
    
    do{
        cout<<"[INFORMACION ACTUAL]";
        cout<<" Cliente: "<<invoice.customer.nombre<<" "<<invoice.customer.apellido_paterno<<" "<<invoice.customer.apellido_materno;
        cout<<"\n\n";
        // cout<<"( Los cambios se reflejan cuando termines cuando selecciones terminar )\n"

        cout<<"Datos a editar del cliente: ";
        cout<<"\n\t[1] Nombre.";
        cout<<"\n\t[2] Apellido paterno.";
        cout<<"\n\t[3] Apellido materno.";
        cout<<"\n\t[0] Terminar y regresar";

        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        cout<<"\n";

        while (option<0&&option>3)
        {
            cout<<"OPCION INVALIDA. Ingrese una opción válida: ";
            cin>>option;
        }
        
        if(option==0){
            break;
        }

        cout<<"\tEscribe el nuevo valor ";
        switch (option) {
            case 1:
                cout<<"del nombre: ";
                cin>>invoice.customer.nombre;

                break;
            case 2:
                cout<<"del apellido paterno: ";
                cin>>invoice.customer.apellido_paterno;
                break;
            case 3:
                cout<<"del apellido materno: ";
                cin>>invoice.customer.apellido_materno;
                break;
            
            default:
                break;
        }

        //invoice.customer=customer;
        notifySave();
        cleanScreen();
    }while(option!=0);
}
void editAddress(Invoice &invoice) {
    int option;


    do{
        cout<<"[INFORMACION ACTUAL]";
        cout<<" Dirección: "<<invoice.address.ciudad<<", Col. "<<invoice.address.colonia<<", Calle "<<invoice.address.calle<<" #"<<invoice.address.numero;
        cout<<"\n\n";

        cout<<"Datos a editar de la dirección: ";
        cout<<"\n\t[1] Ciudad.";
        cout<<"\n\t[2] Colonia.";
        cout<<"\n\t[3] Calle.";
        cout<<"\n\t[4] Numero de calle.";
        cout<<"\n\t[0] Terminar y regresar";

        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        cout<<"\n";

        while (option<0&&option>4)
        {
            cout<<"OPCION INVALIDA. Ingrese una opción válida: ";
            cin>>option;
        }
        
        if(option==0){
            break;
        }

        cout<<"\tEscribe el nuevo valor para ";
        switch (option) {
            case 1:
                cout<<"[1] Ciudad : ";
                cin>>invoice.address.ciudad;
                break;
            case 2:
                cout<<"[2] Colonia : ";
                cin>>invoice.address.colonia;
                break;
            case 3:
                cout<<"[3] Calle : ";
                cin>>invoice.address.calle;
                break;
            case 4:
                cout<<"[4] Numero de calle : ";
                cin>>invoice.address.numero;
                break;
            
            default:
                break;
        }
        
        notifySave();
        cleanScreen();
    }while(option!=0);
}
void editDateTime(Invoice &invoice) {
    int option;
    
    do{
        cout<<"[INFORMACION ACTUAL]";
        cout<<" Fecha y hora: "<<invoice.time.horas<<"H:"<<invoice.time.minutos<<"M:"<<invoice.time.segundos<<"S - "<<invoice.date.dia<<"/"<<invoice.date.mes<<"/"<<invoice.date.anio<<"\n";
        cout<<"\n\n";

        cout<<"Datos a editar de la fecha y hora: ";
        cout<<"\n\t[1] Dia.";
        cout<<"\n\t[2] Mes.";
        cout<<"\n\t[3] Año.";
        cout<<"\n\t[4] Horas.";
        cout<<"\n\t[5] Minutos.";
        cout<<"\n\t[6] Segundos.";
        cout<<"\n\t[0] Terminar y regresar";

        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        cout<<"\n";

        while (option<0&&option>5)
        {
            cout<<"OPCION INVALIDA. Ingrese una opción válida: ";
            cin>>option;
        }
        
        if(option==0){
            break;
        }

        cout<<"\tEscribe el nuevo valor para ";
        switch (option) {
            case 1:
                cout<<"[1] Dia : ";
                cin>>invoice.date.dia;
                break;

            case 2:
                cout<<"[2] Mes : ";
                cin>>invoice.date.mes;
                break;

            case 3:
                cout<<"[3] Año : ";
                cin>>invoice.date.anio;
                break;

            case 4:
                cout<<"[4] Horas : ";
                cin>>invoice.time.horas;
                break;
            case 5:
                cout<<"[5] Minutos : ";
                cin>>invoice.time.minutos;
                break;
            case 6:
                cout<<"[6] Segundos : ";
                cin>>invoice.time.segundos;
                break;
            
            default:
                break;
        }
        
        notifySave();
        cleanScreen();
    }while(option!=0);
}
/*2*/
void editInvoice(){
    if(!areThereInvoices())return;

    Invoice invoice;
    int invoice_index;
    int invoice_number;
    int option;
    char aux;

    cout<<"Ingrese el número de la factura que desea editar: ";
    cin>>invoice_number;

    invoice_index=searchInvoice(invoice, invoice_number);
    if(!invoice_index) return;

    printInvoiceData(invoice);

    do {
        // Menu for fields to edit
        cout<<"Campos editables de la factura:";
        cout<<"\n\t(1) Cliente.";
        cout<<"\n\t(2) Dirección.";
        cout<<"\n\t(3) Fecha y hora.";
        cout<<"\n\t(0) Terminar edición y volver al menú principal";
        
        cout<<"\n\nDigite el número de la opción: ";
        cin>>option;
        while (option<0||option>3){
            cout<<"\n\nLa opción ingresada no existe, digite una opción valida: ";
            cin>>option;
        }

        if(option==0) break;

        cleanScreen();

        // Perform the chosen operation
        cout<<"La opción seleccionada es: ";
        switch (option){
            case 1:
                cout<<"(1) Cliente.\n\n";
                editCustomer(invoice);
                break;

            case 2:
                cout<<"(2) Dirección.\n\n";
                editAddress(invoice);
                break;

            case 3:
                cout<<"(3) Fecha y hora.\n\n";
                editDateTime(invoice);
                break;

            default:
                break;
        }
        notifySave();
        cleanScreen();
    }while(option!=0);
    invoices_list[invoice_index]=invoice;
}

void popInvoice(int invoice_index){
    for(int i=invoice_index; i<amount_invoices; i++){
        invoices_list[i]=invoices_list[i+1];
    }
    invoices_list[amount_invoices]=invoice_empty;
    amount_invoices--;
}
/*3*/
void deleteInvoice(){
    if(!areThereInvoices())return;

    Invoice invoice;
    int invoice_number;
    int invoice_index;

    cout<<"Ingrese el número de la factura que desea eliminar: ";
    cin>>invoice_number;

    invoice_index=searchInvoice(invoice, invoice_number);
    if(!invoice_index) return;

    printInvoiceData(invoice);

    string aux;
    do{
        cout<<"¿Estás seguro que deseas borrar? [SI/NO] : ";
        cin>>aux;
    }while(aux!="SI"&&aux!="NO");

    if(aux=="NO")return;

    popInvoice(invoice_index);

    cout<<"Borrando factura...";
}

/*4*/
void listInvoices(){
    if(!areThereInvoices())return;
    for(int i=1; i<=amount_invoices; i++){
        cout<<"  "<<i<<". Factura #"<<invoices_list[i].invoice_number<<" ("<<invoices_list[i].customer.nombre<<" "<<invoices_list[i].customer.apellido_paterno<<").\n";
    }
}

void printInvoiceData(Invoice invoice){
    cout<<"Factura No. "<<invoice.invoice_number<<" : \n";
    cout<<"  Cliente:  "<<invoice.customer.nombre<<" "<<invoice.customer.apellido_paterno<<" "<<invoice.customer.apellido_materno<<"\n";
    cout<<"  Dirección:  "<<invoice.address.ciudad<<", Col. "<<invoice.address.colonia<<", Calle "<<invoice.address.calle<<" #"<<invoice.address.numero<<"\n";
    cout<<"  Fecha y hora:  "<<invoice.time.horas<<"H:"<<invoice.time.minutos<<"M:"<<invoice.time.segundos<<"S - "<<invoice.date.dia<<"/"<<invoice.date.mes<<"/"<<invoice.date.anio;

    cout<<"\n\n";
}
int searchInvoice(Invoice &invoice, int invoice_number){
    /*
        Invoice is the variable where the result will be saved
    */
    int invoice_index=0;
    for(int i=1; i<=amount_invoices; i++){
        if(invoices_list[i].invoice_number==invoice_number){
            invoice=invoices_list[i];
            invoice_index=i;
            break;
        }
    }
    if(!invoice_index){ // Invoice list doesn't have the invoice requested
        cout<<"ERROR: No existe una factura con ese número de factura.\n";
    }
    cout<<"\n";
    return invoice_index;
}
/*5*/
void showInvoice(){
    if(!areThereInvoices())return;

    Invoice invoice;
    int invoice_number;

    cout<<"Ingrese el número de la factura que desea visualizar: ";
    cin>>invoice_number;

    int request=searchInvoice(invoice, invoice_number);
    if(!request) return;

    printInvoiceData(invoice);
}