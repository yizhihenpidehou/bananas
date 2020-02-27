#include <stdio.h>
#include <string.h>
#include <math.h> 
#include <algorithm>
#include <iostream>
#define Max -9999
#define Min 100000
using namespace std;
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
		//	printf("init%d: %d\n",i,lowcost[i]);
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
	//	printf("index: %d  lowcost: %d\n",index,lowcost[index]);
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
