#include "evaluate.hh"

int main()
{
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	int result;
    	bool error;
    	evaluate(t, result, error);
    	if (error) cout << "Division by 0" << endl;
    	else cout << result << endl;
  	}
}