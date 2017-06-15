#include<iostream>
#include<ctype.h>
#include<vector>
#include<fstream>
#include<map>
int main () {
	using std::cout;
	using std::vector;
	using std::endl;
	//ifstream fileIn("tyut.txt");
	std::ifstream fileIn("python_tutorial.txt");
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
	fileIn.close();
	for(auto i=wmap.begin();i!=wmap.end();i++)
		cout<<i->first<<' '<<i->second<<endl;
	cout<<"Sum:"<<vstr.size()<<endl;
	return 0;
}
