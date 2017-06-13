// 本程序实现了点的名称和数字0 1 2 3 ...的自动映射
// 即输入点时可以输ABCD...(以前是输0123...)且顺序随意
// map的find方法的参数只能是map的第一个参数(iter->first)
#include<iostream>
#include<map>
#include<vector>
#include<fstream>
using namespace std;
const int INF=999;
const int MAX_VERTEX_NUM=20;
// 邻接矩阵
typedef struct ArcCell {
	int weight; // 邻接矩阵中的元素即为边的权值
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	char vexs[MAX_VERTEX_NUM]; // 存放顶点的数组
	AdjMatrix arcs; // 邻接矩阵
	int vexnum,arcnum; // 图的顶点数和边数
}MGraph;

int main() {
	ifstream fileIn("Roads_net1.txt");
	MGraph G;
	int Cost=0; // 最小生成树的代价
	map<char,int> Gmap;
	map<int,int> Vmark; // 标记为0表示没加入生成树
	fileIn>>G.vexnum>>G.arcnum;
	for(int i=0;i<G.vexnum;i++) {
		char c;
		fileIn>>c;
		G.vexs[i]=c;
		Gmap.insert(pair<char,int>(c,i));
	}
	for(auto i=Gmap.begin();i!=Gmap.end();i++) {
		for(auto j=Gmap.begin();j!=Gmap.end();j++) {
			G.arcs[i->second][j->second].weight=INF;
		}
	}
	for(int i=0;i<G.arcnum;i++) {
		char a,b;
		int c;
		fileIn>>a>>b>>c;
		auto k1_iter=Gmap.find(a);
		auto k2_iter=Gmap.find(b);
		G.arcs[k1_iter->second][k2_iter->second].weight=c;
		G.arcs[k2_iter->second][k1_iter->second].weight=c;
	}
	for(auto i=Gmap.begin();i!=Gmap.end();i++) {
		Vmark[i->second]=0;
	}
	// Prim
	vector<char> Zuivex;
	auto k_iter=Gmap.find('A');
	int k=k_iter->second;
	Vmark[k]=1;
	Zuivex.push_back(k_iter->first);
	for(int t=0;t<G.vexnum-1;t++) {
		int min=INF;
		char mincol;
		for(int i=0;i<Zuivex.size();i++) {
			auto ik_iter=Gmap.find(Zuivex[i]);
			int ik=ik_iter->second;
			for(auto col_iter=Gmap.begin();col_iter!=Gmap.end();col_iter++) {
				if(Vmark[col_iter->second]==0&&G.arcs[ik][col_iter->second].weight<min) {
					min=G.arcs[ik][col_iter->second].weight;
					mincol=col_iter->first;
				}
			}
		}
		Cost+=min;
		auto min_iter=Gmap.find(mincol);
		Vmark[min_iter->second]=1;
		cout<<"("<<Zuivex.back()<<","<<min_iter->first<<")"<<endl;
		Zuivex.push_back(min_iter->first);
	}
	if(Zuivex.size()!=G.vexnum) cout<<"非连通图!"<<endl;
	cout<<"min_Cost: "<<Cost<<endl;
	return 0;
}
