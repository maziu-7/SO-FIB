#include <iostream>
#include "BinTree.hh"
using namespace std;

BinTree<int> i_sortTree(BinTree<int> t, int& s){
	if(t.empty()){
		s = 0;
		return BinTree<int>();
	}
	else{
		BinTree<int> te,td;
		int se,sd;
		te = i_sortTree(t.left(),se);
		td = i_sortTree(t.right(),sd);
		s = se + sd + t.value();
		if(sd < se) return BinTree<int>(t.value(),td,te);
		else return BinTree<int>(t.value(),te,td);
	}
}

// Pre: sigui T el valor inicial de t.
// Post: el valor retornat s'obté a partir de T a base de
// swapejar els fills esquerra i dret dels nodes de T
// que cumpleixen que la suma dels valors que penjen del seu fill esquerra és més gran
// estricte que la suma dels valors que penjen del seu fill dret.
BinTree<int> sortTree(BinTree<int> t){
	int s;
	return i_sortTree(t,s);	
}