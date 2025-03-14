//یک رشته آینه‌ای است اگر خواندن آن از سمت چپ و راست یکسان باشد. مثلاً کلمه‌ی madam. تابعی بازگشتی به نام palindrome بنویسید که یک رشته را بگیرد و در صورتی که آینه‌ای باشد مقدار true وگرنه false برگرداند. در این مرحله فرض کنید این رشته فقط از حروف الفبا تشکیل شده است
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool palindrome(string& word, int start, int end)
{
	if(start >= end)
		return true;
	if(tolower(word[start]) != tolower(word[end]))
		return false;
	else
		return palindrome(word, start + 1, end - 1);	
}

int main()
{
	string m = "boft";
	string n = "wGogW";
	string _word;

	cout << boolalpha << "is " << m << " palindrome? " << palindrome(m, 0, m.size() - 1) << endl;
	cout << boolalpha << "is " << n << " palindrome? " << palindrome(n, 0, n.size() - 1) << endl;

	cout << "enter a word to test: ";
	cin >> _word;
	cout << boolalpha << "is " << _word << " palindrome? " << palindrome(_word, 0, _word.size() - 1) << endl;

	return 0;
}
