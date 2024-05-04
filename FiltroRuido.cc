#include "FiltroRuido.h"
#include <random>

// Método main
void FiltroRuido::main() {
    // Ciclo que recorre todas las imágenes, agrega ruido y envía la imagen filtrada al monitor almacenamientoFiltrado
    for (int i = 0; i < N; i++) {
        // Obtener datos de la imagen original
        double* image_data = almacenamiento.getImageData();
        // width y height de la imagen
        int width = almacenamiento.getWidth();
        int height = almacenamiento.getHeight();
        // nombre de la imagen
        name = almacenamiento.getName();
        // Crear un arreglo para almacenar la imagen filtrada
        double* image_data_filtered = new double[height * width];
        // Agregar ruido a la imagen
        agregarRuido(image_data, image_data_filtered, height, width, sigma);
        // Agregar la imagen filtrada al monitor almacenamientoFiltrado
        almacenamientoFiltrado.addImage(name, image_data_filtered, width, height,almacenamientoFiltrado.getMonitorName() );
        cout << "Imagen " << i + 1 << "  con ruido agregada" << endl;
        // Liberar la memoria asignada dinámicamente
        //delete[] image_data_filtered;
        //delete[] image_data;
    }
    //flagEnd = true;
}


// Constructor de la clase
FiltroRuido::FiltroRuido(int N, double sigma, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoFiltrado)
    : almacenamiento(almacenamiento), almacenamientoFiltrado(almacenamientoFiltrado) {
    this->N = N; // Establecer N
    this->sigma = sigma; // Establecer sigma
    //this->flagEnd = false; // Establecer flagEnd
    // Cuerpo del constructor
    cout << "Constructor --- RUIDO" << endl;
}

// Método que le agrega a la imagen ruido gaussiano
void FiltroRuido::agregarRuido(double* image_data, double* image_data_filtered, int height, int width, double sigma) {
    cout << "Agregando ruido" << endl;
    // Creación de la distribución normal
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, sigma);
    // Agregar ruido a la imagen
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            image_data_filtered[i * width + j] = image_data[i * width + j] + distribution(generator);
        }
    }
    cout << "Ruido agregado" << endl;
}

/*
// Método que retorna si la tarea ha terminado
bool FiltroRuido::tareaHaTerminado() {
    return flagEnd;
}
*/