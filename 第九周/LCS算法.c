//
//  main.c
//  作业9
//
//  Created by yizhihenpidehou on 2020/4/21.
//  Copyright © 2020 yizhihenpidehou. All rights reserved.
//

#include <stdio.h>
#include <string.h>
const int maxen=30;
char X[maxen]={'0','A','C','B','A','C'};
char Y[maxen]={'0','C','B','C','A'};
//char X[maxen]={'0','A','B','C','D'};
//char Y[maxen]={'0','B','A','C'};
int C[maxen][maxen];
int B[maxen][maxen];
int len=0;//子序列长度
int res[maxen];//存放最长子序列
void LCS(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i]==Y[j]){
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]=2;//删除两个
            }
            else{
                if(C[i-1][j]>C[i][j-1]){
                    B[i][j]=0;//删除X
                    C[i][j]=C[i-1][j];
                }
                else{
                    B[i][j]=1;//删除Y
                    C[i][j]=C[i][j-1];
               //     printf("<= %d %d:%d\n",i,j,B[i][j]);
                }
            
            }
        }
    }
}
void f(int i,int j){//输出最长公共序列
    if(i==0||j==0) return ;
    if(B[i][j]==2){
       // printf("%c ",X[i]);
        res[++len]=X[i];
        f(i-1,j-1);//删除两个
    }
    else if(B[i][j]==0){
        f(i-1,j);//删除X
    }
    else{
        f(i,j-1);//删除Y
    }
}
int main(int argc, const char * argv[]) {
    int n=5,m=4;
    memset(C, 0, sizeof(C));
    memset(B, -1, sizeof(B));
    LCS(n,m);
    f(n,m);
 /*   printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }*/
    for(int i=len;i>0;i--){
        printf("%c",res[i]);
    }
    printf("\n");
    return 0;
}
