#include <iostream>
using namespace std;

class MyDate{
	int day;
	int month;
	int year;
	bool isValidDate(int days, int months, int years) const {
		if (months < 1 || months > 12 || days < 1 || years < 1 || days > 31 || isLeapYear(years) && months == 2 && days > 29 ||
			months == 2 && days > 28 || months <= 7 && months % 2 != 0 && days > 31 || 
			months > 7 && months % 2 != 0 && days > 30 || months <= 7 && months % 2 == 0 && days > 30 ||
			months > 7 && months % 2 == 0 && days > 31) {
			return false;
		}
		else {
			return true;
		}
	}
	bool isLeapYear(int year) const {
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	void changed_date() {
		while (day >= 31) {
			if (month == 2 && day > 28 || isLeapYear(year) && month == 2 && day > 29 || month <= 7 && month % 2 != 0 && day > 31 ||
				month > 7 && month % 2 == 0 && day > 31) {
				if (isLeapYear(year) && month == 2) {
					day -= 29;
					month += 1;
				}
				else if (month == 2) {
					day -= 28;
					month += 1;
				}
				else {
					day -= 31;
					month += 1;
				}
				if (month == 13) {
					month = 1;
					year += 1;
				}
			}
			else if (month > 7 && month % 2 != 0 && day > 30 || 
				month <= 7 && month % 2 == 0 && day > 30) {
				day -= 30;
				month += 1;
			}
			else if (month <= 7 && month % 2 != 0 && day == 31 ||
				month > 7 && month % 2 == 0 && day == 31) {
				break;
			}
		}
		while (day <= 0) {
			if (month <= 7 && month % 2 != 0 && day < 1 ||
				month > 7 && month % 2 == 0 && day < 1) {
				if (isLeapYear(year) && month == 2) {
					day += 29;
					month -= 1;
				}
				else if (month == 2) {
					day += 28;
					month -= 1;
				}
				else {
					day += 31;
					month -= 1;
				}
				if (month == 0) {
					month = 12;
					year -= 1;
				}
			}
			else if (month > 7 && month % 2 != 0 && day < 1 ||
				month <= 7 && month % 2 == 0 && day < 1) {
				day += 30;
				month -= 1;
			}
			else if (day == 0) {
				day = 1;
				break;
			}
		}
	}
public:
	MyDate() : day(1), month(1), year(2000) {}
	MyDate(int days, int months, int years) {
		if (isValidDate(days, months, years)) {
			day = days;
			month = months;
			year = years;
		}
		else {
			cout << "Error: Invalid date" << endl;
		}
	}
	MyDate& operator++ () {
		this->day += 1;
		changed_date();
		return *this;
	}
	MyDate& operator-- () {
		this->day -= 1;
		changed_date();
		return *this;
	}
	MyDate operator+ (int a) {
		this->day += a;
		changed_date();
		return *this;
	}
	MyDate operator- (int a) {
		this->day -= a;
		changed_date();
		return *this;
	}
	MyDate operator-= (int a) {
		this->day -= a;
		changed_date();
		return *this;
	}
	MyDate operator+= (int a) {
		this->day += a;
		changed_date();
		return *this;
	}
	bool operator< (const MyDate& obj1) const {
		return (year < obj1.year) || (year == obj1.year && (month < obj1.month || (month == obj1.month && day < obj1.day)));
	}
	bool operator> (const MyDate& obj1) const {
		return obj1 < *this;
	}
	bool operator<=(const MyDate& obj1) const {
		return !(obj1 < *this);
	}
	bool operator>=(const MyDate& obj1) const {
		return !(*this < obj1);
	}
	bool operator==(const MyDate& obj1) const {
		return day == obj1.day && month == obj1.month && year == obj1.year;
	}
	bool operator!=(const MyDate& obj1) const {
		return !(*this == obj1);
	}
	int getDay() const { 
		return day;
	}
	int getMonth() const { 
		return month;
	}
	int getYear() const {
		return year;
	}
	void setDay(int days) {
		if (isValidDate(days, month, year)) {
				day = days;
		}
		else {
			cout << "Error: Invalid day" << endl;
		}
	}

	void setMonth(int months) {
		if (isValidDate(day, months, year)) {
			month = months;
		}
		else {
			cout << "Error: Invalid month" << endl;
		}
	}

	void setYear(int years) {
		if (isValidDate(day, month, years)) {
			year = years;
		}
		else {
			cout << "Error: Invalid year" << endl;
		}
	}
	void print() const {
		cout << "Day: " << day << "\tMonth: " << month << "\tYear: " << year << endl;
	}
};

int main() {
	MyDate obj1(2, 2, 2000);
	MyDate obj2(3, 2, 2000);
	obj1.print();
	++obj1;
	obj1.print();
	obj1 += 51;
	obj1.print();
	obj1 = obj1 + 51;
	obj1.print();
	--obj1;
	obj1.print();
	obj1 -= 30;
	obj1.print();
	cout << std::boolalpha;
	cout << (obj1 == obj2) << endl;
}