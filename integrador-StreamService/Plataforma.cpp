
#include "Plataforma.h"
#include "Serie.h"
#include "Pelicula.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Plataforma::Plataforma() {
    cargarDesdeCSV("BasePeliculas.csv");
}

void Plataforma::agregarVideo(Informacion* video) {
    listaDeVideos.push_back(video);
}

void Plataforma::mostrarEp(string nombre) {
    for (Informacion* video : listaDeVideos) {
        Serie* serie = dynamic_cast<Serie*>(video);
        if (serie != nullptr && serie->nombreSerie == nombre) {
            serie->mostrarEpisodios();
        }
    }
}

void Plataforma::calificar(string nombre, float calif) {
    for (Informacion* video : listaDeVideos) {
        video->cambiarCalificacion(nombre, calif);
    }
}

void Plataforma::mostararGenero(string gen) {
    for (Informacion* video : listaDeVideos) {
        video->mostrarInfo(gen);
    }
}

void Plataforma::filtrarPorRating(float param) {
    for (Informacion* video : listaDeVideos) {
        video->filtrarPorRating(param);
    }
}

void Plataforma::mostrarPeliculasPorCalificacion(float param) {
    for (Informacion* video : listaDeVideos) {
        Pelicula* pelicula = dynamic_cast<Pelicula*>(video);
        if (pelicula != nullptr) {
            pelicula->filtrarPorRating(param);
        }
    }
}

void Plataforma::mostrarMenu() {
    cout << "\n----- MENÚ DE PLATAFORMA -----\n";
    cout << "1. Mostrar videos con calificación mayor a....\n";
    cout << "2. Mostrar videos de cierto género\n";
    cout << "3. Mostrar episodios de una serie\n";
    cout << "4. Mostrar películas con calificación mayor a....\n";
    cout << "5. Calificar un video (película o episodio)\n";
    cout << "0. Salir\n";
    cout << "Selecciona una opción: ";
}

void Plataforma::elegirOpcion(int A) {
    switch (A) {
        case 1: {
            float rating;
            cout << "Ingresa la calificación mínima: ";
            cin >> rating;
            filtrarPorRating(rating);
            break;
        }
        case 2: {
            string genero;
            cout << "Ingresa el género: ";
            cin >> genero;
            mostararGenero(genero);
            break;
        }
        case 3: {
            string nombreSerie;
            cout << "Ingresa el nombre de la serie: ";
            cin >> nombreSerie;
            mostrarEp(nombreSerie);
            break;
        }
        case 4: {
            float rating;
            cout << "Ingresa la calificación mínima para películas: ";
            cin >> rating;
            mostrarPeliculasPorCalificacion(rating);
            break;
        }
        case 5: {
            string nombre;
            float calif;
            cout << "Ingresa el nombre del video a calificar: ";
            cin >> nombre;
            cout << "Ingresa la calificación (1 a 10): ";
            cin >> calif;
            calificar(nombre, calif);
            break;
        }
        case 0: {
            cout << "Saliendo del programa...\n";
            break;
        }
        default:
            cout << "Opción inválida.\n";
            break;
    }
}

void Plataforma::cargarDesdeCSV(string archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    getline(file, linea);  

    while (getline(file, linea)) {
        stringstream ss(linea);
        string id, nombre, duracionStr, genero, califStr, fecha, nomEp, tempStr, numEpStr, idEp;

        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, duracionStr, ',');
        getline(ss, genero, ',');
        getline(ss, califStr, ',');
        getline(ss, fecha, ',');
        getline(ss, nomEp, ',');
        getline(ss, tempStr, ',');
        getline(ss, numEpStr, ',');
        getline(ss, idEp, ',');

        float duracion = (duracionStr != "") ? stof(duracionStr) : 0;
        float calif = (califStr != "") ? stof(califStr) : 0;

        if (nomEp.empty()) {
            Pelicula* peli = new Pelicula(id, nombre, calif, duracion, fecha, genero);
            agregarVideo(peli);
        } else {
            int temporada = (tempStr != "") ? stoi(tempStr) : 0;
            int numEpisodio = (numEpStr != "") ? stoi(numEpStr) : 0;

            Episodio* ep = new Episodio(idEp, nomEp, calif, duracion, fecha, temporada, numEpisodio);

            bool encontrada = false;
            for (Informacion* video : listaDeVideos) {
                Serie* serie = dynamic_cast<Serie*>(video);
                if (serie != nullptr && serie->nombreSerie == nombre) {
                    serie->agregarEpisodio(ep);
                    encontrada = true;
                    break;
                }
            }

            if (!encontrada) {
                Serie* nuevaSerie = new Serie(nombre, genero);
                nuevaSerie->agregarEpisodio(ep);
                agregarVideo(nuevaSerie);
            }
        }
    }

    cout << "Archivo cargado correctamente." << endl;
    file.close();
}
