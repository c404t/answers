//در صورتی که بخواهیم برداری ۲۶تایی از کاراکترها داشته باشیم که با کاراکترهای A تا Z مقداردهی شده باشند چگونه آن را تعریف می‌کنیم؟ آیا می‌توان این‌گونه مقداردهی اولیه را یک‌جا انجام داد
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	vector<char> letters(26);
	iota(letters.begin(), letters.end(), 'A');
	
	for(char letter : letters)
		cout << letter << endl;

	return 0;
}
