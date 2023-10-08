/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 October 2023 11:28:18 AM IST
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

int MOD;
struct mi {
	using ll = long long;
	ll v;
	explicit operator ll() const {
		return v;
	}
	mi() {
		v = 0;
	}
	mi(ll _v) {
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0)
			v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b);
	}
	friend bool operator<(const mi& a, const mi& b) {
		return a.v < b.v;
	}
	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD)
			v -= MOD;
		return *this;
	}
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0)
			v += MOD;
		return *this;
	}
	mi& operator*=(const mi& m) {
		v = v * m.v % MOD;
		return *this;
	}
	mi& operator/=(const mi& m) {
		return (*this) *= inv(m);
	}

	friend mi pow(mi a, ll p) {
		mi ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1)
				ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mi operator-() const {
		return mi(-v);
	}
	mi& operator++() {
		return *this += 1;
	}
	mi& operator--() {
		return *this -= 1;
	}
	mi operator++(int32_t) {
		mi temp;
		temp.v = v++;
		return temp;
	}
	mi operator--(int32_t) {
		mi temp;
		temp.v = v--;
		return temp;
	}
	friend mi operator+(mi a, const mi& b) {
		return a += b;
	}
	friend mi operator-(mi a, const mi& b) {
		return a -= b;
	}
	friend mi operator*(mi a, const mi& b) {
		return a *= b;
	}
	friend mi operator/(mi a, const mi& b) {
		return a /= b;
	}
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v;
		return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x;
		is >> x;
		m.v = x;
		return is;
	}
};

const int MAX = 1e5 + 5;
int N;
mi dp_down[MAX], dp_up[MAX];
vector<int> adj[MAX];

void dfs_down(int curr, int parent) {

	// choice 1: curr is painted black
	dp_down[curr] = 1; // for product

	for (int child : adj[curr]) {
		if (child != parent) {
			dfs_down(child, curr);
			dp_down[curr] *= dp_down[child];
		}
	}

	// choice 2: curr is painted white
	dp_down[curr]++;
}

void dfs_up(int curr, int parent) {

	// prefix products
	mi pref = 1;
	for (int child : adj[curr]) {
		if (child != parent) {
			dp_up[child] *= pref; // storing the product for dp_down[siblings]
			pref *= dp_down[child];
		}
	}

	// suffix products
	reverse(ALL(adj[curr]));
	mi suff = 1;
	for (int child : adj[curr]) {
		if (child != parent) {
			dp_up[child] *= suff; // storing the product for dp_down[siblings]
			suff *= dp_down[child];
		}
	}

	for (int child : adj[curr]) {
		if (child != parent) {

			dp_up[child] *= dp_up[curr]; // contribution to product for parent[child]
			dp_up[child]++;

			dfs_up(child, curr);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> MOD;
	F0R(i, N - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs_down(1, 1);
	FOR(i, 1, N) dp_up[i] = 1;
	dfs_up(1, 1);

	FOR(i, 1, N) {
		cout << dp_up[i] * (dp_down[i] - 1) << "\n";
	}

	return 0;
}
