//Problem : https://atcoder.jp/contests/dp/tasks/dp_g

#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;

int n, m, u, v, visited[N], dp[N];
std::vector<int> g[N], comp;

void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs(u);
    }
    comp.push_back(v);
}

void topological_sort() {
    comp.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(comp.begin(), comp.end());
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
    }

    topological_sort();

    for(int x : comp){
        for(int adj : g[x])
            dp[adj] = max(dp[adj], dp[x] + 1);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}
