//It's time to be who I am, rather than who I am supposed to be.
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e12;
const int N = 105;
const int maxVal = 1e5;
int weight[N], value[N], dp[maxVal + 5][N], n, total;

int giveMinWeight(int item, int currVal){
	if(currVal < 0)
		return inf;
	if(currVal == 0)
		return 0;
	if(item == 0) //item = 0 and currVal > 0 => not possible to make
		return inf;

	int &ans = dp[currVal][item];
	if(ans != 0)
		return ans;

	int take = weight[item] + giveMinWeight(item - 1, currVal - value[item]);
	int dont_take = giveMinWeight(item - 1, currVal);

	ans = min(take, dont_take);
	return ans;
}

int32_t main(){ 

	cin >> n >> total;
	for(int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	int ans = 0;

	for(int i = maxVal; i >= 0; i--){
		if(giveMinWeight(n, i) <= total){
			ans = i;
			break;
		}
	}

	cout << ans << '\n';
    
}
