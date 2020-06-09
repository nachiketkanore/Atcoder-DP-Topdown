//Problem : https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e3 + 5, inf = 1e18, mod = 1e9 + 7;

int n, m, maxLen, dp[N][N];
string s, t;

int go(int id1, int id2){
    if(id1 >= n || id2 >= m)
        return 0;
    int& ans = dp[id1][id2];
    if(~ans)
        return ans;
    int c1 = 0;
    if(s[id1] == t[id2])
        c1 = max(c1, 1 + go(id1 + 1, id2 + 1));
    int c2 = go(id1 + 1, id2);
    int c3 = go(id1, id2 + 1);
    return ans = max({c1, c2, c3});
}

void find(int i, int j){
    if(i >= n || j >= m)
        return;

    int actual = go(i, j);

    int c1 = 0;
    if(s[i] == t[j]){
        c1 = 1 + go(i + 1, j + 1);
        if(actual == c1){
            cout << s[i];
            return find(i + 1, j + 1);
        }
    }

    int c2 = go(i + 1, j);
    if(actual == c2){
        return find(i + 1, j);
    }

    int c3 = go(i, j + 1);
    if(actual == c3){
        return find(i, j + 1);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = sz(s), m = sz(t);
    maxLen = go(0,0);
    find(0, 0);
}
