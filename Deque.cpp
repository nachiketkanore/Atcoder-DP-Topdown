//Problem : https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e3 + 5, inf = 1e18, mod = 1e9 + 7;

int n, a[N], dp[N][N];

int go(int L, int R){
    if(L > R)
        return 0;

    int &ans = dp[L][R];
    if(~ans)
        return ans;
    
    int c1 = a[L] - go(L + 1, R);
    int c2 = a[R] - go(L, R - 1);

    return ans = max(c1, c2);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    memset(dp, -1, sizeof(dp));
    cin >> n;   
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << go(1, n);
}
