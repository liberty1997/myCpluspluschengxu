#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int N; // 阶数
	float **A; // N阶系数矩阵
	float *B,*X,*Y; // b/解/Y
	ifstream fileIn("LU_data.txt");
	fileIn>>N;
	B=new float[N];
	X=new float[N];
	Y=new float[N];
	A=new float*[N];
	for(int i=0;i<N;i++) {
		A[i]=new float[N];
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			fileIn>>A[i][j];
		}
	}
	for(int i=0;i<N;i++) {
		fileIn>>B[i];
	}
	cout<<"-----分解 消元-----"<<endl;
	// 处理第一列
	for(int i=1;i<N;i++){
		A[i][0] = A[i][0] / A[0][0];
	}
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j++) {
			float t = 0;
			for(int t1=0;t1<i;t1++) {
				t+=(A[i][t1]*A[t1][j]);
			}
			A[i][j]-=t;
		}
		for(int k=i+1;k<N;k++) {
			float l = 0;
			for(int t2=0;t2<i;t2++) {
				l+=(A[k][t2]*A[t2][k-1]);
			}
			A[k][i]=(A[k][i]-l)/A[i][i];
		}
		for(int i1=0;i1<N;i1++) {
			for(int j1=0;j1<N;j1++) {
				cout<<A[i1][j1]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<"-----回代 求解-----"<<endl;
	// 求Y
	Y[0] = B[0];
	for(int i=1;i<N;i++) {
		float t = 0;
		for(int j=0;j<i;j++) {
			t+=(Y[j]*A[i][j]);
		}
		Y[i]=B[i]-t;
	}
	// 求X
	for(int k=N-1;k>=0;k--) {
		float a = 0;
		for(int j=N-1;j>k;j--) {
			a+=A[k][j]*X[j];
		}
		X[k]=(Y[k]-a)/A[k][k];
	}
	// Output
	for(int i=0;i<N;i++) {
		cout<<"X"<<i+1<<"= "<<X[i]<<endl;
	}
	return 0;
}
