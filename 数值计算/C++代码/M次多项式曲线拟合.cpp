#include<iostream>
#include<cmath>
#define N 20
using namespace std;

void inv(double X[N][N], int n, double E[N][N]){
	int i, j, k;
	double temp = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			if (i == j)
				E[i][j] = 1;
	}
	for (i = 0; i < n - 1; i++){
		temp = X[i][i];
		for (j = 0; j < n; j++){
			X[i][j] = X[i][j] / temp;
			E[i][j] = E[i][j] / temp;
		}
		for (k = 0; k < n; k++){
			if (k == i)
				continue;
			temp = -X[i][i] * X[k][i];
			for (j = 0; j < n; j++){
				X[k][j] = X[k][j] + temp * X[i][j];
				E[k][j] = E[k][j] + temp * E[i][j];
			}
		}
	}
}

int main(){
	int n, M, i, j, k;
	double X[N] = { 0 }, Y[N] = { 0 }, F[N][N] = { 0 }, B[N] = { 0 };
	double A[N][N] = { 0 }, BF[N][N] = { 0 }, C[N] = { 0 }, E[N][N] = { 0 };
	cout << "M�ζ���ʽ�����������" << endl;
	cout << "�����������ϵ�ĸ���:";
	cin >> n;
	cout << "\n������" << n << "�����X��������:\n";
	for (i = 0; i < n; i++)
		cin >> X[i];
	cout << "\n������" << n << "�����Y��������:\n";
	for (i = 0; i < n; i++)
		cin >> Y[i];
	cout << "\n��������Ҫ��ϵĴ���:";
	cin >> M;
	for (i = 0; i < n; i++)
		for (k = 1; k <= M + 1; k++)
			F[i][k - 1] = pow(X[i], k - 1);
	for (i = 0; i < n; i++){
		for (j = 0; j < M + 1; j++){
			BF[j][i] = F[i][j];
		}
	}
	for (i = 0; i < M + 1; i++)
		for (j = 0; j < M + 1; j++)
			for (k = 0; k < n; k++)
				A[i][j] += BF[i][k] * F[k][j];
	for (i = 0; i < M + 1; i++)
		for (j = 0; j < n; j++)
			B[i] += BF[i][j] * Y[j];
	inv(A, n, E);
	for (i = 0; i < M + 1; i++)
		for (j = 0; j < n; j++)
			C[i] += E[i][j] * B[j];
	cout << "\n��Ϻ��" << M << "�ζ���ʽϵ��Ϊ���ݴ��ɸߵ��ͣ�\n";
	for (i = M; i >= 0; i--)
		cout << C[i] << "\t";
	cout << "\n��Ϻ��" << M << "�ζ���ʽΪ:\n";
	cout << "\nP(x)=";
	for (i = M; i >= 0; i--){
		if (i == 0){
			if (C[i] >= 0)
				cout << "+" << C[i];
			else
				cout << C[i];
		}else{
			if (C[i] >= 0)
				cout << "+" << C[i] << "*x^" << i;
			else
				cout << C[i] << "*x^" << i;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}