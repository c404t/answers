
//فرض کنید در رشته‌ی مورد نظر، کاراکترهای غیرحرفی هم وجود دارند که نباید در محاسبه‌ی آینه‌ای بودن در نظر گرفته شوند. همچنین، حروف بزرگ و کوچک هم یکسان در نظر گرفته می‌شوند. با این تعریف رشته‌ی “Madam, I'm Adam” آینه‌ای محسوب می‌شود. تابع palindrome2 را به شکل بازگشتی بنویسید که با تعریف جدید آینه‌ای بودن را تعیین کند
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

bool palindrome(string& word, int start, int end)
{
	if(start >= end)
		return true;
	while(start < end && !isalnum(word[start]))
	{
		start++;
	}
	while(end > start && !isalnum(word[end]))
	{
		end--;
	}

	if(tolower(word[start]) != tolower(word[end]))
		return false;
	else
		return palindrome(word, start + 1, end - 1);	
}

int main()
{
	string m = "boft fj eowim";
	string n = "wGogW, w!! gOg. w?";
	string _word;

	cout << boolalpha << "is " << m << " palindrome? " << palindrome(m, 0, m.size() - 1) << endl;
	cout << boolalpha << "is " << n << " palindrome? " << palindrome(n, 0, n.size() - 1) << endl;

	cout << "enter a word to test: ";
	cin >> _word;
	cout << boolalpha << "is " << _word << " palindrome? " << palindrome(_word, 0, _word.size() - 1) << endl;

	return 0;
}
