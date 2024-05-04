#include <stdio.h>
#include "Lectura.h"
#include "Almacenamiento.h"
//#include "Prueba.h"
#include "FiltroResolucion.h"
#include "FiltroRuido.h"
#include "Normalizacion.h"
#include "Escritura.h"

int main(){
    // monitors
    Almacenamiento* monitor1 = new Almacenamiento(1, "monitor1");
    Almacenamiento* monitor2 = new Almacenamiento(1, "monitor2");
    Almacenamiento* monitor3 = new Almacenamiento(1, "monitor3");
    Almacenamiento* monitor4 = new Almacenamiento(1, "monitor4");
    // tasks
    Lectura* lectura = new Lectura(1,"image", *monitor1);
    FiltroResolucion* filtroResolucion = new FiltroResolucion(1,0.92, *monitor1, *monitor2);
    FiltroRuido* filtroRuido = new FiltroRuido(1, 0.00000000000000001, *monitor2, *monitor3);
    Normalizacion* normalizacion = new Normalizacion(1, 0.03, *monitor3, *monitor4);
    Escritura* escritura = new Escritura(1, "imageout", *monitor4);

    // si la tarea filtroResolucion ha terminado, se eliminan las tareas
    if (escritura->tareaHaTerminado()){
        delete lectura;
        // print termino la tarea de lectura
        cout << "termino la tarea de lectura" << endl;
        delete filtroResolucion;
        // print termino la tarea de filtroResolucion
        cout << "termino la tarea de filtroResolucion" << endl;
        delete normalizacion;
        // print termino la tarea de normalizacion      
        cout << "termino la tarea de normalizacion" << endl;
        delete filtroRuido;
        // print termino la tarea de filtroRuido
        cout << "termino la tarea de filtroRuido" << endl;
    
        delete escritura;
        // print termino la tarea de escritura
        cout << "termino la tarea de escritura" << endl;
        delete monitor1;
        // print termino el monitor 1
        cout << "termino el monitor 1" << endl;
        delete monitor2;
        // print termino el monitor 2
        cout << "termino el monitor 2" << endl;
        delete monitor3;
        // print termino el monitor 3
        cout << "termino el monitor 3" << endl;
        
       
        delete monitor4;
        // print termino el monitor 4
        cout << "termino el monitor 4" << endl;
       
    }
 


    
    
    //Prueba* tarea = new Prueba(*monitor1);
    //delete tarea;
    return 0;

}