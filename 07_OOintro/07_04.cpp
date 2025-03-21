//هدف این تمرین طراحی کلاسی به نام Time است که همان طور که از نام آن پیداست، قرار است برای ذخیره کردن زمان استفاده می‌شود
#include <iostream>
#include <cstdlib>
#include <boost/algorithm/string.hpp> //for to_lower() in main()
using namespace std;

class Time
{
	public:
		Time(int hour, int minute);
		Time(int hour);
		bool is_valid(int hour, int minute);
		void set_time(int hour, int minute);
		int compare(Time time);
		string daytime();
		//getters
		int get_hour() { return hour; }
		int get_minute() { return minute; }
	private:
		int hour;
		int minute;
};

Time::Time(int hour, int minute)
{
	if(!is_valid(hour, minute)) abort(); 
	
	this->hour = hour;
	this->minute = minute;
}

Time::Time(int hour)
{
	if(!is_valid(hour, minute)) abort(); 
	
	this->hour = hour;
	this->minute = 0;
}

bool Time::is_valid(int hour, int minute)
{
	return (hour > 0 && hour < 24 && minute > 0 && minute < 60);
}

void Time::set_time(int hour, int minute)
{
	if(!is_valid(hour, minute)) abort();
	this->hour = hour;
	this->minute = minute;
}

int Time::compare(Time time)
{
	if(hour < time.get_hour()) return -1;
	if(hour > time.get_hour()) return 1;

	if(minute < time.get_minute()) return -1;
	if(minute > time.get_minute()) return 1;

	return 0;
}

string Time::daytime()
{
	if(hour > 19) return "night";
	else if(hour > 17) return "evening";
	else if(hour == 12 && minute == 0) return "noon";
	else if(hour >= 12) return "afternoon";
	else return "morning";
}

int main()
{
	int hour, minute;
	string answer;
start:
	cout << "enter hour: ";
	cin >> hour;
	cout << "enter minute: ";
	cin >> minute;

	Time time(hour, minute);

	cout << "your time is " << time.get_hour() << ":" << time.get_minute() << endl;
	cout << "do you want to modify the time you entered? (y/n): ";
	cin >> answer;
	if((boost::to_lower_copy(string(answer)) == "y") || (boost::to_lower_copy(string(answer)) == "yes"))
		goto start;

	cout << "it's " << time.daytime() << endl;

	return 0;
}
