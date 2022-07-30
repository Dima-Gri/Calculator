#include "Stack.h"

Stack* Stack::insert(Stack* p, long double out) {
    auto t = new Stack;
    t->num = out;
    t->next = p;
    return t;
}

Stack* Stack::remove(Stack* p, long double &in) {
    Stack* t = p;
    in = p->num;
    p = p->next;
    delete t;
    return p;
}

Stack* Stack::insert(Stack* p, char out) {
    auto t = new Stack;
    t->symbol = out;
    t->next = p;
    return t;
}

Stack* Stack::remove(Stack* p, char &in) {
    Stack* t = p;
    in = p->symbol;
    p = p->next;
    delete t;
    return p;
}
