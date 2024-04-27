#include "BinTree.hh"
#include <queue>

void subseq(const BinTree<int> &a, queue<int> seq, int &count) {
    if (a.empty()) return;
    else if (not seq.empty() and a.value() == seq.front()) seq.pop();
    if (a.left().empty() and a.right().empty() and seq.empty()) ++count;
    else {
        if (not a.left().empty()) subseq(a.left(),seq,count);
        if (not a.right().empty()) subseq(a.right(),seq,count);
    }
}

int main() {
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BinTree<int>::INLINEFORMAT  :  BinTree<int>::VISUALFORMAT);
    cin >> t;
    cin.ignore();

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        queue<int> seq;
        int number;
        int count = 0;
        while (iss >> number) {
            seq.push(number);
        }
        subseq(t,seq,count);
        cout << count << endl;
    }
}