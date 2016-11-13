/* ---------------
 * Final Project Year 2016
 * @Subject: Data Structure
 * @Author: Isocrates De La Cruz
 * @Enrollment: 2014-2287
 * ---------------- */
#include <iostream>
#include <stdlib.h>

using namespace std;

/* ----------------
 * Global Variables
 * More easier to assign a value
 ------------------ */
int resp;


/* --------------
 * Class Program
  --------------- */
class Program{

    /* -------------------
     * Class Constructor
     * Is Obligatory to Start the Program
     * Take 0 Param
     --------------------- */
    public:Program(){
        Menu();
    }

    /* -------------------
     * Menu method
     * This is the menu that show the program
     * This menu takes 0 params
     --------------------- */
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
};




int main() {
    Program program;
}