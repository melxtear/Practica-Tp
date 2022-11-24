// Practica Tp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include "funciones.h"
#include <ctime>
#include <stdio.h>
#include <locale.h>
#include <time.h>


int main() {
    //read();
    //time_t curr_time;
    //curr_time = time(NULL);

    //char* tm = ctime(&curr_time);
    //cout << "Today is : " << tm;

    //time_t t = time(0);   // get time now
    //tm* now = localtime(&t);
    //cout << now->tm_hour;
    //tm* now2 = localtime(&t);

    //read();
    //read_archivo("Pacientes.csv");
   // now->tm_year = 1980;
   // out << "Es el año: " << now->tm_year <<  endl;
   

    /*const char* time_details = "16/08/2022";
    struct tm tm;
    strptime(time_details, "%H:%M:%S", &tm);
    time_t t2 = mktime(&tm);
    */

    
    Pacientes* lista1 = new Pacientes[1];
  
    Pacientes* lista_pacientes_irrecuperables = new Pacientes[3];
    Pacientes* lista_pacientes_recuperable = new Pacientes[3];
    lista1[0].apellido = "Almada";
    lista1[0].consulta.dni_pac = 44798519;
    lista1[0].consulta.fecha_solicitado = "04-08-2008"; //03082008
    lista1[0].consulta.fecha_turno = "04-08-2008";
    lista1[0].consulta.matricula_med = "01 - 114 - 7331";
    lista1[0].consulta.medico_consulta.activo = 1;
    lista1[0].consulta.medico_consulta.apellido = "Martinez";
    lista1[0].consulta.medico_consulta.especialidad = "Oculista";
    lista1[0].consulta.medico_consulta.matricula = "01 - 114 - 7331";
    lista1[0].consulta.medico_consulta.nombre = "Roberto";
    lista1[0].consulta.medico_consulta.telefono = "1145784441";
    lista1[0].consulta.presento = 1;
    lista1[0].contacto.celular = "1141736509";
    lista1[0].contacto.direccion = "Belgrano 123";
    lista1[0].contacto.dni_pac = 44798519;
    lista1[0].contacto.mail = "melodyalmada@gmail.com";
    lista1[0].contacto.telefono = "1141736509";
    lista1[0].dni = 44798519;
    lista1[0].estado = "n/c";
    lista1[0].id_os = "Aleman";
    lista1[0].natalicio = 16042003;
    lista1[0].nombre = "Melody";
    lista1[0].sexo = 'M';

    Medicos* lista2 = new Medicos[3];
    

    lista2[0].activo = 1;
    lista2[0].apellido = "Martinez";
    lista2[0].especialidad = "Oculista";
    lista2[0].matricula = "01 - 114 - 7331";
    lista2[0].nombre = "Roberto";
    lista2[0].telefono = "1145784441";

    lista2[1].activo = 1;
    lista2[1].apellido = "Polar";
    lista2[1].especialidad = "Oculista";
    lista2[1].matricula = "16-094-5286";
    lista2[1].nombre = "Hernan";
    lista2[1].telefono = "1147851488";

    lista2[2].activo = 1;
    lista2[2].apellido = "Carides";
    lista2[2].especialidad = "Oculista";
    lista2[2].matricula = "58 - 934 - 7652";
    lista2[2].nombre = "Marcos";
    lista2[2].telefono = "1147874522";
 

    //tm* now3 = Fecha_de_string_a_tm(lista1[0].consulta.fecha_solicitado);

    //cout << now3->tm_yday << now3->tm_mon << now3->tm_year << endl;

    //int dia, mes, anio;
    //cout << "\nFecha (dd mm aa): "; cin >> dia >> mes >> anio;

    
    Pacientes paciente;
    Medicos medico;
    Medicos medico2;
    Pacientes* lista = new Pacientes[200];
   
    medico = Buscar_Medico_Viejo(lista2, lista1[0], 3);
    
    medico2 = Buscar_Medico_Nuevo(lista2, lista1[0], 3);
    

    // std::cout << "Hello World TP_Final";
    cout << "Datos: " << medico.apellido << ", " << medico.nombre << ", " << medico.especialidad << endl;
    cout << "Datos: " << medico2.apellido << ", " << medico2.nombre << ", " << medico2.especialidad << endl;
    
    return 0;
}
// TP1-Grupo13.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void read() {
    fstream fr;
    string name;
    string role;
    char coma;
    int nota1, nota2, nota3, nota4;
    string dummy;

    fr.open("reportcard.csv", ios::in | ios::app);
    if (!fr.is_open())
        cout << "Error al leer archivo";
    else {
        fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
        while (fr) {
            fr >> role >> coma >> name >> coma >> nota1 >> coma >> nota2 >> coma >> nota3 >> coma >> nota4;
            cout << "Mi rol es : " << role << "Me llamo: " << name;
        }

    }


}

void create()
{	// file pointer
    fstream fout;
    // opens an existing csv file or creates a new file.
    fout.open("reportcard.csv", ios::out | ios::app);

    cout << "Enter the details of 5 students:"
        << " roll name maths phy chem bio"
        << endl;

    int i, roll, phy, chem, math, bio;
    string name;

    // Read the input
    for (i = 0; i < 5; i++) {

        cin >> roll
            >> name
            >> math
            >> phy
            >> chem
            >> bio;

        // Insert the data to file
        fout << roll << ","
            << name << ","
            << math << ","
            << phy << ","
            << chem << ","
            << bio
            << "\n";
    }
}


int main()
{



    cout << "Fin del programa . \n";
    create();
    read();
    /*
        cPacientes* miPaciente2, eResultado::Positivo = new cPacientes("Pilar", "Fava", "18436115", "2914611921", "False", "True", "False", "False", "False", "False", eResultado::Negativo);
        cCentrodetesteo* Centro1 = new cCentrodetesteo(0, 2, "Hola"); //creamos puntero dinamico de centro de testeo
        cCentrodetesteo* Centro2 = new cCentrodetesteo(1, 2, "Chau");;
        cLaboratorio* Labpaciente1 = new cLaboratorio("Luana", "3456", "5"); //puntero dinamico de Laboratorio con pacientes 1 y 2
        cLaboratorio* Labpaciente2 = new cLaboratorio("Pilar", "2387", "9");
        
    return 0;

}
*/
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
