//
// Created by wolph on 11/2/2026.
//

#ifndef RATIONAL_RATIONALNUMBER_H
#define RATIONAL_RATIONALNUMBER_H
#include <string>

class Rational {
    int numerator;
    int denominator;
public:
    Rational();
    Rational(int wholeNum);
    Rational(int num, int den);
    Rational(const std::string& str);

    Rational operator+(Rational &rightObj);
    Rational operator-(Rational &rightObj);
    Rational operator*(Rational &rightObj);
    Rational operator/(Rational &rightObj);

    Rational& operator=(Rational &rightObj);
    Rational& operator+=(Rational &rightObj);

    bool operator<(Rational &rightObj);
    bool operator>(Rational &rightObj);
    bool operator==(Rational &rightObj);

    friend std::ostream& operator<<(std::ostream& output, Rational& num);

    static bool validateString(const std::string& str);

};


#endif //RATIONAL_RATIONALNUMBER_H
