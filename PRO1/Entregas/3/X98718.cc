#include <iostream>
using namespace std;

int main() {
    int aaa = 0; //inicializamos un contador para cada caso posible de subwords
    int aab = 0;
    int abb = 0;
    int aba = 0;
    int bbb = 0;
    int bba = 0;
    int baa = 0;
    int bab = 0;
    int pos = -1;

    char first,second,third,n;
    /*first, second y third son los 3 chars del subword que buscamos.
    utilizaremos n como variable de ayuda para hacer búsqueda en ventana*/
    cin >> n;
    first = n;
    cin >> n;
    second = n; //ya tenemos first y second con valor asignado

    bool subword = false; //bool para cuando se encuentre el subword que queremos
    bool first_subword = true;
    /*first_subword lo utilizaremos solo para los 3 primeros chars de una secuencia,
    simplemente para asignar un valor a third*/

    while (not subword) {
        cin >> n;
        if (first_subword) {
            third = n;
            first_subword = false; //ya tenemos el primer subword de la secuencia
        }
        else {
            first = second; //si no es el primer subword, empezamos la búsqueda
            second = third; //en ventana
            third = n;
        }
        //utilizamos un condicional para cada caso posible de subword
        if (first == 'a' and second == 'a' and third == 'a') {
            ++aaa;
            subword = aaa == 2;
        }
        else if (first == 'a' and second == 'a' and third == 'b') {
            ++aab;
            subword = aab == 2;
        }
        else if (first == 'a' and second == 'b' and third == 'b') {
            ++abb;
            subword = abb == 2;
        }
        else if (first == 'a' and second == 'b' and third == 'a') {
            ++aba;
            subword = aba == 2;
        }
        else if (first == 'b' and second == 'b' and third == 'b') {
            ++bbb;
            subword = bbb == 2;
        }
        else if (first == 'b' and second == 'b' and third == 'a') {
            ++bba;
            subword = bba == 2;
        }
        else if (first == 'b' and second == 'a' and third == 'a') {
            ++baa;
            subword = baa == 2;
        }
        else if (first == 'b' and second == 'a' and third == 'b') {
            ++bab;
            subword = bab == 2;
        }
        ++pos;
    }
    cout << first << second << third << ' ' << pos << endl;
}