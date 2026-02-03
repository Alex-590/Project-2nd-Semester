
#include "Episodio.h"
#include <iostream>
using namespace std;

Episodio::Episodio(string id, string nombre, float calificacion, float duracion, string fechaEstreno, int temp, int numEp)
    : Video(id, nombre, calificacion, duracion, fechaEstreno) {
    temporada = temp;
    numeroEpisodio = numEp;
}

void Episodio::imprimir() {
    cout << "Episodio: " << nombre << endl;
    cout << "Temporada: " << temporada << " Episodio: " << numeroEpisodio << endl;
    cout << "Calificación: " << calificacion << endl;
}

void Episodio::mostrarInfo(string gen) {
    imprimir();
}

void Episodio::filtrarPorRating(float param) {
    if (calificacion >= param) {
        imprimir();
    }
}

void Episodio::cambiarCalificacion(string nom, float calif) {
    if (nombre == nom) {
        calificacion = calif;
        cout << "Nueva calificación para el episodio \"" << nombre << "\": " << calificacion << endl;
    }
}

ostream& operator<<(ostream& os, const Episodio& e) {
    os << "Episodio: " << e.nombre << endl;
    os << "Temporada: " << e.temporada << " Episodio: " << e.numeroEpisodio << endl;
    os << "Calificación: " << e.calificacion << endl;
    return os;
}
