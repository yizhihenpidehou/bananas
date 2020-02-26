////////////////Prim算法
#include <stdio.h>
#include <string.h>
#include <math.h> 
#include <algorithm>
#include <iostream>
#define Max -9999
#define Min 100000
int main(void){
	int n,s,e,w,m; 
	int edge[100][100]={0};
	int addnow[120];//记录已被添加的点
	int lowcost[120]; //记录到各点的最短路径 
	scanf("%d %d",&n,&m); //输入点与边的数量 
	for(int i=1;i<=n;++i){  //初始化 	
		lowcost[i]=Min;
	}
	for(int i=1;i<=m;++i){  
		scanf("%d %d %d",&s,&e,&w); //输入起点 终点 权值 
		edge[s][e]=w;
		edge[e][s]=w;
	} 
	int start=1; //将点1设为起点 
	for(int i=2;i<=n;++i){  //初始化起点到相连各点的距离 
		if(edge[start][i]!=0){
			lowcost[i]=edge[start][i];
			addnow[i]=-1;
		} 
	}
	addnow[start]=1; //将起点纳入点集合 
	int sum=0;
	for(int i=2;i<=n;++i){  //还剩下n-1个点 
		int minn=Min;  
		int index=-1;   //index记录点 
		for(int j=1;j<=n;++j){  
			if(addnow[j]!=1&&minn>lowcost[j]){ //寻找权值最小的边并且其对应点未纳入点集合 
				minn=lowcost[j];
				index=j;
			}
		}
		addnow[index]=1;  //将该点纳入集合 
		lowcost[index]=minn; //设置集合中的点到该点的最小消费 
		sum+=lowcost[index];
		for(int i=1;i<=n;++i){ //更新lowcost中的状态 
			if(edge[index][i]!=0&&i!=index&&lowcost[i]>edge[index][i]){
				   lowcost[i]=edge[index][i];
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}

////////////////kruskal算法
#include <stdio.h>
#include <string.h>
#include <math.h> 
#include <algorithm>
#include <iostream>
#define Max -9999
#define Min 100000
using namespace std;
int fa[5000];//存储每个点的父节点
struct node{
	int s;//起点 
	int e;//终点 
	int w;//权值 
}edge[5000];
void init(int n){  //初始化数组，每个人的父亲为自己 
	for(int i=0;i<=n;++i){
		fa[i]=i;
	}
} 
int find(int x){  //寻找顶端父节点 
	return fa[x]==x?x:find(fa[x]);
}
void baba(int x,int y){ //加入集体 
	int fa1=find(x);
	int fa2=find(y);
	fa[fa2]=fa1;
} 
bool cmp(struct node x,struct node y){  
	return x.w<y.w;
}
int main(void){
	int n,m;//点数和边数 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&edge[i].s,&edge[i].e,&edge[i].w); 
	}
	init(n);
    sort(edge+1,edge+n+1,cmp);
    int k=0,sum=0;
	for(int i=1;i<=m;++i){  //从小到大遍历 
    	if(k==n-1) break;
    	else{
    		if(find(edge[i].s)!=find(edge[i].e)){  //判断这两点是否在同一个集体，即判断是否形成闭环 
    			baba(edge[i].s,edge[i].e); //将该边加入路径 
    			k++; //边增加 
    			sum+=edge[i].w; //加上权值 
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}
