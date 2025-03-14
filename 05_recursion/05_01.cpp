//یک تابع «غیربازگشتی» بنویسید که با دریافت یک عدد صحیح، مجموع ارقام آن را برگرداند (مثلاً با دریافت ۳۵۱ مقدار ۹ را برگرداند).
#include <iostream>
using namespace std;

int main()
{
	unsigned long long int number;
	int sum = 0;
	cin >> number;

	do
	{
		int digit = number % 10; //nnn.(n)
		sum += digit;
		number/=10; //(nnn).n
	}
	while(number>0);

	cout << sum << endl;

	return 0; 
}
