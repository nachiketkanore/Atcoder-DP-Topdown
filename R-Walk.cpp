#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;
const int MOD = 1e9 + 7;

int SZ;
set<int> g[102];

int add(int a, int b)
{
    int res = a + b;
    if(res >= MOD)
        return res - MOD;
    return res;
}

int mult(int a, int b)
{
    long long res = a;
    res *= b;
    if(res >= MOD)
        return res % MOD;
    return res;
}

struct matrix
{
    int arr[102][102];

    void reset()
    {
        memset(arr, 0, sizeof(arr));
    }

    void makeiden()
    {
        reset();
        for(int i=0;i<SZ;i++)
        {
            arr[i][i] = 1;
        }
    }

    matrix operator + (const matrix &o) const 
    {
        matrix res;
        for(int i=0;i<SZ;i++)
        {
            for(int j=0;j<SZ;j++)
            {
                res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
            }
        }
        return res;
    }

    matrix operator * (const matrix &o) const 
    {
        matrix res;
        for(int i=0;i<SZ;i++)
        {
            for(int j=0;j<SZ;j++)
            {
                res.arr[i][j] = 0;
                for(int k=0;k<SZ;k++)
                {
                    res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
                }
            }
        }
        return res;
    }
};

matrix power(matrix a, int b)
{
    matrix res;
    res.makeiden();
    while(b)
    {
        if(b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    int n, k;
    cin >> n >> k;
    SZ = n;

    //Remember : nodes are kept 0-indexed
    FOR(i,0,n-1) FOR(j,0,n-1) {
        int yes;
        cin >> yes;
        if(yes) {
            g[i].insert(j);
        }
    }

    matrix M;
    FOR(start,0,n-1) {
        FOR(to,0,n-1) {
            if(g[start].count(to) > 0) 
                M.arr[start][to] = 1;
            else
                M.arr[start][to] = 0;
        }
    }

    M = power(M, k);
    int ans = 0;
    FOR(start,0,n-1) FOR(to,0,n-1) {
        ans = (ans + M.arr[start][to]) % MOD;
    }
    cout << ans << '\n';
}
