#include <iostream>
#include <vector>
using namespace std;
 
const int LENGTH_ALPHABET = 'z' - 'a' + 1;
 
char most_frequent_letter(const string& s) {
        vector <int> lmf(LENGTH_ALPHABET, 0);
        int tams = s.size();
        for (int i = 0; i < tams; ++i) {
                ++lmf[s[i] - 'a'];
        }
        int pos = 0;
        int freq = 0;
        for (int i = 0; i < LENGTH_ALPHABET; ++i) {
                if (lmf[i] > freq) {
                        pos = i;
                        freq = lmf[i];
                }
        }
        char c = 'a' + pos;
        return c;
}

int main() {
        cout.setf(ios::fixed);
        cout.precision(2);
        
        int n;
        double length = 0;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
                cin >> v[i];
                length += v[i].length();
        }
        length = length/n;
        cout << length << endl;
        for (int i = 0; i < n; ++i) {
                if (v[i].length() >= length) {
                        cout << v[i] << ": " << most_frequent_letter(v[i]) << endl;
                }
        }
}