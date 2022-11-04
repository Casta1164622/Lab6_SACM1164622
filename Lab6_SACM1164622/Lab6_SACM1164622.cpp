#include <iostream>
#include "Lista.h"
#include "pokemon.h"
#include "sort.h"
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

// C:\Users\CASTA\Downloads\pokemons.csv
using namespace std;

Lista<pokemon> listaPokemons;

void menuPrincipal();


bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main()
{
    menuPrincipal();
}
    
void leerLista() 
{
    ifstream archivo;
    string linea;
    string posarchiv;
    const char* ptr;


    system("cls");
    cout << "Ingrese la ubicacion del archivo" << endl;
    getline(cin, posarchiv);
    if (posarchiv == "")
    {
        cout << "No ingreso correctamente la posicion del archivo que quiere leer, vuelva a intentarlo \n" << endl;
    }
    else {
        listaPokemons.Clear();
        ifstream archivo(posarchiv);
        string linea;
        char delimitador = ',';
        getline(archivo, linea);
        while (getline(archivo, linea))
        {
            string nombre = "";
            string generacion = "";
            string nationalNumber = "";

            int turn = 0;
            for (int i = 0; i < linea.size(); i++) 
            {
                if (linea[i] == delimitador) 
                {
                    turn++;
                }
                if (turn == 0 && linea[i] != delimitador)
                {
                    nationalNumber += linea[i];
                }
                if (turn == 1 && linea[i] != delimitador)
                {
                    nombre += linea[i];
                }
                if (turn == 2 && linea[i] != delimitador)
                {
                    generacion += linea[i];
                }
            }

            listaPokemons.Add(pokemon(nombre, stoi(generacion), stoi(nationalNumber)));
        }
    }
        cout << "----------------------------------" << endl;
        archivo.close();
}

void menuListaGuardada() 
{
    system("cls");

    string selection;
    int select;
    sort sort;

    if (listaPokemons.GetCount() > 0) 
    {
        int number;
        string display;
        pokemon lookAtPokemon;
        cout << "Lista actual\n";
        cout << "----------------------------------------\n";
        cout << "Nombre | Numero nacional | Generacion\n";
        for (int i = 0; i < listaPokemons.GetCount(); i++) 
        {
            number = i + 1;
            display = to_string(number);
            lookAtPokemon = listaPokemons.GetItem(i)->data;
            cout << display + "| " + lookAtPokemon.GetNombre() + " | " + std::to_string(lookAtPokemon.getNationalNumber()) +" | "+ std::to_string(lookAtPokemon.getGeneracion()) + "\n";
        }
    }
    else 
    {
        cout << "----------------------------------------\n";
        "Aun no hay pokemones en esta lista\n";
        cout << "----------------------------------------\n";
    }

    do
    {
        cout << "Seleccione una opcion\n";
        cout << "1| Ordenar por Generacion (Select sort)\n";
        cout << "2| Ordenar por Generacion (Quick sort)\n";
        cout << "3| Ordenar por Generacion (Shell sort)\n";
        cout << "4| Ordenar por Numero nacional (Select sort)\n";
        cout << "5| Ordenar por Numero nacional (Quick sort)\n";
        cout << "6| Ordenar por Numero nacional (Shell sort)\n";

        cout << "0| regresar\n";

        getline(cin, selection);

        if (is_number(selection))
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

        if (selection == "")
        {
            select = 10;
        }

        switch (select)
        {
        case 1:
            sort.selectSortGen(listaPokemons);
            menuListaGuardada();
            break;
        case 2:
            sort.quicksortGen(listaPokemons , 0 , listaPokemons.GetCount()-1);
            menuListaGuardada();
            break;
        case 3:
            sort.ShellSortGen(listaPokemons);
            menuListaGuardada();
            break;
        case 4:
            sort.selectSortNN(listaPokemons);
            menuListaGuardada();
            break;
        case 5:
            sort.quicksortNN(listaPokemons, 0, listaPokemons.GetCount()-1);
            menuListaGuardada();
            break;
        case 6:
            sort.ShellSortNN(listaPokemons);
            menuListaGuardada();
            break;
        case 0:
            menuPrincipal();
            return;
        default:
            menuListaGuardada();
        }
    } while (select != 0);

}

void menuPrincipal()
{
    string selection;
    int select;

    do
    {
        system("cls");
        cout << "Pokedex\n";
        cout << "Seleccione una opcion\n";
        cout << "1| Mostrar lista de pokemones\n";
        cout << "2| Cargar lista\n";
        cout << "0| Salir del programa\n";

        getline(cin, selection);

        if (is_number(selection))
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

        if (selection == "")
        {
            select = 10;
        }

        switch (select)
        {
        case 1:
            menuListaGuardada();
            break;
        case 2:
            leerLista();
            break;
        case 0:
            exit(0);
            return;
        default:
            menuPrincipal();
        }
    } while(select != 0);
}