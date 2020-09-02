#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int n, k, dp[N], a[N];

int go(int rem) {
    int &ans = dp[rem];
    if (~ans)
        return ans;
    ans = 0;

    // Each player tries to find atleast one losing state for his opponent

    FOR(i,1,n) if (rem - a[i] >= 0) {
        int get = go(rem - a[i]);
        ans |= get == 0;
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    FOR(i,1,n) {
        cin >> a[i];
    }    

    memset(dp, -1, sizeof(dp));

    cout << (go(k) ? "First" : "Second") << '\n';
}
