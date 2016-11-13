/* -------------------------------
 * Proyecto final 2016
 * Estructura de Datos
 * @Autor = Isocrates De La Cruz
 * @Matricula = 2014-2287
 --------------------------------- */

#include <iostream>
#include <stdlib.h>
#include <array>

using namespace std;

char origen[999][999];
char destinacion[999][999];

/*
 * Clase Aerolinea
 * Esta clase es el baseline
 */
class Aerolinea{
    /*
     * Variables
     * Variables que usaremos mas adelante
     */
    public:
        int resp;
        char destinos[999][999];
        char rutas[999][999];
        int count = 0;
        bool pl = true;

    /*
     * Constructor de la clase
     * Obligatorio para empezar a correr el programa
     * No contiene parametros
     */
    public:Aerolinea(){
        Menu();
    }

    /*
     * Metodo Menu
     * Este es el menu que muestra el programa
     * No contiene parametros
     */
    public:void Menu(){
        system("cls");
        cout << "\t" << "-------- Aerolinea ITLA --------" << endl << endl;
        cout << "\t" << "1. Introducir Destino" << endl;
        cout << "\t" << "2. Introducir Ruta" << endl;
        cout << "\t" << "3. Buscar Ruta" << endl << endl;

        cout << "\t" << "Elige una opcion: ";
        cin >> resp;

        switch (resp){
            case 1:
                IntroducirDestino();
                break;
            case 2:
                IntroducirRuta();
                break;
            case 3:
                BuscarRuta();
            default:
                system("cls");
                cout << "\t" << "Error al seleccionar una opcion!" << endl;
        }
    }

    /*
     * Metodo para Introducir los Destinos
     * Aqui los destinos se guardaran en la variable: destinos
     * No contiene paramentros
     */
    public:void IntroducirDestino(){
        do{
            system("cls");
            cout << "-------- Introduciendo Destinos ----------" << endl;
            cout << "\n" << "Introduce el nombre del destino: ";
            cin >> destinos[count];

            cout << "\n\n" << "1. Agregar otro destino";
            cout << "\n" << "2. Volver al menu principal";

            cout << "\n\n" << "Elige una opcion: ";
            cin >> resp;
            count++;

            switch (resp){
                case 1:
                    pl = true;
                    continue;
                case 2:
                    pl = false;
                    break;
            }
        }while(pl!=false);
        Menu();

    }

    /*
     * Metodo para introducir las rutas
     * Aqui se crearan las rutas y se guardaran en la variable: rutas
     * No contiene parametros
     */
    public:void IntroducirRuta(){
        system("cls");
        int c = 0;
        int p = 0;
        cout << "\t" << "----- Rutas ------";
        for(int a = 0; a < count; a++){
            cout << "\n" << c <<") " << destinos[a];
            c++;
        }
        void Origen(){

        }
        void Destinacion(){

        }

    }

    /*
     * Metodo para buscar las rutas
     * Aqui se mostraran las rutas que queramos buscar
     * No contiene parametros
     */
    public:void BuscarRuta(){

    }
};

/*
 * Metodo main
 * Aqui empieza el programa
 */
int main(){
    Aerolinea aerolinea;
}

