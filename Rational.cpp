#include "Rational.h"

#include <regex>
#include <stdexcept>
#include <iostream>




Rational::Rational()
    :numerator(0), denominator(1) {
    std::cout << "default_constructor" << std::endl;
}

Rational::Rational(const int num)
    :numerator(num), denominator(1) {
    std::cout << "one_arg_constructor" << std::endl;
}

Rational::Rational(const int num, const int den)
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
    if (den != "0") {
        denominator = std::stoi(den);
    } else throw std::runtime_error("ERROR: cannot divide by 0");

    std::cout << "COMPLETE string_constructor" << std::endl;
}

bool Rational::validateString(const std::string& str) {
    std::cout << "BEGAN validate_string" << std::endl;

    // allowed characters: -/1234567890
    const std::regex pattern("[-/0-9]");

    std::cout << "COMPLETE validate_string" << std::endl;
    return std::regex_match(str, pattern);
}

Rational Rational::operator+(const Rational& rightObj) const {
    int numLeft = this->numerator;
    int numRight = rightObj.numerator;
    int denLeft = this->denominator;
    int denRight = rightObj.denominator;

    if (denLeft != denRight) {
        numLeft *= denRight;
        numRight *= denLeft;
        denLeft *= denRight;
        denRight = denLeft;
    }
    numLeft += numRight;

    const int gcd = std::__gcd(numLeft,denLeft);
    numLeft /= gcd;
    denLeft /= gcd;

    return {numLeft,denLeft};
}

Rational Rational::operator-(const Rational& rightObj) const {
    int numLeft = this->numerator;
    int numRight = rightObj.numerator;
    int denLeft = this->denominator;
    int denRight = rightObj.denominator;

    if (denLeft != denRight) {
        numLeft *= denRight;
        numRight *= denLeft;
        denLeft *= denRight;
        denRight = denLeft;
    }
    numLeft -= numRight;

    const int gcd = std::__gcd(numLeft,denLeft);
    numLeft /= gcd;
    denLeft /= gcd;

    return {numLeft,denLeft};

}

Rational Rational::operator*(const Rational& rightObj) const {
    int numTemp = this->numerator;
    int denTemp = this->denominator;

    numTemp *= rightObj.numerator;
    denTemp *= rightObj.denominator;

    const int gcd = std::__gcd(numTemp, denTemp);
    numTemp /= gcd;
    denTemp /= gcd;

    return {numTemp, denTemp};
}

Rational Rational::operator/(const Rational& rightObj) const {
    int numTemp = this->numerator;
    int denTemp = this->denominator;

    numTemp *= rightObj.denominator;
    denTemp *= rightObj.numerator;

    const int gcd = std::__gcd(numTemp, denTemp);
    numTemp /= gcd;
    denTemp /= gcd;

    return {numTemp, denTemp};
}

