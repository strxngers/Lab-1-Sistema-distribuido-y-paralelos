#include "Prueba.h"

Prueba::Prueba(Almacenamiento &almacenamiento): almacenamiento(almacenamiento){
}

void Prueba::main(){
    cout << "Llegue" << endl;
    double* image_data = almacenamiento.getImageData(0);
    int width = almacenamiento.getSizes(0)[0]; // Obtener el ancho de la imagen
    int height = almacenamiento.getSizes(0)[1]; // Obtener la altura de la imagen
    
    // Iterar sobre cada fila de la imagen
    for (int y = 0; y < height; y++) {
        // Iterar sobre cada columna de la imagen
        for (int x = 0; x < width; x++) {
            // Calcular el índice del píxel en la imagen
            int index = y * width + x;
            // Imprimir el valor del píxel
            cout << image_data[index] << " ";
        }
        cout << endl; // Saltar a la siguiente línea después de imprimir una fila completa
    }
}

