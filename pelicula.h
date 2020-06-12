#include "media.h"
#include <fstream>
#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
using namespace std;

class Pelicula:public Media{
 public:
   Pelicula();
   Pelicula(string,string,string,int);
};
#endif // !PELICULA_H_INCLUDED
