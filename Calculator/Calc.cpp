#include "Calc.h"
#include "Stack.h"

Calc::Calc(const std::string &in) {
    del_space(in);
    get_post();
    get_result();
}

bool Calc::is_number(const char &symbol) {
    return '0' <= symbol && symbol <= '9';
}

bool Calc::is_operation(const char &symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int Calc::prior(const char &symbol) {
    if (symbol == '*' || symbol == '/')
        return 3;
    else if (symbol == '-' || symbol == '+')
        return 2;
    else if (symbol == '(')
        return 1;
    return 0;
}


void Calc::del_space(const std::string& in) {
    for (const auto& symbol : in){
        if (symbol != ' '){
            input_str_ += symbol;
        }
    }
}

long double Calc::get_nearest_num(size_t& index, bool is_negative) {
    long double temp_num = 0.0;
    long long after_point;
    bool point_check = false;
    after_point = is_negative ? -1ll : 1ll;
    while (index != input_str_.size() && (is_number(input_str_[index]) || input_str_[index] =='.')) {
        if (input_str_[index] == '.') {
            point_check = true;
            ++index;
            continue;
        }
        temp_num = temp_num * 10 + int(input_str_[index]) - 48;
        if (point_check) {
            after_point *= 10;
        }
        ++index;
    }
    --index;
    return temp_num / after_point;
}

void Calc::get_post() {
    Stack *up = nullptr;
    size_t index = 0;
    while (index != input_str_.size()) {
        if (input_str_[index] == '-' && is_number(input_str_[index + 1]) || is_number(input_str_[index])){
            long double num;
            if ((index == 0 || input_str_[index - 1] == '(') && input_str_[index] == '-' && is_number(input_str_[index + 1])){
                ++index;
                num = get_nearest_num(index, true);
                post_view.push_back({false, num});
            } else if (is_number(input_str_[index])) {
                num = get_nearest_num(index, false);
                post_view.push_back({false, num});
            }
        }

        if (input_str_[index] == '(')
            up = up->insert(up, '(');

        if (input_str_[index] == ')') {
            while (up->symbol != '(') {
                char a;
                up = up->remove(up, a);
                post_view.push_back({true, 0,a});
            }
            Stack* t = up;
            up = up->next;
            delete t;
        }
        if (is_operation(input_str_[index])) {
            while (up != nullptr && prior(up->symbol) >= prior(input_str_[index])) {
                char a;
                up = up->remove(up, a);
                post_view.push_back({true, 0, a});
            }
            up = up->insert(up, input_str_[index]);
        }
        ++index;
    }
    while (up != nullptr) {
        char a;
        up = up->remove(up, a);
        post_view.push_back({true, 0, a});
    }
}

void Calc::get_result() {
    Stack* top;
    for (auto it : post_view) {
        if (!it.is_char) {
            top = top->insert(top, it.num);
        } else {
            long double first_num, second_num;
            top = top->remove(top, second_num);
            top = top->remove(top, first_num);
            switch (it.c) {
                case '+': result = first_num + second_num; break;
                case '-': result = first_num - second_num; break;
                case '*': result = first_num * second_num; break;
                case '/': result = first_num / second_num; break;
            }
            top = top->insert(top, result);
        }
    }
}
