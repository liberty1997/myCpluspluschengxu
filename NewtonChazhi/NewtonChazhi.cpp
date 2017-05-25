#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<float> a,b,c; // 点的数组和差商的数组
	float N;
	a={0.4,0.55,0.65,0.8,0.9,1.05};
	b={0.41075,0.57815,0.69675,0.88811,1.02652,1.25386};
	float x=0.596;
	N=b[0];
	for(int i=1;i<a.size();i++) {
		// 求i阶差商
		float p=0;
		for(int j=0;j<i+1;j++) {
			float C=1;
			for(int k=0;k<i+1;k++) {
				if(j!=k)
					C*=(a[j]-a[k]);
			}
			p+=(b[j]/C);
		}
		c.push_back(p);
	}
	for(int i=0;i<c.size();i++) {
		cout<<c[i]<<endl;
	}
	for(int i=0;i<c.size();i++) {
		float t=1;
		for(int j=0;j<i+1;j++) {
			t*=(x-a[j]);
		}
		N+=(t*c[i]);
	}
	cout<<"N="<<N<<endl;
	return 0;
}
