/*
    Alumno: Adrian Alejandro Gonzalez Dominguez
    Matricula: 359834
    Grupo: 2CC2
*/
/*
    Wednesday 18/05/2022
    
    Customers managment program

    This program do the follow operations through a menu:
    1.- Catch a new customer
    2.- List all customers
    3.- List prompt customers
    4.- List defaulter customers
    5.- Show customer data by ID
    
*/
#include <bits/stdc++.h>
using namespace std;

struct Customer{
    int id;
    string name="";
    string father_lastname="";
    string mother_lastname="";
    double balance;
    bool status;
};

/* --------------------------------DECLARATIONS---------------------------------------------*/

Customer customer_empty;
Customer customers_list[11];
int amount_customers=0;

Customer getCustomerData();
void catchCustomer();


void deleteCustomer();
void listCustomers();
void listCustomersByStatus(bool status);
void showCustomer();

bool areThereCustomers();
int searchCustomer(Customer &customer, int customer_id);
void printCustomerData(Customer customer);

void cleanScreen();
void notifySave();

/* --------------------------------------MAIN--------------------------------------------------*/

int main(){
    // Clean the console
    system ("clear");

    int option=0;
    do {
        // Start poster
        cout<<"|=================================================|\n";
        cout<<"|= .-.-. ESTADOS DE CUENTA (por Adrigondo) .-.-. =|\n";
        cout<<"|=================================================|\n\n";

        // Options menu
        cout<<"- Menu de operaciones disponibles -";
        cout<<"\n\t1. Ingresar datos de nuevo cliente.";
        cout<<"\n\t2. Ver listado de clientes.";
        cout<<"\n\t3. Ver listado de clientes puntuales.";
        cout<<"\n\t4. Ver listado de clientes morosos.";
        cout<<"\n\t5. Ver datos de cliente por ID.";
        cout<<"\n\t6. Borrar cliente.";
        cout<<"\n\t0. Salir";

        // Read the option from the user
        cout<<"\n\nDigite el número de la operación que desea realizar: ";
        cin>>option;
        while (option<0||option>6){
            cout<<"\n\nLa opción ingresada no existe, digite una opción valida: ";
            cin>>option;
        }
        
        if(option==0) break;

        cleanScreen();

        // Perform the chosen operation
        cout<<"\nSeleccionó la opción: ";
        switch (option){
            case 1:
                cout<<"\n\t1. Ingresar datos de nuevo cliente.\n\n";
                catchCustomer();
                break;

            case 2:
                cout<<"\n\t2. Ver listado de clientes.\n\n";
                listCustomers();
                break;

            case 3:
                cout<<"\n\t3. Ver listado de clientes puntuales.\n\n";
                listCustomersByStatus(0);
                break;

            case 4:
                cout<<"\n\t4. Ver listado de clientes morosos.\n\n";
                listCustomersByStatus(1);
                break;

            case 5:
                cout<<"\n\t5. Ver datos de cliente por ID.\n\n";
                showCustomer();
                break;

            case 6:
                cout<<"\n\t6. Borrar cliente.\n\n";
                deleteCustomer();
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

bool areThereCustomers(){
    if(amount_customers==0){
        cout<<"[No hay clientes registradas]";
        return false;
    }
    return true;
}

Customer setCustomerData(){
    Customer customer;

    cout<<"\nIngrese los datos del nuevo cliente:\n";
    cout<<"  >Primer nombre: ";
    cin>>customer.name;
    cout<<"  >Apellido paterno: ";
    cin>>customer.father_lastname;
    cout<<"  >Apellido materno: ";
    cin>>customer.mother_lastname;
    cout<<"  >Saldo: ";
    cin>>customer.balance;
    cout<<"  >Estado ( [0] puntual / [1] moroso ): ";
    cin>>customer.status;

    return customer;
}
void popCustomer(int customer_index){
    for(int i=customer_index; i<amount_customers; i++){
        customers_list[i]=customers_list[i+1];
    }
    customers_list[amount_customers]=customer_empty;
    amount_customers--;
}
void printCustomerData(int customer_index){
    cout<<"Cliente #"<<customers_list[customer_index].id<<" : \n";
    cout<<"  >Nombre:  "<<customers_list[customer_index].name<<" "<<customers_list[customer_index].father_lastname<<" "<<customers_list[customer_index].mother_lastname<<"\n";
    cout<<"  >Saldo:  $"<<customers_list[customer_index].balance<<"\n";
    cout<<"  >Estado:  ";
    if(customers_list[customer_index].status==false){
        cout<<"Puntual\n";
    }else{
        cout<<"Moroso\n";
    }

    // cout<<"\n\n";
}
int searchCustomer(int customer_id){
    int customer_index=0;

    for(int i=1; i<=amount_customers; i++){
        if(customers_list[i].id==customer_id){
            customer_index=i;
            break;
        }
    }
    if(customer_index==0){ // Customers list doesn't have the customer requested
        cout<<"ERROR: No existe un cliente con ese id.\n";
    }
    
    cout<<"\n";
    return customer_index;
}

void catchCustomer() {
    if(amount_customers==10){
        cout<<"ERROR: Solo puede tener guardados a 10 clientes, debe borrar alguno para ingresar uno nuevo.\n";
        return;
    }
    Customer customer=setCustomerData();
    customer.id=customers_list[amount_customers].id+1;
    customers_list[++amount_customers]=customer;
    cout<<"\nGuardando nuevo cliente...";
}

void deleteCustomer(){
    if(!areThereCustomers())return;

    int customer_number;
    int customer_index;

    cout<<"Ingrese el número del cliente que desea eliminar: ";
    cin>>customer_number;

    customer_index=searchCustomer(customer_number);
    if(customer_index==0) return;

    printCustomerData(customer_index);

    string aux;
    do{
        cout<<"¿Estás seguro que deseas borrar? [SI/NO] : ";
        cin>>aux;
    }while(aux!="SI"&&aux!="NO");

    if(aux=="NO")return;

    popCustomer(customer_index);

    cout<<"Borrando cliente...";
}

void listCustomers(){
    if(!areThereCustomers())return;
    for(int i=1; i<=amount_customers; i++){
        cout<<"  "<<i<<". Cliente #"<<customers_list[i].id<<" ("<<customers_list[i].name<<" "<<customers_list[i].father_lastname<<").\n";
    }
}

void listCustomersByStatus(bool status){
    if(!areThereCustomers())return;
    int it=1;
    for(int i=1; i<=amount_customers; i++){
        if(status==customers_list[i].status){
            cout<<"  "<<it++<<". Cliente #"<<customers_list[i].id<<" ("<<customers_list[i].name<<" "<<customers_list[i].father_lastname<<").\n";
        }
    }
}

void showCustomer(){
    if(!areThereCustomers())return;

    int customer_index;
    int customer_id;

    cout<<"Ingrese el número del cliente que desea visualizar: ";
    cin>>customer_id;

    customer_index=searchCustomer(customer_id);
    if(customer_index==0) return;

    printCustomerData(customer_index);
}