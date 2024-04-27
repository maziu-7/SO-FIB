#include <iostream>
#include <list>
using namespace std;

int recalculate(const list<int>& l, int e) {
    int num = *l.begin();
    for(list<int>::const_iterator it = ++l.begin(); it != l.end(); ++it) {
        if ((*it)*e > num*e) num = *it;
    }
    return num;
}

int main() {
    list<int> l;
    list<int>::iterator it = l.begin();
    int n,num;
    int elems = 0;
    int suma = 0;
    int min = 0;
    int max = 0;
    bool first = true;
    cin >> n >> num;
    while (n != 0) {
        if (n == -1) {
            if (first) min = max = num;
            else if (num > max) max = num;   
            else if (num < min) min = num;
            l.insert(l.end(),num);
            suma += num;
            ++elems;
            first = false;   
        }
        else {
            it = l.begin();
            while (it != l.end() and *it != num) ++it;
            if (it != l.end()) {
                l.erase(it);
                --elems;
                suma -= num;
            }
            if (elems == 0) first = true;
            else if (num == max) max = recalculate(l,1);     
            else if (num == min) min = recalculate(l,-1);     
        }
        if (elems == 0) cout << 0 << endl;
        else cout << min << " " << max << " " << double(suma)/elems << endl;
        cin >> n >> num;
    }
}