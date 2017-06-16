#include<iostream>
#include<ctype.h>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<map>
int main (int argc, char * argv[]) {
	using std::cout;
	using std::vector;
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
		std::vector<char> vc;
		std::map<std::string,int> wmap;
		std::vector<std::string> vstr;
		char s;
		while(fileIn.get(s)) {
			std::string str="";
			if((s>='a'&&s<='z')||(s<='Z'&&s>='A')) {
				s=tolower(s);
				vc.push_back(s);
			}
			else if((s==' '||s=='.'||s=='\n')&&!vc.empty()) {
				for(auto a:vc) str+=a;
				vstr.push_back(str);
				auto wm_iter=wmap.find(str);
				if(wm_iter==wmap.end()) {
					wmap.insert(std::pair<std::string,int>(str,1));
				}
				else {
					for(auto i=wmap.begin();i!=wmap.end();i++) {
						if(i->first==str) i->second+=1;
					}
				}
				vc.clear();
			}
		}
		fileIn.clear();
		fileIn.close();
		cout<<"----***filename["<<file<<"]: "<<argv[file]<<"***----"<<'\n';
		for(auto i=wmap.begin();i!=wmap.end();i++) {
			cout<<i->first<<' '<<i->second<<'\n';
		}
		cout<<"Sum:"<<vstr.size()<<endl;
	}
	return 0;
}
