#include "Lectura.h"


void Lectura::main(){
    // Aquí va todo, leer y mandar a monitor
    // Directorio donde se encuentran los archivos FITS
    std::string directorio = "./ruta/al/directorio/";

    // Prefijo y extensión de los archivos FITS a buscar
    std::string prefijo = "hola";
    std::string extension = ".fits";

    // Recorrer el directorio en busca de archivos que cumplan con el criterio
    for (const auto& archivo : fs::directory_iterator(directorio)) {
        if (archivo.is_regular_file() && archivo.path().extension() == extension &&
                archivo.path().filename().string().find(prefijo) == 0) {
                cout << archivo.path().string();
                //leerImagen(archivo.path().string());
        }
    }

}

// Con esto asumo que ya todo se pasó bien
Lectura::Lectura(int N, string prefijo){
        this->N = N;
        this->prefijo = prefijo;
        this->names = new string[N];
        this->image_data = new float*[N];
    }

void Lectura::readImage(const std::string& nombreArchivo, int i){
    fitsfile* fptr;
    int status = 0;
    // Abrir el archivo FITS en modo de lectura
    fits_open_file(&fptr, nombreArchivo.c_str(), READONLY, &status);
    if (status != 0) {
        fits_report_error(stderr, status);
        return;
    }
    int bitpix, naxis;
    long naxes[2];

    // Obtener información básica de la imagen FITS
    fits_get_img_param(fptr, 2, &bitpix, &naxis, naxes, &status);
    if (status != 0) {
        fits_report_error(stderr, status); // Imprimir mensaje de error si falla la obtención de parámetros
        exit(EXIT_FAILURE);
    }
    // Verificar que la imagen tenga dos ejes (2D)
    if (naxis != 2) {
        std::cerr << "La imagen FITS no es 2D." << std::endl;
        exit(EXIT_FAILURE);
    }
    // Dimensiones de la imagen (ancho x alto)
    int width = naxes[0];
    int height = naxes[1];
    // Crear un buffer para almacenar la imagen
    float *image_data = new float[width * height];
    long fpixel[2] = {1, 1}; // Coordenadas del primer píxel a leer
    // Leer toda la imagen
    fits_read_pix(fptr, TFLOAT, fpixel, width * height, NULL, image_data, NULL, &status);
    if (status != 0) {
        fits_report_error(stderr, status); // Imprimir mensaje de error si falla la lectura de la imagen
        exit(EXIT_FAILURE);
    }

    // Guardar en la lista
    this->names[i] = nombreArchivo;
    this->sizes[i][0] = width;
    this->sizes[i][1] = height;
    this->image_data[i] = image_data; 

    // Cerrar el archivo FITS
    fits_close_file(fptr, &status);
        

} 

    





