// <<C++ Primer Plus>> P121
#include<iostream>
#include<vector> // STL C++98
#include<array> // C++11

int main() {
	using namespace std;
	// C, original C++
	double a1[4]={1.2,2.4,3.6,4.8};
	// C++98 STL
	vector<double> a2(4); // creat vector with 4 elements
	// 不能将上一行的小括号换成方括号!
	// no simple way to initialize in C98
	a2[0]=1.0/3.0;
	a2[1]=1.0/5.0;
	a2[2]=1.0/7.0;
	a2[3]=1.0/9.0;
	// C++11 -- creat and initialize array object
	array<double, 4> a3={3.14, 2.72, 1.62, 1.41};
	array<double, 4> a4;
	a4=a3; // valid for array objects of same size
	// use array notation
	cout<<"a1[2]: "<<a1[2]<<" at "<<&a1[2]<<endl;
	cout<<"a2[2]: "<<a2[2]<<" at "<<&a2[2]<<endl;
	cout<<"a3[2]: "<<a3[2]<<" at "<<&a3[2]<<endl;
	cout<<"a4[2]: "<<a4[2]<<" at "<<&a4[2]<<endl;
	// misdeed 违法行为
	a1[-2]=20.2;
	// 上一行代码将被转换为
	// *(a1-2)=20.2;
	// 即:找到a1指向的地方,向前移两个double元素,并将20.2存到目的地
	// C和C++不会检查这种越界错误
	cout<<"a1[-2]: "<<a1[-2]<<" at "<<&a1[-2]<<endl;
	cout<<"a3[2]: "<<a3[2]<<" at "<<&a3[2]<<endl;
	cout<<"a4[2]: "<<a4[2]<<" at "<<&a4[2]<<endl;
	return 0;
}
