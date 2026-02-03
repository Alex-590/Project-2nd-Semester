
#include "Pelicula.h"
#include <iostream>
#include <sstream>
using namespace std;

Pelicula::Pelicula(string id, string nombre, float calificacion, float duracion, string fechaEstreno, string genero)
    : Video(id, nombre, calificacion, duracion, fechaEstreno) {
    generoP = genero;
}

void Pelicula::mostrarInfo(string gen) {
    stringstream ssGenero(generoP);
    string generoIndividual;

    while (getline(ssGenero, generoIndividual, ';')) {
        if (generoIndividual.find(gen) != string::npos) {
            imprimir();
            break;
        }
    }
}
void Pelicula::filtrarPorRating(float param) {
    if (calificacion >= param) {
        imprimir();
    }
}

void Pelicula::cambiarCalificacion(string nom, float calif) {
    if (nombre == nom) {
        calificacion = calif;
    }
}

void Pelicula::imprimir() {
    cout << "Pelicula - Género: " << generoP << endl;
    Video::imprimir();
}

ostream& operator<<(ostream& os, Pelicula& p) {
    os << "Pelicula - Género: " << p.generoP << endl;
    p.imprimir();
    return os;
}
