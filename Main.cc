#include <stdio.h>
#include "Lectura.h"
#include "Almacenamiento.h"
//#include "Prueba.h"
#include "FiltroResolucion.h"
#include "FiltroRuido.h"
#include "Normalizacion.h"

int main(){
    // monitors
    Almacenamiento* monitor1 = new Almacenamiento(2);
    Almacenamiento* monitor2 = new Almacenamiento(2);
    Almacenamiento* monitor3 = new Almacenamiento(2);
    Almacenamiento* monitor4 = new Almacenamiento(2);
    // tasks
    Lectura* lectura = new Lectura(2,"image", *monitor1);
    FiltroResolucion* filtroResolucion = new FiltroResolucion(2,0.5, *monitor1, *monitor2);
    FiltroRuido* filtroRuido = new FiltroRuido(2, 0.5, *monitor2, *monitor3);
    Normalizacion* normalizacion = new Normalizacion(2, 5, *monitor3, *monitor4);
    // si la tarea filtroResolucion ha terminado, se eliminan las tareas
    if (normalizacion->tareaHaTerminado()){
        delete filtroResolucion;
        delete filtroRuido;
        delete normalizacion;
        delete lectura;
        delete monitor1;
        delete monitor2;
        delete monitor3;
        delete monitor4;
    }
 


    
    
    //Prueba* tarea = new Prueba(*monitor1);
    //delete tarea;
    return 0;

}