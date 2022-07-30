#ifndef POST_CALC_H
#define POST_CALC_H

#include <iostream>
#include <vector>

class Calc {
public:
    explicit Calc(const std::string &in);
    long double result = 0.0;

private:
    struct Elem {
        bool is_char;
        long double num;
        char c;
    };
    std::vector<Elem> post_view = {};

    std::string input_str_;

    static bool is_number(const char &symbol);

    static bool is_operation(const char &symbol);

    static int prior(const char &symbol);

    void del_space(const std::string &in);

    long double get_nearest_num(size_t &index, bool is_negative);

    void get_post();

    void get_result();
};


#endif //POST_CALC_H
