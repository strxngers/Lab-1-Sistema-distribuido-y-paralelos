#include "Almacenamiento.h"

Almacenamiento::Almacenamiento(int N, string monitorName) {
    this->N = N;
    this->names.resize(N);
    this->image_data.resize(N);
    this->width.resize(N);
    this->height.resize(N);
    this->i = 0;
    this->monitorName = monitorName;
}

// Método para agregar una imagen
void Almacenamiento::addImage(string name, double* data, int width, int height, string monitorName) {
    this->names[i] = name;
    this->image_data[i] = data;
    this->width[i] = width;
    this->height[i] = height;
    this->monitorName = monitorName;
    // imprimir el nombre de la imagen que se esta guardando
    cout << name << " guardada en " << monitorName << endl;
    i++;

    noEmpty.signal();
}

// metodo para obtener el monitorName
string Almacenamiento::getMonitorName() {
    return monitorName;
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
    double* image = image_data.front();
    cout << monitorName << " entrega: " << this->names[0] << endl;

    image_data.erase(image_data.begin() + 0);
    i--;
    return image;
}

// metodo para obtener el width de una imagen
int Almacenamiento::getWidth() {

    // que entregue el vector completo de width
    int w = width.front();
    //eliminar el width de la lista
    width.erase(width.begin() + 0);
    return w;
}

// metodo para obtener el height de una imagen
int Almacenamiento::getHeight() {

    int h = height.front();
    height.erase(height.begin() + 0);
    return h;
}

// metodo para obtener el nombre de una imagen
string Almacenamiento::getName() {

    string name = names.front();
    names.erase(names.begin() + 0);
    return name;
}



