#include<bits/stdc++.h>
using namespace std;
//由题，贪心策略显然是按结束时间排序，我们这里使用pair来排序
typedef pair<int,int> pii;
pii a[1005];
int n;
//这样处理可以少打一些代码，同时又可以赋予意义
#define st second
#define ed first
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].st>>a[i].ed;
    sort(a+1,a+n+1);
    int t=a[1].ed,ans=1;
    for(int i=2;i<=n;i++)
        if(a[i].st>=t)
            ans++,t=a[i].ed;
    cout<<ans<<endl;
    return 0;
}
