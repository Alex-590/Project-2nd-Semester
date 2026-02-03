
#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
using namespace std;

class Pelicula : public Video {
private:
    string generoP;

public:
    Pelicula(string id, string nombre, float calificacion, float duracion, string fechaEstreno, string genero);
    void mostrarInfo(string gen) override;
    void filtrarPorRating(float param) override;
    void cambiarCalificacion(string nom, float calif) override;
    void imprimir() override;

    friend ostream& operator<<(ostream& os,  Pelicula& p);
};

#endif
