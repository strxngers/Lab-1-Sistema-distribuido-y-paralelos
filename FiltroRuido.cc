#include "FiltroRuido.h"
#include <random>

// Método main
void FiltroRuido::main() {
    for (int i = 0; i < N; i++) {
        // Obtener datos de la imagen original
        double* image_data = almacenamiento.getImageData();
        // width y height de la imagen
        int width = almacenamiento.getWidth();
        int height = almacenamiento.getHeight();
        // nombre de la imagen
        name = almacenamiento.getName();
        cout << "Aplicando ruido a la imagen " << name << "..." << endl;
        // Crear un arreglo para almacenar la imagen filtrada
        double* image_data_filtered = new double[height * width];
        // Agregar ruido a la imagen
        agregarRuido(image_data, image_data_filtered, height, width, sigma);
        cout << "Ruido aplicado a la imagen " << name << "." << endl;
        // Agregar la imagen filtrada al monitor almacenamientoFiltrado
        almacenamientoFiltrado.addImage(name, image_data_filtered, width, height,almacenamientoFiltrado.getMonitorName() );
    }
}    

// Constructor de la clase
FiltroRuido::FiltroRuido(int N, double sigma, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoFiltrado)
    : almacenamiento(almacenamiento), almacenamientoFiltrado(almacenamientoFiltrado) {
    this->N = N; // Establecer N
    this->sigma = sigma; // Establecer sigma
}

// Método que le agrega a la imagen ruido gaussiano
void FiltroRuido::agregarRuido(double* image_data, double* image_data_filtered, int height, int width, double sigma) {
    // Creación de la distribución normal
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, sigma);
    // Agregar ruido a la imagen
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            image_data_filtered[i * width + j] = image_data[i * width + j] + distribution(generator);
        }
    }
}