//برنامه‌ای بنویسید که تعدادی کلمه را از ورودی بخواند و آن‌ها را در قالب یک لیست که با کاما جدا شده‌اند چاپ کند
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_data(const vector<string>& data)
{
	cout << "[";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i];
        if (i < data.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
	vector<string> data;

	string entery;
	cout << "enter words: " << endl;
	while(cin >> entery)
		data.push_back(entery);

	print_data(data);

	return 0;
}
