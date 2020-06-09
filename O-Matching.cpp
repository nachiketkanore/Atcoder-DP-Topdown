//Problem : https://atcoder.jp/contests/dp/tasks/dp_o

#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 21, mod = 1e9 + 7;

int n, comp[N][N], dp[N][1 << N];

int go(int id, int taken){
    if(id >= n)
        return 1;
    int &ways = dp[id][taken];
    if(~ways)
        return ways;
    ways = 0;
    for(int i = 0; i < n; i++) if((taken >> i & 1) == 0){
        if(comp[id][i])
            ways = (ways + go(id + 1, taken | (1 << i))) % mod;
    }
    return ways;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> comp[i][j];
    cout << go(0, 0);
}
