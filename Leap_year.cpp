// Problem link:https://practice.geeksforgeeks.org/problems/leap-year0943/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include <iostream>
using namespace std;

int isLeap(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1;  // The year is a leap year
    } else {
        return 0;  // The year is not a leap year
    }
}

bool Leap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

int main() {
    int year = 2024;

    // Testing the first approach
    cout << "First approach: " << isLeap(year) << endl;

    // Testing the second approach
    cout << "Second approach: " << isLeap(year) << endl;

    return 0;
}
