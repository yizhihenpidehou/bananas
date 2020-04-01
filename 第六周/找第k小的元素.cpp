//
//  main.cpp
//  作业6
//
//  Created by yizhihenpidehou on 2020/3/31.
//  Copyright © 2020 yizhihenpidehou. All rights reserved.
//
#include <iostream>
#include <stdio.h>
using namespace std;
const int maxen=100;
void InsertSort(int n[],int low,int high){ //插入排序
    int i,j;
    for(i=low+1;i<=high;i++){
        j=i-1;
        int tmp=n[i];
        while(j>=low&&tmp<n[j]){
            n[j+1]=n[j];
            j--;
        }
        n[j+1]=tmp;
    }
}
int FindMid(int n[],int low,int high){ //找出中位数
    if(low==high) return n[low];
    int i,k;
    for(i=low;i+4<=high;i+=5){
        InsertSort(n, i, i+4);
        k=i-low;
        swap(n[low+k/5],n[i+2]);
    }
    int cnt=high-i+1;
    if(cnt>0){
        InsertSort(n, i, high);
        k=i-low;
        swap(n[low+k/5],n[i+cnt/2]);
    }
    k=k/5;
    if(k==0) return n[low];
    return FindMid(n,low,low+k);
}
int FindMidIndex(int n[],int low,int high,int midd){ //找出中位数的下标
    for(int i=low;i<=high;i++){
        if(n[i]==midd){
            return i;
        }
    }
    return -1;
}
int Partition(int n[],int low,int high,int index){ //根据求出的中位数进行划分，求出划分后中位数的位置
    if(low<=high){
        int i=low,j=high;
        swap(n[index],n[low]);
        int tmp=n[low];
        while(i!=j){
            while(i<j&&n[j]>=tmp){
                j--;}
            n[i]=n[j];
            while(i<j&&n[i]<=tmp){
                i++;}
            n[j]=n[i];
        }
        n[i]=tmp;
        return i;
    }
        return -1;
}
int BFPTR(int n[],int low,int high,int k){
    int midd=FindMid(n,low,high);
    int indexx=FindMidIndex(n,low,high,midd);
    int newIndex=Partition(n,low,high,indexx);
    int rank=newIndex-low+1;
    if(rank==k) return newIndex;
    else if(rank>k) return BFPTR(n,low,newIndex-1,k);
    return BFPTR(n,newIndex+1,high,k-rank);
}
int main(int argc, const char * argv[]) {
    int num[maxen]={-1,12,1,8,10,6,2,5,9,11,3,4,7};
    int k;
    scanf("%d",&k);
    int low=1;
    int high=12;
    int index=BFPTR(num,low,high,k);
    printf("%d\n",num[index]);
    for(int i=low;i<high;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}

