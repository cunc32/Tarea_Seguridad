#include <iostream>
#include <string>

std::string cifradoEspartano (const std::string& mensaje, int lados, int columnas);
std::string descifradoEspartano(const std::string& cifrado, int lados, int columnas);

std::string cifradoCesar(const std::string& mensaje, int desplazamiento);
std::string descifradoCesar(const std::string& mensaje, int desplazamiento);

std::string cifradoVigenere(const std::string& mensaje, const std::string& clave);
std::string descifradoVigenere(const std::string& cifrado, const std::string& clave);


int main(int argc, const char* argv[]) {
    std::cout << "Cifrado Espartano\n\n"
    
    std::string mi_mensaje = cifradoEspartano("Hola que tal", 6, 5);

    std::cout << mi_mensaje << "\n";

    mi_mensaje = descifradoEspartano(mi_mensaje, 6, 5);

    std::cout << mi_mensaje << "\nCifrado Cesar\n\n";

    std::string mi_mensaje = cifradoCesar("Hola que tal", 1);

    std::cout << mi_mensaje << "\n";

    mi_mensaje = descifradoCesar(mi_mensaje, 1);

    std::cout << mi_mensaje << "\n";

    std::cout << mi_mensaje << "\nCifrado Vigenere\n\n";

    std::string mensaje = "Hello World!";
    std::string clave = "key";
    
    std::string cifrado = cifradoVigenere(mensaje, clave);
    std::cout << "Mensaje cifrado: " << cifrado << std::endl;
    
    std::string mensaje_descifrado = descifradoVigenere(cifrado, clave);
    std::cout << "Mensaje descifrado: " << mensaje_descifrado << std::endl;
}

std::string cifradoEspartano (const std::string& mensaje, int lados, int columnas) {
    std::string cifrado = "";
    for (int i = 0; i <= lados; i++) {
        for (int j = 0; j <= columnas; j++) {
            std::cout << "Posicion en curso: " << j * columnas + i;
            if (j * columnas + i < mensaje.length()) {
                cifrado += mensaje[j * columnas + i];
                std::cout << " Ingresando letra: " << mensaje[j * columnas + i];
            } else {
                cifrado += " ";
                std::cout << " Ingresando espacio";
            }
            
            std::cout << "\n";
        }
    }
    return cifrado;
}

std::string descifradoEspartano(const std::string& cifrado, int lados, int columnas) {
    std::string mensaje = "";
    int longitud = cifrado.length();
    
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < lados; j++) {
            std::cout << "Revisando la fila: " << lados * j + i << "\n";
            mensaje += cifrado[lados * j + i];
        }
    }
    
    return mensaje;
}

std::string cifradoCesar(const std::string& mensaje, int desplazamiento) {
    std::string temporal = "";
    for (int i = 0; i < mensaje.length(); i++) {
        temporal += tolower(mensaje[i]);
    }
    std::string cifrado = "";
    std::cout << temporal;
    for (int i = 0; i < mensaje.length(); i++) {
        if (temporal[i] < 123 && temporal[i] > 96) {
            if (temporal[i] + desplazamiento > 122) {
                std::cout << "Letra nueva: " << (char)(mensaje[i] + desplazamiento - 26) << " Letra actual: " << mensaje[i];
                cifrado += mensaje[i] + desplazamiento - 26;
            }
            else {
                std::cout << "Letra nueva: " << (char)(mensaje[i] + desplazamiento) << " Letra actual: " << mensaje[i];
                cifrado += mensaje[i] + desplazamiento;
            }
        }
        else {
            cifrado += mensaje[i];
        }

        std::cout << "\n";
    }
    return cifrado;
}

std::string descifradoCesar(const std::string& mensaje, int desplazamiento) {
    std::string temporal = "";
    for (int i = 0; i < mensaje.length(); i++) {
        temporal += tolower(mensaje[i]);
    }
    std::string cifrado = "";
    std::cout << temporal;
    for (int i = 0; i < mensaje.length(); i++) {
        if (temporal[i] < 123 && temporal[i] > 96) {
            if (temporal[i] + desplazamiento < 97) {
                std::cout << "Letra nueva: " << (char)(mensaje[i] - desplazamiento + 26) << " Letra actual: " << mensaje[i];
                cifrado += mensaje[i] - desplazamiento + 26;
            }
            else {
                std::cout << "Letra nueva: " << (char)(mensaje[i] - desplazamiento) << " Letra actual: " << mensaje[i];
                cifrado += mensaje[i] - desplazamiento;
            }
        }
        else {
            cifrado += mensaje[i];
        }

        std::cout << "\n";
    }
    return cifrado;
}

std::string cifradoVigenere(const std::string& mensaje, const std::string& clave) {
    std::string cifrado = "";
    int mensajeLength = mensaje.length();
    int claveLength = clave.length();
    
    for (int i = 0; i < mensajeLength; ++i) {
        char letra = mensaje[i];
        char claveChar = clave[i % claveLength];
        char cifradoChar;
        
        if (isalpha(letra)) {
            int offset = isupper(letra) ? 'A' : 'a';
            cifradoChar = ((letra + claveChar - 2 * offset) % 26) + offset;
        } else {
            cifradoChar = letra;
        }
        
        cifrado += cifradoChar;
    }
    
    return cifrado;
}

std::string descifradoVigenere(const std::string& cifrado, const std::string& clave) {
    std::string mensaje = "";
    int cifradoLength = cifrado.length();
    int claveLength = clave.length();
    
    for (int i = 0; i < cifradoLength; ++i) {
        char letra = cifrado[i];
        char claveChar = clave[i % claveLength];
        char descifradoChar;
        
        if (isalpha(letra)) {
            int offset = isupper(letra) ? 'A' : 'a';
            descifradoChar = ((letra - claveChar + 26) % 26) + offset;
        } else {
            descifradoChar = letra;
        }
        
        mensaje += descifradoChar;
    }
    
    return mensaje;
}