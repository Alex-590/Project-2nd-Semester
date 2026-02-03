#include "Video.h"
#include <iostream>
using namespace std;

Video::Video(string ID, string nom, float calif, float Duracion, string fechaE) {
    id = ID;
    nombre = nom;
    calificacion = calif;
    duracion = Duracion;
    fechaDeEstreno = fechaE;
}

void Video::imprimir() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Calificación: " << calificacion << endl;
    cout << "Duración: " << duracion << " min" << endl;
    cout << "Fecha de estreno: " << fechaDeEstreno << endl;
}
