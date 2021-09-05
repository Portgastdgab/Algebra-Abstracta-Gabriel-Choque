#include "Cifrado_Descifrado.h"
#include "cryptanalysis_frequencies.h"

int main() {
    string file = "../Message.txt";
    string mensaje = fileOpen(file);
    int clave = 12;
    Cesar Emisor, Receptor;
    //Emisor.Cypher(mensaje, clave);
    cout << "Cifrado: " << mensaje << endl;
    frecuencias1(mensaje);
    //Receptor.Decypher(mensaje, clave);
    cout<<"\n\nDescifrado: "<<mensaje<<endl;
}