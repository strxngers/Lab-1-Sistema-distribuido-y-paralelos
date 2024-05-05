#include "FiltroResolucion.h"

void FiltroResolucion::main(){
    // Crear el kernel
    vector<vector<double>> kernel;
    newKernel(kernel, 27, 0.92);
    // Iterar sobre las N imágenes
    for (int i = 0; i < N; i++) {
        // Obtener datos de la imagen original
        double* image_data = almacenamiento.getImageData();  
        // width y height de la imagen
        int width = almacenamiento.getWidth();
        int height = almacenamiento.getHeight();
        // nombre de la imagen
        name = almacenamiento.getName();
        cout << "Aplicando filtro de resolución a la imagen " << name << "..." << endl;
        // Crear un arreglo para almacenar la imagen filtrada
        double* image_data_filtered = new double[height * width];
        // Aplicar el filtro
        aplicarFiltro(kernel, image_data, image_data_filtered, height, width);
        cout << "Filtro de resolución aplicado a la imagen " << name << "." << endl;
        // Agregar la imagen filtrada al monitor almacenamientoFiltrado
        almacenamientoFiltrado.addImage(name, image_data_filtered, width, height, almacenamientoFiltrado.getMonitorName());
    }
}

FiltroResolucion::FiltroResolucion(int N, double theta, Almacenamiento &almacenamiento, Almacenamiento &almacenamientoFiltrado)
    : almacenamiento(almacenamiento), almacenamientoFiltrado(almacenamientoFiltrado) {
    this->N = N; // Establecer N
    this->theta = theta; // Establecer theta
}

 // Método que crea el kernel de la máscara de convolución
void FiltroResolucion::newKernel(vector<vector<double>>& kernel, int ksize, double theta) {
    // Parámetros de la máscara de convolución
    const double sigma_x = 3.5;     // sigma x e y son iguales 
    const double sigma_y = 3.5; 
    double sum = 0.0;
    int centro = ksize / 2;
    double a = cos(theta) * cos(theta) / (2 * sigma_x * sigma_x) + sin(theta) * sin(theta) / (2 * sigma_y * sigma_y);
    double b = -sin(2 * theta) / (4 * sigma_x * sigma_x) + sin(2 * theta) / (4 * sigma_y * sigma_y);
    double c = sin(theta) * sin(theta) / (2 * sigma_x * sigma_x) + cos(theta) * cos(theta) / (2 * sigma_y * sigma_y);
    kernel.resize(ksize, vector<double>(ksize, 0));
    // Creación del kernel 27x27
    for (int i = 0; i < ksize; ++i) {
        for (int j = 0; j < ksize; ++j) {
            double x = i - centro;
            double y = j - centro;
            kernel[i][j] = exp(-(a * x * x + 2 * b * x * y + c * y * y));
            sum += kernel[i][j];
        }
    }
    // Normalización del kernel
    for (int i = 0; i < ksize; ++i) {
        for (int j = 0; j < ksize; ++j) {
            kernel[i][j] /= sum;
        } 
    }  
}

void FiltroResolucion::aplicarFiltro(vector<vector<double>>& kernel, double* image_data, double* image_data_filtered, int height, int width) {
    // Verificar que el tamaño del kernel sea cuadrado
    int ksize = kernel.size();
    if (ksize % 2 == 0 || ksize != kernel[0].size()) {
        cerr << "El tamaño del kernel debe ser un número impar y cuadrado." << endl;
        return;
    }
    int centro = ksize / 2;
    // Iterar sobre cada fila de la imagen
    for (int y = 0; y < height; y++) {
        // Iterar sobre cada columna de la imagen
        for (int x = 0; x < width; x++) {
            // Calcular el índice del píxel en la imagen
            int index = y * width + x;
            // Inicializar el valor del píxel filtrado
            image_data_filtered[index] = 0;
            // Iterar sobre cada fila del kernel
            for (int i = 0; i < ksize; i++) {
                // Iterar sobre cada columna del kernel
                for (int j = 0; j < ksize; j++) {
                    // Calcular las coordenadas del píxel en la imagen
                    int x_imagen = x + i - centro;
                    int y_imagen = y + j - centro;
                    // Verificar que el píxel esté dentro de la imagen
                    if (x_imagen >= 0 && x_imagen < width && y_imagen >= 0 && y_imagen < height) {
                        // Calcular el índice del píxel en la imagen
                        int index_imagen = y_imagen * width + x_imagen;
                        // Sumar el valor del píxel multiplicado por el valor del kernel
                        image_data_filtered[index] += image_data[index_imagen] * kernel[i][j];
                    }
                }
            }
        }
    }
}





