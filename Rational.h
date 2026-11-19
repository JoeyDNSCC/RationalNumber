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
    explicit Rational(int num);
    Rational(int num, int den);
    explicit Rational(const std::string& str);

    Rational operator+(const Rational& rightObj) const;
    Rational operator-(const Rational& rightObj) const;
    Rational operator*(const Rational& rightObj) const;
    Rational operator/(const Rational& rightObj) const;

    bool operator<(const Rational& rightObj) const;
    bool operator>(const Rational& rightObj) const;
    bool operator==(const Rational& rightObj) const;

    const friend std::ostream& operator<<(std::ostream& output, const Rational& num);

    static bool validateString(const std::string& str);
};


#endif //RATIONAL_RATIONALNUMBER_H
