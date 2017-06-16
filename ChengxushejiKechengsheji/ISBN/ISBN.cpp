#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
int main(int argc, char * argv[]) {
	using std::cout;
	using std::endl;
	if(argc==1) {
		std::cerr<<"Usage: "<<argv[0]<<" filename[s]"<<'\n';
		exit(EXIT_FAILURE);
	}
	std::ifstream fileIn;
	for(int file=1;file<argc;file++) {
		fileIn.open(argv[file]);
		if(!fileIn.is_open()) {
			std::cerr<<"Could not open "<<argv[file]<<'\n';
			fileIn.clear();
			continue;
		}
		std::vector<std::string> vecs;
		std::string s;
		while(fileIn>>s) {
			vecs.push_back(s);
		}
		for(int i=0;i<vecs.size();i++) {
			int num=0,m,ii=0;
			for(int j=0;j<vecs[i].size()-1;j++) {
				if(vecs[i][j]!='-') {
					ii+=1;
					num+=((int(vecs[i][j])-48)*ii);
				}
			}
			m=num%11;
			if((m==(int(vecs[i][12])-48))||(m==10&&vecs[i][12]=='X')) {
				cout<<"Right"<<endl;
			}
			else {
				vecs[i][12]=(m==10?'X':char(m+48));
				cout<<vecs[i]<<endl;
			}
		}
		fileIn.clear();
		fileIn.close();
	}
	return 0;
}
