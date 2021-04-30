/**
 *	Author: Nachiket Kanore
 *	Created: Friday 30 April 2021 06:50:27 PM IST
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

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

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

const int MOD = 1e9 + 7;
struct mi {
	using ll = long long;
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
	mi& operator+=(const mi& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
	mi& operator-=(const mi& m) { if ((v -= m.v) < 0) v += MOD;	return *this; }
	mi& operator*=(const mi& m) { v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
			return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); return pow(a,MOD-2);	}

	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	mi operator++(int32_t) { mi temp; temp.v = v++; return temp; }
	mi operator--(int32_t) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v; return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x; is >> x;
		m.v = x;
		return is;
	}
};

mi fact[N+1];

mi paths(int x1, int y1, int x2, int y2) {
	assert(x2 >= x1 && y2 >= y1);
	int x = x2 - x1;
	int y = y2 - y1;
	return fact[x + y] / fact[x] / fact[y];
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<int,int>> blocked(k+1);
	vector<mi> dp(k+1);
	
	F0R (i,k) cin >> blocked[i].first >> blocked[i].second;
	blocked[k].first = n;
	blocked[k].second = m;
	
	sort(ALL(blocked));

	F0R (i,sz(blocked)) dp[i] = paths(1, 1, blocked[i].first, blocked[i].second);

	for (int i = 0; i < sz(blocked); i++) {
		for (int j = i + 1; j < sz(blocked); j++) {
			auto [x1, y1] = blocked[i];
			auto [x2, y2] = blocked[j];
			if (x2 >= x1 && y2 >= y1) {
				dp[j] -= dp[i] * paths(blocked[i].first, blocked[i].second, blocked[j].first, blocked[j].second);
			}
		}
	}

	cout << dp.back() << '\n';
}

int32_t main() {
	fact[0] = 1;
	FOR (i,1,N) fact[i] = i * fact[i - 1];
	solve();
}
