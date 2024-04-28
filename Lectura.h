#ifndef LECTURA_H
#define LECTURA_H

#include <fitsio.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

_Task Lectura{
    private:
    // Lista que guarda los nombres de las imágenes
    string* names;
    // Información de cada imagen
    float **image_data;
    // Monitor donde voy a guardar las cosas
    // por añadir
    // Cantidad de imágenes
    int N;
    string prefijo;
    // Lista de tamaño de imágenes
    int* sizes[2];

    void main();


    public:
    // Con esto asumo que ya todo se pasó bien
    Lectura(int N, string prefijo);

    void readImage(const std::string& nombreArchivo, int i);

};

#endif
