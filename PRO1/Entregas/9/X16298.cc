#include <iostream>
#include <vector>
using namespace std;

int findEndIndex(const string &s, int start) {
    char target = s[start];
    int low = start;
    int high = s.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (s[mid] == target) low = mid + 1;
        else high = mid - 1;
    }
    return low - 1;
}

// Pre: s is formed with three different characters c1,c2,c3, and is of the form c1...c1c2...c2c3...c3.
// Post: n1, n2, n3 are the number of occurrences of c1, c2, c3 in s, respectively.
void numberOccurrences(const string &s, int &n1, int &n2, int &n3) {
    n1 = n2 = n3 = 0;

    // Find the end index of the block for c1
    int endC1 = findEndIndex(s, 0);
    n1 = endC1 + 1;

    // Find the end index of the block for c2
    int endC2 = findEndIndex(s, n1);
    n2 = endC2 - endC1;

    // Find the end index of the block for c3
    int endC3 = findEndIndex(s, n1 + n2);
    n3 = endC3 - endC2;
}

// Pre: s begins with one or more occurrences of a character c1, followed by one or more
//      occurrences of a character c2, followed by one or more occurrences of a character c3,
//      and there are no more characters in s.
//      moreover, either c1c2c3 = ":-)" or c1c2c3 = "(-:" or c1c2c3 = ":-(" or c1c2c3 = ")-:".
// Post: If c1c2c3 = ":-)" or c1c2c3 = "(-:", the function returns the number of happy subsequences.
//       If c1c2c3 = ":-(" or c1c2c3 = ")-:", the function returns the number of sad subsequences.
int numberHappyOrSadSubsequences(const string &s) {
    int n1 = 0, n2 = 0, n3 = 0, aux;
    numberOccurrences(s, n1, n2, n3);
    aux = n1*n2*n3;
    return aux;
}

int main() {
    int n1 = 0, n2 = 0, n3 = 0;
    string s;
    while (cin >> s) {
        numberOccurrences(s, n1, n2, n3);
        cout << numberHappyOrSadSubsequences(s) << endl;
    }
}