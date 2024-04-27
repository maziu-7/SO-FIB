#include <iostream>
using namespace std;

int main() {
    int nspaces,nrombes;

    while (cin >> nspaces >> nrombes) {
        for (int i = 0; i < nrombes; ++i) { //imprime n rombos
            for (int j = 0; j <= nspaces; ++j) {
                //imprime hasta la línea del medio
                /* hace un recorrido vertical, de línea en línea,
                 * y luego un recorrido horizontal,
                 * de espacio en espacio.
                 */
                for (int k = 0; k < nspaces*2 + 1; ++k) {
                    //cada línea tiene como máximo n*2 + 1 espacios
                    if ((k == nspaces - j) or (k == nspaces + j))
                    cout << '*';
                    else if (k < nspaces + j) cout << ' ';
                }
                cout << endl;
            }

            for (int j = nspaces - 1; j > 0; --j) { //imprime la parte de abajo,
                for (int k = 0; k < nspaces*2 + 1; ++k) { //excepto la última línea
                    if ((k == nspaces - j) or (k == nspaces + j))
                    cout << '*';
                    else if (k < nspaces + j) cout << ' ';
                }
                cout << endl;
            }
        }
        for (int i = 0; i < nspaces; ++i) cout << ' ';
        cout << '*' << endl; //imprime la última línea
        cout << endl;
    }
}