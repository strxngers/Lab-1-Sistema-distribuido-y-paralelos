#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

#include "fitsio.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <vector>
using namespace std;
namespace fs = filesystem;

_Monitor Almacenamiento{
    private:
        // Lista que guarda los nombres de las imágenes
        // vector que guarda los nombres de las imagenes
        //string* names;
        vector<string> names;
        uCondition noEmpty;
        // Información de cada imagen
        // vector de imagenes
        // imagen = double* (lista)
        // double** image_data;
        vector<double*> image_data;
        // Cantidad máxima de imágenes que se pueden guardar
        int N;
        // Lista de tamaño de imágenes
        vector<int> width;
        vector<int> height;
        // Contador
        int i;
        string monitorName;
    public:
        // Constructor de la clase
        Almacenamiento(int N, string monitorName);
        // metodo para agregar una imagen	
        void addImage(string name, double* data, int width, int height, string monitorName);
        // metodo para imprimir los nombres de las imagenes
        void printNames();
        // metodo para obtener los datos de una imagen
        double* getImageData();
        // metodo para eliminar una imagen
        void deleteImage();
        // metodo para obtener width
        int getWidth();
        // metodo para obtener height
        int getHeight();
        // metodo para obtener el nombre de la imagen
        string getName();
        // metodo para obtener el monitorName
        string getMonitorName();

};
#endif