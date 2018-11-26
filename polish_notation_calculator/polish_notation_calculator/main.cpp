// Practice with std stack

#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long double (*operation_type)(long double, long double);
// returns appropriate operation based on character equivalent
operation_type get_operation_type(char c);

// Operation types supported
long double add(long double a, long double b)       { return a + b; }
long double subtract(long double a, long double b)  { return a - b; }
long double divide(long double a, long double b)    { return a / b; }
long double multiply(long double a, long double b)  { return a * b; }
long double power(long double a, long double b) { return pow(a, b); }

// Get single binary operator result
long double calculate(long double a, long double b, char c);
// Get the solution to string polish notation expression
long double polish_calculator(string polish_notation);

bool is_numeric(char c);

int main(int argc, const char * argv[]) {
    int i = 0;
    
    string eq = "32 144 50 * + ";
    long double result = polish_calculator(eq);
    cout << "result" << ++i << " = " << result << endl;
    
    eq = "9 2 5 * ^ ";
    result = polish_calculator(eq);
    cout << "result" << ++i << " = " << result << endl;
    
    eq = "923 83 19 - + ";
    result = polish_calculator(eq);
    cout << "result" << ++i << " = " << result << endl;
    
    return 0;
}

long double polish_calculator(string polish_notation){
    stack<long double> seq;
    long double result = 0;
    
    for (int i = 0; i < polish_notation.length(); i++){
        bool neg = false;
        if (polish_notation[i] == '-' && is_numeric(polish_notation[i+1])) neg = true;
        if (is_numeric(polish_notation[i])){
            long double d = polish_notation[i]-'0';
            while (polish_notation[i+1] != ' '){
                i++;
                d = d * 10 + polish_notation[i] - '0';
            }
            seq.push(d);
        }
        else if (polish_notation[i] != ' '){
            long double a = (neg) ? -1 * seq.top() : seq.top();
            seq.pop();
            long double b = (neg) ? -1 * seq.top() : seq.top();
            seq.pop();
            result = calculate(a, b, polish_notation[i]);
            seq.push(result);
        }
    }
    result = seq.top(); seq.pop();
    return result;
}
operation_type get_operation_type(char c){
    switch(c){
        case '+': return add;
        case '-': return subtract;
        case '/': return divide;
        case '*': return multiply;
        case '^': return power;
        default: {
            std::cout << "Error. Invalid char.\n";
            exit(-1);
        }
    }
};
long double calculate(long double a, long double b, char c){
    operation_type oper = get_operation_type(c);
    return oper(a, b);
}
bool is_numeric(char c){
    if ((int)c >= 48 && (int)c <= 57) return true;
    else return false;
}
