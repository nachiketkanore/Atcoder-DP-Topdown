/**
 *	Author: Nachiket Kanore
 *	Created: Friday 30 April 2021 07:49:36 PM IST
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
const int N = 5e5 + 5;

int32_t main() {
	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));
	vector<int> mask_score(1<<n);
	vector<int> dp(1<<n, -inf);
	
	F0R (i,n) F0R (j,n) cin >> a[i][j];
	
	F0R (mask,1<<n) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((mask >> i & 1) && (mask >> j & 1)) {
					mask_score[mask] += a[i][j];
				}
			}
		}
	}

	dp[0] = 0;

	for (int mask = 1; mask < (1 << n); mask++) {
		for (int sub_mask = mask; sub_mask; sub_mask = (sub_mask - 1) & mask) {
			cmax(dp[mask], mask_score[sub_mask] + dp[mask ^ sub_mask]);
		}
	}

	cout << dp.back();
}
