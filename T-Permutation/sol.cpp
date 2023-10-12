/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 12 October 2023 10:33:30 PM IST
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

const int MAX = 3005;
int N;
string S;
bool vis[MAX][MAX];
mi dp[MAX][MAX];

/* mi go(int id, int put_here) {
	if (id == 1) {
		return (put_here == 1 ? 1 : 0);
	}

	if (vis[id][put_here]) {
		return dp[id][put_here];
	}

	vis[id][put_here] = true;
	mi& ans = dp[id][put_here];

	const char which = S[id - 2];

	int L, R;
	if (which == '<') {
		L = 1, R = put_here - 1;

		ans += go_pref(id - 1, R) - go_pref(id - 1, L - 1);
	}
	if (which == '>') {
		L = put_here, R = id - 1;
		ans += go_pref(id - 1, R) - go_pref(id - 1, L - 1);
	}

	// put_here in range [1, id]
	// previous in range [1, id - 1]

	FOR(prev, 1, id - 1) {
		// suppose the construction of length id-1 was [id-1, id-2, ... 3, 2, 1]
		// now we are attempting to make it [id-1, id-2, ... 3, 2, 1, put_here]
		// this should be valid permutation of length = put_here
		// rearranged values = [1, 2, 3, 4, ... put_here - 1, put_here]
		// here we need to +1 all values in range [put_here, put_here + 1, ... id]
		// to make it a valid permutation
		//
		// for our DP, we only care about the previous chosen value of the permutation
		// it will be +1 if it is >= put_here
		// else it will remain the same
		int prev_real = prev;
		if (prev >= put_here) {
			prev_real += 1;
		}

		if ((which == '<' && prev_real < put_here) || (which == '>' && prev_real > put_here)) {
			ans += go(id - 1, prev);
		}
	}

	return ans;
}

mi go_pref(int id, int put_here) {
	if (put_here == 0)
		return 0;

	mi ans = go(id, put_here) + go(id, put_here - 1);

	return ans;
} */

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// O(N^2) solution
	cin >> N >> S;

	/* mi answer = 0;

	FOR(last_element, 1, N) {
		answer += go(N, last_element);
	} */

	dp[1][1] = 1;

	FOR(id, 2, N) {
		// For prefix sums from previous dp row values
		vector<mi> previous_dp_pref(id);
		F0R(j, id) {
			previous_dp_pref[j] = dp[id - 1][j];
			if (j) {
				previous_dp_pref[j] += previous_dp_pref[j - 1];
			}
		}

		// choices for what the last element of the permutation of length id
		// could be
		FOR(put_here, 1, id) {
			if (S[id - 2] == '<') {
				int L = 1, R = put_here - 1;
				dp[id][put_here] += (previous_dp_pref[R] - previous_dp_pref[L - 1]);
			}
			if (S[id - 2] == '>') {
				int L = put_here, R = id - 1;
				dp[id][put_here] += (previous_dp_pref[R] - previous_dp_pref[L - 1]);
			}
			/* FOR(prev, 1, id - 1) {
				int real_prev = prev;
				if (prev >= put_here)
					++real_prev;

				if (S[id - 2] == '<' && real_prev < put_here) {
					dp[id][put_here] += dp[id - 1][prev];
					// sum of dp[id - 1][x]
					// x in range [1, put_here - 1]
				} else if (S[id - 2] == '>' && real_prev > put_here) {
					dp[id][put_here] += dp[id - 1][prev];
					// sum of dp[id - 1][x]
					// x in range [put_here, id - 1]
				}
			} */
		}
	}

	mi answer = 0;
	FOR(last_element, 1, N) {
		answer += dp[N][last_element];
	}
	cout << answer << '\n';

	return 0;
}
