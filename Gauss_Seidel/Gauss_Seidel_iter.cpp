#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main() {
	int t=0;
	float a=0,b=0,c=0,d=0; // d为2-范式
	while(true) {
		cout<<"x1="<<a<<" x2="<<b<<" x3="<<c<<endl;
		float a1=a,b1=b,c1=c;
		d=sqrt(a*a+b*b+c*c);
		a=0.1*b+0.2*c+0.72;
		b=0.1*a+0.2*c+0.83;
		c=0.2*a+0.2*b+0.84;
		float d1=sqrt(a*a+b*b+c*c);
		t++;
		if(fabs(d1-d)<0.5*pow(10,-2)) {
			cout<<"次数: "<<t<<endl;
			printf("x1=%.2f, x2=%.2f, x3=%.2f\n",a,b,c);
			break;
		}
	}
	return 0;
}
