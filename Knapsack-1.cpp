//1.Top-down with memoization (AC)

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e12;
const int N = 105;
const int W = 1e5 + 5;

int n, total, weight[N], value[N], dp[N][W];

int solve(int item, int remain){
	if(remain < 0)
		return -inf;
	if(remain == 0 || item == 0)
		return 0;

	int &ans = dp[item][remain];
	if(ans != 0)
		return ans;

	int take = value[item] + solve(item - 1, remain - weight[item]);
	int dont_take = solve(item - 1, remain);
		
	ans = max(take, dont_take);

	return ans;
}

int32_t main(){ 

	cin >> n >> total;
	for(int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	cout << solve(n, total) << '\n';
    
}


//2.Recursive without memoization (TLE)

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e12;
const int N = 105;

int n, total, weight[N], value[N];

int solve(int item, int remain){
	if(remain < 0)
		return -inf;
	if(remain == 0 || item == 0)
		return 0;

	int take = value[item] + solve(item - 1, remain - weight[item]);
	int dont_take = solve(item - 1, remain);
	return max(take, dont_take);
}

int32_t main(){ 
	
	cin >> n >> total;
	for(int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	cout << solve(n, total) << '\n';
    
}
