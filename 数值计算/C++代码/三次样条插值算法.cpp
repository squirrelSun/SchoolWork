#include<iostream>
#include<iomanip>
using namespace std;
const int max = 50;
float x[max], y[max], h[max];
float c[max], a[max], fxym[max];

float f(int x1, int x2, int x3){
    float a=(y[x3]-y[x2])/(x[x3]-x[x2]);
    float b=(y[x2]-y[x1])/(x[x2]-x[x1]);
    return (a-b)/(x[x3]-x[x1]);
} 

void cal_m(int n){             
    float B[max];
    B[0]=c[0]/2;
    for(int i=1;i<n;i++)
    B[i]=c[i]/(2-a[i]*B[i-1]);
    fxym[0]=fxym[0]/2;
    for(int i=1;i<=n;i++)
    fxym[i]=(fxym[i]-a[i]*fxym[i-1])/(2-a[i]*B[i-1]);
    for(int i=n-1;i>=0;i--)
    fxym[i]=fxym[i]-B[i]*fxym[i+1];
}

void printout(int n){
    cout<<setprecision(6);
    for(int i=0; i<n; i++){
        cout<<i+1<<": ["<<x[i]<<" , "<<x[i+1]<<"]\n"<<endl;
		cout<<"S"<<i+1<<"=";
        float t=fxym[i]/(6*h[i]);
        if(t>0) 
			cout<<-t<<"*(x-"<<x[i+1]<<")^3";
        else 
			cout<<-t<<"*(x-"<<x[i+1]<<")^3";
        t=fxym[i+1]/(6*h[i]);
        if(t > 0) 
			cout<<"+"<<t<<"*(x-"<<x[i]<<")^3";
        else 
			cout<<"-"<<t<<"*(x-"<<x[i]<<")^3";
        cout<<endl;
        t=(y[i]-fxym[i]*h[i]*h[i]/6)/h[i];
        if(t>0) 
			cout<<"-"<<t<<"*(x-"<<x[i+1]<<")";
        else 
			cout<<"-"<<-t<<"*(x-"<<x[i+1]<<")";
        t=(y[i+1]-fxym[i+1]*h[i]*h[i]/6)/h[i];
        if(t>0)
			cout<<"+"<<t<<"*(x-"<<x[i]<<")";
        else
			cout<<"-"<<-t<<"*(x-"<<x[i]<<")";
        cout<<endl;
    }
cout<<endl;
}
int main(){
    int n=3,i;
    char ch;
    for(i=0;i<=n;i++){
        cout<<"请输入 (x"<<i<<",y"<<i<<"):"<<endl;
        cin>>x[i]>>y[i]; 
	}
    for(i=0;i<n;i++)            
        h[i]=x[i+1]-x[i];
    cout<<"请输入边界条件\n 已知两端的导数阶数: "<<endl;
    int t;
    float f0, f1;
    cin>>t;
    switch(t){
		case 1:cout<<"输入 Y0\' Y"<<n<<"\'"<<endl;
			cin>>f0>>f1;
			c[0]=1;a[n]=1;
			fxym[0]=6*((y[1]-y[0])/(x[1]-x[0])-f0)/h[0];
			fxym[n]=6*(f1-(y[n]-y[n-1])/(x[n]-x[n-1]))/h[n-1];
			break;
        case 2:cout<<"输入 Y0\" Y"<<n<<endl;
			cin>>f0>>f1;
			c[0]=a[n]=0;
			fxym[0]=2*f0; 
			fxym[n]=2*f1;
			break;
        default:cout<<"不可用\n";
    };
    for(i=1;i<n;i++)
		fxym[i]=6*f(i-1,i,i+1);
    for(i=1;i<n;i++){
        a[i]=h[i-1]/(h[i]+h[i-1]);
        c[i]=1-a[i];
    }
    a[n]=h[n-1]/(h[n-1]+h[n]);
    cal_m(n);
    cout<<"三次样条插值函数为：";
    printout(n);
return 0;
}