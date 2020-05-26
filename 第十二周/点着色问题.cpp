//
//  main.cpp
//  作业12
//
//  Created by yizhihenpidehou on 2020/5/26.
//  Copyright © 2020 yizhihenpidehou. All rights reserved.
//

#include <iostream>
#include <stdio.h>
int graph[100][100];//记录无向图
int color[100];//记录颜色
int count;
int n,m;;//点数，颜色数
int check(int num){//检查每两个点之间是否着色不同
    for(int i=1;i<=num;i++){//检查前个点与当前点的颜色是否冲突
        if(graph[num][i]==1&&color[i]==color[num]){//两点相连并且着色相同，则冲突
            return 0;
        }
    }
    return 1;
}
void graphColor(int num){//着色
    if(num==n+1){
        for(int i=1;i<=num;++i){//输出方案
            printf("%d ",color[i]);
        }
        printf("\n");
        count++;
        return ;
    }
    else{
        for(int i=1;i<=m;i++){
            color[num]=i;//先着色
            if(check(num)){//测试当前颜色是否冲突
                graphColor(num+1);//继续向下着色
            }
            color[num]=0;//回溯
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){//输入连通图
        for(int j=1;j<=n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\n");
    graphColor(1);
    if(count==0){//不存在方案
        printf("NO\n");
    }
    else{
        printf("num:%d\n",count);//输出方案数
    }
    return 0;
}
