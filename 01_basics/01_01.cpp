//برنامه‌ای بنویسید که با نمایش پیغام مناسبی، یک عدد را که واحد آن اینچ فرض می‌شود از ورودی دریافت کند و آن را به سانتی‌متر تبدیل کرده در خروجی بنویسد
#include <iostream>
using namespace std;

float cm(float inch)
{
	float cm = 2.54*inch;
	return cm;
}

int main()
{
	float inch;
	cout << "how many inches? ";
	cin >> inch;
	cout << "that's " << cm(inch) << "cm bro!" << endl;
	return 0;
}
