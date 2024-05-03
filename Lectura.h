#ifndef LECTURA_H
#define LECTURA_H

#include "fitsio.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <vector>
#include "Almacenamiento.h"
using namespace std;
namespace fs = filesystem;

_Task Lectura{
    private:
        // Lista que guarda los nombres de las imágenes
        // string* names;
        vector<string> names;
        // Información de cada imagen
        // double** image_data;
        vector<double*> image_data;
        // Monitor donde voy a guardar las Imágenes
        Almacenamiento &almacenamiento;
        // Cantidad de imágenes
        int N;
        string prefijo;
        // Lista de tamaño de imágenes
        vector<int> width;
        vector<int> height;
        void main();

    public:
        // Constructor de la clase
        Lectura(int N, string prefijo, Almacenamiento &almacenamiento);
        // Metodo para leer una imagen
        void readImage(const string& nombreArchivo, int i);
};

#endif
