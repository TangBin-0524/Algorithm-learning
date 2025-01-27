//洛谷里面有很好的题解，第一篇就行
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5; // 定义数组大小的最大值
ll a[N],n,ave,ans; // a数组用于存储糖果的前缀和，n是孩子的数量，ave是平均糖果数，ans是最终答案

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); // 快速输入输出设置
	cin>>n; // 输入孩子的数量
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=a[i-1]; // 输入每个孩子的糖果数，并计算前缀和
	ave=a[n]/n; // 计算平均糖果数
	for(int i=1;i<=n;i++)
		a[i]-=i*ave; // 计算偏差
	sort(a+1,a+n+1); // 对偏差数组进行排序
	for(int i=1;i<=n;i++)
		ans+=abs(a[(n+1)>>1]-a[i]); // 计算每个孩子的糖果数与中位数的绝对差值之和，作为最终答案
	cout<<ans<<endl; // 输出最终答案
	return 0;
}
