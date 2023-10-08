/**
 *	Author: Nachiket Kanore
 *	Created: Sunday 08 October 2023 09:35:36 PM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int inf = 1e18;
const int N = 16;
vector<vector<int>> a(N, vector<int>(N));
vector<int> mask_score(1 << N);
vector<int> dp(1 << N, -1);

int solve(int mask) {
	if (mask == 0) {
		return 0;
	}

	int& ans = dp[mask];
	if (~ans)
		return ans;

	ans = -inf;

	for (int sub_mask = mask; sub_mask; sub_mask = (sub_mask - 1) & mask) {
		ans = max(ans, mask_score[sub_mask] + solve(mask ^ sub_mask));
	}

	return ans;
}

int32_t main() {
	int n;
	cin >> n;

	F0R(i, n) F0R(j, n) cin >> a[i][j];

	F0R(mask, 1 << n) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((mask >> i & 1) && (mask >> j & 1)) {
					mask_score[mask] += a[i][j];
				}
			}
		}
	}

	int start_mask = (1 << n) - 1;
	cout << solve(start_mask) << '\n';
}
