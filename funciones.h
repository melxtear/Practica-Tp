#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <ctime>

using namespace std;


typedef struct Medicos {

	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
} Medicos;

typedef struct Consultas {

	int dni_pac;
	string fecha_solicitado;
	string fecha_turno;
	bool presento;
	string matricula_med;
	//Medicos medico_consulta;

} Consultas;

typedef struct Contactos {

	int dni_pac;
	string telefono;
	string celular;
	string direccion;
	string mail;

} Contactos;

typedef struct Pacientes {

	unsigned int dni;
	string nombre;
	string apellido;
	char sexo;
	string natalicio;
	string estado;
	string id_os;
	Contactos contacto;//tendria que tener 2? uno de emergencia y otra dle mismo paciente
	Contactos contacto_emergencia;
	//Consultas consulta;//consulta asociada, lee la del paciente

}Pacientes;


//typedef struct Hospital {
	//struct Medicos Lista_Medicos[5];
	//struct Pacientes Lista_Pacientes_Agenda[10];
	//struct Pacientes Lista_Pacientes_Total[20];
	//struct Pacientes Lista_Pacientes_Archivados[12];
//}Hospital;

//void nuevo_Paciente(Pacientes* lista, int tam);
//void nuevo_Medico(Medicos* lista, int tam);
Medicos* Buscar_Medico_Viejo(Medicos* Lista_Medicos, Consultas consulta, Pacientes paciente, int tam);
Medicos* Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Consultas consulta, Pacientes paciente, int tam);
//tm*& Fecha_de_string_a_tm(string fecha);
//Pacientes* leer_archivos_pacientes(string a1);
void agregar(Pacientes*& lista_pac, Pacientes paciente, int* tamactual);
void resize(Pacientes*& lista_pac, int* tamactual, int cantidad_aumentar);
//Pacientes* read_archivos(string a1);
//void read();
//Pacientes* LeerArchivo(string archivo);

bool Asignar_Turno(Medicos* Lista_Medicos, Pacientes paciente_a_asignar_turno);