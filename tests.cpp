#include "tests.h"

#include "calculator.h"
#include <string>
#include <vector>
#include <cassert>

using namespace std;

void test_parse()
{
    string expression = "sin(0) + cos(0) + tg(pi/4) * ctg(pi/4)";
    vector <Token> tokens = parse(expression);
    assert(tokens.size() == 23);

    expression = "ln(e) + log(2,8)";
    tokens = parse(expression);
    assert(tokens.size() == 10);

    expression = "e";
    tokens = parse(expression);
    assert(tokens.size() == 1);
    
    expression = "2.2^1.1 + (1 - 6)";
    tokens = parse(expression);
    assert(tokens.size() == 9);

    expression = "arcsin(0) + arccos(1) + arctg(3.3) + arcctg(1)";
    tokens = parse(expression);
    assert(tokens.size() == 19);
}

void test_negative_numbers()
{
    string expression = "-2.5 + (-3 +9)";
    vector <Token> tokens = parse(expression);
    vector <Token> tokens_ = negative_numbers(tokens);
    assert(tokens_[0].value == "0");
    assert(tokens_[5].value == "0");

    expression = "-(-pi + 6) + sin(-1)";
    tokens = parse(expression);
    tokens_ = negative_numbers(tokens);
    assert(tokens_[0].value == "0");
    assert(tokens_[3].value == "0");
    assert(tokens_[12].value == "0");

    expression = " - cos(3)";
    assert(tokens_[0].value == "0");
}
void test_RPN()
{
    string expression = "2 * (cos(3 - 1))^2 +ln(3) / exp(-2)";
    vector <Token> tokens = parse(expression);
    vector <Token> tokens_ = negative_numbers(tokens);
    queue <Token> rpn = RPN(tokens_);

    assert(rpn.front().value == "2");
    rpn.pop();
    assert(rpn.front().value == "3");
    rpn.pop();
    assert(rpn.front().value == "1");
    rpn.pop();
    assert(rpn.front().value == "-");
    rpn.pop();
    assert(rpn.front().value == "cos");
    rpn.pop();
    assert(rpn.front().value == "2");
    rpn.pop();
    assert(rpn.front().value == "^");
    rpn.pop();
    assert(rpn.front().value == "*");
    rpn.pop();
    assert(rpn.front().value == "3");
    rpn.pop();
    assert(rpn.front().value == "ln");
    rpn.pop();
    assert(rpn.front().value == "0");
    rpn.pop();
    assert(rpn.front().value == "2");
    rpn.pop();
    assert(rpn.front().value == "-");
    rpn.pop();
    assert(rpn.front().value == "exp");
    rpn.pop();
    assert(rpn.front().value == "/");
    rpn.pop();
    assert(rpn.front().value == "+");
    rpn.pop();
}

void test_stack_calc()
{
   
    string expression = "arctg(0)";
    vector <Token> tokens = parse(expression);
    vector <Token> tokens_ = negative_numbers(tokens);
    queue <Token> rpn = RPN(tokens_);
    double result = stack_calc(rpn);
    assert(result == 0);
}
