#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxen=200;
const int Maxx=9999;
int edge[maxen][maxen];
void init(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)
			  edge[i][j]=Maxx;
			else
			  edge[i][j]=0;
		}
	}
}
void Floyd(int n){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(edge[i][j]>edge[i][k]+edge[k][j]){
					edge[i][j]=edge[i][k]+edge[k][j];
				}
			}
		}
	}
}
int main(){
	int n,m;//n为顶点数,m为边数˝;
	scanf("%d %d",&n,&m);
	int s,e,w;		
	init(n);
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&s,&e,&w);
		edge[s][e]=w;
	} 
    Floyd(n);
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j){
    		printf("s:%d e:%d w:%d\n",i,j,edge[i][j]);
		}
		printf("\n");
	}
	return 0;
}
