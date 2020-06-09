#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

int n, u, v;
std::vector<int> g[N];
int dp[2][N];

int go(int u, int par, int col){
	int &ans = dp[col][u];
	if(~ans)
		return ans;
	ans = 1;

	for(int v : g[u]) if(v != par){
		if(col == 0){
			ans = (ans * go(v, u, !col)) % mod;
		}
		else{
			ans = (ans * (go(v, u, !col) + go(v, u, col))) % mod;
		}
	}
	return ans;
}

int32_t main(){
	
	memset(dp, -1, sizeof(dp));
	cin >> n;
	FOR(i,2,n){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = go(1,-1,0) + go(1,-1,1);
	ans %= mod;
	cout << ans;
}
