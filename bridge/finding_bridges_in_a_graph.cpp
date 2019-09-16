/***************************************************
 * Problem Name : Finding bridges in a graph(Emax).cpp
 * OJ           : Basic Code
 * Verdict      : Complete
 * Date         : 2018-08-09
 * Problem Type : Graph ( Bridge)
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
vector<int>adj[MAX];
bool vis[MAX];
int low[MAX], dis[MAX];
int n, m;
int t;
void dfs (int u, int p) {
    vis[u] = true;
    dis[u] = t;
    low[u] = t;
    t++;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        if (vis[v] == true) {
            low[u] = min (low[u], dis[v]);

        } else {
            dfs (v, u);
            low[u] = min (low[u], low[v]);

            if (low[v] > dis[u]) {
                cout << u << " to " << v << " has a bridge\n";
            }
        }
    }
}
void find_bridge() {
    SET (vis, false);
    SET (low, -1);
    SET (dis, -1);
    t = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs (i, -1);
    }
}
int main () {
    //~ __FastIO;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    find_bridge();
    return 0;
}
/*
input :
8 6
0 1
1 2
1 3
2 3
3 4
7 6

output :
0 1
3 4
6 7
Basic code problem uva 796 - Critical Links
*/
