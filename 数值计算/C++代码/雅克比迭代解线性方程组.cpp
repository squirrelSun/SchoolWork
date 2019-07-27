#include <iostream>
#include <cmath>
using namespace std;
#define e 0.000001
#define n 4
#define M 100  

int main(){
	int i, j, k;
	double err, norm, A[n][n], b[n], P[n], X[n];   
	cout << "请输入系数矩阵A:" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> A[i][j];
	cout << "请输入列向量b:" << endl;
	for (i = 0; i < n; i++)
		cin >> b[i];
	cout << "请输入矩阵P:" << endl;
	for (i = 0; i < n; i++)
		cin >> P[i];
	for (k = 0; k < M; k++){
		for (j = 0; j < n; j++){
			X[j] = b[j];
			for (i = 0; i < n; i++)
				X[j] = X[j] - A[j][i] * P[i];
			X[j] = (X[j] + A[j][j] * P[j]) / A[j][j];
		}
		norm = 0;
		for (i = 0; i < n; i++)
			norm = norm + pow((X[i] - P[i]), 2);
		norm = pow(norm, 0.5);
		err = fabs(norm);             
		for (i = 0; i < n; i++)
			P[i] = X[i];
		if (err < e)
			goto loop;
	}
loop:cout << "得到X=" << endl;
	for (i = 0; i < n; i++)
		cout << X[i] << endl;
	system("pause");
	return 0;
}