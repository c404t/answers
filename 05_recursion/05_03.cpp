//تابعی بازگشتی بنویسید که یک بردار از اعداد صحیح را به عنوان ورودی بگیرد و حاصل جمع اعداد مثبت آن را برگرداند.
#include <iostream>
#include <vector>
using namespace std;

int sum_list(vector<int>& v, int head = 0)
{
	if(head == v.size())
		return 0;
	else
		return v[head] + sum_list(v, head + 1);
}

int main()
{
	vector<int> vec;
	int input;

	while(cin >> input)
		vec.push_back(input);
	
	cout << "sum = " << sum_list(vec) << endl;
	return 0;
}
