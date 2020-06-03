/***************************************************
 * Problem Name : Topological Sorting(E-MAX).cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2018-09-15
 * Problem Type : Graph
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX], ans;
bool vis[MAX];

void dfs (int u) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs (v);
        }
    }

    ans.pb (u);
}

void top_sort (int n) {
    SET (vis, false);
    ans.clear();

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i);
        }
    }

    reverse (all (ans) );
}

int main () {
    //~ __FastIO;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb (v);
    }

    top_sort (n);

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }

    nl;
    return 0;
}
