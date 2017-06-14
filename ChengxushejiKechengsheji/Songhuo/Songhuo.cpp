#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
int main() {
	using std::cout;
	using std::endl;
	using std::vector;
	using std::ifstream;
	const int INF=999;
	ifstream fileIn("songhuo_data.txt");
	int N,M,a,b,k; // a b 辅助输入
	fileIn>>N>>M;
	vector<vector<int> > Matrix(N);
	vector<int> dir;
	for(int i=0;i<N;i++) {
		Matrix[i].resize(N);
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			Matrix[i][j]=0;
		}
	}
	// 矩阵初始化: 有路为1,无路为0,走过为2
	while(fileIn>>a>>b) {
		Matrix[a-1][b-1]=1; // 点的编号是从一开始的
		Matrix[b-1][a-1]=1;	// 所以直接用ab作下标减个1
	}
	k=0; // 从点1开始
	dir.push_back(k);
	// 每走过一条边,就把矩阵中对应的值+1
	// 搜寻邻接边过程中,如果一个点的邻接边都走过了
	// 即对应的矩阵那行都是0或2,则说明不存在符合的路径
	for(int j=0;j<M;j++) {
		for(int i=0;i<N;i++) {
			if(i==N-1&&(Matrix[k][i]==0||Matrix[k][i]==2)) {
				cout<<"-1"<<endl;
				dir.push_back(-1);
				return 0;
			}
			if(Matrix[k][i]==1) {
				dir.push_back(i);
				Matrix[k][i]+=1;
				Matrix[i][k]+=1;
				k=i;
				break;
			}
		}
	}
	if(dir.back()!= -1) {
		for(auto i:dir) cout<<i+1<<' ';
	}
	cout<<endl;
	return 0;
}
