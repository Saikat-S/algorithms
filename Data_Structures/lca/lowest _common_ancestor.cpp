/***************************************************
 * Problem Name : lowest_common_ancestor.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2019-09-16
 * Problem Type : Graph
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <deque>
#include <stack>
#include <bitset>
#include <cassert>
#include <map>
#include <set>
#include <cassert>
#include <iomanip>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin)
#define __FileWrite freopen ("output.txt", "w", stdout)
#define SET(a,v) memset(a,v,sizeof(a))
#define SZ(v) (int)v.size()
#define pii pair<ll,ll>
#define pll pair <ll, ll>
#define debug cout <<"######\n"
#define debug1(x) cout <<"### " << x << " ###\n"
#define debug2(x,y) cout <<"# " << x <<" : "<< y <<" #\n"
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 10005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

/************************************ Code Start Here ******************************************************/
struct LCA {
    int par[MAX]; // store the 1st parent
    int table[MAX][16]; // store the precalculation parents
    int level[MAX]; // store the height/level of nodes
    LCA (vector<vector<int>> &adj, int n) {
        par[1] = -1;
        level[1] = 0;
        SET (table, -1);
        dfs (adj, 1, -1);  //store the height and 1st parent of each node
        build (n);  // precalculation parents for all nodes
    }
    void dfs (vector<vector<int>> &adj, int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;

            par[v] = u;
            level[v] = level[u] + 1;
            dfs (adj, v, u);
        }
    }
    void build (int n) {
        for (int i = 1; i <= n; i++) {
            table[i][0] = par[i];
        }

        for (int j = 1; (1 << j) < n; j++) {
            for (int i = 1; i <= n; i++) {
                if (table[i][j - 1] != -1) {
                    table[i][j] = table[table[i][j - 1]][j - 1];
                }
            }
        }
    }
    int query (int u, int v) {
        if (level[u] < level[v]) swap (u, v);

        int k = log2 (level[u]);  // 2^k  <= level[u]

        // make level[u] == level[v]
        for (int i = k; i >= 0; i--) {
            if ( (level[u] - (1 << i) ) >= level[v]) {
                u = table[u][i];
            }
        }

        if (u == v) return u;

        for (int i = k; i >= 0; i--) {
            if (table[u][i] != -1 && table[u][i] != table[v][i]) {
                u = table[u][i];
                v = table[v][i];
            }
        }

        return par[u];
    }
};

int main () {
    //~ __FastIO;
    int n, m; // number of node and edge
    cin >> n >> m;
    vector<vector<int>>adj (n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;   // u is parent of v
        adj[u].pb (v);
    }

    LCA lca (adj, n);
    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;
        int res = lca.query (u, v);
        cout << res << "\n";
    }

    return 0;
}
//easy problem
//https://www.spoj.com/problems/LCASQ/
