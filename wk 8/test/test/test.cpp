#include <iostream>
#include <cmath>
using namespace std;
const double pi=3.14;

int main(){
	double t,u,q,n,e,r0;
	double e0=1.6e-19;
	double d=5e-3;
	double rou=981;
	double ita=1.83e-5;
	double s=0.0016;
	double g=9.794;
	double b=0.00823;
	double p=101325;
	double eAvg;
	int sumn2=0;
	double sumnq=0;
	double sumde=0;
	int n2[10]={0};
	double nq[10]={0};
	double de[10]={0};
	
	double qs[10]={0};
	double ns[10]={0};
	double es[10]={0};
	for (int i=1;i<=10;++i){
		cout << "please input U, t:" << endl;
		cin >> u >> t;
		r0=sqrt(9*ita*s/(2*g*rou*t));
		q=9*sqrt(2)*pi*d*sqrt(1/(rou*g))*(ita*s/(t*(1+b/(r0*p))))*sqrt(ita*s/(t*(1+b/(r0*p))))/u;
		qs[i-1]=q;
		cout << "q=" << q << endl;
		n= int(q/e0+0.5);
		ns[i-1]=n;
		cout << "n=" << n << endl;
		e=q/n;
		es[i-1]=e;
		cout << "e=" << e << endl;
		n2[i-1]=n*n;
		sumn2+=n2[i-1];
		nq[i-1]=n*q;
		sumnq+=nq[i-1];
	}
	eAvg=sumnq/sumn2;
	cout << "eAvg=" << eAvg << endl;
	for (int i=1;i<=10;++i){
		de[i-1]=sqrt(((qs[i-1]/ns[i-1])-eAvg)*((qs[i-1]/ns[i-1])-eAvg)/(9));
		sumde+=de[i-1];
	}
	cout << "de=" << sumde << endl;
	cout << "E0=" << (fabs(eAvg-e0)/e0) * 100 << "%" << endl;
	return 0;
} 
