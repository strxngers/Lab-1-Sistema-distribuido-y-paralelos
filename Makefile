all: Main FiltroReslucion Lectura Almacenamiento

Main: Main.cc FiltroReslucion.o Lectura.o Almacenamiento.o
	u++ -o Main.cc FiltroReslucion.o Lectura.o Almacenamiento.o

FiltroReslucion: FiltroReslucion.cc FiltroReslucion.h Almacenamiento.o
	u++ -c FiltroReslucion.cc Almacenamiento.o

Lectura: Lectura.cc Lectura.h Almacenamiento.o
	u++ -c Lectura.cc Almacenamiento.o

Almacenamiento.o: Almacenamiento.cc Almacenamiento.h
	u++ -c Almacenamiento.cc

clean: 
	rm -f *.o