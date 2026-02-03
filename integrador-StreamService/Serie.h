
#ifndef SERIE_H
#define SERIE_H

#include "Informacion.h"
#include "Episodio.h"
#include <vector>
using namespace std;

class Serie : public Informacion {
public:
    string nombreSerie;
    string generoS;
    vector<Episodio*> episodios;

    Serie(string nombre, string genero);
    void mostrarInfo(string genero) override;
    void agregarEpisodio(Episodio* ep);
    void mostrarEpisodios();
    void cambiarCalificacion(string nombreEpisodio, float calif) override;
    void filtrarPorRating(float param) override;
};

#endif
