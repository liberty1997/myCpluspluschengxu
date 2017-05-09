#include<iostream>
using namespace std;

int main() {
    int R,C; // 行列
	float **A; // 增广矩阵
	float X[C-1]; // 解
    cout<<"请输入行数和列数(eg:3 4)"<<endl;
	cin>>R; cin>>C;
	A=new float*[R];
	for(int i=0;i<R;i++) {
		A[i]=new float[C];
	}
	cout<<"请输入线性方程组的增广矩阵:"<<endl;
    cout<<"Example:"<<endl;
    cout<<"2  8  2 14"<<endl;
    cout<<"1  6 -1 13"<<endl;
    cout<<"2 -1  2  5"<<endl;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
			cin>>A[i][j];
        }
    }
	cout<<endl;
	cout<<"-----消元:-----"<<endl;
	for(int k=0;k<C-2;k++) {
		for(int r=k+1;r<R;r++) {
			float t=A[r][k]/A[k][k];
			for( int c=k;c<C;c++) {
				A[r][c]=A[r][c]-t*A[k][c];
			}
		}
	    for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {	
				cout<<A[i][j]<<"   ";
		}
			cout<<endl;
		}
		cout<<"---------------"<<endl;
    }
	cout<<endl;
	cout<<"-----回代:-----"<<endl;
	X[C-2]=A[R-1][C-1]/A[R-1][C-2];
	for(int k=C-3;k>=0;k--) {
		float t=0;
		for(int i=C-2;i!=k;i--) {
			t=t+A[k][i]*X[i];
		}
		X[k]=(A[k][C-1]-t)/A[k][k];
	}
	for(int i=0;i<C-1;i++) {
		cout<<"X"<<i+1<<"= "<<X[i]<<"  ";
	}
	cout<<endl;
    return 0;
}
