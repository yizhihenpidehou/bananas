//
//  binary_search.cpp
//  
//
//  Created by yizhihenpidehou on 2020/3/10.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxen=500;
int binary_search(int *num,int search_num,int len){
    int left=1;
    int right=len;
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(num[mid]==search_num){
            return mid;
        }
        else if(num[mid]<search_num){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return j;
}
int main(){
    int n;//输入数的数量
    scanf("%d",&n);
    int j=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int search_num;
    scanf("%d",&search_num);
    j=binary_search(num,search_num,n);
    printf("%d\n",j);
    return 0;
}
