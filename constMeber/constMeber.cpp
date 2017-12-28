#include <iostream>
#include <string>

using namespace std;

class Date
{
	public:
		Date(int y=1990, int m=1, int d = 1):y(y),m(m),d(d){}
		
		int day() const
		{
			return d;
		}

		int month() const
		{
			return m;
		}

		int year () const
		{
			return y;
		}

		void add_year(int n)
		{
			y += n;
		}

		void add_day(int n)
		{
			d += n;
		}

		void add_mon(int n)
		{
			m += n;
		}

		void mul_change(int b) const
		{
			mul = b*b;
		}
		
		int mult() const
		{
			return mul +7;
		}
	private:
		int d, m, y;
		mutable int mul;
};

void fun(Date& d, const Date& cd)
{
	int dd = d.day();
	d.add_mon(dd+1);

	int cm = cd.year();
	//cd.add_year(4);	//const cant be changed
	
	d.mul_change(5);	// multable member can be change in const funtction
	cd.mul_change(5);
	cout <<dd<<"," << cm<<", "<<d.mult()<<","<<cd.mult() <<endl;
}

int main()
{
	Date d,cd;
	fun(d,cd);
	return 0;
}

