#include <iostream>
#include <fstream>
#include "serie.h"
#include <vector>
#include "pelicula.h"
#include "serie.h"
#include <string>
#include <iomanip>
#include <regex>


using namespace std;

int menu(){
    int index = 1;
    cout << "Bienvenido al sistema de clasificacion" << endl;

    vector <Serie> listaSeries;
    vector <Pelicula> listaPeliculas;
    ifstream datosStream;
    string payload, str;
    regex ws_re(",");
    int p;
while(index != 0){
    cout << "Por favor seleccione una de las siguientes opciones" << endl;
    cout << "1) Cargar archivo de datos\n" << "2) Mostrar los videos en general con una cierta calificación o de un cierto género" << endl;
    cout << "3) Mostrar los episodios de una determinada serie con una calificacion determinada\n" << "4) Mostrar las películas con cierta calificación" << endl;
    cout << "5) Calificar un video\n" << "0) Salir" << endl;
    cin >> index;
    if (index == 1){
      cout << "---------------------------------------------" << endl << endl;
      cout << "Introduce el nombre de tu archivo con su terminacion correcta\n";
      cout << "Ejemplo: 'archivo1.txt'" << endl;
      cin >> payload;

      datosStream.open(payload,ios::in);
      cout << "Archivo " << payload << " cargado con exito!" << endl;
      cout << "---------------------------------------------" << endl << endl;

      if (datosStream.fail()){
          cout << "Error al cargar el archivo" << endl;
          cout << "---------------------------------------------" << endl << endl;
        }
      while(getline(datosStream, str)){
        vector<string> listaSeparacion{
        sregex_token_iterator(str.begin(), str.end(), ws_re, -1), {}};
        if(listaSeparacion[0] == "c"){
          Serie serieCreada(listaSeparacion[1],listaSeparacion[2],listaSeparacion[4],stoi(listaSeparacion[3]),stoi(listaSeparacion[6]), listaSeparacion[5]);
          listaSeries.push_back(serieCreada);

        }else if(listaSeparacion[0] == "p"){
          Pelicula peliculaCreada(listaSeparacion[1],listaSeparacion[2],listaSeparacion[4],stoi(listaSeparacion[3]));
          listaPeliculas.push_back(peliculaCreada);
        }
        }

      }else if(index == 2){ // TERMINAAAAAAAAAAAAAAAAAAAAAAAAAR
        //2) Mostrar los videos en general con una cierta calificación o de un cierto género
        cout << "---------------------------------------------" << endl << endl;
        string filtroMetodo, filtroGenero;
        cout << "Ingrese si quiere buscar a base del genero o de su califacion (g / c)\n";
        cin >> filtroMetodo;


        if (filtroMetodo == "g"){
          cout << "Ingrese el genero que desea buscar" << endl;
          cin >> filtroGenero;
          cout << "Desplegando series con ese genero: " << endl;
          cout << "---------------------------------------------" << endl << endl;

          cout << "Serie" << "                       " << "Capitulo" << "                       " << "ID\n";
            for(int methodCheckerSeries = 0; methodCheckerSeries < listaSeries.size(); methodCheckerSeries++){
              if (listaSeries[methodCheckerSeries].getGenero() == filtroGenero){
                cout << listaSeries[methodCheckerSeries].getTitulo() << "     ";
                cout << listaSeries[methodCheckerSeries].getNombre() << "     ";
                cout << listaSeries[methodCheckerSeries].getID() <<endl << endl;
              }
            }
            cout << "Desplegando peliculas con ese genero: " << endl;
            cout << "---------------------------------------------" << endl << endl;
            cout << "Pelicula" << "                    " << "ID" << endl;

            int counterFiltro = 0;

            for(int j=0; j < filtroGenero.size(); j++){
              int temp = filtroGenero[j];
              counterFiltro += temp;}

            for(int methodCheckerPeliculas = 0; methodCheckerPeliculas < listaPeliculas.size(); methodCheckerPeliculas++){

              int counterGenero = 0;
              string tempo = listaPeliculas[methodCheckerPeliculas].getGenero();
              for(int counterstrike=0; counterstrike < tempo.size(); counterstrike++){
                int tempCount = tempo[counterstrike];
                counterGenero += tempCount;}

                cout << counterGenero << " " << counterFiltro << endl;
              if (counterFiltro == counterGenero){
                cout << listaPeliculas[methodCheckerPeliculas].getNombre() << "     ";
                cout << listaPeliculas[methodCheckerPeliculas].getID() << "     " << endl;
              }
            }

            cout << "---------------------------------------------" << endl << endl;
          }else  if (filtroMetodo == "c"){
            cout << "Ingrese la calificacion minima que desea buscar" << endl;
          }else {
            cout << "Seleccione una opcion valida" << endl;
            cout << "---------------------------------------------" << endl << endl;
          }
    }else if(index == 3){
          //REPARAR LOOP
          string serieNombre;
          int calificacionSerie;
          cout << "---------------------------------------------" << endl << endl;
          cout << "Ingrese el nombre de la serie" << endl;
          cin >> serieNombre;
          cout << "Ingrese la calificacion para la busqueda" << endl;
          cin >> calificacionSerie;

          for(int comboChecker = 0; comboChecker < listaSeries.size();comboChecker++){
            if (serieNombre == listaSeries[comboChecker].getTitulo() && calificacionSerie >= listaSeries[comboChecker].getCalificacion()){
              cout << listaSeries[comboChecker].getEpisodio() << "     ";
              cout << listaSeries [comboChecker].getCalificacion() << endl;
            }
          }
      }else if(index == 4){
        int calificacionPeli;
        cout << "---------------------------------------------" << endl << endl;
        cout << "Ingresa la calificacion con la que quieres buscar" << endl;
        cin >> calificacionPeli;
        if(calificacionPeli < 6 && calificacionPeli > 0){
        cout << "---------------------------------------------" << endl << endl;
        cout << "Nombre" << "         " << "Rating" << endl;
        for (int peliCalifChecker = 0; peliCalifChecker < listaPeliculas.size(); peliCalifChecker++){
          if(calificacionPeli < listaPeliculas[peliCalifChecker].getCalificacion()){
            cout << listaPeliculas[peliCalifChecker].getNombre() << "     ";
            cout << listaPeliculas[peliCalifChecker].getCalificacion() << endl;
          }
        }
        cout << "---------------------------------------------" << endl << endl;
      }else{
        cout << "El valor tiene que ser entre 1 y 5" << endl;
        cout << "---------------------------------------------" << endl << endl;

      }
    }else if(index == 5){ //IMPRIME EL ERROR PERO NO TIENE ERROR
        string selectTipo, selectID;
        int rating;
        int contador = 0;

      cout << "---------------------------------------------" << endl << endl;

      if(listaSeries.size() > 0 || listaPeliculas.size() > 0){
        cout << "Calificar serie o pelicula (s / p)" << endl;
        cin >> selectTipo;

       if (selectTipo == "s"){
         cout << "Ingresa el ID de la serie a calificar" << endl;
         for(int f = 0; f < listaSeries.size();f++){
           cout << listaSeries[f].getTitulo();
           cout << "   " << listaSeries[f].getID() << endl;
            }
            cin >> selectID;



            for (p = 0; p < listaSeries.size();p++){
              if (listaSeries[p].getID() == selectID){
                cout << "Ingrese su calificacion del 1 al 5" << endl;
                cin >> rating;
                if (rating < 6 && rating > 0){
                listaSeries[p].setCalificacion(rating);
                cout << "Calificacion de: " << listaSeries[p].getCalificacion() <<" guardada con exito" << endl;
                }else{
                  cout << "El valor tiene que ser entre 1 y 5" << endl;
                  cout << "---------------------------------------------" << endl << endl;
                }
              }else if(listaSeries[p].getID() != selectID && contador !=1){
                cout << "ID erroneo o inexistente, revisa tu sintaxis" << endl;
                cout << "---------------------------------------------" << endl << endl;
                contador++;
              }
        }
      }else if (selectTipo == "p"){
        cout << "Ingresa el ID de la pelicula a calificar" << endl;
        for(int f = 0; f < listaPeliculas.size();f++){
          cout << listaPeliculas[f].getNombre();
          cout << "   " << listaPeliculas[f].getID() << endl;
           }
           cin >> selectID;



           for (p = 0; p < listaPeliculas.size();p++){
             if (listaPeliculas[p].getID() == selectID){
               cout << "Ingrese su calificacion del 1 al 5" << endl;
               cin >> rating;
               listaPeliculas[p].setCalificacion(rating);
               cout << "Calificacion de: " << listaPeliculas[p].getCalificacion() <<" guardada con exito" << endl;
               contador++;
             }else if(listaPeliculas[p].getID() != selectID && contador !=1){
               cout << "ID erroneo o inexistente, revisa tu sintaxis" << endl;
               cout << "---------------------------------------------" << endl << endl;
               contador++;

             }
       }
     }else{
       cout << "Ingrese un comando valido" << endl;
       cout << "---------------------------------------------" << endl << endl;

     }

      }else{
        cout << "Debes cargar el archivo primero" << endl;
        cout << "---------------------------------------------" << endl << endl;
      }
     }else if(index == 0){
        return 0;
      }else{
        cout << "Seleccione una opcion valida" << endl;
        cout << "---------------------------------------------" << endl << endl;
      }

    };
    return 0;
  };
int main (){
    menu();

    return 0;
};
