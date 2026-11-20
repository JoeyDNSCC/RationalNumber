#include "Rational.h"

#include <regex>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <numeric>


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

    if (den != 0) {
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
    if (ss.peek() != EOF) {
        std::getline(ss, den);  // grab the rest
    }

    numerator = std::stoi(num);
    if (std::stoi(den) != 0) {
        denominator = std::stoi(den);
    } else throw std::runtime_error("ERROR: cannot divide by 0");

    std::cout << "COMPLETE string_constructor" << std::endl;
}

bool Rational::validateString(const std::string& str) {
    std::cout << "BEGAN validate_string" << std::endl;

    // allowed characters: -/1234567890
    const std::regex pattern(R"(-?[0-9]+(/-?[0-9]+)?)");

    std::cout << "COMPLETE validate_string" << std::endl;
    return std::regex_match(str, pattern);
}

Rational Rational::operator+(const Rational& rightObj) const {
    std::cout << "BEGAN addition_operator" << std::endl;
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

    const int gcd = std::gcd(numLeft,denLeft);
    numLeft /= gcd;
    denLeft /= gcd;
    if (denLeft < 0) {
        numLeft = -numLeft;
        denLeft = -denLeft;
    }

    std::cout << "COMPLETE addition_operator" << std::endl;
    return {numLeft,denLeft};
}

Rational Rational::operator-(const Rational& rightObj) const {
    std::cout << "BEGAN subtraction_operator" << std::endl;
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

    const int gcd = std::gcd(numLeft,denLeft);
    numLeft /= gcd;
    denLeft /= gcd;
    if (denLeft < 0) {
        numLeft = -numLeft;
        denLeft = -denLeft;
    }
    std::cout << "COMPLETE subtraction_operator" << std::endl;
    return {numLeft,denLeft};

}

Rational Rational::operator*(const Rational& rightObj) const {
    std::cout << "BEGAN multiplication_operator" << std::endl;
    int numTemp = this->numerator;
    int denTemp = this->denominator;

    numTemp *= rightObj.numerator;
    denTemp *= rightObj.denominator;

    const int gcd = std::gcd(numTemp, denTemp);
    numTemp /= gcd;
    denTemp /= gcd;
    if (denTemp < 0) {
        numTemp = -numTemp;
        denTemp = -denTemp;
    }

    std::cout << "COMPLETE multiplication_operator" << std::endl;
    return {numTemp, denTemp};
}

Rational Rational::operator/(const Rational& rightObj) const {
    std::cout << "BEGAN division_operator" << std::endl;

    if (rightObj.numerator == 0) {
        throw std::runtime_error("ERROR: cannot divide by zero");
    }

    int numTemp = this->numerator;
    int denTemp = this->denominator;

    numTemp *= rightObj.denominator;
    denTemp *= rightObj.numerator;

    const int gcd = std::gcd(numTemp, denTemp);
    numTemp /= gcd;
    denTemp /= gcd;
    if (denTemp < 0) {
        numTemp = -numTemp;
        denTemp = -denTemp;
    }

    std::cout << "COMPLETE division_operator" << std::endl;
    return {numTemp, denTemp};
}

bool Rational::operator<(const Rational &rightObj) const {
    std::cout << "less_than_operator" << std::endl;
    return static_cast<double>(this->numerator) / this-> denominator < static_cast<double>(rightObj.numerator) / rightObj.denominator;
}

bool Rational::operator>(const Rational &rightObj) const {
    std::cout << "greater_that_operator" << std::endl;
    return static_cast<double>(this->numerator) / this-> denominator > static_cast<double>(rightObj.numerator) / rightObj.denominator;

}

bool Rational::operator==(const Rational &rightObj) const {
    std::cout << "equivalence_operator" << std::endl;
    if (this->numerator * rightObj.denominator == this->denominator * rightObj.numerator) return true;
    return false;
}

const std::ostream &operator<<(std::ostream &output, const Rational &num)
{
    const int wholeNum = num.numerator / num.denominator;
    const int remainder = num.numerator % num.denominator;
    output << wholeNum << "+" << remainder << "/" << num.denominator;
    return output;
}

int Rational::Numerator() const {
    return numerator;
}
