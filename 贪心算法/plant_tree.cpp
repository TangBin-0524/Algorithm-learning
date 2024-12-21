#include<bits/stdc++.h>
using namespace std;
inline void ckmin(int &x,int y){x=y<x?y:x;}
inline void ckmax(int &x,int y){x=y>x?y:x;}
typedef long long ll;
const int N=3e4+5,H=5e3+5;
int n,h,ans;
bool vis[N];//vis[i]表示第i处是否种了树
struct line{int b,e,t;}a[H];
int main()
{
    cin>>n>>h;
    for(int i=1;i<=h;i++)
        cin>>a[i].b>>a[i].e>>a[i].t;
    //按区间末端排序
    //顺便小小秀一下lamda表达式
    sort(a+1,a+h+1,[&](line x,line y){return x.e<y.e;});
    for(int i=1;i<=h;i++)
    {
        int k=0;
        for(int j=a[i].b;j<=a[i].e;j++)
            k+=vis[j];
        if(k>=a[i].t)continue;//如果树已经够了就跳过
        for(int j=a[i].e;j>=a[i].b;j--)//否则从最后开始往前种在尾部
        {
            if(!vis[j]){
                vis[j]=1;
                k++;ans++;
                if(k==a[i].t)break;//也是点到为止
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

