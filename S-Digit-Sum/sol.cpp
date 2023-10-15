/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 15 October 2023 04:07:45 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MOD = 1e9 + 7;

const int MAX = 1e4 + 5;
string K;
int D;
int dp[2][MAX][100];

int go(int id, bool small_taken, int sod_mod) {
	if (id == (int)K.size()) {
		return sod_mod == 0;
	}

	int& ans = dp[small_taken][id][sod_mod];
	if (~ans)
		return ans;
	ans = 0;

	int digit = K[id] - '0';
	int lo = 0, hi = digit;
	if (small_taken)
		hi = 9;

	for (int put = lo; put <= hi; put++) {
		ans += go(id + 1, small_taken || (put < digit), (sod_mod + put) % D);
		ans %= MOD;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> D;
	memset(dp, -1, sizeof(dp));
	cout << (go(0, false, 0) - 1 + MOD) % MOD << '\n';

	return 0;
}
