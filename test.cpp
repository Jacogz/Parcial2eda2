#include "Lista.h"
#include "Encriptador.h"
#include <iostream>
#include <unordered_map>
#include <string>


int main(int argc, char* argv[]){
    std::string texto = "In a world driven by rapid technological advancements, communication has become instantaneous, connecting people across continents within seconds. With the proliferation of smartphones and social media platforms, information dissemination has reached unprecedented levels, shaping societal norms and cultural landscapes. However, amidst this digital revolution, concerns regarding privacy, misinformation, and data security have emerged, challenging the ethical and regulatory frameworks governing the digital sphere. As technology continues to evolve, striking a balance between innovation and responsible usage remains paramount, ensuring a future where digital connectivity enriches lives while safeguarding fundamental human rights and values.";

    Encriptador e;

    std::unordered_map<char, std::string>* tabla = new std::unordered_map<char, std::string>;

    std::cout << "Texto a comprimir :   " << texto << "\n" << std::endl;

    std::string encriptado = e.encriptar(&texto, tabla);

    std::cout << "Texto comprimido :    " << encriptado << "\n" << std::endl;

    std::string descifrado = e.descifrar(&encriptado, tabla);
    
    std::cout << "Texto descomprimido :    " << descifrado << "\n" << std::endl;

    return 0;
}