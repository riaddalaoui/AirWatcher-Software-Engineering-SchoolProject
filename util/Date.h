#ifndef DATE_H
#define DATE_H

class Date {
public:
    int year, month, day, hour, minute, second;

    Date(int y, int m, int d, int h = 12, int min = 0, int s = 0)
        : year(y), month(m), day(d), hour(h), minute(min), second(s) {}

    bool operator<(const Date& other) const {
        if (year < other.year) return true;
        if (year == other.year && month < other.month) return true;
        if (year == other.year && month == other.month && day < other.day) return true;
        if (year == other.year && month == other.month && day == other.day && hour < other.hour) return true;
        if (year == other.year && month == other.month && day == other.day && hour == other.hour && minute < other.minute) return true;
        if (year == other.year && month == other.month && day == other.day && hour == other.hour && minute == other.minute && second < other.second) return true;
        return false;
    }

    bool operator>(const Date& other) const {
        return other < *this;
    }

    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day && hour == other.hour && minute == other.minute && second == other.second;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    bool operator>=(const Date& other) const {
        return *this > other || *this == other;
    }
};

#endif // DATE_H
