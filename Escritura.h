#ifndef ESCRITURA_H
#define ESCRITURA_H

#include "fitsio.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <vector>
#include "Almacenamiento.h"
using namespace std;
namespace fs = filesystem;

_Task Escritura{
    private:
        // monitor almacenamiento
        Almacenamiento &almacenamiento;
        // prefijo del archivo de salida
        string prefijoSalida;
        void main();
        bool flagEnd;
        double* image_data;
        int N;
    
    public:
        // Constructor de la clase
        Escritura(int N, string prefijoSalida, Almacenamiento &almacenamiento);        
        // Método que escribe la imagen normalizada en un archivo FITS
        void writeImage(string nombreNuevoArchivo, double* image_data, int width, int height);
        // Método que retorna si la tarea ha terminado
        bool tareaHaTerminado();
};
#endif
