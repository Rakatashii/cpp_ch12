#ifndef term_hpp
#define term_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

class Polynomial;

class Term{
public:
    Term();
    Term(double c, double deg);
    double evaluate(double x);
    
    double get_coef() const;
    double get_degree() const;
    void set_coef(double c);
    void set_degree(double deg);
    
    bool operator<(const Term& t) const;
    bool operator>(const Term& t) const;
    bool operator<=(const Term& t) const;
    bool operator>=(const Term& t) const;
    
    bool operator==(const Term& t) const;
    bool operator!=(const Term& t) const;
    
    friend class Polynomial;
    
    std::string term2str() const;
private:
    double coef;
    double degree;
};

#endif /* term_hpp */
