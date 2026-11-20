#include "Rational.h"

#include <iostream>


using namespace std;
int main() {
    bool endProgram = false;
    while (!endProgram) {
        cout << "\n\nWelcome to Fractions 101" << endl;

        string firstInput;
        bool isValid;
        bool isCreated;
        Rational fraction1;

        do {
            cout << "\nPlease enter the first fraction:" << endl;
            getline(cin, firstInput);

            isValid = Rational::validateString(firstInput);
            isCreated = false;

            if (isValid) {
                try {
                    fraction1 = Rational(firstInput);
                    isCreated = true;
                }
                catch (runtime_error&) {
                    cout << "cannot divide by 0" << endl;
                    isCreated = false;
                }
                catch (out_of_range&) {
                    cout << "thats a whole lotta number for this little program" << endl;
                    isCreated = false;
                }
                catch (exception&) {
                    isCreated = false;
                }
            } else {
                cout << "Invalid input, must be a non-decimal rational number" << endl;
            }

        } while (!isValid || !isCreated);

        string secondInput;
        Rational fraction2;
        do {
            cout << "\nPlease enter the second fraction:" << endl;
            getline(cin, secondInput);

            isValid = Rational::validateString(secondInput);
            isCreated = false;

            if (isValid) {
                try {
                    fraction2 = Rational(secondInput);
                    isCreated = true;
                }
                catch (runtime_error&) {
                    cout << "cannot divide by 0" << endl;
                    isCreated = false;
                }
                catch (out_of_range&) {
                    cout << "that's a whole lotta number for this little program" << endl;
                    isCreated = false;
                }
                catch (exception&) {
                    isCreated = false;
                }
            }

        } while (!isValid || !isCreated);

        cout << "\nYou entered " << fraction1;
        cout << " and " << fraction2;
        cout << "\n" << endl;

        auto result = Rational();

        cout << " --- ADDITION --- " << endl;
        result = fraction1 + fraction2;
        cout << fraction1;
        cout << " + " << fraction2;
        cout << " = " << result;
        cout << "\n" << endl;

        cout << " --- SUBTRACTION --- " << endl;
        result = fraction1 - fraction2;
        cout << fraction1;
        cout << " - " << fraction2;
        cout << " = " << result;
        cout << "\n" << endl;

        cout << " --- MULTIPLICATION --- " << endl;
        result = fraction1 * fraction2;
        cout << fraction1;
        cout << " * " << fraction2;
        cout << " = " << result;
        cout << "\n" << endl;

        cout << " --- DIVISION --- " << endl;
        if (fraction2.Numerator() != 0) {
            result = fraction1 / fraction2;
            cout << fraction1;
            cout << " / " << fraction2;
            cout << " = " << result;
        } else {
            cout << "cannot divide by 0" << endl;
        }
        cout << "\n" << endl;

        cout << " --- LESS THAN --- " << endl;
        bool compResult = fraction1 < fraction2;
        cout << fraction1;
        if (compResult) {
            cout << " is less than " << fraction2;
        } else {
            cout << " is not less than " << fraction2;
        }
        cout << "\n" << endl;

        cout << " --- GREATER THAN --- " << endl;
        compResult = fraction1 > fraction2;
        cout << fraction1;
        if (compResult) {
            cout << " is greater than " << fraction2;
        } else {
            cout << " is not greater than " << fraction2;
        }
        cout << "\n" << endl;

        cout << " --- EQUIVALENT --- " << endl;
        compResult = fraction1 == fraction2;
        cout << fraction1;
        if (compResult) {
            cout << " is equal to " << fraction2;
        } else {
            cout << " is not equal to " << fraction2;
        }
        cout << "\n" << endl;


        cout << " --- DEFAULT CONSTRUCTOR --- " << endl;
        Rational test1;
        cout << test1;
        cout << "\n" << endl;

        cout << " --- ONE ARG CONSTRUCTOR --- " << endl;
        auto test2 = Rational(5);
        cout << test2;
        cout << "\n" << endl;

        cout << " --- TWO ARG CONSTRUCTOR --- " << endl;
        auto test3 = Rational(3, 7);
        cout << test3;
        cout << "\n" << endl;

        cout << "Enter \"X\" to end program, enter anything to continue";
        string exit;
        getline(cin, exit);
        if (exit == "x" || exit == "X") endProgram = true;
    }
    return 0;
}
