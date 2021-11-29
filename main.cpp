/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Brooks McKinley
 */

#include "std_lib_facilities.h"

class NoRealRoots {};
class BadQuadratic {};

void printRoots(double a, double b, double c);

int main(void) {
    double a, b, c;
    cout << "Enter the values for a, b, and c separated by a space:";
    cin >> a >> b >> c;
    try {
        printRoots(a, b, c);
    } catch (NoRealRoots) {
        cout << "No real roots for this function!" << endl;
    } catch (BadQuadratic) {
        cout << "That function is not a quadratic equation!" << endl;
    }
}

void printRoots(double a, double b, double c) {
    double discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0) {
        throw NoRealRoots{};
    }
    // If a == 0, the equation is linear, not a quadratic!
    if (a == 0) {
        throw BadQuadratic{};
    }

    double quadraticPlus = (-1 * b + sqrt(discriminant)) / (2 * a);
    double quadraticMinus = (-1 * b - sqrt(discriminant)) / (2 * a);

    // If the discriminant is zero, there's only one solution
    if (abs(discriminant) < 0.000001) {
        cout << "The root for the equation " << a << "x^2 + " << b << "x + " << c << " is " << quadraticPlus << endl;
    } else {
        cout << "The roots for the equation " << a << "x^2 + " << b << "x + " << c << " are " << quadraticPlus <<
            " and " << quadraticMinus << endl;
    }
}