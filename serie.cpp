#include "serie.h"

Serie::Serie(){}
Serie::Serie(string unId,string unNombre,string unGenero,int unaDuracion,int unEpisodio, string unTitulo):Media(unId,unNombre,unGenero,unaDuracion){
  episodio = unEpisodio;
  titulo = unTitulo;
}

int Serie::getEpisodio(){return episodio;}
void Serie::setEpisodio(int fixEpisodio){
  episodio = fixEpisodio;
}
string Serie::getTitulo(){return titulo;}
void Serie::setTitulo(string fixTitulo){
  titulo = fixTitulo;
}
