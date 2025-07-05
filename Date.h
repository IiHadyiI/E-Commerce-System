#ifndef DATE_H_
#define DATE_H_

#include <iostream>

struct Date {
    int day;
    int month;
    int year;

    bool operator<(const Date& other) const {
        if (year != other.year)  return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
};

#endif