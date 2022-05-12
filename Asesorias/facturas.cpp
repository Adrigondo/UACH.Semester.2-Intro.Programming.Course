
#include <iostream>

using namespace std;

struct Direccion{
    char calle [50];
    int  numero;
    char colonia [50];
    char ciudad [50];
};

struct Fecha{
    int dia;
    int mes;
    int ano;
};

struct Hora{
    int hora;
    int minuto;
    int segundo;
};

struct Cliente{
    char nombre [20];
    char apellido_paterno [20];
    char apellido_materno [20];
};

struct Factura{
   Direccion Direcciones;
		Fecha Fechas;
		Hora Horas;
		Cliente Clientes;
};

// Parte 1 //
Direccion Capturador (Direccion datos){
	cout << "Introduce la calle: \n";
	cin >> datos.calle;
	
	cout << "Introduce el numero: \n";
	cin >> datos.numero;
	
	cout << "Introduce la colonia: \n";
	cin >> datos.colonia;
	
	cout << "Introduce la ciudad: \n";
	cin >> datos.ciudad;
	return datos;
}

//Parte 1.2 //
Fecha Capturador (Fecha fech){
	int F;
	
	cout << "Introduce el dia; \n";
	cin >> fech.dia;
	F = fech.dia;
	while (F > 31 || F <= 0){
		cout << "Error, vuelva a intoducir el dia: \n ";
		cin >> fech.dia;
		F = fech.dia;
	}
	
	while(F > 30 && (F == 4 ||F == 6 || F == 9 || F == 11)){
		cout << "Error, vuelva a intoducir el dia: \n";
		cin >> fech.dia;
		F = fech.dia;
	}
	while(F == 2 && F > 28){
		cout << "Error, vuelva a intoducir el dia: \n";
		cin >> fech.dia;
		F = fech.dia;
	}
	cout << "Introduce el mes (en numero): \n";
	cin >> fech.mes;
	F = fech.mes;
	while(F <= 0 || F > 12){
		cout << "Error, vuelva a introducir el mes (en numero): \n";
		cin >> fech.mes;
		F = fech.mes;
	}
	
	cout << "Introduce el ano: \n";
	cin >> fech.ano;
		while(fech.ano > 2023){
		cout << "Error, vuelva a intoducir el año: \n";
		cin >> fech.ano;
	}
	return fech;
}

//Parte 1.3 //
Hora Capturador (Hora ho){
	cout << "Ingrese la hora: \n";
	cin >> ho.hora;
	while (ho.hora >= 24 || ho.hora < 0){
		cout << "Error, vuelva a introducir la hora: \n";
		cin >> ho.hora;
	}
	cout << "Ingrese los minutos: \n";
	cin >> ho.minuto;
	while (ho.minuto >= 60 || ho.minuto < 0){
		cout << "Error, vuelva a introducir los minutos: \n";
		cin >> ho.minuto;
	}
	
	cout << "Ingrese los segundos: \n";
	cin >> ho.segundo;
	while (ho.segundo >= 60 || ho.segundo < 0 ){
		cout << "Error, vuelva a introducir los segundos: \n";
		cin >> ho.segundo;
	}
	return ho;
}

//Parte 1.4 //
Cliente Capturador (Cliente clie){
	cout << "Ingrese el nombre: \n";
	cin >> clie.nombre;
	
	cout << "Ingrese el apellido paterno: \n";
	cin >> clie.apellido_paterno;
	
	cout << "Ingrese el apellido materno: \n";
	cin >> clie.apellido_materno;
	return clie;
}

//Parte 2 //
int main()
{
    Factura Facturas[20];
	Factura FacturaV;
	int F;
	int i=0;
	int i2=0;
	int F2;
	int F3;
	int F4;
	int F5;
    
    cout << "--------------------------------------- \n";
    cout << "                Facturas                \n";
    cout << "--------------------------------------- \n";
    
    cout << "***************** MENU ****************\n";
    cout << "1) Capturar nueva factura \n";
    cout << "2) Editar una captura existente \n";
    cout << "3) Eliminar una captura existente \n";
    cout << "4) Mostrar lista de facturas \n";
    cout << "5) Mostrar una factura en particular \n";
    cout << "Ingrese la opcion que guste: \n";
    cin >> F;
    
    while(F != 6){
		switch (F){
			case 1:
			Facturas[i2].Direcciones = Capturador (Facturas[i2].Direcciones);
				Facturas[i2].Fechas = Capturador (Facturas[i2].Fechas);
				Facturas[i2].Horas = Capturador (Facturas[i2].Horas);
				Facturas[i2].Clientes = Capturador (Facturas[i2].Clientes);
				i2++;
			break;
			
			case 2:
				switch (i2){
					case 0:
						cout << "Factura inexistente";
						break;
						//Parte 2.1.1//
					case 1:
						cout << "Nomas hay una factura existente para editar\n";
						cout << "************************\n";
						cout << "¿Que datos quiere editar?\n";
						cout << "************************\n";
						cout << "1) Direccion\n";
						cout << "2) Fecha\n";
						cout << "3) Hora\n";
						cout << "4) cliente\n";
						cout << "5) Volver al menu\n";
						cin>>F2;
						F3 = 1;
						//Parte 2.1.2//
						while(F3 == 1){
							switch (F2){
								case 1:
									Facturas[0].Direcciones = Capturador (Facturas[0].Direcciones);
									cout << "Si desea hacer otro cambio estriba 1, por el contrario escriba 0: \n";
									cin >> F3;
									break;
								case 2:
									Facturas[0].Fechas = Capturador (Facturas[0].Fechas);
									cout << "Si desea hacer otro cambio estriba 1, por el contrario escriba 0: \n";
									cin >>F3;
									break;
								case 3:
									Facturas[0].Horas = Capturador (Facturas[0].Horas);
									cout << "Si desea hacer otro cambio estriba 1, por el contrario escriba 0: \n";
									cin >> F3;
									break;
								case 4:
									Facturas[0].Clientes = Capturador (Facturas[0].Clientes);
									cout << "Si desea hacer otro cambio estriba 1, por el contrario escriba 0: \n";
									cin >> F3;
									break;
								default:
									cout << "Si desea hacer otro cambio estriba 1, por el contrario escriba 0: \n";
									break;
							}
						}
						//Parte 2.2//
						break;
					default:
						F3=1;
						cout << "¿Que numero de Factura desea editar (a partir del 0)?: \n";
						cin >> i;
						while ( i <0 || i > 19 || i >= i2){
							cout << "Error, no existe la factura, vuelva a intentar: \n";
							cin >> i;
						}
						while(F3 == 1){
							cout << "¿Que gusta editar de la factura?: \n";
							cout << "1) Direccion\n";
							cout << "2) Fecha\n";
							cout << "3) Hora\n";
							cout << "4) Datos del cliente\n";
							cout << "5) Volver al menu\n";
							cin >> F2;
							F3 = 1;
							//Parte 2.2.1//
							switch (F2){
								case 1:
									Facturas[i].Direcciones = Capturador (Facturas[i].Direcciones);
									cout << "Si deseas hacer otro cambio escriba 1, por lo contrario escriba 0:\n";
									cin >> F3;
									break;
								case 2:
									Facturas[i].Fechas = Capturador (Facturas[i].Fechas);
									cout << "Si deseas hacer otro cambio escriba 1, por lo contrario escriba 0:\n";
									cin >> F3;
									break;
								case 3:
									Facturas[i].Horas = Capturador (Facturas[i].Horas);
									cout << "Si deseas hacer otro cambio escriba 1, por lo contrario escriba 0:\n";
									cin >> F3;
									break;
								case 4:
									Facturas[i].Clientes = Capturador (Facturas[i].Clientes);
									cout << "Si deseas hacer otro cambio escriba 1, por lo contrario escriba 0:\n";
									cin >> F3;
									break;
								default:
									cout << "Si deseas hacer otro cambio escriba 1, por lo contrario escriba 0:\n";
									F3=0;
									break;
							}
						}
					break;
				}
			break;
			//parte 3 //
			case 3:
				F5 = 1;
				while (F5 == 1){
					if(i2 == 0){
						cout<<"No existe ninguna factura para borrar"<<endl;
						F5=0;
					}else{
						cout << "¿Que numero de factura quieres eliminar (inicia en 0)?: \n";
						cin >> i;
						while (i < 0 || i > 19 || i >= i2){
									cout << "Error, no existe la factura, vuelva a intentar: \n";
									cin >> i;
						}
						cout << "Si desea eliminar la factura escriba 1, por lo contrario escriba 2: \n";
						cin >> F4;
						if(F4 == 1){
							Facturas[i]=FacturaV;
							i2--;
						}else{
							cout<<"Se conservaron los datos"<<endl;
						}
						cout<<"Si desea eliminar otra factura escriba 1, por lo contrario escriba 2:"<<endl;
						cin>>F5;
					}
				}
			break;
			
			//Parte 4 //
			case 4:
				if (i2 <= 0){
					cout << "No existe ninguna factura capturada\n";
				}else{
					cout << "Existen " << i2 << " Facturas capturadas\n";
				}
			break;
			case 5:
				if (i2 <= 0){
					cout << "Noexiste ninguna factura capturada" << endl;
				}else{
					cout << "Escribe el numero de factura que quiere cansultar (inicia en 0): \n";
					cin >> i;
					while (i < 0 || i > 19 || i >= i2){
						cout << "Error, no existe esa factura, vuelva a intentar; \n";
						cin >> i;
					}
				cout << "La direccion de la factura " << i << " es: calle " << Facturas[i].Direcciones.calle << ", numero " << Facturas[i].Direcciones.numero << ", colonia " << Facturas[i].Direcciones.colonia << " en la ciudad de " << Facturas[i].Direcciones.ciudad << "\n";
					cout << "La fecha de la factura es el dia "<<Facturas[i].Fechas.dia<<" de ";
					switch (Facturas[i].Fechas.mes){
						case 1: cout<<"Enero";
						break;
						case 2: cout<<"Febrero";
						break;
						case 3: cout<<"Marzo";
						break;
						case 4: cout<<"Abril";
						break;
						case 5: cout<<"Mayo";
						break;
						case 6: cout<<"Junio";
						break; 
						case 7: cout<<"Julio";
						break;
						case 8: cout<<"Agosto";
						break;
						case 9: cout<<"Septiembre";
						break;
						case 10: cout<<"Octubre";
						break;
						case 11: cout<<"Noviembre";
						break;
						case 12: cout<<"Diciembre";
						break;
						default: cout<<"Error, vuelva a intentar otra vez";
						break;
						}	
						cout << Facturas[i].Fechas.mes << " del ano " << Facturas[i].Fechas.ano << "\n";
					cout << "A las " << Facturas[i].Horas.hora << ":" << Facturas[i].Horas.minuto << ":" << Facturas[i].Horas.segundo << "\n";
					cout << "Expedido en nombre de " << Facturas[i].Clientes.nombre << " " << Facturas[i].Clientes.apellido_paterno << " " << Facturas[i].Clientes.apellido_paterno << "\n";
				}
			break;
		}
	cout << "1) Capturar nueva factura \n";
    cout << "2) Editar una captura existente \n";
    cout << "3) Eliminar una captura existente \n";
    cout << "4) Mostrar lista de facturas \n";
    cout << "5) Mostrar una factura en particular \n";
    cout << "6) Salir \n";
    cout << "Si desea continuar escriba el numero que guste, por lo oontrario, escriba 6 para salir: \n";
	cin >> F;
	}		
}	