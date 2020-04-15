#include<iostream>
using namespace std;
const int maxen=100;
//p为矩阵链，p[0],p[1]代表第一个矩阵的行数和列数，p[1],p[2]代表第二个矩阵的行数和列数,length为p的长度
//所以如果有六个矩阵，length=7，m为存储最优结果的二维矩阵，s为存储选择最优结果路线的
void MatrixChainOrder(int *p,int m[maxen][maxen],int s[maxen][maxen],int length)
{
    int n=length-1;
    int l,i,j,k,q=0;
    //m[i][i]只有一个矩阵，所以相乘次数为0，即m[i][i]=0;
    for(i=1;i<length;i++)
    {
        m[i][i]=0;
    }
    //l表示矩阵链的长度
    // l=2时，计算 m[i,i+1],i=1,2,...,n-1 (长度l=2的链的最小代价)
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1; //以i为起始位置，j为长度为l的链的末位，
            m[i][j]=999999;
            for(k=i;k<=j-1;k++) //k从i到j-1,以k为位置划分
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    printf("%d\n", m[1][5-1]);//输出计算的最少次
}
void Print_(int s[maxen][maxen],int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        Print_(s,i,s[i][j]);
        Print_(s,s[i][j]+1,j);
        printf(")");
    }
}
int main()
{
   // int p[maxen]={30,35,15,5,10,20,25};
    int p2[maxen]={1,2,2,3,4};
    int m[maxen][maxen],s[maxen][maxen];
    MatrixChainOrder(p2,m,s,7);
    Print_(s,1,5-1);
    return 0;
}
