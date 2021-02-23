#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=405;

int n;
int a[N], pref[N];
int cache[N][N];

int dp(int i, int j)
{
	if(i==j)
		return 0;
	int &ans=cache[i][j];
	if(ans!=-1)
		return ans;
	ans=1e15;
	for(int k=i;k<=j-1;k++)
		ans=min(ans, dp(i, k) + dp(k+1, j) + pref[j]-pref[i-1]);
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + a[i];
	}
	cout<<dp(1, n);
	return 0;
}
