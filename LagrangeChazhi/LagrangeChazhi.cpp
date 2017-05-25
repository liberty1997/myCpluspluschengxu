#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<float> a,b,l; // 点 基函数 的数组
	float s; // 求的函数值
	a={0.4,0.55,0.65,0.8,0.9,1.05};
	b={0.41075,0.57815,0.69675,0.88811,1.02652,1.25386};
	float x=0.596;
	for(int i=0;i<a.size();i++) {
		float aa=1,bb=1,ll=1;
		for(int j=0;j<b.size();j++) {
			if(i!=j) {
				aa*=(x-a[j]);
				bb*=(a[i]-a[j]);
			}
		}
		ll=aa/bb;
		l.push_back(ll);
	}
	for(auto i:a) {
		cout<<i<<' ';
	}
	cout<<endl;
	for(auto i:b) {
		cout<<i<<' ';
	}
	cout<<endl;
	for(int i=0;i<b.size();i++) {
		s+=(l[i]*b[i]);
	}
	cout<<"值: "<<s<<endl;
	return 0;
}
