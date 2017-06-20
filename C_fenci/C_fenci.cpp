#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
const int LIST_INIT_SIZE = 300;
const int LISTINCREMENT = 50;
// 线性表中每个元素的结构
typedef struct {
	string word="";
	int count=0;
}ElemType;
// 线性表结构
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

// 确定是否需要插入,是的话就返回插入的位置
int LocateElem(SqList &L, string s) {
	int pos=-1;
	for(int i=0;i<L.length;i++) {
		if(L.elem[i].word==s) {
			L.elem[i].count+=1;
			return -3; // 找到相同元素(单词) 不插入,只增加次数
		}
		else if(L.elem[i].word>s) {
			pos=i;
			return pos; // 因为是按字典序,所以
			// 一旦找到表中有个元素比要插入的元素大
			// 那就可以确定插入位置了
		}
		else if(i==L.length-1&&L.elem[i].word<s) {
			return L.length; // 当i循环到表尾时若还没找到插入位置
			// 即当前表中元素(按字典序排的)均比需要插入的元素小
			// 所以插入到表尾
		}
	}
	return -2; // 插入到空表 即上面的for就没运行
}

int InsertList(SqList &L, int i, string s) {
	if(i<0 || i>L.length+1) {
		cout<<"Insert Loc wrong!"<<endl;
		return -1;
	}
	if(L.length>=L.listsize) {
		ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) {
			cout<<"realloc failed!!!"<<endl;
			return -1;
		}
		L.elem=newbase;
		L.listsize += LISTINCREMENT;
	}
	if(i==0&&L.length<1 || i==L.length+1) { // 插入到空表的表头或非空表的表尾
		L.elem[i].word=s;
		L.elem[i].count=1;
	}
	else {
		for(int loc=L.length-1;loc>=i;loc--) { // 在非空表的中间位置插入
			L.elem[loc+1].word=L.elem[loc].word;
			L.elem[loc+1].count=L.elem[loc].count;
		}
		L.elem[i].word=s;
		L.elem[i].count=1;
	}
	L.length++; // 不管哪种插入,最后都要L.length++
	return 0;
}

int main() {
	ifstream fileIn("tyut.txt");
	vector<char> a;
	char c;
	SqList L;
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) {
		cout<<"malloc failed in main()!!!"<<'\n';
		return 0;
	}
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	int num=0;
	while(fileIn.get(c)) {
		/* 按字符读取,遇到字母就保留,当遇到能分隔一个单词的字符
			就把当前保留的字符串跳出来
		*/
		if((c>='a'&&c<='z')||(c<='Z'&&c>='A')) {
			c=tolower(c);
			a.push_back(c);
		}
		else if((c==' '||c=='.'||c=='\n'||c==','||c=='?')&&!a.empty()) {
			string word="";
			for(auto i:a)
				word+=i;
			//cout<<"word=== "<<word<<endl;
			num++;
			int pos=LocateElem(L,word);
			//cout<<"pos="<<pos<<endl;
			if(pos==-3) {}
			else if(pos==-2) InsertList(L,0,word); // 插入到空表
			else InsertList(L,pos,word);
			//cout<<"Length="<<L.length<<endl;
			a.clear();
			/* 调试用,查看每次找到词后的插入是否正确
			cout<<"-------------------------------"<<endl;
			for(int i=0;i<L.length;i++) {
				cout<<L.elem[i].word<<' ';
				cout<<L.elem[i].count<<endl;
			}
			cout<<"-------------------------------"<<endl;
			*/
		}
	}
	fileIn.close();
	for(int i=0;i<L.length-1;i++) {
		cout<<L.elem[i].word<<' ';
		cout<<L.elem[i].count<<endl;
	}
	cout<<"出现了 "<<num<<" 个单词"<<endl;
	cout<<"合并后有 "<<L.length<<" 个单词"<<endl;
	return 0;
}
