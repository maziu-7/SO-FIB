#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Slot {
    vector<string> listsubjects;
    vector<string> listteachers;
};

struct Class {
    string subject, teacher;
    int day, start, end;
};

typedef vector<vector<Slot> > TableSlots;

int which_day(string day) {
    if (day == "monday") return 0;
    if (day == "tuesday") return 1;
    if (day == "wednesday") return 2;
    if (day == "thursday") return 3;
    return 4;
}

void printSlotClass(const TableSlots& tableslots, int i, int j) {
    int slotClasses = tableslots[i][j].listsubjects.size();
    int spaceCounter = 9;
    while (slotClasses/10 > 0) slotClasses /= 10, --spaceCounter;
    for (int x = 0; x < spaceCounter; ++x) cout << ' ';
    cout << tableslots[i][j].listsubjects.size();
}

void printSlotTeacher(vector <string> slotTeachers, int& replacementsNeeded) {
    int repeatedTeachers = 0;
    sort(slotTeachers.begin(), slotTeachers.end());
    for (int x = 1; x < slotTeachers.size(); ++x) if (slotTeachers[x] == slotTeachers[x - 1]) ++replacementsNeeded, ++repeatedTeachers;
    int uniqueTeachers = slotTeachers.size() - repeatedTeachers;
    int spaceCounter = 9;
    while (uniqueTeachers/10 > 0) uniqueTeachers /= 10, --spaceCounter;
    for (int x = 0; x < spaceCounter; ++x) cout << ' ';
    cout << slotTeachers.size() - repeatedTeachers;
}

int main() {
    vector<Class> classes(0, Class());
    Class input;
    string day;
    int maxHour = 0;
    int minHour = 24;
    int replacementsNeeded = 0;
    while (cin >> input.subject >> input.teacher >> day >> input.start >> input.end) {
        if (input.subject == "end") break;
        input.day = which_day(day);
        classes.push_back(input);
        if (input.start < minHour) minHour = input.start;
        if (input.end > maxHour) maxHour = input.end;
    }
    TableSlots tableslots (maxHour - minHour, vector<Slot> (5, Slot () ) );
    for (int i = 0; i < classes.size(); ++i) {
        for (int a = classes[i].start - minHour; a < classes[i].end - minHour; ++a) {
            tableslots[a][classes[i].day].listsubjects.push_back(classes[i].subject);
            tableslots[a][classes[i].day].listteachers.push_back(classes[i].teacher);
        }
    }
    cout << "number of subjects per slot:" << endl << " h    monday   tuesday wednesday  thursday    friday" << endl;
    for (int i = 0; i < tableslots.size(); ++i) {
        int current_hour = minHour + i;
        if (current_hour < 10) cout << ' ';
        cout << current_hour;
        for (int j = 0; j < 5; ++j) printSlotClass(tableslots, i, j);
        cout << endl;
    }
    cout << "number of teachers per slot:" << endl << " h    monday   tuesday wednesday  thursday    friday" << endl;
    for (int i = 0; i < tableslots.size(); ++i) {
        int current_hour = minHour + i;
        if (current_hour < 10) cout << ' ';
        cout << current_hour;
        for (int j = 0; j < 5; ++j) printSlotTeacher(tableslots[i][j].listteachers, replacementsNeeded);
        cout << endl;
    }
    cout << "number of replacements needed to avoid conflicts:" << endl << replacementsNeeded << endl;
}