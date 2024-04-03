#include "Lista.h"
#include "Encriptador.h"
#include <iostream>
#include <unordered_map>
#include <string>


int main(int argc, char* argv[]){
    std::string texto = "HóoLÄ mV,n.do!¡";

    Encriptador e;

    std::unordered_map<char, std::string>* tabla = new std::unordered_map<char, std::string>;

    std::cout << "Texto a comprimir :   " << texto << "\n" << std::endl;

    std::string encriptado = e.encriptar(&texto, tabla);

    std::cout << "Texto comprimido :    " << encriptado << "\n" << std::endl;

    std::string descifrado = e.descifrar(&encriptado, tabla);
    
    std::cout << "Texto descomprimido :    " << descifrado << "\n" << std::endl;

    return 0;
}