#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "funciones.h"

using namespace std;

/*
void nuevo_Paciente(Pacientes* lista, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << "Ingrese apellido paciente: " << endl;
		cin >> lista[i].apellido;
		cout << "Ingrese nombre paciente: " << endl;
		cin >> lista[i].nombre;
		cout << "Ingrese dni paciente: " << endl;
		cin >> lista[i].dni;
		cout << "Ingrese sexo paciente: " << endl;
		cin >> lista[i].sexo;
		cout << "Ingrese natalicio paciente: " << endl;
		cin >> lista[i].natalicio;
		cout << "Ingrese estado paciente: " << endl;
		cin >> lista[i].estado;
		cout << "Ingrese id obra social paciente: " << endl;
		cin >> lista[i].obra_social.id_os;
		cout << "Ingrese obra social: " << endl;
		cin >> lista[i].obra_social.obra_social;
		cout << "Ingrese id_os: " << endl;
		cin >> lista[i].id_os;
		cout << "Ingrese celular contacto: " << endl;
		cin >> lista[i].contacto.celular;
		cout << "Ingrese direccion contacto: " << endl;
		cin >> lista[i].contacto.direccion;
		cout << "Ingrese dni_pac contacto: " << endl;
		cin >> lista[i].contacto.dni_pac;
		cout << "Ingrese mail contacto: " << endl;
		cin >> lista[i].contacto.mail;
		cout << "Ingrese telefono contacto: " << endl;
		cin >> lista[i].contacto.telefono;
		cout << "Ingrese dni_pac consulta: " << endl;
		cin >> lista[i].consulta.dni_pac;
		cout << "Ingrese fecha solicitado consulta: " << endl;
		cin >> lista[i].consulta.fecha_solicitado;
		cout << "Ingrese fecha_turno consulta: " << endl;
		cin >> lista[i].consulta.fecha_turno;
		cout << "Ingrese matricula_med: " << endl;
		cin >> lista[i].consulta.matricula_med;
		cout << "Ingrese presento consulta: " << endl;
		cin >> lista[i].consulta.presento;
		cout << "Ingrese medico consulta activo: " << endl;
		cin >> lista[i].consulta.medico_consulta.activo;
		cout << "Ingrese medico consulta apellido: " << endl;
		cin >> lista[i].consulta.medico_consulta.apellido;
		cout << "Ingrese medico consulta especialidad: " << endl;
		cin >> lista[i].consulta.medico_consulta.especialidad;
		cout << "Ingrese medico consulta matricula: " << endl;
		cin >> lista[i].consulta.medico_consulta.matricula;
		cout << "Ingrese medico consulta nombre: " << endl;
		cin >> lista[i].consulta.medico_consulta.nombre;
		cout << "Ingrese medico consulta telefono: " << endl;
		cin >> lista[i].consulta.medico_consulta.telefono;
	}
}
void nuevo_Medico(Medicos* lista, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << "Ingrese apellido medico: " << endl;
		cin >> lista[i].apellido;
		cout << "Ingrese nombre medico: " << endl;
		cin >> lista[i].nombre;
		cout << "Ingrese matricula medico: " << endl;
		cin >> lista[i].matricula;
		cout << "Ingrese especialidad medico: " << endl;
		cin >> lista[i].especialidad;
		cout << "Ingrese telefono medico: " << endl;
		cin >> lista[i].telefono;
		cout << "Ingrese activo medico: " << endl;
		cin >> lista[i].activo;

	}
}*/

//FUNCIONA BIEN
Medicos Buscar_Medico_Viejo(Medicos* Lista_Medicos, Pacientes paciente, int tam) {

	Medicos aux;
	for (int i = 0; i < tam; i++) {
		if (paciente.consulta.matricula_med == Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
			//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
			aux = Lista_Medicos[i]; //encontramos al medico
		}
	}
	return aux;//retornamos el struct del medico, significa que se puede asignar turno con el medico 
}

//FUNCIONA BIEN
Medicos Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Pacientes paciente, int tam) {

	Medicos aux;
	for (int i = 0; i < tam; i++) {
		if (paciente.consulta.matricula_med != Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true && Lista_Medicos[i].agenda_llena==false) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
			//le asigna el primer medico activo y que no sea el que lo haya atendido antes, tambien que sea de la especialidad que busca
			aux = Lista_Medicos[i];
		}//habria que ver porque deberia fijarse si el medico tiene agenda llena o algo asi, entonces recorre la lista y se fija de asignar turno con el primer medico que encuentre
		
	}
	return aux;//retornamos el medico
}
void agregar(Pacientes*& lista_pac, Pacientes paciente, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Pacientes* aux = new Pacientes[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_pac[i];
		i++;
	}
	aux[i] = paciente;

	delete[] lista_pac;
	lista_pac = aux;

	return;
}

void resize(Pacientes*& lista_pac, int* tamactual, int cantidad_aumentar) {
	*tamactual = *tamactual + cantidad_aumentar;
	int i = 0;

	Pacientes* aux = new Pacientes[*tamactual];

	while (i < *tamactual - cantidad_aumentar) {
		aux[i] = lista_pac[i];
		i++;
	}

	delete[] lista_pac;
	lista_pac = aux;

	return;
}
Pacientes* leer_archivos_pacientes(string a1) {

	Pacientes* l_pac = new Pacientes[0];
	Pacientes aux;

	string dummy;
	char coma;
	unsigned int dniaux;
	int tamact = 0;

	fstream fp;
	fp.open(a1, ios::in);

	if (!(fp.is_open()))
		return nullptr;

	fp >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//pacientes

	while (fp) { //lee archivo de pacientes 
		fp >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
		cout << "Lei paciente: " << aux.nombre << endl;
	}
	agregar(l_pac, aux, &tamact);
	fp.close();
	return l_pac;
}
Pacientes* LeerArchivo(string archivo)  //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
{
	Pacientes* Lista_pacientes = new Pacientes[0];
	string header=" ";
	Pacientes aux;
	fstream pacientes;
	int tamact_p = 0;
	pacientes.open(archivo, ios::in);

	if (!(pacientes.is_open()))
	{
		cout << "no se pudo abrir el archivo de pacientes" << endl;
		return nullptr;
	}

	char coma=' ';
	pacientes >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;//simepre vamos a saber la cantidad de variables es decir N

	while (pacientes)
	{
		string fecha; //pruebo leer con un auxiliar la variable de tipo tm para que no tire error
		//------------------leemos el archivo--------------------
		pacientes >> aux.dni >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> fecha >> coma >> aux.estado >> coma >> aux.id_os;

		//----------------Agregamos a la lista ----------------------
		agregar(Lista_pacientes, aux, &tamact_p);
	}
	pacientes.close();
}
/*
Pacientes* read(string a1) {
	Pacientes* l_pac = new Pacientes[0];
	Pacientes aux;
	fstream fr;
	string name;
	string dni;
	string apellido;
	string fecha;
	string sexo;
	string obra_social;
	string role;
	string dummy;
	string estado;
	char coma;
	int nota1, nota2, nota3, nota4;
	int tamact = 0;

	fr.open(a1, ios::in);
	//fr.open(a1, ios::in | ios::app);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> coma >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
			cout << aux.nombre << '\n';
		}

	}
	agregar(l_pac, aux, &tamact);

	return l_pac;
}*/