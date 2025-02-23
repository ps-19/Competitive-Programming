class Solution {
    bool isLeap(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
    const string week[7] = {"Thursday", "Friday",  "Saturday", "Sunday", "Monday",   "Tuesday", "Wednesday"};
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days = 0;
        for (int i = 1971; i < year; i++) {
            if (isLeap(i)) {
                days += 366;
            } else {
                days += 365;
            }
        }
        for (int i = 1; i < month; i++) {
            if (i == 2) {
                if (isLeap(year)) {
                    days += 29;
                } else {
                    days += 28;
                }
            }
            else if (i == 4 || i == 6 || i == 9 || i == 11) days += 30;
            else days += 31;
        }
        days += day;
        return week[days % 7];
    }
};
