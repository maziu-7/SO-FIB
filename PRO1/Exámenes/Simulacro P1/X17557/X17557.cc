#include <iostream>
using namespace std;

int main() {
    char x;
    bool mid_b = false;
    bool is_a = false;
    int c_counter = 0;
    int d_counter = 0;
    int found_d = 0;

    while (cin >> x) {
        if (x == 'a') {
            if (found_d != 0) {
                d_counter += found_d;
                found_d = 0;
            }
            is_a = true;
            mid_b = false;
        }
        else if (x == 'b') {
            mid_b = true;
            is_a = false;
            found_d = 0;
        }
        else if (x == 'c') {
            if (not mid_b and is_a) ++c_counter;
            mid_b = false;
        }
        else ++found_d;
    }
    cout << c_counter << ' ' << d_counter << endl;        
}