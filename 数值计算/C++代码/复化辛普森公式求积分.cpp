#include <iostream> 
#include <cmath> 
using namespace std; 
double f(double x);
double simpse(double a,double b,double n);

int main(){
	double a,b,n,s;
	cout << " ������������� [a,b]:" << endl;
	cin >> a >> b; 
	cout << " ����ȷַ��� n:" << endl;
	cin >> n;
	cout << " �ɸ�������ɭ��ʽ��ý��Ϊ��  "<<endl;	
	s = simpse(a, b, n);
	cout << s;
	return 0;
} 

double f(double x){
	double y;
	y = 4 / (1 + x * x * x);
	return (y);
} 

double simpse(double a, double b, double n){
	double h = (b - a) / n;
	double x, s1 = 0, s2 = 0;
	for (int k = 1; k < n; k++){
		x = a + h * k;
		s1 = s1 + f(x);
	}
	for (int k = 0; k < n; k++){
		x = a + h * (k + 1 / 2);
		s2 = s2 + f(x);
	}
	double s = (f(a) + 2 * s1 + 4 * s2 + f(b)) * h / 6;
	return s;
}