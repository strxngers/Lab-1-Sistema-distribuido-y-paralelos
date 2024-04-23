#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "fitsio.h"

int main(int argc, char const *argv[])
{
    std::cout << "Hola Mundo" << std::endl;
    fitsfile *fptr;               // FITS file pointer
    fitsfile *gptr;               // FITS file pointer for output file
    int status = 0;               // CFITSIO status value MUST be initialized to zero!
    long fpixel = 1;              // first pixel to read/write (assuming a 1D array here)
    double *myimage;              // pointer to array of pixels to read
    long naxes[2] = {1024, 1024}; // dimensions of the image, adjust as necessary

    myimage = new double[naxes[0] * naxes[1]]; // dynamic allocation of image array
    fits_open_file(&fptr, "image_out_inc52.9_PA_226.2.fits", READONLY, &status);
    std::cout << "Status: " << status << std::endl;
    fits_get_img_size(fptr, 2, naxes, &status);
    std::cout << "size = (" << naxes[1] << ", " << naxes[0] << ")" << std::endl;

    fits_read_img(fptr, TDOUBLE, fpixel, naxes[0] * naxes[1], NULL, myimage, NULL, &status);
    std::cout << myimage[1024*512+128] << std::endl;

    // Zero out small values
    for (int i = 0; i < naxes[0] * naxes[1]; i++)
    {
        if (myimage[i] <= 4e-8)
        {
            myimage[i] = 0.0;
        }
    }
    std::cout << "end for" << std::endl;

    // Create a new FITS file and copy the header from the input file
    fits_create_file(&gptr, "image_out_inc52.9_PA_226.2_clipped.fits", &status);
    std::cout << "end fits create file" << std::endl;

    fits_copy_header(fptr, gptr, &status);

    std::cout << "end fits copy header" << std::endl;

    // Write the modified image data to the new FITS file
    fits_write_img(gptr, TDOUBLE, fpixel, naxes[0] * naxes[1], myimage, &status);

    std::cout << "end fits write img" << std::endl;

    fits_close_file(fptr, &status);
    std::cout << "end close fptr" << std::endl;

    fits_close_file(gptr, &status);
    std::cout << "end close gptr" << std::endl;


    delete[] myimage; // free dynamically allocated memory
    std::cout << "end delete myimage" << std::endl;

    return status;
}