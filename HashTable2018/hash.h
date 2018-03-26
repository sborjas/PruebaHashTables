//
// Created by Samuel Borjas on 25/3/2018.
//

#include <iostream>
#include <cstdlib>
#include <string>



#ifndef HASHTABLE2018_HASH_H
#define HASHTABLE2018_HASH_H

class hash{
private:
    static const int tableSize = 10;
    struct registro{
        std::string nombre;
        std::string apellido;
        registro *sig;
    };

    registro *TablaHash[tableSize];



public :
    hash();
    int tablaHash(std::string key);
    void IngresarDato(std::string nombre, std::string apellido);
    int cantRegistrosenIndice(int index);
    void imprimirTablaHash();
    void imprimirRegistroporIndice(int index);
    void buscarRegistro(std::string nombre);

};

#endif //HASHTABLE2018_HASH_H
