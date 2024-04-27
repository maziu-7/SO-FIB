#include "evaluatePrefix.hh"

void reverse(string& s){
	for(int i = 0; i < s.length()/2; ++i){
		char c = s[i];
		s[i] = s[s.length()-i];
		s[s.length()-i] = c;
	}
}
string i_evaluatePrefix(BinTree<string> t){
	if(t.left().empty() and t.right().empty()) return t.value();
	else{
		string resi = i_evaluatePrefix(t.left());
		if(t.value() == "Reverse"){
			reverse(resi);
			return resi;
		}
		else if(t.value() == "Concat"){
			string resd = i_evaluatePrefix(t.right());
			return resi + resd;
		}
	}
	return "";
}


string evaluatePrefix(BinTree<string> t, int n){
	string res = i_evaluatePrefix(t);
	return res.substr(0,n);
}