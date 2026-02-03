
#ifndef INFORMACION_H
#define INFORMACION_H

#include <string>
using std::string;

class Informacion {
public:
    virtual void mostrarInfo(string gen) = 0;
    virtual void filtrarPorRating(float param) = 0;
    virtual void cambiarCalificacion(string nom, float calif) = 0;
};

#endif