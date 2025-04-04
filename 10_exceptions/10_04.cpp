//خطای دیگری که ممکن است در برنامه رخ دهد این است که طول نام دانشجو از ۲ کم‌تر باشد. برای این خطا یک کلاس استثنا تعریف کنید و به آن رسیدگی کنید. دقت کنید که برای یک بلوک try می‌توان چند بلوک catch داشت
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

class Bad_Date_Exception {};

class Invalid_Name{};

class Date {
public:
    Date(int d, int m, int y);
    void print();
private:
    int day;
    int month;
    int year;
};

bool is_leap_year(int y) {
    int r = y % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int days_of_month(int m, int y) {
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
	return 666;
}

Date::Date(int d, int m, int y) {
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > days_of_month(m, y)) {
        throw Bad_Date_Exception();
    }
    day = d;
    month = m;
    year = y;
}

void Date::print() {
    cout << year << '/' << month << '/' << day;
}

class Student {
public:
    Student(string n, Date bd) : name(n), bdate(bd) {
	if(n.size() < 2)
		throw Invalid_Name();
	}
    void print() { cout << name << '\t'; bdate.print(); }
private:
    string name;
    Date bdate;
};

Date read_date(ifstream& input) {
    int d, m, y;
    char ch;
    input >> d;
    input >> ch;
    if (ch != '/') {
        throw Bad_Date_Exception();
    }
    input >> m;
    input >> ch;
    if (ch != '/') {
        throw Bad_Date_Exception();
    }
    input >> y;
    return Date(d, m, y);
}

Student read_student(ifstream& input) {
    string name;
	if(name.size() < 2)
		throw Invalid_Name();
    input >> name;
	Date bdate(0, 0, 0);
	try 
	{
    	Date bdate = read_date(input);
	} 
	catch(Bad_Date_Exception e)
	{
		return Student(name, Date(1, 1, 1));
	}
	catch (Invalid_Name e) 
	{
		return Student("null", bdate);
	}

    return Student(name, bdate);
}

void read_student_info(char* filename, vector<Student>& v) {
    ifstream input(filename);
    int count;
    input >> count;
    for (int i = 0; i < count; i++) {
        try {
            Student s = read_student(input);
            v.push_back(s);
        } catch (Bad_Date_Exception ex) {
            cerr << "Error in line #" << (i+1) << endl;
        }
		catch (Invalid_Name e) {
			cerr << "Invalid name in line #" << (i+1) << endl;
		}
    }
}

void do_some_processing(vector<Student>& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i].print();
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    vector<Student> students;
    read_student_info(argv[1], students);
    do_some_processing(students);
}
