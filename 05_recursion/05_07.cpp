//تابعی بازگشتی بنویسید که برداری به نام a را بگیرد و حاصل عبارت a[0] - a[1] + a[2] - … ± a[n-1] را برگرداند (علامت جمله آخر براساس زوج یا فرد بودن n تعیین می‌شود)
#include <iostream>
#include <vector>
using namespace std;

int calculate(vector<int>& v, int index = 0)
{
	if(index == v.size())
		return 0;
	else
	{
		if(index % 2 == 0)
			return v[index] + calculate(v, index + 1);
		else
			return -v[index] + calculate(v, index + 1);
	}
}

int main()
{
	vector<int> vec;
	int input;

	while(cin >> input)
		vec.push_back(input);

	cout << calculate(vec) << endl;

	return 0;
}
