#include<iostream>
#include <ctype.h> //<---aqui se encuentran las funciones toupper y tolower
#include"modulos.h"

using namespace std;

int totalCasados,totalMayoresEdad;
float propinaxEstudiante;
int totalViudasPesoMayorA50;
int opcion;
int edad;
int peso;
int totalpersonas;
int propina;
float acumuladoPropina = 0;
int acumuladopropinaSalon1=0, acumuladopropinaSalon2 = 0,
acumuladopropinaSalon3 = 0, acumuladopropinaSalon4 = 0, acumuladopropinaSalon5 = 0;
int salon;
int estudxSalon;


char  estadoCivil;



void ModuloProceso() {

	if (estadoCivil == 'c')
		totalCasados++;

	if (edad >=18)
		totalMayoresEdad++;

	if ( estadoCivil=='v' &&   peso > 50)
		totalViudasPesoMayorA50++;

	if (edad != 0) {
		totalpersonas++;
		acumuladoPropina = acumuladoPropina + propina;
		propinaxEstudiante = acumuladoPropina / totalpersonas;
	}

	if (salon == 1) acumuladopropinaSalon1 += propina;
	if (salon == 2) acumuladopropinaSalon2 += propina;
	if (salon == 3) acumuladopropinaSalon3 += propina;
	if (salon == 4) acumuladopropinaSalon4 += propina;
	if (salon == 5) acumuladopropinaSalon5 += propina;

}

void moduloMostrar() {
	cout << "Cant de personas casadas es: " << totalCasados << endl;
	cout << "Cant de personas mayores de edad: " << totalMayoresEdad << endl;
	cout << "Cant de personas viudas y peso mayor a 50 kg : " << totalViudasPesoMayorA50 << endl;
	cout << "monto de propina promedio por estudiante:  " << propinaxEstudiante << endl;
	cout << "monto de propina por salon1:  " << acumuladopropinaSalon1 << endl;
	cout << "monto de propina por salon2: " << acumuladopropinaSalon2 << endl;
	cout << "monto de propina por salon3:  " << acumuladopropinaSalon3 << endl;
	cout << "monto de propina por salon4:  " << acumuladopropinaSalon4 << endl;
	cout << "monto de propina por salon5:  " << acumuladopropinaSalon5 << endl;
	
}

void IngresoDatos() {
	// ingresando el salon
	do {
		salon = leerInt("ingrese numero de salon 1-2-3-4-5");
		if (salon <= 0 || salon >= 5)
			cout << "salon incorrecta, ingrese numero de salon 1-2-3-4-5" << endl;

	} while (salon <= 0 || salon >= 5);

	// ingresando edad
	do {
		edad = leerInt("Ingreso edad (0 -120)");


		if (edad <= 0 || edad >= 120)

		{
			cout << "Ingreso edad (0 -120 M), vuelva a intentar" << endl;

		}
	} while (edad <= 0 || edad >= 120);

	//ingresando el estado civil
	do {
		estadoCivil = leerChar("Ingrese estado civil c=casado || s=soltero || d=divorciado || v=viuda(o)");
		estadoCivil = tolower(estadoCivil);
		if (estadoCivil != 'c' && estadoCivil != 's' && estadoCivil != 'd' && estadoCivil != 'v')


		{
			cout << "Ingreso incorrecto es (C, S o D),vuelva a intentar" << endl;

		}
	} while (estadoCivil != 'c' && estadoCivil != 's' && estadoCivil != 'd' && estadoCivil != 'v');


	// ingresando las pesos

	do {
		peso = leerInt("ingrese peso");
		if (peso <= 0 || peso >= 120)
			cout << "ingreso incorrecto debe ser entre (0-120)" << endl;

	} while (peso <= 0 || peso >= 120);

	//ingresando propinas
	do {
		propina = leerInt("ingrese propinas");
		if (propina < 0)
			cout << "ingreso incorrecto debe ser positivo" << endl;

	} while (propina < 0);

}

void salir() {
	cout << "GRACIAS POR USAR EL MENU";
}

void menu() {
	do {
		do
		{
			cout << "Menu principal" << endl;
			cout << "1 Recaudar Datos" << endl;
			cout << "2 Reportar Datos" << endl;
			cout << "3 Salir" << endl;
			cout << "Ingrese Opcion" << endl;
			cin >> opcion;
		} while (opcion == 1 && opcion == 2 && opcion == 3);
		switch (opcion)
		{
		case 1: {

			IngresoDatos();
			ModuloProceso();
					
			break;
		}
		case 2: {
			
			moduloMostrar();
			break;
		}
		case 3: {

			salir();
			break;
		}

		}
	} while (opcion != 3);


}
