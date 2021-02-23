/*
Author: Nachiket Kanore
Created: Tuesday 23 February 2021 10:00:36 AM IST
(ツ) No person is your friend who demands your silence, or denies your right to grow.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int mod = 1e9+7;

struct BIT
{
	static const int offset = 5;
    int N;
    vector<int> bit;

    void init(int n)
    {
        N = 2 * n;
        bit.assign(2 * n + 10, 0);
    }

    void update(int idx, int val)
    {
    	idx += offset;
        while(idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int pref(int idx)
    {
    	idx += offset;
        int ans = 0;
        while(idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    int rsum(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);	
	for (int &x : a) cin >> x;
	
	vector<int> dp(k+1);
	FOR (val,0,a[0]) dp[val] = 1;
	
	for (int i = 1; i < n; i++) {
		vector<int> ndp(k+1);
		BIT dp_sums;
		dp_sums.init(k+5);
		FOR (val,0,k)
			dp_sums.update(val, dp[val]);
		
		FOR (tot,0,k) {
			ndp[tot] += dp_sums.rsum(tot - a[i], tot);

			ndp[tot] %= mod;
			// ndp[tot] += dp[tot - 0];
			// ndp[tot] += dp[tot - 1];
			// ndp[tot] += dp[tot - 2];
			// .
			// .
			// .
			// .
			// ndp[tot] += dp[tot - a[i]];
			// range = [tot - a[i], tot]
			// ndp[tot] += sum(dp[range])

			// FOR (give,0,a[i]) {
			// 	if (tot >= give)
			// 		ndp[tot] = (ndp[tot] + dp[tot-give]) % mod;
			// }
		}
		dp = ndp;
	}
	cout << dp[k] << '\n';
}
