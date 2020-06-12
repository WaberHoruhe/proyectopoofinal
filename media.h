#include <string>
#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED
using namespace std;

class Media {
 public:
    Media();
    Media(string,string,string,int);
    string getID();
    string getNombre();
    string getGenero();
    int getDuracion();
    int getCalificacion();


    void setID(string);
    void setNombre(string);
    void setGenero(string);
    void setDuracion(int);
    void setCalificacion(int);
 private:
   string id, nombre, genero;
   int duracion, calificacion;
};
#endif // !MEDIA_H_INCLUDED
