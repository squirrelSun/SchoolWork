#include<iostream>
using namespace std;

int main(){
	double f(double xx, int k, double x[], double y[], int n); 
	double sum = 0;
	int n;
	cout << "请输入点的个数n:";
	cin >> n;
	double* x = (double*)malloc(n * sizeof(double));
	double* y = (double*)malloc(n * sizeof(double));
	double xx;
	int i;
	for (i = 0; i < n; i++){
		cout << "请输入(x" << i << ",y" << i << "):";
		cin >> x[i] >> y[i];
	}
	cout << "请输入插值点xx:";
	cin >> xx;
	for (i = 0; i < n; i++){
		sum = sum + f(xx, i, x, y, n) * y[i];
	}
	cout << "拉格朗日插值公式所得的结果：" << sum << endl;
	return 0;
}

double f(double xx, int k, double x[], double y[], int n) {
	int i;
	double t = 1;
	double s;
	for (i = 0; i < n; i++){
		if (i == k) continue;
		else s = (xx - x[i]) / (x[k] - x[i]);
		t = t * s;
	}
	return t;
}