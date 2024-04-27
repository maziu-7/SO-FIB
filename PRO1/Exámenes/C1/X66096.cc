#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    int y;
    cin >> y;
    double e;
    cin >> e;
    string act;
    cin >> act;

    if (act == "making_things") {
        cout << "Making things produced " << e*0.31;
        cout << " CO2 Gt in " << y << endl;
    }
    else if (act == "pluggin_in") {
        cout << "Pluggin in produced " << e*0.27;
        cout << " CO2 Gt in " << y << endl;
    }
    else if (act == "growing_things") {
        cout << "Growing things produced " << e*0.19;
        cout << " CO2 Gt in " << y << endl;
    }
    else if (act == "getting_around") {
        cout << "Getting around produced " << e*0.16;
        cout << " CO2 Gt in " << y << endl;
    }
    else {
        cout << "Keeping warm and cold produced " << e*0.07;
        cout << " CO2 Gt in " << y << endl;
    }
}