#include <iostream>
using namespace std;

int main() {
    string vacio,name;
    int edad;

    while (cin >> vacio >> vacio >> vacio >> name >> vacio >> vacio >> vacio >> edad >> vacio >> vacio) {
        cout << name << ", you look younger. I thought you were " << edad-edad/10 << " years old." << endl;
    }
}