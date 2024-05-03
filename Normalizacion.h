#ifndef NORMALIZACION_H
#define NORMALIZACION_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <cmath>
#include <vector>
#include "Almacenamiento.h"
using namespace std;
namespace fs = filesystem;

_Task Normalizacion{
    private:
        // monitor almacenamiento
        Almacenamiento &almacenamiento;
        // monitor al que le enviaré la imagen filtrada
        Almacenamiento &almacenamientoNormalizado; 

        // imagen inicial
        double* image_data;
        // imagen normalizada
        double* image_data_normalized;
        // tamaño de la imagen
        int width;
        int height;
        string name;
        double Jmax; // Valor máximo de intensidad en mJy
        int N;
        bool flagEnd;
        void main();
    
    public:
        // Constructor de la clase
        Normalizacion(int N, double Jmax, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoNormalizado);        
        // Método que normaliza la imagen en base al valor máximo de intensidad
        void normalizarImagen(double* image_data, double* image_data_normalized, int height, int width, double Jmax);
        // Método que retorna si la tarea ha terminado
        bool tareaHaTerminado();
};
#endif        