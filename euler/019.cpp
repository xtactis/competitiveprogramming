#include <bits/stdc++.h>
using namespace std;

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int dow = 0;
    int day = 0;
    int month = 0;
    int year = 1900;
    int t = 0;
    while (year < 1901) {
        dow = (dow + 1) % 7;
        ++day;
        // ugly
        if (isleap(year) && month == 1) {
            if (day == months[month]+1) {
                day = 0;
                ++month;
            } 
        } else {
            if (day == months[month]) {
                day = 0;
                ++month;
            }
        }
        if (month == 12) {
            month = 0;
            ++year;
        }
    }
    int ans = 0;
    while (year < 2001) {
        if (dow == 6 && day == 0) ++ans;
        dow = (dow + 1) % 7;
        ++day;
        // ugly
        if (isleap(year) && month == 1) {
            if (day == months[month]+1) {
                day = 0;
                ++month;
            } 
        } else {
            if (day == months[month]) {
                day = 0;
                ++month;
            }
        }
        if (month == 12) {
            month = 0;
            ++year;
        }
    }
    printf("%d", ans);
    return 0;
}