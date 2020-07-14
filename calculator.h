#pragma once

#include <vector>
#include <queue>
#include <string>

using namespace std;

enum Token_type
{
    NUMBER,
    OPERATOR,
    BRACKET,
    FUNCTION,
    CONSTANT
};

struct Token
{
    Token_type type;
    string value;
};

vector <Token> parse(const string& expression);

vector <Token> negative_numbers(vector <Token>& tokens);

int check(Token symbol);

queue <Token> RPN(const vector <Token>& tokens);

double stack_calc(queue <Token>& rpn_tokens);

double evaluate(string& expression);