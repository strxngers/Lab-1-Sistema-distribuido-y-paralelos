#include "Normalizacion.h"

// main del task
void Normalizacion::main() {
    // Ciclo que recorre todas las imágenes, normaliza la imagen y envía la imagen normalizada al monitor almacenamientoNormalizado
    for (int i = 0; i < N; i++) {
        // Obtener datos de la imagen original
        double* image_data = almacenamiento.getImageData();
        // width y height de la imagen
        int width = almacenamiento.getWidth();
        int height = almacenamiento.getHeight();
        // nombre de la imagen
        name = almacenamiento.getName();
        // Crear un arreglo para almacenar la imagen normalizada
        double* image_data_normalized = new double[height * width];
        // Normalizar la imagen
        normalizarImagen(image_data, image_data_normalized, height, width, Jmax);
        // Agregar la imagen normalizada al monitor almacenamientoNormalizado
        almacenamientoNormalizado.addImage(name, image_data_normalized, width, height);
        cout << "Imagen " << i + 1 << "  normalizada" << endl;
        // Liberar la memoria asignada dinámicamente
        //delete[] image_data_normalized;
        //delete[] image_data;
    }
    flagEnd = true;
}

// Constructor de la clase
Normalizacion::Normalizacion(int N,double Jmax, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoNormalizado): almacenamiento(almacenamiento), almacenamientoNormalizado(almacenamientoNormalizado){
    this->Jmax = Jmax;
    this->N = N;
    this->flagEnd = false;
    cout << "Constructor --- NORMALIZACION" << endl;
}

// Método que normaliza la imagen en base al valor máximo de intensidad
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
    cout << "min_intensity: " << min_intensity << endl;
    // Normalizar la imagen en base al valor máximo de intensidad Jmax
    for (int i = 0; i < height * width; i++) {
        image_data_normalized[i] = (image_data[i] - min_intensity) / (max_intensity - min_intensity) * Jmax;
    }
    cout << "Imagen normalizada" << endl;
}

// metodo para saber si la tarea ha terminado
bool Normalizacion::tareaHaTerminado() {
    return flagEnd;
}