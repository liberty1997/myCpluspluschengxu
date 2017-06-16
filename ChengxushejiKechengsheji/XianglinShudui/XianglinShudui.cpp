#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
int main(int argc, char * argv[]) {
	if(argc==1) {
		std::cerr<<"Usage: "<<argv[0]<<" filenames\n";
		exit(EXIT_FAILURE);
	}
	std::ifstream fileIn;
	for(int file=1;file<argc;file++) {
		int N;
		int count=0;
		fileIn.open(argv[file]);
		if(!fileIn.is_open()) {
			std::cerr<<"Could not open "<<argv[file]<<'\n';
			fileIn.clear();
			continue;
		}
		fileIn>>N;
		int A[N];
		for(int i=0;i<N;i++) {
			fileIn>>A[i];
		}
		fileIn.clear();
		fileIn.close();
		std::sort(A,A+N);
		for(int i=1;i<N;i++) {
			if(A[i]-A[i-1]==1) {
				count++;
			}
		}
		std::cout<<count<<std::endl;
	}
	return 0;
}
