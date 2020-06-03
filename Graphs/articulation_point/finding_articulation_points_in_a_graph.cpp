/***************************************************
 * Problem Name : Finding articulation points in a graph.cpp
 * OJ           : Basic Code
 * Verdict      : Complete
 * Date         : 2018-08-09
 * Problem Type : Graph ( Articulation Point )
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

/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX];
int n, m, t;
bool vis[MAX], chk[MAX];
int dis[MAX], low[MAX];
void dfs (int u, int p) {
    vis[u] = true;
    dis[u] = low[u] = t++;
    int child  = 0;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        if (vis[v] == true) {
            low[u] = min (low[u], dis[v]);

        } else {
            dfs (v, u);
            low[u] = min (low[u], low[v]);

            if (dis[u] <= low[v] && p != -1 && chk[u] == 0) {
                cout << u << " is a articulation point\n";
                chk[u] = 1;
            }

            child++;
        }
    }

    if (p == -1 && child > 1 && chk[u] == 0) {
        cout << u << " is a articulation point\n";
        chk[u] = 1;
    }
}
void find_articulation_point() {
    t = 0;
    SET (vis, false);
    SET (chk, false);
    SET (dis, -1);
    SET (low, -1);

    for (int i = 1; i <= n; i++) {
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

    find_articulation_point();
    return 0;
}
/*
input :
5 4
1 5
2 5
3 5
4 5

output :
1
*/
