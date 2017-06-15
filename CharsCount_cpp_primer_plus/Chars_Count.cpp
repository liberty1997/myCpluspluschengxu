/* C++ Primer Plus 程序清单17.17
   counting characters in a list of files
   *nix下相似命令行程序 wc
   本程序重点在对命令行参数的处理上
   Something: 优先级:后缀优于前缀,前缀和解除引用(*)同级
   有些C++实现要求在该程序末尾使用fin.clear(),有些则不要求,
   这取决于将文件与ifstream对象关联起来时,是否自动重置流状态.
   使用fin.clear()是无害的,即使在不必使用它的时候使用.
*/
#include<iostream>
#include<fstream>
#include<cstdlib> // for exit()
int main(int argc, char * argv[]) { // 如何获得argc的值?
	using namespace std;
	if(argc==1) {
		cerr<<"Usage: "<<argv[0]<<" filename[s]\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin;
	long count;
	long total=0;
	char ch;
	for(int file=1;file<argc;file++) {
		fin.open(argv[file]); // connect stream to argv[file]
		if(!fin.is_open()) {
			cerr<<"Could not open "<<argv[file]<<endl;
			fin.clear();
			continue;
		}
		count=0;
		while(fin.get(ch)) count++;
		cout<<count<<" characters in "<<argv[file]<<endl;
		total+=count;
		fin.clear(); // needed for some implementations
		fin.close(); // disconnect file
	}
	cout<<total<<" characters in all files\n";
	return 0;
}
