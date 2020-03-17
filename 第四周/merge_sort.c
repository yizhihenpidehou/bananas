//
//  main.c
//  作业4
//
//  Created by yizhihenpidehou on 2020/3/17.
//  Copyright © 2020 yizhihenpidehou. All rights reserved.
//

#include <stdio.h>
#define maxen 30
void merge(int arr[],int l,int r){
    int mid=(l+r)/2;
    int tmp[maxen];
    int x1=l;
    int x2=mid+1;
    int i=0;
    while(x1<=mid&&x2<=r){  //对子列进行归并
        tmp[i++]=arr[x1]<arr[x2]?arr[x1++]:arr[x2++];
    }
    while(x1<=mid){//将剩余的放入tmp
        tmp[i++]=arr[x1++];
    }
    while(x2<=r){ //将剩余的放入tmp
        tmp[i++]=arr[x2++];
    }
    for(int j=0;j<(r-l+1);j++){
        arr[j+l]=tmp[j];   //将tmp已经归并好的子序列放到arr中
    }
}
void merge_sort(int arr[],int l,int r){ // 归并排序
    if(l==r){
        return ;
    }
    int mid=(l+r)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr,mid+1, r);
    merge(arr,l,r);
}

int main(void) {
    int num[maxen]={0,2,3,6,8,1,4,5,7};
    merge_sort(num, 1, 8);
    for(int i=1;i<=8;i++){
        printf("%d\n",num[i]);
    }
    
    return 0;
}
