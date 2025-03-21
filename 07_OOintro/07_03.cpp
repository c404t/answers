//با فرض این که ۱ فروردین ۱ جمعه است، متدی به کلاس تاریخ به نام day_of_week اضافه کنید که مشخص کند تاریخ مربوطه چه روزی از هفته است. مقدار که این تابع برمی‌گرداند یکی از رشته‌های "sun"، "sat" تا "fri" است
#include <iostream>
#include <cstdlib>
#include <algorithm> //for swap function in days_between()
#include <vector>
using namespace std;

bool is_leap_year(int year)
{
	int r = year % 33;
	return (r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30);
}

int days_of_month(int m, int y)
{
	if (m < 7)
		return 31;
	else if (m < 12)
		return 30;
	else if (m == 12)
		return is_leap_year(y) ? 30 : 29;
	else
		abort();
}

class date
{
	public:
		date(int d, int m, int y);
		void set_date(int d, int m, int y);
		void print_date();
		bool invalid(int d, int m, int y);
		void inc_one_day();
		int compare(date date);
		bool equals(date date);
		string days_of_week(); //1st of farvardin is friday
		//getters
		int get_day() { return day; }
		int get_month() { return month; }
		int get_year() { return year; }
	private:
		int day;
		int month;
		int year;
};

date::date(int d, int m, int y) : day(d), month(m), year(y) {}

bool date::invalid(int d, int m, int y)
{
	//return true if date is invalid
	//following conditions show invalid days
	return (
			year < 0 || 
			m < 1 || m > 12	||
			d < 1 ||
			d > days_of_month(m, y)
		   );
}

void date::set_date(int d, int m, int y)
{
	if(invalid(d, m, y))
		abort();
	day = d;
	month = m;
	year = y;
}

void date::print_date()
{
	cout << day << "/" << month << "/" << year;
}

void date::inc_one_day()
{
	day++;
	if (day > days_of_month(month, year)) {
		day = 1;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}

int date::compare(date date)
{
	if (year < date.get_year()) return -1;
	if (year > date.get_year()) return 1;

	if (month < date.get_month()) return -1;
	if (month > date.get_month()) return 1;

	if (day < date.get_day()) return -1;
	if (day > date.get_day()) return 1;
	
	return 0;
}

bool date::equals(date date)
{
	return day == date.day && month == date.month && year == date.year;
}

int days_between(date d1, date d2)
{
	if(d1.compare(d2) == 1) swap(d1, d2);
	int count = 1;
	while(!d1.equals(d2))
	{
		d1.inc_one_day();
		count++;
	}
	return count;
}

string date::days_of_week()
{
	vector<string> days = {"fri", "sat", "sun", "mon", "tue", "wed", "thu"};
	int distance = days_between(date(1, 1, 1404), date(day, month, year));
	return days[distance%7];
}

int main()
{
	cout << date(8, 1, 1404).days_of_week() << endl;
}
