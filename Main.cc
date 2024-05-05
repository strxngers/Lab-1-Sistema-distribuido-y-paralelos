#include <stdio.h>
#include <iostream>
#include <string>
#include "Lectura.h"
#include "Almacenamiento.h"
#include "FiltroResolucion.h"
#include "FiltroRuido.h"
#include "Normalizacion.h"
#include "Escritura.h"


int main(int argc, char* argv[]){
    // Inicio del programa
    cout << "Starting program" << endl;
    // variables para los argumentos
    string inputFilePrefix, outputFilePrefix;
    float sigma, theta, intensity;
    int N;

    // Parseo de argumentos
    int opt;
    while ((opt = getopt(argc, argv, "i:o:s:t:j:N:")) != -1) {
        switch (opt) {
            case 'i':
                inputFilePrefix = optarg;
                break;
            case 'o':
                outputFilePrefix = optarg;
                break;
            case 's':
                sigma = atof(optarg);
                break;
            case 't':
                theta = atof(optarg);
                break;
            case 'j':
                intensity = atof(optarg);
                break;
            case 'N':
                N = atoi(optarg);
                break;
            default:
                cout << "Invalid argument, check flags" << endl;
                return 1;
        }
    }

    // Inicialización de monitores
    Almacenamiento* monitor1 = new Almacenamiento(N, "monitor1");
    Almacenamiento* monitor2 = new Almacenamiento(N, "monitor2");
    Almacenamiento* monitor3 = new Almacenamiento(N, "monitor3");
    Almacenamiento* monitor4 = new Almacenamiento(N, "monitor4");

    // Inicialización de tareas
    Lectura* lectura = new Lectura(N,inputFilePrefix, *monitor1);
    FiltroResolucion* filtroResolucion = new FiltroResolucion(N, theta, *monitor1, *monitor2);
    FiltroRuido* filtroRuido = new FiltroRuido(N, sigma, *monitor2, *monitor3);
    Normalizacion* normalizacion = new Normalizacion(N, intensity, *monitor3, *monitor4);
    Escritura* escritura = new Escritura(N, outputFilePrefix, *monitor4);

    // Si la tarea escritura (útima)
    if (escritura->tareaHaTerminado()){
        delete lectura;
        delete filtroResolucion;
        delete filtroRuido;
        delete normalizacion;
        delete escritura;
        cout << "All tasks have been completed and deleted" << endl;
        delete monitor1;
        delete monitor2;
        delete monitor3; 
        delete monitor4;
        cout << "All monitors have been deleted" << endl;      
    }
    cout << "Program finished" << endl;
    return 0;

}