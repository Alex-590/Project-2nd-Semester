
#include "Serie.h"
#include <iostream>
using namespace std;

Serie::Serie(string nombre, string genero) {
    nombreSerie = nombre;
    generoS = genero;
}

void Serie::mostrarInfo(string genero) {
    if (generoS == genero) {
        cout << "Serie: " << nombreSerie << endl;
        cout << "Género: " << generoS << endl;
    }
}

void Serie::agregarEpisodio(Episodio* ep) {
    episodios.push_back(ep);
}

void Serie::mostrarEpisodios() {
    for (size_t i = 0; i < episodios.size(); i++) {
        cout << "Episodio " << i + 1 << ":" << endl;
        episodios[i]->imprimir();
    }
}

void Serie::cambiarCalificacion(string nombreEpisodio, float calif) {
    for (size_t i = 0; i < episodios.size(); i++) {
        episodios[i]->cambiarCalificacion(nombreEpisodio, calif);
    }
}

void Serie::filtrarPorRating(float param) {
    for (size_t i = 0; i < episodios.size(); i++) {
        if (episodios[i]->calificacion >= param) {
            episodios[i]->imprimir();
        }
    }
}
