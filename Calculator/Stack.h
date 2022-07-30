#ifndef POST_STACK_H
#define POST_STACK_H


class Stack {
public:
    char symbol;
    long double num;
    Stack* next;

    Stack* insert(Stack* p, long double out);

    Stack* remove(Stack* p, long double &in);

    Stack* insert(Stack* p, char out);

    Stack* remove(Stack* p, char &in);
};


#endif //POST_STACK_H
