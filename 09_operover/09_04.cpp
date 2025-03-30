//یک کلاس به نام Rational برای نگهداری اعداد گویا (کسری) تعریف کنید. برای این کلاس انواع عملگرهای محاسباتی را تعریف کنید. مثال‌هایی از این عملگرها می‌تواند چهارعمل اصلی، عملگرهای جایگزینی متناظر آنها (مانند =+)، عملگر درج در خروجی و عملگر تساوی (==) باشد. عملگرهای محاسباتی (مانند جمع) را در سه شکل Rational + Rational، Rational + double و double + Rational تعریف کنید. برای این کلاس دو سازنده تعریف کنید که یکی صورت و مخرج و دیگری فقط صورت را می‌گیرد و مخرج را یک فرض می‌کند
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class rational
{
	private:
		int p; //numerator
		int q; //denominator
	public:
		rational(int p, int q);
		rational(int p) : p(p), q(1) {}
		rational& operator++();
		rational operator++(int);
		rational& operator--();
		rational operator--(int);
		rational& operator+=(const rational& n);
		rational& operator-=(const rational& n);
		friend rational operator+(rational lhs, const rational& rhs);
		friend rational operator-(rational lhs, const rational& rhs);
		friend rational operator+(rational lhs, int rhs);
		friend rational operator-(rational lhs, int rhs);
		friend ostream& operator<<(ostream& os, const rational& n);
		friend istream& operator>>(istream& is, rational& n);
		inline bool operator==(const rational& n);
};

rational::rational(int p, int q) : p(p), q(q) 
{
	if(q == 0)
		throw overflow_error("error");
}

rational& rational::operator++() 
{
	p = p + q;
	return *this;
}

rational rational::operator++(int)
{
	rational old = *this;
	operator++();
	return old;
}

rational& rational::operator--() 
{
	p = p - q;
	return *this;
}

rational rational::operator--(int)
{
	rational old = *this;
	operator--();
	return old;
}

rational& rational::operator+=(const rational& n)
{
	p = ((p * n.q) + (n.p * q));
	q = (q * n.q);
	return *this;
}

rational& rational::operator-=(const rational& n)
{
	p = ((p * n.q) - (n.p * q));
	q = (q * n.q);
	return *this;
}

rational operator+(rational lhs, const rational& rhs)
{
	lhs += rhs;
	return lhs;
}

rational operator-(rational lhs, const rational& rhs)
{
	lhs -= rhs;
	return lhs;
}

rational operator+(rational lhs, int rhs)
{
	lhs += rational(rhs);
	return lhs;
}

rational operator-(rational lhs, int rhs)
{
	lhs -= rational(rhs);
	return lhs;
}

ostream& operator<<(ostream& os, const rational& n)
{
	return os << n.p << "/" << n.q;
}

istream& operator>>(istream& is, rational& n)
{
	std::string input;
	if (getline(is, input, '\n')) {
		size_t slashPos = input.find('/');
		if (slashPos != std::string::npos) {
			n.p = std::stoi(input.substr(0, slashPos));
			n.q = std::stoi(input.substr(slashPos + 1));
		} else {
			is.setstate(ios::failbit);
		}
	}
	return is;	
}

inline bool rational::operator==(const rational& n)
{
	return (p * n.q == n.p * q);
}

int main()
{
	rational number = rational(0);
	cout << "enter a rational number: ";
	cin >> number;
	cout << "you have entered " << number << "! " << endl;
	rational inc = number+3;
	cout << number << "+3 = " << inc << endl;
	rational dc = number-2;
	cout << number << "-2 = " << dc << endl;
	cout << "is number equal to 2/3? " << ((number+1)==rational(2, 3)) << endl;
	return 0;
}

