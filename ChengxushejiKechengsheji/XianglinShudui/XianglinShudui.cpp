#include<iostream>
#include<fstream>
#include<algorithm>
int main() {
	using std::cout;
	using std::endl;
	using std::ifstream;
	using std::sort;
	ifstream fileIn("XianglinShu_data1.txt");
	int N;
	int A[N];
	int count=0;
	fileIn>>N;
	for(int i=0;i<N;i++) {
		fileIn>>A[i];
	}
	fileIn.close();
	sort(A,A+N);
	for(int i=1;i<N;i++) {
		if(A[i]-A[i-1]==1) {
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
