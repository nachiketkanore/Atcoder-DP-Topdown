/**
 *	Author: Nachiket Kanore
 *	Created: Friday 30 April 2021 05:45:15 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>
#include <chrono>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;
using namespace std::chrono;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct starter{
	high_resolution_clock::time_point t1, t2;

	starter() {
		ios::sync_with_stdio(0); cin.tie(0);
		t1 = high_resolution_clock::now();
	}
	~starter() {
		t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		cerr << "It took " << time_span.count() << " seconds.";
	}
} starter_;

const int inf = 1e18;
const int N = 305;

int n;
bool vis[N][N][N];
double dp[N][N][N];

double go(int c1, int c2, int c3) {
	if (c1 == 0 && c2 == 0 && c3 == 0) return 0.;
	if (vis[c1][c2][c3]) return dp[c1][c2][c3];
	vis[c1][c2][c3] = 1;
	double &ans = dp[c1][c2][c3];
	ans = 1;
	if (c1 > 0) ans += 1. * c1 / n * go(c1 - 1, c2, c3);
	if (c2 > 0) ans += 1. * c2 / n * go(c1 + 1, c2 - 1, c3);
	if (c3 > 0) ans += 1. * c3 / n * go(c1, c2 + 1, c3 - 1);
	double p0 = 1. * (n - c1 - c2 - c3) / n;
	ans /= 1. - p0;
	return ans;
}

int32_t main() {
	cin >> n;
	vector<int> cnt(4);
	F0R (i,n) {
		int u;
		cin >> u;
		cnt[u]++;
	}
	printf("%0.10f\n", go(cnt[1], cnt[2], cnt[3]));
}
