//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5+10;
const int mod = 998244353;
const int inf = 1e18;
int n, h[N], dp[N];

int solve(int n){
	if(n <= 0)
		return inf;

	int &ans = dp[n];

	if(ans != inf)
		return ans;

	ans = min(abs(h[n] - h[n-1]) + solve(n-1), abs(h[n] - h[n-2]) + solve(n-2));
	
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
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> h[i];
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    cout << solve(n) << '\n';

}
