#include <iostream>
using namespace std;

bool is_leap_year(int year) {
    return (year%4 == 0 and not (year%100 == 0 and (year/100)%4 != 0));
}