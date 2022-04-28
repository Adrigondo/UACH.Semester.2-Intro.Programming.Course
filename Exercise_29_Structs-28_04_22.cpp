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
    string calle;
    int numero;
    string colonia;
    string ciudad;
};
struct Date{
    int dia;
    int mes; 
    int anio;
};
struct Time{
    int horas;
    int minutos;
    int segundos;
};
struct Customer{
    string nombre;
    string apellido_paterno;
    string apellido_materno;
};
struct Invoice{
    Address address;
    Date date;
    Time time;
    Customer customer;
    int invoice_number;
};

Invoice invoices_list[11];
int it_invoice=0;

Address getAddressData();
Date getDateData();
Time getTimeData();
Customer getCustomerData();
Invoice getInvoiceData();
/*1*/ void catchInvoice();
Invoice editInvoiceData();
/*2*/ void editInvoice();
/*3*/ void deleteInvoice();
/*4*/ void listInvoices();
/*5*/ void showInvoice();

int main(){
    // Clean the console
    system ("clear");

    int option=0;
    char aux=' ';
    do {
        // Start poster
        cout<<"|=====================================================|\n";
        cout<<"|= .-.-. FACTURADOR AUTOMÁTICO (por Adrigondo) .-.-. =|\n";
        cout<<"|=====================================================|\n\n";

        // Options menu
        cout<<"- Menu de procedimientos disponibles -";
        cout<<"\n\t1. Capturar nueva factura.";
        cout<<"\n\t2. Editar factura existente.";
        cout<<"\n\t3. Eliminar factura existente.";
        cout<<"\n\t4. Listar facturas (numeros de facturas).";
        cout<<"\n\t5. Ver factura por su número.";
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
                cout<<"\n\t1. Capturar nueva factura.\n\n";
                catchInvoice();
                break;

            case 2:
                cout<<"\n\t2. Editar factura existente.\n\n";
                editInvoice();
                break;

            case 3:
                cout<<"\n\t3. Eliminar factura existente.\n\n";
                break;

            case 4:
                cout<<"\n\t4. Listar facturas (numeros de facturas).\n\n";
                
                cout<<"Ingrese los números separados por espacio: ";
                break;

            case 5:
                cout<<"\n\t5. Ver factura por su número.\n\n";
                break;

            default:
                break;
        }

        // Request to the user if wants do more operations?
        cout<<"\n\nPuse cualquier número para volver al menú... ";
        cin>>aux;

        // Clean lines since menu
        system ("clear");
    }while(option!=0);
    cout<<"¡Tenga un excelente día BIP BOP!\n\n";
}

Address setAddressData(){
    Address address;

    cout<<"\nIngrese los datos de su dirección:";
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

    cout<<"\nIngrese la fecha:";
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
    invoices_list[it_invoice]=invoice;
    cout<<"\nFactura nueva guardada con exito\n";
    
        //cout<<"\nERROR: Revisa que hayas llenado los campos correctamente.\n";
    
}

/*2*/
void editInvoice(){
    Invoice invoice=NULL;
    int invoice_number;
    int invoice_index;
    char aux;


    cout<<"Ingrese el número de la factura que desea editar: ";
    cin>>invoice_number;
    for(int i=0; i<=it_invoice; i++){
        if(invoices_list[i].invoice_number==invoice_number){
            invoice=invoices_list[i];
            invoice_index=i;
            break;
        }
    }
    if(!invoice){ // It is empty
        cout<<"ERROR: No existe una factura con ese número de factura.\n";
        return();
    }

    cout<<"La información de la factura "<<invoice_number<<" es la siguiente:\n";
    cout<<"  Nombre completo: "<<invoice.customer.nombre<<" "<<invoice.customer.apellido_paterno<<" "<<invoice.customer.apellido_materno<<"\n";
    cout<<"  Dirección: "<<invoice.address.ciudad<<", Col. "<<invoice.address.colonia<<", Calle "<<invoice.address.calle<<" #"<<invoice.address.numero<<"\n";
    cout<<"  Fecha y hora: "<<invoice.time.horas<<"H:"<<invoice.time.minutos<<"M:"<<invoice.time.segundos<<"S:"<<invoice.date.dia<<"/"<<invoice.date.mes<<"/"<<invoice.date.anio<<"\n";
    
    cout<<"\n¿Desea continuar con la edición?[Se sobreescribirá la información actual] (s/n): ";
    cin>>aux;
    while(aux!='s'&&aux!='n'){
        cout<<"\nERROR: La opción ingresada no es válida.\n";
        cout<<"Si desea editar la información ingrese \'s\' o si desea volver al menú, ingrese \'n\' : ";
        cin>>aux;
    }
    if(aux=='n'){
        return();
    }
    cout<<"[Escribe la nueva información]\n";

    invoice=setInvoiceData();
    invoices_list[invoice_index]=invoice;
}
/*3*/
void deleteInvoice();
/*4*/
void listInvoices();
/*5*/
void showInvoice();