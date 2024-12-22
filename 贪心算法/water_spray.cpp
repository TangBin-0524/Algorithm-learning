#include<bits/stdc++.h>
using namespace std;
inline void ckmin(int &x,int y){x=y<x?y:x;}
inline void ckmax(int &x,int y){x=y>x?y:x;}
typedef long long ll;
const int N=1.5e4+5;
//为了覆盖整个矩形，我们只需要考虑完全覆盖上边缘
//由勾股定理即得每个喷头覆盖的区间为x±sqrt(r*r-W*W/4)
//然后考虑贪心处理，按区间起点排序，设已经覆盖到了s
//每次找满足st<=s中的ed最大的，这样就能接起来并且覆盖最大
int n,L,W,top;
//top表示有效的喷头数量，对于r<=W/2的喷头，可知其不能覆盖到上边缘
struct seg{double st,ed;}a[N];//区间结构体
void read()
{
    cin>>n>>L>>W;
    top=0;
    for(int i=1;i<=n;i++)
    {
        int x,r;
        cin>>x>>r;
        if(r<=W/2.0)continue;//舍弃掉无效的喷头
        a[++top].st=x-sqrt(r*r-W*W/4.0);
        a[top].ed=x+sqrt(r*r-W*W/4.0);
    }
}
void solve()
{
    double s=0;
    int ans=0,i=1;
    while(s<L)//还没覆盖完
    {
        ans++;
        double t=s;
        //下面这个循环的时间复杂度由i控制，由i只会增可知均摊下来为O（n）
        for(;a[i].st<=s&&i<=top;i++)//这里是暴力枚举查找能够覆盖s的最大右端点
            if(t<a[i].ed)
                t=a[i].ed;
        if(t==s){
            puts("-1");
            return;
        }
        s=t;
    }
    cout<<ans<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        read();
        sort(a+1,a+top+1,[&](seg &x,seg &y){return x.st<y.st;});//核心的排序
        solve();
    }
    return 0;
}

