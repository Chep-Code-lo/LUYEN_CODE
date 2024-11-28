#include <iostream>
using namespace std;
bool is_Leap_Year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

}
int days(int month, int year) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_Leap_Year(year))
        return 29;
    return days[month];
}

bool is_Valid_Date(int day, int month, int year) {
    if (month < 1 || month > 12)
        return false;
    return day >= 1 && day <= days(month, year);

}

void get_Next_Day(int day, int month, int year) {
    day++;
    if (day > days(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
	        month = 1;
            year++;

        }
    }
	cout << day << " " << month << " " << year << "\n";
}

void get_Previous_Day(int day, int month, int year) {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = days(month, year);
    }
	cout << day << " " << month << " " << year << "\n";
}
int d, m, y;
int main() {
    cin >> d >> m >> y;
    if (!is_Valid_Date(d, m, y))		cout << "KHONG HOP LE" <<"\n";
    else {

        cout << "HOP LE" << "\n";
        cout << (m-1)/3 + 1 << "\n";
        cout << days(m, y) << "\n";
        get_Next_Day(d, m, y);
        get_Previous_Day(d, m, y);
    }

}

