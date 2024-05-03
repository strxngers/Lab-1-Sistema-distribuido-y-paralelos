#ifndef FILTRORESOLUCION_H
#define FILTRORESOLUCION_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <cmath>
#include <vector>
#include "Almacenamiento.h"
using namespace std;
namespace fs = filesystem;

_Task FiltroResolucion{
    private:
        // monitor almacenamiento
        Almacenamiento &almacenamiento;
        // monitor al que le enviaré la imagen filtrada
        Almacenamiento &almacenamientoFiltrado; 
        // theta
        double theta;
        // imagen original
        double* image_data;
        // imagen filtrada
        double* image_data_filtered;
        // tamaño de la imagen
        int width;
        int height;
        string name;
        // Kernel para la máscara de convolución
        //<vector<vector<double>> Kernel;
        // main
        int N;
        //bool flagEnd;
        void main();
             
    public:
        // Constructor de la clase
        FiltroResolucion(int N, double theta, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoFiltrado);        
        // Método que crea el kernel de la máscara de convolución
        void newKernel(vector<vector<double>>& kernel, int ksize, double theta);
        // Método al que se le entrega un kernel y una imagen y devuelve la imagen filtrada
        void aplicarFiltro(vector<vector<double>>& kernel, double* image_data, double* image_data_filteres , int height, int width);
        // Método que retorna si la tarea ha terminado
        //bool tareaHaTerminado();


};
#endif


