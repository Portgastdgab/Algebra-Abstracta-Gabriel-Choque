#include "Cifrado_Descifrado.h"

int module(int a, int n) {
    int r = a - n * (a / n);
    r = r + (r < 0) * n;
    return r;
}

string fileOpen(string file){
    ifstream archivo(file.c_str());
    string linea;
    string text;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
        text = text + linea;
    }
    return text;
}

void Cesar::Cypher(string &mensaje, int clave) {
    for (int i = 0; i < mensaje.size(); ++i) {
        palabra.push_back(alfabeto[module(((alfabeto.find(mensaje[i])) + clave), alfabeto.size())]);
    }
    mensaje = palabra;
}

void Cesar::Decypher(string &mensaje, int clave) {
    for (int i = 0; i < mensaje.size(); ++i) {
        if(mensaje[i] == ' '){
            palabra.push_back(' ');
        }
        else{
            palabra.push_back(alfabeto[module(((alfabeto.find(mensaje[i])) - clave), alfabeto.size())]);
        }
    }
    mensaje = palabra;
}