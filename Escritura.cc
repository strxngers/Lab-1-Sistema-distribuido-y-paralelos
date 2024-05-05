#include "Escritura.h"

void Escritura::main() {
    // Ciclo que recorre todas las imágenes, escribe la imagen en un archivo FITS 
    for (int i = 0; i < N; i++) {
        // Obtener datos de la imagen normalizada
        double* image_data = almacenamiento.getImageData();
        // width y height de la imagen
        int width = almacenamiento.getWidth();
        int height = almacenamiento.getHeight();
        // crear el nombre de la nueva imagen a partir del prefijo de salida y el contador i + 1
        string name = "!" + prefijoSalida + to_string(i + 1) + ".fits";
        cout << "Escribiendo " << name << "..." << endl;
        // Escribir la imagen en un archivo FITS
        writeImage(name, image_data, width, height);
        cout << "Imagen Out " << i + 1 << " escrita" << endl;
    }
    flagEnd = true;
}


Escritura::Escritura(int N, string prefijoSalida, Almacenamiento &almacenamiento) : almacenamiento(almacenamiento) {
    this->N = N;
    this->prefijoSalida = prefijoSalida;
    flagEnd = false;
}

void Escritura::writeImage(string nombreNuevoArchivo, double* imagenAGuardar, int width, int height) {
    fitsfile *fptr;
    int status = 0;

    if (fits_create_file(&fptr, nombreNuevoArchivo.c_str(), &status)) {
        fits_report_error(stderr, status);
        exit(status);
    }

    // Escribir la imagen en el archivo FITS
    long naxis = 2;
    long naxes[2] = {width, height}; // Acceder a ancho y alto de la clase
    if (fits_create_img(fptr, DOUBLE_IMG, naxis, naxes, &status)) {
        fits_report_error(stderr, status);
        exit(status);
    }

    long fpixel = 1;
    long nelements = naxes[0] * naxes[1];
    if (fits_write_img(fptr, TDOUBLE, fpixel, nelements, imagenAGuardar, &status)) {
        fits_report_error(stderr, status);
        exit(status);
    }
    /*
    // Copiar el header del archivo original al archivo de salida
    fitsfile *gptr;
    fits_open_file(&gptr, this->nombreArchivoOriginal.c_str(), READONLY, &status); // Acceder a nombreArchivoOriginal de la clase
    fits_copy_header(fptr, gptr, &status);
    fits_close_file(gptr, &status);
    */
    fits_close_file(fptr, &status);
}

bool Escritura::tareaHaTerminado() {
    return flagEnd;
}
