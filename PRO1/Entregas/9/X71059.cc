#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Programmer{
    string name;
    int level;
};

bool cmp(string a, string b){
    return a < b;
}

int main() {
    int k;

    while (cin >> k){
        int n1, n2;
        cin >> n1;
        vector<Programmer> listUSA(n1);
        for (int i = 0; i < n1; ++i){
            cin >> listUSA[i].name >> listUSA[i].level;
        }

        cin >> n2;
        vector<Programmer> listRussia(n2);
        for (int i = 0; i < n2; ++i){
            cin >> listRussia[i].name >> listRussia[i].level;
        }

        int i = 0;
        int j = 0;
        int countUSA = 0;
        int countRussia = 0;
        vector<string> team(k);
        for (int aux = 0; aux < n1 + n2; ++aux){
            int index = aux%k;
            if (j == n2) {
                team[index] = listUSA[i].name;
                ++i;
                ++countUSA;
            }
            else if (i == n1) {
                team[index] = listRussia[j].name;
                ++j;
                ++countRussia;
            }
            else if (listUSA[i].level > listRussia[j].level) {
                team[index] = listUSA[i].name;
                ++i;
                ++countUSA;
            }
            else if (listUSA[i].level < listRussia[j].level) {
                team[index] = listRussia[j].name;
                ++j;
                ++countRussia;
            }
            else if ((listUSA[i].level == listRussia[j].level)) {
                if (countUSA < countRussia){
                    team[index] = listUSA[i].name;
                    ++i;
                    ++countUSA;
                }
                else if (countUSA > countRussia) {
                    team[index] = listRussia[j].name;
                    ++j;
                    ++countRussia;
                }
                else {
                    if (listUSA[i].name < listRussia[j].name) {
                        team[index] = listUSA[i].name;
                        ++i;
                        ++countUSA;
                    }
                    else {
                        team[index] = listRussia[j].name;
                        ++j;
                        ++countRussia;
                    }
                }
            }

            if ((aux + 1)%k == 0) {
                sort(team.begin(), team.end(), cmp);

                for (int z = 0; z < k; ++z) {
                    cout << team[z];
                    if (z != k - 1) cout << ' ';
                }
                cout << endl;

                fill(team.begin(), team.end(), 0);
                countUSA = 0;
                countRussia = 0;
            }
        }
        cout << endl;
    }
}