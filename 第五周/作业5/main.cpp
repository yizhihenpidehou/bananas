//
//  main.cpp
//  作业5
//
//  Created by yizhihenpidehou on 2020/3/24.
//  Copyright © 2020 yizhihenpidehou. All rights reserved.
//
/*问题：求二维空间中欧几里得距离最小的点对*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxen=50000;
struct Node{  //存储节点
    double x;
    double y;
};
bool cmpX(Node a,Node b){ //对X轴排序
    return a.x<b.x;
}
bool cmpY(Node a,Node b){ //对Y轴排序
    return a.y<b.y;
}
double dist(Node a,Node b){ //返回距离
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
Node arr[maxen];
double dirctSearch(int n,Node a[]){
    if(n==1) return 0;
    else return dist(a[1],arr[2]);
}
double EfficientClosestPair(int l,int r){
    int mid=(l+r)/2;
    int count=1;
    double d=0;
    if(l==r) return 999999;
    d=(min(EfficientClosestPair(l,mid),EfficientClosestPair(mid+1,r)));
    Node tmp[maxen];
    for(int i=mid;i>=l&&(arr[mid].x-arr[i].x<d);i--){  //筛选出左边间距小于d的
        tmp[count++]=arr[i];
    }
    for(int i=mid+1;i<=r&&(arr[i].x-arr[mid].x<d);i++){ //筛选出z右边间距d小于d的
        tmp[count++]=arr[i];
    }
    sort(tmp+1,tmp+count,cmpY); //将按d划分的区间中的点集合按照y轴排序
    for(int i=1;i<count;i++){
        for(int j=i+1;j<count&&(arr[j].y-arr[i].y<d);j++){
            d=min(d,dist(arr[i],arr[j]));//更新d
        }
    }
    return d;
}
int main(int argc, const char * argv[]) {
    int n;
    double minDist;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&arr[i].x,&arr[i].y);
    }
    if(n<=2){
        minDist=dirctSearch(n, arr); //若点的数量比较少，则直接暴力
    }
    else{   //采用分治思想，二分找出两个区间最小的点对距离，然后再找出按照最小点对划分的区间的中间区域查找是否有更短的点对
        sort(arr+1,arr+1+n,cmpX); //按照X轴排序
        minDist=EfficientClosestPair(1,n);
    }
 //   printf("%.2f\n",sqrt(10));
    printf("%.2f\n",minDist);
    return 0;
}
