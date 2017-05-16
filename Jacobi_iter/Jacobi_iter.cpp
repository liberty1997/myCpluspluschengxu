#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int t=0;
	float a=0,b=0,c=0,d=0; // d为1-范数
	float a1,b1,c1,d1=0;
	while(true) {
		cout<<"x1="<<a<<"  x2="<<b<<"  x3="<<c<<endl;
		d=a+b+c;
		a1=0.1*b+0.2*c+0.72;
		b1=0.1*a+0.2*c+0.83;
		c1=0.2*a+0.2*b+0.84;
		d1=a1+b1+c1;
		t++;
		if(fabs(d1-d)<0.5*pow(10,-2)) {
			// 输出迭代结束的这次的x值
			cout<<"x1="<<a1<<"  x2="<<b1<<"  x3="<<c1<<endl;
			cout<<"----------------------"<<endl;
			cout<<"次数:  "<<t<<endl;
			cout<<"x1="<<a<<"  x2="<<b<<"  x3="<<c<<endl;
			break;
		}
		else {
			a=a1;b=b1;c=c1; // 更新abc
		}
	}
	return 0;
}
