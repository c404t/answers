//نظیر سؤال قبل تابعی بازگشتی بنویسید که یک عدد را دریافت کرده ارقام آن را برعکس کند و برگرداند. مثلاً با دریافت ۳۵۱، عدد ۱۵۳ را برگرداند. در نوشتن این تابع از بردار یا رشته استفاده نکنید
#include <iostream>
using namespace std;

int reverse(int& no)
{
	int reversed_number = 0;
	while (no > 0) {
		int last_digit = no % 10; //get the last digit
		//multiple the existing new number by 10 and add the extracted digit
		reversed_number = (reversed_number * 10) + last_digit;
		no /= 10; //remove last digit (nnnn).n
	}
	return reversed_number;
}

int main()
{
	int number;
	cin >> number;

	cout << reverse(number);

	return 0;
}
