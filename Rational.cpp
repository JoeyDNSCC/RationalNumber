//
// Created by wolph on 11/2/2026.
//

#include "Rational.h"

#include <stdexcept>


Rational::Rational() = default;

Rational::Rational(int num)
    :numerator(num), denominator(1){
}

Rational::Rational(int num, int den)
    :numerator(num){
    if (den == 0) {
        this->denominator = den;
    } else {
        throw std::runtime_error("ERROR: cannot divide by 0");
    }
}

Rational::Rational(std::string str) {

}
