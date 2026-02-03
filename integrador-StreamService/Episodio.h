
#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"
using namespace std;

class Episodio : public Video {
private:
    int temporada;
    int numeroEpisodio;

public:
    Episodio(string id, string nombre, float calificacion, float duracion, string fechaEstreno, int temp, int numEp);
    void imprimir() override;
    void mostrarInfo(string gen) override;
    void filtrarPorRating(float param) override;
    void cambiarCalificacion(string nom, float calif) override;

    friend ostream& operator<<(ostream& os, const Episodio& e);
};

#endif
