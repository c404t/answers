//تابعی بازگشتی بنویسید که یک بردار از اعداد صحیح را به عنوان ورودی بگیرد و تعداد اعداد مثبت آن را برگرداند
#include <iostream>
#include <vector>
using namespace std;

int count_pos(vector<int> v, int index = 0)
{
	if(index == v.size())
		return 0;
	else
	{
		if(v[index] > 0)
			return 1 + count_pos(v, index + 1);
		else
			return count_pos(v, index + 1);
	}
}

int main()
{
	vector<int> vec;
	int input;

	while(cin >> input)
		vec.push_back(input);
	
	cout << "number of positive numbers: " << count_pos(vec) << endl;
	return 0;
}
