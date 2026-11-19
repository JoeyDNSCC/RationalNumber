#include <iostream>
#include "Rational.h"

using namespace std;
int main() {
    cout << "Welcome to Fractions 101" << endl;

    string firstInput;
    do {
        cout << "Please enter the first fraction:" << endl;
        getline(cin, firstInput);
    } while (Rational::validateString(firstInput));

    string secondInput;
    do {
        cout << "Please enter the second fraction:" << endl;
        getline(cin, secondInput);
    } while (Rational::validateString(secondInput));

    return 0;
}
