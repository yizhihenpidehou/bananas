//
//  main.c
//  作业11
//
//  Created by yizhihenpidehou on 2020/5/12.
//  Copyright © 2020 yizhihenpidehou. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int weight;
    int lchild,rchild,parent;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;
HuffmanCode HC;
HuffmanTree HT;
int s1;
int s2;
void SelectMin(HuffmanTree tree,int n){ //找出权值最小的两棵树
    int minn=1;//存放临时最小值
    for(int i=1;i<=n;i++){
        if(tree[i].parent==0){//找出一个暂时的最小值
            minn=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(tree[i].parent==0&&tree[i].weight<tree[minn].weight){//找出第一个最小值
            minn=i;
        }
    }
    s1=minn;
    for(int i=1;i<=n;i++){
        if(tree[i].parent==0&&i!=s1){//找出一个暂时的最小值
            minn=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
           if(tree[i].parent==0&&tree[i].weight<tree[minn].weight&&i!=s1){//找出第二个最小值
               minn=i;
           }
       }
       s2=minn;
  //  printf("s1:%d s2:%d\n",s1,s2);
}
void Huffman(HuffmanTree tree,int *w,int n){//哈夫曼编码
    int m=2*n-1;//哈夫曼树的节点数
    tree=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//申请节点
    for(int i=1;i<=m;i++){//初始化树
        tree[i].lchild=0;
        tree[i].rchild=0;
        tree[i].parent=0;
        if(i<=n){//设置每个叶子节点的权值
           tree[i].weight=w[i];
        }
        else{
            tree[i].weight=0;
        }
    }
    for(int i=n+1;i<=m;i++){
        SelectMin(tree,i-1);
     //   printf("s1 %d s2 %d\n",s1,s2);
        tree[s1].parent=i;//将s1的父亲设置为i
        tree[s2].parent=i;//将s2的父亲设置为i
        tree[i].lchild=s1;//将s1作为i的左孩子
        tree[i].rchild=s2;//将s2作为i的右孩子
        tree[i].weight=tree[s1].weight+tree[s2].weight;//i的权值为s1与s2的和
      //  printf("val s1:%d s2:%d\n",tree[s1].weight,tree[s2].weight);
    //   printf("new NODE %d %d %d %d\n",tree[i].parent,tree[i].lchild,tree[i].rchild,tree[i].weight);
    }
    //以上为建造一颗哈夫曼树，以下为求哈夫曼编码
    HC=(HuffmanCode)malloc((n+1)*(sizeof(char *)));//相当于申请一个二维数组，存放n个哈夫曼编码
    char *cd;
    cd=(char *)malloc(n*sizeof(char));//相当于申请一个一维数组，暂存哈夫曼编码
    cd[n-1]='\0';//编码结束符
    int start;
    for(int i=1;i<=n;i++){
        start=n-1;//初始点
        for(int j=i,f=tree[i].parent;f!=0;j=f,f=tree[f].parent){ //逆向求哈夫曼编码
            if(tree[f].lchild==j) cd[--start]='0'; //向左为0
            else cd[--start]='1';//向右为1
        }
        HC[i]=(char *)malloc((n-start)*sizeof(char));
        strcpy(HC[i],&cd[start]);//将该字符的哈夫曼编码赋到HC中
        //printf("%c",cd[start]);
    }
    free(cd);
    
}
int main(int argc, const char * argv[]) {

    int n=10;
    int w[200]={0,30,40,20,10,5,15,10,45,20,60};//存放每个字符的权值
  //  int w1[200]={0,10,5,20};
    Huffman(HT, w, n);
  //  Huffmancode(HT,HC,n);
    for(int k=1;k<n;k++){//输出每个字符的哈夫曼编码
        printf("%s\n",HC[k]);
    }
    printf("\n");
    return 0;
}
