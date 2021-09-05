#include "Cifrado_Descifrado.h"

class letter{
public:
    int num;
    char let;
};

void swap(letter arr[], int pos1, int pos2) {
    letter temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}


void bubbleSort(letter arr[], int n) {
    bool vuelta;
    for (int i = 0; i < n-1; i++) {
        vuelta = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].num < arr[j + 1].num) {
                swap(arr, j, j + 1);
                vuelta = true;
            }
        }
        if (vuelta == false)
            break;
    }
}
string frecuencias1(string &mensaje) {
    string frec_ingles = "etaoinshr";
    int contador;
    string alfa = Cesar().alfabeto;
    letter frecuencia[alfa.size()];
    for (int i = 0; i < alfa.size()+1; ++i) {
        contador = 0;
        for (int j = 0; j < mensaje.size(); ++j) {
            if (alfa[i] == mensaje[j]) {
                contador++;
            }
        }
        frecuencia[i].let = alfa[i];
        frecuencia[i].num = contador;
    }
    bubbleSort(frecuencia, alfa.size());
    cout<<endl;
    cout<<"Letras con mayor frecuencia y las veces que aparecen:"<<endl;
    for (int i = 0; i < alfa.size(); ++i) {
        cout<<frecuencia[i].let<<"\t";
    }
    cout<<endl;
    for (int i = 0; i < alfa.size(); ++i) {
        cout<<frecuencia[i].num<<"\t";
    }
    cout<<endl;
    int possible_key;
    bool value = false;
    for (int i = 1; i < frec_ingles.size(); ++i) {
        possible_key = module((Cesar().alfabeto.find(frecuencia[0].let)) - (Cesar().alfabeto.find(frec_ingles[0])), alfa.size());
        for (int j = 1; j < frec_ingles.size(); ++j) {
            if(alfa[module(((alfa.find(frecuencia[i].let)) - possible_key), alfa.size())] == frec_ingles[j]){
                value = true;
                break;
            }
        }
        cout<<"Veces de prueba:\n"<<"Value: "<<value<<endl;
        if (value == true){
            break;
        }
        else{
            swap(frecuencia, 0, i);
        }

    }
    cout<<"\n\nPosible clave: "<<possible_key<<endl;
    Cesar final;
    final.Decypher(mensaje, possible_key);
}