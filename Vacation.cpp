//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5+10;
const int mod = 998244353;
const int inf = 1e12;
int n, cost[N][3], dp[N][3];

int solve(int curr, int task){
	if(curr < 1)
		return 0;

	int &ans = dp[curr][task];
	if(ans != 0)
		return ans;

	for(int i = 0; i < 3; i++){
		if(i != task){
			ans = max(ans, cost[curr][task] + solve(curr - 1, i));
		}
	}
	/*	Alternative : 
		vector<int> otherTwo;
		for(int i = 0; i < 3; i++)
			if(i != task)
				otherTwo.push_back(i);

		ans = cost[curr][task] + max(solve(curr - 1, otherTwo[0]), solve(curr - 1, otherTwo[1]));
	*/
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    dp[1][0] = cost[1][0],
    dp[1][1] = cost[1][1],
    dp[1][2] = cost[1][2];

    cout << max({solve(n,0), solve(n,1), solve(n,2)}) << '\n';
    
}
