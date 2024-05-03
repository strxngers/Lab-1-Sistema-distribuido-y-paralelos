#include "Lectura.h"


void Lectura::main() {
    // Aquí va todo, leer y mandar a monitor
    // Directorio donde se encuentran los archivos FITS
    string directorio = ".";

    // Prefijo y extensión de los archivos FITS a buscar
    string prefijo = "image";
    string extension = ".fits";
    // Indexa los archivos que cumplan con el criterio y los guarda en esa posición
    int i = 0;
    // Recorrer el directorio en busca de archivos que cumplan con el criterio
    for (const auto& archivo : fs::directory_iterator(directorio)) {
        if (archivo.is_regular_file() && archivo.path().extension() == extension &&
                archivo.path().filename().string().find(prefijo) != string::npos) {
            readImage(archivo.path().filename().string(), i);
            // Guardar en el monitor
            almacenamiento.addImage(names[i], image_data[i], width[i], height[i]);
            i++;
        }
        if(i == N) {
            break;
        }
    }
    //almacenamiento.printNames();
}

// Constructor de la clase
Lectura::Lectura(int N, string prefijo, Almacenamiento &almacenamiento): almacenamiento(almacenamiento) {
    this->N = N;
    this->prefijo = prefijo;
    this->names.resize(N);
    this->image_data.resize(N);
    this->width.resize(N);
    this->height.resize(N);
    cout << "Lectura" << endl;
}

void Lectura::readImage(const string& nombreArchivo, int i) {
    fitsfile* fptr;
    int status = 0;
    //cout << nombreArchivo << endl;
    // Abrir el archivo FITS en modo de lectura
    fits_open_file(&fptr, nombreArchivo.c_str(), READONLY, &status);
    if (status != 0) {
        fits_report_error(stderr, status);
        return;
    }
    cout << "Leyendo imagen FITS..." << nombreArchivo << endl;

    int bitpix, naxis;
    long naxes[2];
    //cout << "salio1" << endl;
    // Obtener información básica de la imagen FITS
    fits_get_img_param(fptr, 2, &bitpix, &naxis, naxes, &status);
    if (status != 0) {
        fits_report_error(stderr, status);
        exit(EXIT_FAILURE);
    }
    //cout << "salio2" << endl;
    // Verificar que la imagen tenga dos ejes (2D)
    if (naxis != 2) {
        cerr << "La imagen FITS no es 2D." << endl;
        exit(EXIT_FAILURE);
    }

    // Asignar dimensiones de la imagen (ancho x alto) a vectores width y height
    width[i] = naxes[0];
    height[i] = naxes[1];

    // Imprimir los valores de ancho y alto para verificar el tamaño del arreglo de datos
    //cout << "Ancho de la imagen: " << width[i] << endl;
    //cout << "Altura de la imagen: " << height[i] << endl;

    //cout << "salio3" << endl;
    // Crear un buffer para almacenar la imagen
    double *image_data = new double[width[i] * height[i]];
    long fpixel = 1; // Coordenadas del primer píxel a leer
    // Leer toda la imagen
    //cout << "aa " << status << endl;
    fits_read_img(fptr, TDOUBLE, fpixel, width[i] * height[i], NULL, image_data, NULL, &status);
    //fits_read_pix(fptr, TBYTE, fpixel, width * height, NULL, image_data, NULL, &status);
    if (status != 0) {
        cout << "a" << endl;
        fits_report_error(stderr, status);
        exit(EXIT_FAILURE);
    }
    //cout << "salio4" << endl;

    // Guardar en la lista
    names[i] = nombreArchivo;
    this->image_data[i] = image_data;

    //cout << image_data << " " << width[i] << " " << height[i] << endl;
    //cout << "salio5" << endl;

    // Cerrar el archivo FITS
    fits_close_file(fptr, &status);
    cout << "Imagen FITS leída exitosamente." << endl;
}


