
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include "Informacion.h"
using namespace std;

class Video : public Informacion {
private:
    string id;
    float duracion;
    string fechaDeEstreno;

public:
    string nombre;
    float calificacion;

    Video(string ID, string nom, float calif, float Duracion, string fechaE);
    virtual void imprimir();
};

#endif