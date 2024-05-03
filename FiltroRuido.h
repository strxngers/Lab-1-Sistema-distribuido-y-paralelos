#ifndef FILTRORUIDO_H
#define FILTRORUIDO_H 

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <cmath>
#include <vector>
#include "Almacenamiento.h"
using namespace std;
namespace fs = filesystem;

_Task FiltroRuido{
    private:
        // monitor almacenamiento
        Almacenamiento &almacenamiento;
        // monitor al que le enviaré la imagen filtrada
        Almacenamiento &almacenamientoFiltrado; 

        // sigma
        double sigma;
        // imagen inicial
        double* image_data;
        // imagen filtrada
        double* image_data_filtered;
        // tamaño de la imagen
        int width;
        int height;
        string name;
        int N;
        //bool flagEnd;
        void main();
    
    public:
        // Constructor de la clase
        FiltroRuido(int N, double sigma, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoFiltrado);        
        // Método que le agrega a la imagen ruido gaussiano
        void agregarRuido(double* image_data, double* image_data_filtered, int height, int width, double sigma);
        // Método que retorna si la tarea ha terminado
        //bool tareaHaTerminado();


};
#endif