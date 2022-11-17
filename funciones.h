#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

typedef struct Medicos {

	string matricula;
	string nombre;
	string apellido;
	unsigned int telefono;
	string especialidad;
	bool activo;
	bool agenda_llena;
}Medicos;

typedef struct Consultas {

	unsigned int dni_pac;
	unsigned int fecha_solicitado;
	unsigned int fecha_turno;
	bool presento;
	string matricula_med;
	Medicos medico_consulta;

} Consulta;


typedef struct Contactos {

	unsigned int dni_pac;
	unsigned int telefono;
	unsigned int celular;
	string direccion;
	string mail;

}Contactos;

typedef struct Pacientes {

	unsigned int dni;
	string nombre;
	string apellido;
	char sexo;
	unsigned int natalicio;
	string estado;
	string id_os;
	Contactos contacto;//tendria que tener 2? uno de emergencia y otra dle mismo paciente
	Consultas consulta;//consulta asociada, lee la del paciente

}Pacientes;

typedef struct Hospital {
	struct Medicos Lista_Medicos[5];
	struct Pacientes Lista_Pacientes_Agenda[10];
	struct Pacientes Lista_Pacientes_Total[20];
	struct Pacientes Lista_Pacientes_Archivados[12];
}Hospital;

//void nuevo_Paciente(Pacientes* lista, int tam);
//void nuevo_Medico(Medicos* lista, int tam);
Medicos Buscar_Medico_Viejo(Medicos* Lista_Medicos, Pacientes paciente, int tam);
Medicos Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Pacientes paciente, int tam);


Pacientes* leer_archivos_pacientes(string a1);
void agregar(Pacientes*& lista_pac, Pacientes paciente, int* tamactual);
void resize(Pacientes*& lista_pac, int* tamactual, int cantidad_aumentar);
Pacientes* read(string a1);
Pacientes* LeerArchivo(string archivo);