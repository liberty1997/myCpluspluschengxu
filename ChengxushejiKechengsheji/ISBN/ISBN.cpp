#include<iostream>
#include<vector>
#include<fstream>
int main() {
	using std::cout;
	using std::endl;
	using std::string;
	using std::ifstream;
	using std::vector;
	ifstream fileIn("ISBN_data.txt");
	vector<string> vecs;
	string s;
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
	fileIn.close();
	return 0;
}
