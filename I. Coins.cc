#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 3001, inf = 1e18;

int n;
double p[N];
bool vis[N][N];
double dp[N][N];

double go(int id, int cH) {
	if (id == n+1) {
		int cT = n - cH;
		if (cH > cT) return 1.0;
		return 0.0;
	}
	if (vis[id][cH]) return dp[id][cH];
	vis[id][cH] = true;
	double ans = 0;
	ans += p[id] * go(id+1, cH+1);
	ans += (1.0 - p[id]) * go(id+1, cH);
	dp[id][cH] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	FOR (i,1,n) cin >> p[i];
	printf("%0.10lf\n", go(1,0));
}
