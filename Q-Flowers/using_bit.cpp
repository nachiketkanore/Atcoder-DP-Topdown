/*
Author: Nachiket Kanore
Created: Wednesday 24 February 2021 04:58:18 PM IST
(ツ) Love is the master key that opens the gates of happiness.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;

struct BIT {
	int N;
	vector<int> bit;

	void init(int n) {
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val) {
		while (idx <= N) {
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val) {
		while (idx <= N) {
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r) {
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx) {
		int ans = -inf;
		while (idx > 0) {
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
} dp;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	dp.init(n);
	vector<int> h(n), a(n);
	for (int& x : h)
		cin >> x;
	for (int& x : a)
		cin >> x;
	for (int i = 0; i < n; i++) {
		int best = a[i] + dp.prefMax(h[i] - 1);
		cmax(best, a[i]);
		see(best);
		dp.updateMax(h[i], best);
		cmax(ans, best);
	}
	cout << ans << '\n';
}
