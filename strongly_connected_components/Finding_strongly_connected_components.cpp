/***************************************************
 * Problem Name : Finding strongly connected components.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2018-10-25
 * Problem Type : Graph Theory
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
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX], adjR[MAX], order, component;
bool vis[MAX];
void dfs (int u) {
    vis[u] = true;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (!vis[v]) {
            dfs (v);
        }
    }

    order.pb (u);
}
void dfs1 (int u) {
    vis[u] = true;
    component.pb (u);

    for (int i = 0; i < (int) adjR[u].size(); i++) {
        int  v = adjR[u][i];

        if (!vis[v]) {
            dfs1 (v);
        }
    }
}
int main () {
    //~ __FastIO;
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb (v);   // store actual graph
        adjR[v].pb (u);  // store reverse graph
    }

    SET (vis, false);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i);
        }
    }

    int cnt = 0;
    SET (vis, false);

    for (int i = 1; i <= n; i++) {
        int u = order[n - i];       // for 1 base graph if 0 base then [n-1-i]

        if (!vis[u]) {
            dfs1 (u);
            cnt++;

            for (int j = 0; j < (int) component.size(); j++) {
                cout << component[j] << " ";
            }

            nl;
            component.clear();
        }
    }

    cout << "Number of connected component : " <<  cnt << "\n";
    return 0;
}

