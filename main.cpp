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
    cout << "Enter an expression: ";
    getline(cin, expression);
    
    double result = evaluate(expression);

    cout << "Answer: " << result << endl;

    return 0;
}
