#include <iostream>
#include <vector>
using namespace std;

void printDouble(double d) {
    if (abs(d) < 1e-7) cout << 0.0;
    else cout << d;
}

struct Point {
    double x, y, z;
};

struct Particle {
    Point p,v;
    double m;
};

Point sum(Point p1, Point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    p1.z += p2.z;
    return p1;
}

Point mul(double a, Point p) {
    p.x *= a;
    p.y *= a;
    p.z *= a;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.setf(ios::fixed);
    cout.precision(5);
    int n, k;
    while (cin >> n >> k) {
        vector<Particle> particula(n, Particle());
        Particle centro_masas;
        centro_masas.p.x = 0; //inicializamos todas las varibles a cero
        centro_masas.p.y = 0;
        centro_masas.p.z = 0;
        centro_masas.v.x = 0;
        centro_masas.v.y = 0;
        centro_masas.v.z = 0;
        centro_masas.m = 0;
        for (int i = 0; i < n; ++i) {
            cin >> particula[i].p.x >> particula[i].p.y >> particula[i].p.z >> particula[i].v.x >> particula[i].v.y >> particula[i].v.z >> particula[i].m;
            centro_masas.p = sum(centro_masas.p, mul(particula[i].m, particula[i].p));
            centro_masas.v = sum(centro_masas.v, mul(particula[i].m, particula[i].v));
            centro_masas.m += particula[i].m; //calculamos suma de posiciones, velocidades y masas
        }
        centro_masas.m = 1/centro_masas.m;
        centro_masas.p = mul(centro_masas.m, centro_masas.p); //valor de la posicion del centro de masas
        centro_masas.v = mul(centro_masas.m, centro_masas.v); //valor de la velocidad del centro de masas
        double t_total = 0; //tiempo total transcurrido
        while (k > 0) {
            double t;
            cin >> t;
            t_total += t;
            centro_masas.p = sum(centro_masas.p, mul(t, centro_masas.v));
            printDouble(centro_masas.p.x);
            cout << ' ';
            printDouble(centro_masas.p.y);
            cout << ' ';
            printDouble(centro_masas.p.z);
            cout << '\n';
            --k;
        }
        for (int i = 0; i < n; ++i) {
            particula[i].p = sum(particula[i].p, mul(t_total, particula[i].v ) );
            printDouble (particula[i].p.x);
            cout << ' ';
            printDouble (particula[i].p.y);
            cout << ' ';
            printDouble (particula[i].p.z);
            cout << '\n';
        }
        cout << '\n';
    }
}