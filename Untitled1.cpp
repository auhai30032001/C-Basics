#include<iostream>
#include<cmath>
using namespace std;
class tong{
	private :
		int a;
		int b;
		int c;
		public :
			tong();
			tong cong();
			void input();
			void output();
};

tong :: tong ()
{
	a = 2;
	b = 4;
}

tong tong :: cong()
{
	return tong(a+b);
}
int main()
{
tong x;

x.cong();
	

}
