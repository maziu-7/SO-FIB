#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Scoreboard {
    int a,b;
};

struct Table {
    int team,points,goals_s,goals_r;
};

typedef vector <vector<Scoreboard>> Matrix;

Matrix read(int n) {
    Matrix mat(n, vector<Scoreboard>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j].a >> mat[i][j].b;
        }
    }

    return mat;
}

bool classification(const Table &a, const Table &b) {
    if (a.points == b.points) {
        if (a.goals_s - a.goals_r == b.goals_s - b.goals_r) {
            return a.team < b.team;
        }
        return a.goals_s - a.goals_r > b.goals_s - b.goals_r;
    }
    return a.points > b.points;
}

int main() {
    int n;
    cin >> n;

    Matrix table = read(n);

    vector<Table> league(n);

    for(int i = 0; i < n; ++i) {
        
    }
}