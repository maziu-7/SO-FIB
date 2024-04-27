#include <iostream>
#include <algorithm>
#include "BinTree.hh"
using namespace std;

void i_agd(const BinTree<int> &a, BinTree<int> &agd, int& h){
	if(a.empty()) h = 0;
	else{
		int he, hd;
		BinTree<int> agde,agdd;
		i_agd(a.left(),agde,he);
		i_agd(a.right(),agdd,hd);
		agd = BinTree<int>(he-hd,agde,agdd);
		h = max(he,hd)+1;
	}
}

void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd){
	int h;
	i_agd(a,agd,h);
}