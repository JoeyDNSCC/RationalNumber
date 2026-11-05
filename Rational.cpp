//
// Created by wolph on 11/2/2026.
//

#include "Rational.h"

#include <regex>
#include <stdexcept>
#include <iostream>


Rational::Rational()
    :numerator(0), denominator(1) {
    std::cout << "default_constructor" << std::endl;
}

Rational::Rational(int num)
    :numerator(num), denominator(1) {
    std::cout << "one_arg_constructor" << std::endl;
}

Rational::Rational(int num, int den)
    :numerator(num){
    std::cout << "BEGAN two_arg_constructor" << std::endl;

    if (den == 0) {
        this->denominator = den;
    } else {
        throw std::runtime_error("ERROR: cannot divide by 0");
    }

    std::cout << "COMPLETE two_arg_constructor" << std::endl;
}

Rational::Rational(const std::string& str) {
    std::cout << "BEGAN string_constructor" << std::endl;

    std::stringstream ss(str);

    std::string num;
    std::string den = "1"; //incase not provided

    std::getline(ss, num, '/'); //grab everything until '/'
    std::getline(ss, den);  // grab the rest

    numerator = std::stoi(num);
    denominator = std::stoi(den);

    std::cout << "COMPLETE string_constructor" << std::endl;
}

bool Rational::validateString(const std::string& str) {
    std::cout << "BEGAN validate_string" << std::endl;

    // allowed characters: -/1234567890
    const std::regex pattern("[-/0-9]");

    std::cout << "COMPLETE validate_string" << std::endl;
    return std::regex_match(str, pattern);
}