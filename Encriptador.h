#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H

#include "Lista.h"
#include <string>
#include <unordered_map>

class Encriptador {
    private:
        void pathFinder(std::string d, Nodo* nodo, std::unordered_map<char, std::string>* tabla);
    public:
        std::string encriptar(std::string* texto, std::unordered_map<char, std::string>* codigos);
        std::string descifrar(std::string* texto, std::unordered_map<char, std::string>* codigos);
};

#endif