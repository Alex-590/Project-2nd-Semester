
#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Informacion.h"
#include <vector>
#include <string>
using namespace std;

class Plataforma {
private:
    vector<Informacion*> listaDeVideos;

public:
    Plataforma();
    void agregarVideo(Informacion*);
    void mostrarEp(string nombreSerie);
    void calificar(string nombre, float calif);
    void mostararGenero(string gen);
    void filtrarPorRating(float param);
    void mostrarPeliculasPorCalificacion(float param);
    void mostrarMenu();
    void elegirOpcion(int A);
    void cargarDesdeCSV(string archivo);
};

#endif
