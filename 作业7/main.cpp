//
//  main.cpp
//  作业7
//
//  Created by yizhihenpidehou on 2020/4/7.
//  Copyright © 2020 yizhihenpidehou. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxen=200;
int Fk[maxen][maxen]={0};//存放第k个项目投资x元可以获得的最大收益
int fk[maxen][maxen]={0};//存放第k个项目x元可以获得的收益
int dp(int n,int m){
    for(int k=1;k<=n;k++){//前k个项目
        for(int x=1;x<=m;x++){//前K个项目共投资多少钱
            for(int z=0;z<=x;z++){//给第K个项目分配多少钱
                Fk[k][x]=max(Fk[k][x],fk[k][z]+Fk[k-1][x-z]);
                //计算钱该怎么分配给第k个项目与前k-1个项目收益最大
            }
        }
    }
    return Fk[n][m]; //返回收益最大的情况(因为每次Fk[k][x]都是存最大收益)
}
int main(int argc, const char * argv[]) {
    int n=4,m=5;//有4个项目，共有5万元
    memset(Fk,0,sizeof(Fk));
    memset(fk,0,sizeof(fk));
    fk[1][0]=0;fk[1][1]=11;fk[1][2]=12;fk[1][3]=13;fk[1][4]=14;fk[1][5]=15;
    fk[2][0]=0;fk[2][1]=0;fk[2][2]=5;fk[2][3]=10;fk[2][4]=15;fk[2][5]=20;
    fk[3][0]=0;fk[3][1]=2;fk[3][2]=10;fk[3][3]=30;fk[3][4]=32;fk[3][5]=40;
    fk[4][0]=0;fk[4][1]=20;fk[4][2]=21;fk[4][3]=22;fk[4][4]=23;fk[4][5]=24;
    int maxx=dp(n,m);
    printf("maxx:%d\n",maxx);
    return 0;
}
