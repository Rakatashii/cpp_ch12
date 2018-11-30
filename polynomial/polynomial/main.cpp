/*
 Exercise P12.14. Write a class Polynomial that stores a polynomial such as
 p(x) = 5x10 + 9x7 − x − 10
 as a linked list of terms. A term contains the coefficient and the power of x. For example, you would store p(x) as
 (5,10),(9,7),(−1,1),(−10,0)
 Supply member functions to add, multiply, and print polynomials. Supply a constructor that makes a polynomial from a single term. For example, the polynomial p can be constructed as
 Polynomial p(Term(-10, 0));
 p.add(Polynomial(Term(-1, 1)));
 p.add(Polynomial(Term(9, 7)));
 p.add(Polynomial(Term(5, 10)));
 Then compute p(x) × p(x).
 Polynomial q = p.multiply(p);
 q.print();
*/

#include <iostream>
#include "polynomial.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Polynomial p = Polynomial();
    p.add((-10.0), 0.0);
    p.add(-1.0, 1.0);
    p.add(9.0, 7.0);
    p.add(Term(5, 10));
    
    p.print("Before multiply");
    p.multiply(p);
    p.print("After  multiply");
    cout << endl;
    
    double x = 1.0;
    double solution = p.evaluate();
    printf("(x == %2.2f) solution = %12.2f\n", 4, x, solution);
    x = 2.0;
    solution = p.evaluate(x);
    printf("(x == %2.2f) solution = %12.2f\n", 4, x, solution);
    
    // Consider replacing double w long double (or even long long double)
    
    cout << endl;
    return 0;
}
