#include "tests.h"
#include "calculator.h"

#include <iostream>
#include <string>
using namespace std;


int main()
{
    test_parse();
    test_negative_numbers();
    test_RPN();
    test_stack_calc();
    
    string expression;
    cout << "Введите выражение: ";
    getline(cin, expression);
    
    double result = evaluate(expression);

    cout << "Ответ: " << result << endl;

    return 0;
}