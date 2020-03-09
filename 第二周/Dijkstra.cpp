#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxen=200;
const int Maxx=9999;
int edge[maxen][maxen];//±ﬂæÿ’Û 
int visit[maxen];//记录某个点是否被访问过
int lowcost[maxen];//存放起点到其他点最短的距离
void init(int n){  //初始化
	for(int i=1;i<=n;++i){
		visit[i]=false;
		lowcost[i]=Maxx;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)
			  edge[i][j]=99999;
			else
			  edge[i][j]=0;
		}
	}
}
void Dijkstra(int start,int n){
	for(int i=1;i<=n-1;i++){  //遍历接下来n-1个点
		int minn=99999;
		int index=0;
		for(int j=1;j<=n;j++){
			if(minn>lowcost[j]&&visit[j]!=true){  //寻找距离起点最短且若改点未访问过的点
				minn=lowcost[j]; 
				index=j;
			}
		}
		visit[index]=true;  //标记访问过
		for(int k=1;k<=n;k++){  //更新起点到每个点的最短距离
			if(lowcost[k]>lowcost[index]+edge[index][k]){  //’‚¿Ô «lowcost[index]µƒ‘≠“Ú «edge¿Ô√Êµƒ±ﬂ≥§≤ª «∏¸–¬π˝µƒ±ﬂ≥§ 
				lowcost[k]=lowcost[index]+edge[index][k];
			}
		}
	}
}
int main(void){
	int n,m;//∂•µ„ ˝”Î±ﬂ ˝
	int s,e,w;
	scanf("%d %d",&n,&m);
	init(n);//≥ı ºªØ ˝◊È 
	int start=1;//起点为1
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s,&e,&w);
		edge[s][e]=w;
		if(s==start) lowcost[e]=w;//初始化起点到每个点的距离
	} 
	lowcost[start]=0;
	visit[start]=true; //标记起点访问过 
	Dijkstra(start,n); 
	printf("%d\n",lowcost[8]);// 输出到点8的距离
	return 0;
}
