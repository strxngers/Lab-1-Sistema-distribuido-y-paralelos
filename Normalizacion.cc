#include "Normalizacion.h"

// main del task
void Normalizacion::main() {
    // Ciclo que recorre todas las imágenes, normaliza la imagen y envía la imagen normalizada al monitor almacenamientoNormalizado
    for (int i = 0; i < N; i++) {
        // Obtener datos de la imagen original
        double* image_data = almacenamiento.getImageData();
        if (image_data != NULL) {
            cout << "Imagen obtenida" << endl;
        } else {
            cout << "No se pudo obtener la imagen" << endl;
        }
        // width y height de la imagen
        int width = almacenamiento.getWidth();
        int height = almacenamiento.getHeight();
        // nombre de la imagen
        name = almacenamiento.getName();
        cout << "Nombre de la imagen: " << name << endl;
        // Crear un arreglo para almacenar la imagen normalizada
        double* image_data_normalized = new double[height * width];
        // Normalizar la imagen
        normalizarImagen(image_data, image_data_normalized, height, width, Jmax);
        // Agregar la imagen normalizada al monitor almacenamientoNormalizado
        almacenamientoNormalizado.addImage(name, image_data_normalized, width, height, almacenamientoNormalizado.getMonitorName());
        //almacenamientoNormalizado.addImage(name, image_data, width, height, almacenamientoNormalizado.getMonitorName());

        //cout << "Imagen " << i + 1 << "  normalizada" << endl;
        // Liberar la memoria asignada dinámicamente
        //delete[] image_data;
    }
    //delete[] image_data_normalized;
    //flagEnd = true;
}

// Constructor de la clase
Normalizacion::Normalizacion(int N,double Jmax, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoNormalizado): almacenamiento(almacenamiento), almacenamientoNormalizado(almacenamientoNormalizado){
    this->Jmax = Jmax;
    this->N = N;
    //this->flagEnd = false;
    cout << "Constructor --- NORMALIZACION" << endl;
}

void Normalizacion::normalizarImagen(double* image_data, double* image_data_normalized, int height, int width, double Jmax) {
    double min_intensity = image_data[0];
    double max_intensity = image_data[0];

    // Encontrar el valor mínimo y máximo de intensidad en la imagen
    for (int i = 0; i < height * width; i++) {
        if (image_data[i] < min_intensity) {
            min_intensity = image_data[i];
        }
        if (image_data[i] > max_intensity) {
            max_intensity = image_data[i];
        }
    }

    // Si el valor mínimo y máximo son iguales, evita la división por cero
    if (max_intensity == min_intensity) {
        // Establece el valor máximo y mínimo a diferentes valores
        max_intensity = min_intensity + 1.0;
    }

    cout << "min_intensity: " << min_intensity << endl;
    
    // Normalizar la imagen en base al valor máximo de intensidad Jmax
    for (int i = 0; i < height * width; i++) {
        // Convertir el valor de intensidad a mili Janskys
        //double intensity_mJy = image_data[i] * 1000.0; // Convertir a mili Janskys
        // Normalizar la imagen
        image_data_normalized[i] = (image_data[i] - min_intensity) / (max_intensity - min_intensity) * Jmax;
    }

    //cout << "Imagen normalizada" << endl;
}


/*
// metodo para saber si la tarea ha terminado
bool Normalizacion::tareaHaTerminado() {
    return flagEnd;
}
*/