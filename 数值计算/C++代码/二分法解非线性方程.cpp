#include<iostream>
using namespace std;
#define ep 1e-5

int main(){
	double f(double x);
	double f1, f2, f3, a, b, c;
	cout << "二分法求方程x^3-x-1=0的根" << endl;
	cout << "求根区间为(1,2)" << endl;
	a = 0, b = 5;
	f1 = f(a);
	f2 = f(b);
	while ((b - a) > ep){
		c = (a + b) / 2;
		f3 = f(c);
		if (f3 == 0)
			break;
		else if (f3 * f2 < 0){
			a = c;
			f1 = f3;
		}else{
			b = c;
			f2 = f3;
		}
	}
	cout << "方程的根为:x=" << c << endl;
}
double f(double x) {
	return x * x * x - x - 1;
}