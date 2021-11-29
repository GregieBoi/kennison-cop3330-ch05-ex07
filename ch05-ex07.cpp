/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 McGreggor Kennison
 */

#include "std_lib_facilities.h"

// calculates value inside sqaure root
double calcDiscriminant(double a, double b, double c) {

    // initialize discriminant
    double discriminant;

    // calculate discriminant
    discriminant = (b * b) - (4 * a * c);

    // check if discriminant is less than 0
    if (discriminant < 0) {

        // if less than 0 print no real roots
        cout << "No real roots\n";

    }

    // return discriminant
    return discriminant;

}

// prints output
void printOutput(double root1, double root2, int rootFlag) {

    // check if flag = 1
    if (rootFlag == 1)

        // print roots seperated by comma
        cout << root1 << ", " << root2 << "\n";
    
    // else
    else

        // print singular root
        cout << root1 << "\n";

}

// solves for roots
void solve() {

    // initialize variables
    double a, b, c, root1 = 0, root2 = 0;
    int rootFlag = 0;

    // print input prompt and scan input
    cout << "Please enter the variables a, b, and c of your quadratic seperated by spaces (ex. 1 2 3): ";
    cin >> a >> b >> c;

    // set discriminant to return of calcDiscriminant
    double discriminant = calcDiscriminant(a, b, c);

    // check if discriminant is > 0
    if (discriminant > 0) {

        // print two real roots
        cout << "Two real roots: ";

        // calculate roots and set rootFlag to 1
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        rootFlag = 1;

    }

    // check if discriminant is 0
    else if (discriminant == 0) {

        // print one real root
        cout << "One real root: ";
    
        // calculate singular root
        root1 = (-b) / (2 * a);

        // check if root1 is -0
        if (root1 == -0)

            // set root1 to 0 so it doesn't print -0 later
            root1 = 0;

    }

    // else
    else {

        // throw error for no real roots
        error("input results in non real roots");

    }

    // call print output
    printOutput(root1, root2, rootFlag);

}

// main
int main() {

    // call solve
    solve();

}