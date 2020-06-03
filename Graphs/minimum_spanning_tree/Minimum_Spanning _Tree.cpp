/***************************************************
 * Problem name : Minimum Spanning Tree.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2017-07-29
 * Problem Type : Graph (MST)
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 1000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX], W[MAX];
int par[MAX];
struct edges {
    int u, v, w;
    bool operator< (const edges &p) const {
        return w < p.w;
    }
};
vector<edges>e;
int find (int r) {
    return (par[r] == r) ? r : (par[r] = find (par[r]) );
}
int MST (int n) {
    sort (e.begin(), e.end() );

    for (int i = 0; i < n; i++) {
        par[i] = i;
    }

    int cnt = 0, s = 0, sz = e.size();

    for (int i = 0; i < sz; i++) {
        int u = find (e[i].u);
        int v = find (e[i].v);

        if (u != v) {
            par[u] = v;
            cnt++;
            s += e[i].w;

            //~ for store the tree:
            //~ adj[u].push_back(v);
            //~ adj[v].push_back(u);
            //~ W[u].push_back(e[i].w);
            //~ W[v].push_back(e[i].w);
            if (cnt == n - 1) break;
        }
    }

    return s;
}
int main () {
    int E, N;
    scanf ("%d %d", &N, &E);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf ("%d %d %d", &u, &v, &w);
        edges get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back (get);
    }

    //~ MST(N);
    printf ("Minimum Spanning Tree: %d\n", MST (N) );
    return 0;
}
