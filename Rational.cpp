//
// Created by wolph on 11/2/2026.
//

#include "Rational.h"

#include <regex>
#include <stdexcept>


Rational::Rational()
    :numerator(0), denominator(1) {}

Rational::Rational(int num)
    :numerator(num), denominator(1) {}

Rational::Rational(int num, int den)
    :numerator(num){
    if (den == 0) {
        this->denominator = den;
    } else {
        throw std::runtime_error("ERROR: cannot divide by 0");
    }
}

Rational::Rational(std::string str) {
    std::stringstream ss(str);

    std::string num;
    std::string den = "1"; //incase not provided

    std::getline(ss, num, '/'); //grab everything until '/'
    std::getline(ss, den);  // grab the rest

    numerator = std::stoi(num);
    denominator = std::stoi(den);
}

bool validateString(const std::string& str) {
    // allowed characters: -/1234567890
    const std::regex pattern("[-/0-9]");

    return std::regex_match(str, pattern);
}