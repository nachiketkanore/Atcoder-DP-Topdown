/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 25 July 2023 02:03:30 PM IST
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

struct Block {
	int w, s, v;
	Block(int w, int s, int v) : w(w), s(s), v(v) {
	}
};

const int MX = 1001;
int N, dp[MX][10 * MX];
vector<Block> A;

int go(int id, int top_weight_sum) {
	if (id == N || top_weight_sum > 10000) {
		return 0;
	}
	int& ans = dp[id][top_weight_sum];
	if (~ans)
		return ans;
	ans = 0;
	ans = go(id + 1, top_weight_sum);
	if (top_weight_sum <= A[id].s) {
		ans = max(ans, A[id].v + go(id + 1, top_weight_sum + A[id].w));
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	F0R(i, N) {
		int w, s, v;
		cin >> w >> s >> v;
		A.push_back(Block(w, s, v));
	}

	sort(ALL(A), [&](const Block& left, const Block& right) {
		return left.w + left.s < right.w + right.s;
	});

	memset(dp, -1, sizeof(dp));

	cout << go(0, 0) << '\n';

	return 0;
}
