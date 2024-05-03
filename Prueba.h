#ifndef PRUEBA_H
#define PRUEBA_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <cmath>
#include <vector>
#include "Almacenamiento.h"
using namespace std;
//namespace fs = filesystem;

_Task Prueba{
    //esto es una tarea para probar si puedo entregarle las cosas a otra tarea con el monitor
    private:
        // monitor almacenamiento
        Almacenamiento &almacenamiento;

        // main
        void main();
    
    public:
        // Constructor de la clase
        Prueba(Almacenamiento &almacenamiento);
        // método que imprime la imagen del monitor

            


};
#endif