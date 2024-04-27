#include <set>
#include <iostream>
using namespace std;

int main() {
    set<string> lista_todas; //Jugadores que han hecho todas las actividades
    set<string> cap_act; //Cap activitat
    string nom;
    cin >> nom;
    
    while(nom != ".") {
        lista_todas.insert(nom);
        cin >> nom;
    }
    cap_act = lista_todas;
    int n; //Numero de actividades
    cin >> n;
    for (int i = 0; i < n; i++) {
        set<string> participantes = lista_todas;
        while(cin >> nom and nom != ".") {
            participantes.erase(nom);
            cap_act.erase(nom);
        }
        //Interseccion conjunto lista_alumnos con conjunto participantes
        set<string>::iterator it = participantes.begin();
        while(it != participantes.end()) {
            lista_todas.erase(*it);
            ++it;
        }
    }
    cout << "Totes les activitats:";
    set<string>::iterator it = lista_todas.begin();
    while(it != lista_todas.end()){
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    cout << "Cap activitat:";
    it = cap_act.begin();
    while(it != cap_act.end()){
        cout << " " << *it;
        ++it;
    }
    cout << endl;
}