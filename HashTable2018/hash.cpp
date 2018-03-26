//
// Created by Samuel Borjas on 25/3/2018.
//

#include "hash.h"

hash::hash(){
    for(int i=0;i<tableSize;i++){
        TablaHash[i] = new registro;
        TablaHash[i]->nombre = "empty";
        TablaHash[i]->apellido = "empty";
        TablaHash[i]->sig = NULL;

    }
}

int hash::tablaHash(std::string key) {
    int hash = 0;
    int index;

    for(int i=0; i<key.length();i++){
        hash = hash + (int)key[i];
        //std::cout<<"ValoresHash = " <<hash << std::endl;
    }


    index = hash % tableSize;
    return index;
}

void hash::IngresarDato(std::string nombre, std::string apellido) {
    int index = tablaHash(nombre);

    if(TablaHash[index]->nombre =="empty"){
        TablaHash[index]->nombre = nombre;
        TablaHash[index]->apellido = apellido;

    }else{
        registro * ptr = TablaHash[index];
        registro *nuevo = new registro;
        nuevo->nombre = nombre;
        nuevo->apellido = apellido;
        nuevo->sig = NULL;
        while(ptr->sig !=NULL ){
            ptr = ptr->sig;
        }
        ptr->sig = nuevo;

    }
}

int hash::cantRegistrosenIndice(int index) {
    int contador=0;
    if(TablaHash[index]->nombre == "empty"){
        return contador;
    }else{
        contador++;
        registro *ptr = TablaHash[index];
        while(ptr->sig != NULL){
            contador++;
            ptr = ptr->sig;
        }
    }
    return contador;
}

void hash::imprimirTablaHash() {
    int n;
    for(int i=0;i<tableSize; i++){
        n = cantRegistrosenIndice(i);
        std::cout<< "====================\n";
        std::cout<<"Indice= "<<i<<std::endl;
        std::cout<< TablaHash[i]->nombre<<std::endl;
        std::cout<< TablaHash[i]->apellido<<std::endl;
        std::cout<<" # de Registros = " << n << std::endl;
        std::cout<< "====================\n";
    }
}

void hash::imprimirRegistroporIndice(int index) {
    registro * ptr =  TablaHash[index];
    if(ptr->nombre == "empty"){
        std::cout<<"No hay nada para mostrar"<<std::endl;
    }else{
        std::cout<< "El indice "<<index << " contiene estos registros" <<std::endl;
        while(ptr->sig !=NULL){
            std::cout<< "================\n";
            std::cout<<ptr->nombre <<std::endl;
            std::cout<<ptr->apellido <<std::endl;
            std::cout<< "================\n";
            ptr = ptr->sig;

        }
    }
}

void hash::buscarRegistro(std::string nombre) {
    int index = tablaHash(nombre);
    bool encontrado = false;
    std::string apellido;

    registro *ptr = TablaHash[index];
    while(ptr != NULL){
        if(ptr->nombre == nombre){
            encontrado = true;
            apellido = ptr->apellido;
        }
        ptr = ptr->sig;
    }

    if(encontrado == true){
        std::cout<<" REGISTRO ENCONTRADO\n";
        std::cout<< nombre << " "<< apellido << std::endl;
    }else{
        std::cout<< "Valor no encontrado "<<std::endl;
    }
}
