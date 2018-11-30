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

#include "polynomial.hpp"

bool compare_terms( const Term& a, const Term& b ) {
    if (a < b) std::cout << a.term2str() << " < " << b.term2str() << std::endl;
    else       std::cout << a.term2str() << " > " << b.term2str() << std::endl;
    return a > b;
    /*
     if (a.get_degree() < b.get_degree()) return true;
     else if (a.get_degree() == b.get_degree()){
     if (a.get_coef() < b.get_coef()) return true;
     else return false;
     }
     else return false;
     */
}

Polynomial::Polynomial(){}
Polynomial::Polynomial(const Term& t){
    poly.push_back(t);
    order();
}
Polynomial::Polynomial(double c, double deg){
    Term t((double)c, (double)deg);
    poly.push_back(t);
}
void Polynomial::add(double c, double deg){
    Term t((double)c, (double)deg);
    poly.push_back(t);
}
void Polynomial::add(const Term& t){
    poly.push_back(t);
    order();
}
void Polynomial::print(std::string name){
    std::string poly_str;
    order();
    Term first = poly.front();
    Term last = poly.back();
    std::cout << name << ": ";
    for (std::list<Term>::iterator iter = poly.begin(); iter != poly.end(); ++iter){
        if (iter->coef > 0.0) {
            if (*iter != first) poly_str += " + ";
            poly_str += iter->term2str();
        }
        else if (iter->coef < 0.0) {
            if (*iter != first) poly_str += " - ";
            if (iter->degree != 0){
                poly_str += "(" + iter->term2str().substr(1) + ")";
            } else poly_str += iter->term2str().substr(1);
        }
    }
    std::cout << poly_str << std::endl;
}
void Polynomial::order(){
    //std::sort(poly.begin(), poly.end(), compare_terms);
    poly.sort(compare_terms);
}
void Polynomial::multiply(const Polynomial& p){
    std::list<Term> plist = p.get_list();
    for (std::list<Term>::iterator this_iter = poly.begin(); this_iter != poly.end(); this_iter++){
        for (std::list<Term>::iterator piter = plist.begin(); piter != plist.end(); piter++){
            if (this_iter->degree == piter->degree){
                this_iter->degree += piter->degree;
                this_iter->coef *= piter->coef;
            }
        }
    }
}

double Polynomial::evaluate(double x){
    double sol = 0.0;
    for (std::list<Term>::iterator pos = poly.begin(); pos != poly.end(); pos++){
        sol += pos->evaluate(x);
    }
    return sol;
}

