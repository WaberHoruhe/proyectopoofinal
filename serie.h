#include "media.h"
#include <fstream>
#ifndef SERIE_H_INCLUDED
#define SERIE_H_INCLUDED
using namespace std;

class Serie:public Media{
  public:
    
    Serie();
    Serie(string,string,string,int,int,string);
    int getEpisodio();
    void setEpisodio(int);
    string getTitulo();
    void setTitulo(string);
  private:
    int episodio;
    string titulo;
};
#endif // !SERIE_H_INCLUDED
