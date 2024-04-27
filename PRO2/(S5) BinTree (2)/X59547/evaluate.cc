#include "evaluate.hh"
#include "utils.hh"

int evaluate(map<string,int> &variable2value, BinTree<string> t) {
    int valor;
    if (isNumber(t.value())) valor = mystoi(t.value());
    else if (isVariable(t.value())) valor = variable2value[t.value()];
    else {
        if (t.value() == "*") valor = (evaluate(variable2value, t.left()) * evaluate(variable2value,t.right()));
        else if (t.value() == "+") valor = (evaluate(variable2value, t.left()) + evaluate(variable2value, t.right()));
        else if (t.value() == "-") valor = (evaluate(variable2value, t.left()) - evaluate(variable2value, t.right()));
    }
    return valor;
}