#include<iostream>
#include<stdio.h> 
#include<math.h> 
double f(double x){
	return x * x;
}

int main(){
	int M = 1, n = 0, p = 0, K = 0, i = 0, j = 0, J = 0;
	double h = 0.0, a = 0.0, b = 0.0, err = 1.0, quad = 0.0, s = 0.0, x = 0.0, tol = 0.0;
	double R[30][30] = { 0 };
	a = 0;
	b = 1;
	h = b - a;
	n = 4;
	tol = 0.00001;
	printf("��⺯��y=x^2��(0,1)�ϵ����������\n");
	printf("����������������Ϊ%d\n�����Ϊ%lf\n", n, tol);
	R[0][0] = h * (f(a) + f(b)) / 2;
	while (((err > tol) && (J < n)) || (J < 4)){
		J = J + 1;
		h = h / 2;
		s = 0;
		for (p = 1; p <= M; p++){
			x = a + h * (2 * p - 1);
			s = s + f(x);
		}
		R[J][0] = R[J - 1][0] / 2 + h * s;
		M = 2 * M;
		for (K = 1; K <= J; K++){
			R[J][K] = R[J][K - 1] + (R[J][K - 1] - R[J - 1][K - 1]) / (4 * K - 1);
		}
		err = fabs(R[J - 1][J - 1] - R[J][K]);
	}
	quad = R[J][J];
	printf("\n���������Ϊ:\n");
	for (i = 0; i < (J + 1); i++){
		for (j = 0; j < (J + 1); j++){
			printf("%.5lf ", R[i][j]);
		}
		printf("\n");
	}
	printf("\n����ֵΪ:quad=%lf", quad);
	printf("\n������Ϊ:err=%lf", err);
	printf("\nʹ�ù�����С����h=%lf\n", h);
	system("pause:");
	return 0;
}