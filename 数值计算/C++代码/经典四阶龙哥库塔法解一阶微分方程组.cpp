#include <iostream>
#include <iomanip>
using namespace std;

double Runge_Kuta(double(*f)(double x, double y), double x0, double y0, double xn, int step){
	double k1, k2, k3, k4, result;
	double h = (xn - x0) / step;
	if (step <= 0)
		return(y0);
	if (step == 1){
		k1 = f(x0, y0);
		k2 = f(x0 + h / 2, y0 + h * k1 / 2);
		k3 = f(x0 + h / 2, y0 + h * k2 / 2);
		k4 = f(x0 + h, y0 + h * k3);
		result = y0 + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}else{
		double x1, y1;
		x1 = xn - h;
		y1 = Runge_Kuta(f, x0, y0, xn - h, step - 1);
		k1 = f(x1, y1);
		k2 = f(x1 + h / 2, y1 + h * k1 / 2);
		k3 = f(x1 + h / 2, y1 + h * k2 / 2);
		k4 = f(x1 + h, y1 + h * k3);
		result = y1 + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}
	return(result);
}

int main(){
	double f(double x, double y); double x0, y0;
	double a, b;
	cout << "请输入初值x0  y0: "<<endl;
	cin >> x0 >> y0;
	cout << "请输入区间："<<endl;
	cin >> a >> b;
	double x, step;
	cout << "请输入步长："<<endl;
	cin >> step;
	cout.precision(10);
	for (int i = 0; i <= (b - a) / step; i++){
		x = x0 + i * step;
		cout << endl << setw(8) << x << setw(18) << Runge_Kuta(f, x0, y0, x, i) << endl;
	}
	return(0);
}

double f(double x, double y){
	double r;
	r = (x - y) / 2;
	return (r);
}