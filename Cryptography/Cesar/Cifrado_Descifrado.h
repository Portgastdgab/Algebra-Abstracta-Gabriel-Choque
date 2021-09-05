#include <iostream>
#include "fstream"

using namespace std;

int module(int , int );
string fileOpen(string);

class Cesar {
private:

    string palabra;

public:
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    void Cypher(string &, int );
    void Decypher(string &, int );
};