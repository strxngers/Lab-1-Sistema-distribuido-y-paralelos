#include "Almacenamiento.h"

Almacenamiento::Almacenamiento(int N) {
    this->N = N;
    this->names.resize(N);
    this->image_data.resize(N);
    this->width.resize(N);
    this->height.resize(N);
    this->i = 0;
}

// Método para agregar una imagen
void Almacenamiento::addImage(string name, double* data, int width, int height) {
    this->names[i] = name;
    this->image_data[i] = data;
    this->width[i] = width;
    this->height[i] = height;
    // imprimir el nombre de la imagen que se esta guardando
    cout << "Imagen " << name << " guardada" << endl;
    i++;
    noEmpty.signal();
}

// Método para imprimir todos los nombres de las imágenes
void Almacenamiento::printNames() {
    for (int j = 0; j < i; j++) {
        cout << this->names[j] << endl;
    }
}

// Método para obtener los datos de una imagen
double* Almacenamiento::getImageData() {
    if (i == 0){
        noEmpty.wait();
    }
    double* image = this->image_data[0];
    image_data.erase(image_data.begin() + 0);
    return image;
}

// metodo para obtener el width de una imagen
int Almacenamiento::getWidth() {
    if (i == 0){
        noEmpty.wait();
    }
    // que entregue el vector completo de width
    int w = this->width[0];
    //eliminar el width de la lista
    width.erase(width.begin() + 0);
    return w;
}

// metodo para obtener el height de una imagen
int Almacenamiento::getHeight() {
    if (i == 0){
        noEmpty.wait();
    }
    int h = this->height[0];
    height.erase(height.begin() + 0);
    return h;
}

// metodo para obtener el nombre de una imagen
string Almacenamiento::getName() {
    if (i == 0){
        noEmpty.wait();
    }
    string name = this->names[0];
    names.erase(names.begin() + 0);
    return name;
}



