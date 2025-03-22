//تابعی به نام most_frequent بنویسید که یک بردار از اعداد صحیح را بگیرد و عددی را برگرداند که بیشترین تعداد تکرار را داشته است. اگر بیشترین تعداد تکرار متعلق به چند عدد بود یکی را به دلخواه برگرداند
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int most_frequent(vector<int> v)
{
	int most_frequent_number = *(v.begin()); //* extracts the value from v.being() iter
	int max = 0;
	int size = v.size();
	for(size_t i = 0; i < size; ++i)
	{
		int c = count(v.begin(), v.end(), v.at(i));
		if(c > max)
		{
			max = c;
			most_frequent_number = v.at(i);
		}
	}
	return most_frequent_number;
}

int main()
{
	vector<int> vec = {2, 2, 3, 4, 8, 8, 3, 2, 14};
	cout << most_frequent(vec) << endl;
	return 0;
}
