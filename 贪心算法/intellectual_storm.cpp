#include<bits/stdc++.h>
using namespace std;
const int N=505;
/*
显然这个题的贪心就是按照罚款降序排序，罚款多的优先做
，为了尽量不占用其他时间，最好把它安排到活动截止前最后的有空时间。
如果没法塞进去就只好被罚款了
*/
struct act{
	int t,w;
}Act[N];//定义活动的结构体
int m,n,hsh[N],ans;
//m为时间段，n为活动个数，hsh标记哪些时间段有活动，ans为最小罚款
int main()
{
    cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>Act[i].t;
	for(int i=1;i<=n;i++)cin>>Act[i].w;
	//按照罚款降序排序
	sort(Act+1,Act+n+1,[&](act &x,act &y){return x.w>y.w;});
	for(int i=1;i<=n;i++)
	{
		bool fined=1;//标记是否有罚款
		//尝试从最晚往前安排活动
		for(int j=Act[i].t;j>=1;j--)
			if(!hsh[j]){
				fined=0;
				hsh[j]=1;
				break;
			}
		//罚款了就只能将活动安排到剩余时间最晚的位置
		if(fined)
		{
			for(int k=n;k>=1;k--)
				if(!hsh[k]){hsh[k]=1;break;}
			ans+=Act[i].w;
		}
	}
	cout<<m-ans<<endl;
    return 0;
}

