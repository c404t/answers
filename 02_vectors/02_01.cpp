//برداری از کاراکترها تعریف کنید که در ابتدا به اندازه‌ی ۱۰۰ کاراکتر جا داشته باشد که همه‌ی آنها با کاراکتر A مقداردهی اولیه شده‌اند
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> data(100, "A");
	cout << data[3] << endl;
	cout << data[99] << endl;
	try
	{
		cout << data[103] << endl;
	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
