Main: Main.cc Escritura.o Normalizacion.o FiltroRuido.o FiltroResolucion.o Lectura.o Almacenamiento.o
	u++ Main.cc Escritura.o Normalizacion.o FiltroRuido.o FiltroResolucion.o Lectura.o Almacenamiento.o -lcfitsio -o pipeline

Escritura.o: Escritura.cc Escritura.h Almacenamiento.o
	u++ -c Escritura.cc Almacenamiento.o -lcfitsio

Normalizacion.o: Normalizacion.cc Normalizacion.h Almacenamiento.o
	u++ -c Normalizacion.cc Almacenamiento.o -lcfitsio

FiltroRuido.o: FiltroRuido.cc FiltroRuido.h Almacenamiento.o
	u++ -c FiltroRuido.cc Almacenamiento.o -lcfitsio

FiltroResolucion.o: FiltroResolucion.cc FiltroResolucion.h Almacenamiento.o
	u++ -c FiltroResolucion.cc Almacenamiento.o -lcfitsio

Lectura.o: Lectura.cc Lectura.h Almacenamiento.o
	u++ -c Lectura.cc Almacenamiento.o -lcfitsio

Almacenamiento.o: Almacenamiento.cc Almacenamiento.h
	u++ -c Almacenamiento.cc -lcfitsio

clean:
	rm -f *.o pipeline