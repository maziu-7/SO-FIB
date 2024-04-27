#include <iostream>
using namespace std;

void info_sequence(int& sum, int& last) {
    int num;
    cin >> num;

    sum = 0;

    while (num != 0) {
        sum += num;
        last = num;
        cin >> num;
    }
}

int main() {
    int sum_first,last_first;
    int c = 1;
    info_sequence(sum_first,last_first);

    int sum_next = 1;
    int last_next = 1;

    while (sum_next != 0) {
        info_sequence(sum_next,last_next);
        if (sum_first == sum_next and last_first == last_next) ++c;
    }
    cout << c << endl;
}