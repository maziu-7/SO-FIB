#include <iostream>
using namespace std;

void infoSequence(int& max, int& lpos) {
    int n, pos2 = 1;
    
    while (cin >> n and n != max and n != 0) pos2++;
    
    if (n == max) cout << max << " " << lpos << " " << pos2 << endl;
    else cout << max << " " << lpos << " -" << endl;
}

int main() {
    int n;
    int max = 0;
    int pos = 0;
    int c = 1;
    
    cin >> n;
    while (n != 0) {
        if (max == 0 and pos == 0) {
            max = n;
            pos = c;
        }
        else if (n >= max) {
            max = n;
            pos = c;
        }
        ++c;
        cin >> n;
    }
    infoSequence(max, pos); 
}