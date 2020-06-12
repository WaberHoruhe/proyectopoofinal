#include "media.h"

using namespace std;
Media::Media(){}
Media::Media(string fixID, string fixNombre, string fixGenero, int fixDuracion){
  id = fixID;
  nombre = fixNombre;
  genero = fixGenero;
  duracion = fixDuracion;
}
string Media::getID(){return id;}
string Media::getNombre(){return nombre;}
string Media::getGenero(){return genero;}
int Media::getDuracion(){return duracion;}
int Media::getCalificacion(){return calificacion;}

void Media::setID(string fixID){id = fixID;}
void Media::setNombre(string fixNombre){nombre = fixNombre;}
void Media::setGenero(string fixGenero){genero = fixGenero;}
void Media::setDuracion(int fixDuracion){duracion = fixDuracion;}
void Media::setCalificacion(int fixCalificacion){calificacion = fixCalificacion;}
