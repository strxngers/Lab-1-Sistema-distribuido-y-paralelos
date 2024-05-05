#include "Normalizacion.h"

// main del task
void Normalizacion::main() {
    for (int i = 0; i < N; i++) {
        // Obtener datos de la imagen original
        double* image_data = almacenamiento.getImageData();
        // width y height de la imagen
        int width = almacenamiento.getWidth();
        int height = almacenamiento.getHeight();
        // nombre de la imagen
        name = almacenamiento.getName();
        cout << "Normalizando la imagen " << name << "..." << endl;
        // Crear un arreglo para almacenar la imagen normalizada
        double* image_data_normalized = new double[height * width];
        // Normalizar la imagen
        normalizarImagen(image_data, image_data_normalized, height, width, Jmax);
        cout << "Imagen " << name << " normalizada." << endl;
        // Agregar la imagen normalizada al monitor almacenamientoNormalizado
        almacenamientoNormalizado.addImage(name, image_data_normalized, width, height, almacenamientoNormalizado.getMonitorName());
    }
}

// Constructor de la clase
Normalizacion::Normalizacion(int N,double Jmax, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoNormalizado): almacenamiento(almacenamiento), almacenamientoNormalizado(almacenamientoNormalizado){
    this->Jmax = Jmax;
    this->N = N;
}

void Normalizacion::normalizarImagen(double* image_data, double* image_data_normalized, int height, int width, double Jmax) {
    // Verificar punteros nulos
    if (image_data == nullptr || image_data_normalized == nullptr) {
        cout << "Error: Se encontró un puntero nulo." << endl;
        return;
    }
    // Verificar dimensiones de la imagen
    if (height <= 0 || width <= 0) {
        cout << "Error: Dimensiones de la imagen inválidas." << endl;
        return;
    }
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
    // Manejar caso de división por cero
    if (max_intensity == min_intensity) {
        max_intensity = min_intensity + 1.0; // Asignar un valor predeterminado
    }
    // Normalizar la imagen en base al valor máximo de intensidad Jmax
    for (int i = 0; i < height * width; i++) {
        image_data_normalized[i] = (image_data[i] - min_intensity) / (max_intensity - min_intensity) * Jmax;
    }
}