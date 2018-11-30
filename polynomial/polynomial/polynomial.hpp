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

#ifndef polynomial_hpp
#define polynomial_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "term.hpp"

class Polynomial{
public:
    Polynomial();
    Polynomial(const Term& t);
    Polynomial(double c, double deg);
    void add(const Term& t);
    void add(double c, double deg);
    void order();
    void multiply(const Polynomial& p);
    void print(std::string name = "Polynomial");
    double evaluate(double x = 1);
private:
    std::list<Term> poly;
    std::list<Term> get_list() const { return poly; }
};

bool compare_terms(const Term& a, const Term& b);

#endif /* polynomial_hpp */
