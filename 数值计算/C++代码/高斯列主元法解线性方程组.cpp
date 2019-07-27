#include<iostream>
using namespace std;
const int n = 4;	

void guass(double a[n][n],double b[n]) {
	double m;	
	for (int i = 0;i<n ; i++){		
		for (int j = 1; j < n-i ; j++){
			m = a[i + j][i] / a[i][i];		
			for (int k = 0; k < n; k++){
				a[i + j][k] = a[i + j][k] - m * a[i][k];	
			}
			b[i + j] = b[i + j] - m * b[i];		
		}
	}
	double x[n] = { 0,0,0,0 };
	double k = 0;
	for (int i = 4; i > 0; i --) {	
		k = b[i - 1];
		for (int j = 0; j <n-i; j++) {
			k = k - x[n-j-1] * a[i-1][n-j-1];
		}
		x[i-1] = k / a[i-1][i-1];
	}
	cout<<"方程组解为："<<endl;
	for (int i = 0; i < 4; i++) {
		cout << "x" << i + 1 << "=" << x[i] << endl;
	}
}
int  main() {
	double a[n][n], b[n];
	cout << "请输入系数矩阵A:" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	cout << "请输入列向量b:" << endl;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	guass(a, b);
	return 0;
}