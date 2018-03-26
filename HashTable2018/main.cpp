#include <iostream>
#include <cstdlib>
#include <string>
#include "hash.h"


int main() {
    hash ObjetoHash;
    std::string nombre;
    //ObjetoHash.imprimirTablaHash();


    //Ingreso de valores en tabla hash

    ObjetoHash.IngresarDato("Samuel","Borjas");
    ObjetoHash.IngresarDato("Andres","Martinez");
    ObjetoHash.IngresarDato("Carlos","Gutierrez");
    ObjetoHash.IngresarDato("Juan","Roberto");
    ObjetoHash.IngresarDato("Jose","David");
    ObjetoHash.IngresarDato("Jonas","Artica");
    ObjetoHash.IngresarDato("Alexis","Romero");


    //ObjetoHash.imprimirTablaHash();
    //ObjetoHash.imprimirRegistroporIndice(0);

    //=====BUSQUEDA DE REGISTRO==============
    while(nombre != "salir"){
        std::cout<<"Ingresar nombre a buscar\n";
        std::cin>>nombre;
        if(nombre != "salir")
            ObjetoHash.buscarRegistro(nombre);
    }


    return 0;
}