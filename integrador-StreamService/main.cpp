
#include "Plataforma.h"
#include <iostream>
using namespace std;

int main() {
    Plataforma plataforma;
    int opcion;

    do {
        plataforma.mostrarMenu();
        cin >> opcion;
        plataforma.elegirOpcion(opcion);
    } while (opcion != 0);

    return 0;
}
