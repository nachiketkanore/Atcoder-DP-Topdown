//Problem : https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e3 + 5, inf = 1e18, mod = 1e9 + 7;

int H, W, dp[N][N];
char mat[N][N];

bool inside(int x, int y){
    return x >= 1 && y >= 1 && x <= H && y <= W;
}

int go(int x, int y){
    if(!inside(x,y)) return 0;
    if(mat[x][y] == '#')    return 0;
    if(x == H && y == W)
        return 1;
    int &ans = dp[x][y];
    if(~ans)
        return ans;
    ans = 0;
    ans = (ans + go(x + 1, y)) % mod;
    ans = (ans + go(x, y + 1)) % mod;
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    memset(dp, -1, sizeof(dp));
    cin >> H >> W;
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++)
            cin >> mat[i][j];
    cout << go(1,1);
}
