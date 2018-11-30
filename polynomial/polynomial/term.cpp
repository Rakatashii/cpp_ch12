#include "term.hpp"

Term::Term(){
    coef = 0.0;
    degree = 0.0;
}
Term::Term(double c, double deg){
    coef = c;
    degree = deg;
}
double Term::evaluate(double x){
    return coef * (pow(x, degree));
}
double Term::get_coef() const{
    return coef;
}
double Term::get_degree() const{
    return degree;
}
void Term::set_coef(double c){
    coef = c;
}
void Term::set_degree(double deg){
    degree = deg;
}
bool Term::operator<(const Term& t) const{
    if (degree < t.degree) return true;
    else if (degree == t.degree){
        if (coef < t.coef) return true;
        else return false;
    }
    else return false;
}
bool Term::operator>(const Term& t) const{
    if (degree > t.degree) {
        //oss << degree << " > " << t.degree;
        //std::cout << oss.str() << std::endl;
        return true;
    }
    else if (degree == t.degree){
        if (coef > t.coef) return true;
        else return false;
    }
    else return false;
}
bool Term::operator<=(const Term& t) const{
    if (degree < t.degree) return true;
    else if (degree == t.degree){
        if (coef <= t.coef) return true;
        else return false;
    }
    else return false;
}
bool Term::operator>=(const Term& t) const{
    if (degree > t.degree) return true;
    else if (degree == t.degree){
        if (coef >= t.coef) return true;
        else return false;
    }
    else return false;
}
bool Term::operator==(const Term& t) const{
    if (degree == t.degree && coef == t.coef) return true;
    else return false;
}
bool Term::operator!=(const Term& t) const{
    if (degree != t.degree || coef != t.coef) return true;
    else return false;
}
std::string Term::term2str() const{
    std::ostringstream oss;
    if (coef == 0.0) return "";
    else oss << coef;
    if (degree != 0.0) oss << "x\u005E" << degree;
    return oss.str();
}

/*
 void Polynomial::print(){
 std::string poly_str;
 Term last = poly.back();
 for (std::list<Term>::iterator iter = poly.begin(); iter != poly.end(); iter++){
 poly_str += iter->coef;
 poly_str += '\u005E' + iter->get_degree();
 if (*iter != last) {
 if (iter->coef > 0) poly_str += " + ";
 else if (iter->coef < 0) poly_str += " - ";
 }
 }
 std::cout << poly_str << std::endl;
 }
*/







