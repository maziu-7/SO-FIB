#include <iostream>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        int par = 0;
        int sen = 0;
        int count = 1;
        int con = 1;

        while (n > 0) {
            if ((n%10)%2 == 0 and n%10 != 0) {
                par += n%10*count;
                count *= 10;
            }
            if ((n%10)%2 != 0 and n%10 != 0) {
                sen += n%10*con;
                con *= 10;
            }
            n /= 10;
        }
        int sum = sen*count + par;
        cout << sum << " " << sum*2 << endl;
    }
}