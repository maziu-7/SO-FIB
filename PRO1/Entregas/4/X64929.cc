#include <iostream>
using namespace std;

int main() {
    char first,second,third;
    int happy_c = 0; //inicializamos contadores
    int sad_c = 0;
    cin >> first >> second; //hacemos cin fuera del while para empezar la búsqueda en ventana
    while (cin >> third) { //cin del tercer elemento
        //utilizamos un condicional para cada caso posible
        if (first == ':' and second == '-' and third == ')') ++happy_c;
        else if (first == '(' and second == '-' and third == ':') ++happy_c;
        else if (first == ':' and second == '-' and third == '(') ++sad_c;
        else if (first == ')' and second == '-' and third == ':') ++sad_c;
        first = second; //deslizamos first y second hacia la derecha
        second = third;
    }
    cout << happy_c << " " << sad_c << endl;
}