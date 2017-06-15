#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>
#include<fstream>
using namespace std;
int main() {
	ifstream fileIn("LeastSquareFittingData2.txt");
	int N,M; // 拟合方程的阶数和数据点数
	fileIn>>M;
	vector<float> A,B,a; // 保存点和系数的数组
	for(int i=0;i<M;i++) {
		float a,b;
		fileIn>>a>>b;
		A.push_back(a);
		B.push_back(b);
	}
	fileIn>>N;
	vector<vector<float> > L(N+1); // 进行最小二乘的矩阵
	for(int i=0;i<N+1;i++) {
		L[i].resize(N+2);
	}
	fileIn.close();
	// 以上为读取文本文件中的信息
	// 写入矩阵 求中间的矩阵
	for(int i=0;i<N+1;i++) {
		int ii=i*2;
		for(int j=i;j<N+1;j++) {
			float x=0;
			for(int k=0;k<A.size();k++) {
				x+=(pow(A[k],ii));
			}
			L[i][j]=x;
			ii+=1;
		}
	}
	for(int i=1;i<N+1;i++) {
		for(int j=0;j<i;j++) {
			L[i][j]=L[j][i];
		}
	}
	//			求最后一列
	for(int i=0;i<N+1;i++) {
		for(int j=0;j<A.size();j++) {
			L[i][N+1]+=(pow(A[j],i)*B[j]);
		}
	}
	for(int i=0;i<N+1;i++) {
		for(int j=0;j<N+2;j++) {
			cout<<L[i][j]<<' ';
		}
		cout<<endl;
	}
	// 高斯消元
	for(int k=0;k<N;k++) {
		for(int r=k+1;r<N+1;r++) {
			float t=L[r][k]/L[k][k];
			for(int c=k;c<N+2;c++) {
				L[r][c]-=(t*L[k][c]);
			}
		}
	}
	// 回代 求拟合方程系数
	a.push_back(L[N][N+1]/L[N][N]);
	for(int k=N-1;k>=0;k--) {
		float t=0.0,tt=0;
		for(int i=N;i>k;i--) {
			t+=(L[k][i]*a[tt]);
			tt++;
		}
		a.push_back((L[k][N+1]-t)/L[k][k]);
	}
	cout<<"方程:\ny="<<a[a.size()-1];
	int t=1;
	// 2017/06/15 更新了下面格式化输出的语句
	// 更多用法参见C++ Primer Plus
	for(int i=a.size()-2;i>=0;i--) {
		cout.setf(ios_base::showpos);
		cout<<a[i]<<"x^";
		cout.unsetf(ios_base::showpos);
		cout<<t;
		t++;
	} 
	cout<<endl;
	return 0;
}
