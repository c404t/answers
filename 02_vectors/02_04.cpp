//تابع بالا را طوری تغییر دهید که اگر بیشترین تعداد تکرار متعلق به چند عدد باشد تمام این اعداد را برگرداند. (به این ترتیب، تایپ بازگشتی این تابع از نوع vector خواهد بود.) 
#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> most_frequent(vector<int> v)
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
	unordered_set<int> most_frequent_numbers;
	for(size_t i = 0; i < size; ++i)
	{
		int c = count(v.begin(), v.end(), v.at(i));
		if(c == max)
		{
			most_frequent_numbers.insert(v.at(i));
		}
	}
	return most_frequent_numbers;
}

int main()
{
	vector<int> vec = {2, 2, 3, 4, 8, 8, 3, 2, 14, 8};
	unordered_set<int> lst = most_frequent(vec);
	for(const auto& element : lst)
		cout << element << " ";
	return 0;
}
