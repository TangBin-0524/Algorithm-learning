#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct work{int a,b,id;}W[N];
int n,ans[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>W[i].a,W[i].id=i;
    for(int i=1;i<=n;i++)
        cin>>W[i].b;
    // 按照 min(a, b) 的升序对任务进行排序
    sort(W+1,W+n+1,[&](work &x,work &y){return min(x.a,x.b)<=min(y.a,y.b);});
    int l=0,r=n+1;
    // 根据 Johnson 算法分配任务到左右两端
    for(int i=1;i<=n;i++)
        if(W[i].a<=W[i].b)
            ans[++l]=i;// 如果 a <= b，则将任务放入左端
        else ans[--r]=i;// 否则将任务放入右端
    l=r=0;// 重置 l 和 r 为 0，用于模拟计算总时间
    for(int i=1;i<=n;i++)
    {
        l+=W[ans[i]].a;// 累加当前任务的 a 值到 l
        if(r<l)r=l;// 更新 r 为 l 和 r 中的较大值
        r+=W[ans[i]].b;// 累加当前任务的 b 值到 r
    }
    cout<<r<<endl;
    // 输出任务的调度顺序（按原始编号）
    for(int i=1;i<=n;i++)
        cout<<W[ans[i]].id<<' ';
    cout<<endl;
    return 0;
}

