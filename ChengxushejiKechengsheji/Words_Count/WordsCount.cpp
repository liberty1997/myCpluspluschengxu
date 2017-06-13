#include<iostream>
#include<ctype.h>
#include<vector>
#include<fstream>
#include<map>
using namespace std;
int main () {
	//ifstream fileIn("tyut.txt");
	ifstream fileIn("python_tutorial.txt");
	vector<char> vc;
	map<string,int> wmap;
	vector<string> vstr;
	char s;
	while(fileIn.get(s)) {
		string str="";
		if((s>='a'&&s<='z')||(s<='Z'&&s>='A')) {
			s=tolower(s);
			vc.push_back(s);
		}
		else if((s==' '||s=='.'||s=='\n')&&!vc.empty()) {
			for(auto a:vc) str+=a;
			vstr.push_back(str);
			auto wm_iter=wmap.find(str);
			if(wm_iter==wmap.end()) {
				wmap.insert(pair<string,int>(str,1));
			}
			else {
				for(auto i=wmap.begin();i!=wmap.end();i++) {
					if(i->first==str) i->second+=1;
				}
			}
			vc.clear();
		}
	}
	for(auto i=wmap.begin();i!=wmap.end();i++)
		cout<<i->first<<' '<<i->second<<endl;
	cout<<"Sum:"<<vstr.size()<<endl;
	return 0;
}
