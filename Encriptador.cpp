#include "Encriptador.h"

void Encriptador::pathFinder(std::string d, Nodo* nodo, std::unordered_map<char, std::string>* tabla){
    char _c = nodo->c;
    if(_c != '\0'){
        (*tabla)[_c] = d;
    }else{
        if(nodo->izquierdo != nullptr){
            pathFinder(d + "0", nodo->izquierdo, tabla);
        }
        if(nodo->derecho != nullptr){
            pathFinder(d + "1", nodo->derecho, tabla);
        }
    }
}

std::string Encriptador::encriptar(std::string* texto, std::unordered_map<char, std::string>* codigos){
    Lista* lista = new Lista();
    for(char c : *texto){
        Nodo* nodo = lista->contiene(c);
        if(nodo != nullptr){
            nodo->frecuencia++;
        }else{
            lista->agregar(new Nodo(c, 1));
        }
    }
    lista->mergeSort();
    lista->convertirAHuffman();

    pathFinder("", lista->cabeza, codigos);

    std::string comprimido = "";

    for(char c : *texto){
        comprimido += codigos->at(c);
    }

    return comprimido;
}

std::string Encriptador::descifrar(std::string* texto, std::unordered_map<char, std::string>* codigos){
    std::string descifrado = "";

    std::string codigo = "";

    for(char c : *texto){
        codigo += c;
        for(std::pair<char, std::string> par : *codigos){
            if(par.second == codigo){
                descifrado += par.first;
                codigo = "";
                break;
            }
        }
    }
    
    return descifrado;
}