#include<iostream>
#include<cmath>
#define N 2      
#define ep 0.0001  
#define max  100       
using namespace std;
const int N2 = 2 * N;

int main(){
	void ff(double xx[N], double yy[N]);
	void ffjacobi(double xx[N], double yy[N][N]);
	void inv_jacobi(double yy[N][N], double inv[N][N]);
	void newdun(double x0[N], double inv[N][N], double y0[N], double x1[N]);
	double x0[N] = { 2.0,0.25 }, y0[N], jacobi[N][N], invjacobi[N][N], x1[N], fanshu;
	int i, nargin = 0;
	cout << "初始解向量为：" << endl;
	for (i = 0; i < N; i++)
		cout << x0[i] << "  "<<endl;
	do{
		nargin = nargin + 1;
		ff(x0, y0);
		ffjacobi(x0, jacobi);
		inv_jacobi(jacobi, invjacobi);
		newdun(x0, invjacobi, y0, x1);
		fanshu = 0;
		for (i = 0; i < N; i++)
			fanshu = fanshu + fabs(x1[i] - x0[i]); 
		if (fanshu < ep)
			break;
		for (i = 0; i < N; i++)
			x0[i] = x1[i];
	} while (nargin < max);
	cout << "近似解向量：" << endl;
	for (i = 0; i < N; i++)
		cout << x1[i] << "  " << endl;
	return 0;
}

void ff(double xx[N], double yy[N])  {
	double x, y;
	int i;
	x = xx[0];
	y = xx[1];
	yy[0] = x * x - 2 * x - y + 0.5;
	yy[1] = x * x + 4 * y * y - 4;
}

void ffjacobi(double xx[N], double yy[N][N]){ 
	double x, y;
	int i, j;
	x = xx[0];
	y = xx[1];
	yy[0][0] = 2 * x - 2;
	yy[0][1] = -1;
	yy[1][0] = 2 * x;
	yy[1][1] = 8 * y;
}

void inv_jacobi(double yy[N][N], double inv[N][N]){
	float aug[N][N2], L;
	int i, j, k;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			aug[i][j] = yy[i][j];
		for (j = N; j < N2; j++)
			if (j == i + N) aug[i][j] = 1;
			else aug[i][j] = 0;
	}
	for (i = 0; i < N; i++){
		for (k = i + 1; k < N; k++){
			L = -aug[k][i] / aug[i][i];
			for (j = i; j < N2; j++)
				aug[k][j] = aug[k][j] + L * aug[i][j];
		}
	}
	for (i = N - 1; i > 0; i--){
		for (k = i - 1; k >= 0; k--){
			L = -aug[k][i] / aug[i][i];
			for (j = N2 - 1; j >= 0; j--)
				aug[k][j] = aug[k][j] + L * aug[i][j];
		}
	}
	for (i = N - 1; i >= 0; i--)
		for (j = N2 - 1; j >= 0; j--)
			aug[i][j] = aug[i][j] / aug[i][i];
	for (i = 0; i < N; i++){
		for (j = N; j < N2; j++)
			inv[i][j - N] = aug[i][j];
	}
}

void newdun(double x0[N], double inv[N][N], double y0[N], double x1[N]){
	int i, j;
	double sum = 0;
	for (i = 0; i < N; i++){
		sum = 0;
		for (j = 0; j < N; j++)
			sum = sum + inv[i][j] * y0[j];
		x1[i] = x0[i] - sum;
	}
}