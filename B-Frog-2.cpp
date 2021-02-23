//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5+10;
const int mod = 998244353;
const int inf = 1e12;
int n, k, h[N], dp[N];

int solve(int currPos){
	if(currPos <= 0)
		return inf;

	int &ans = dp[currPos];
	if(ans != inf)
		return ans;

	for(int i = 1; i <= k; i++){
		int prev = currPos - i;
		if(prev >= 1){
			ans = min(ans, solve(prev) + abs(h[prev] - h[currPos]));
		}
	}
	return ans;

}

int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

    fill(dp, dp + N, inf);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    	cin >> h[i];

    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    cout << solve(n) << '\n';

}
