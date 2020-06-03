/***************************************************
 * Problem Name : dijkstra.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-06-03
 * Problem Type : Graph - Dijkstra
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
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define MAX 100005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX], cost[MAX];
int dis[MAX];
struct node {
    int x, w;
    node (int a, int c) {
        x = a;
        w = c;
    }
    //~ bool operator < ( const node &p ) const {
    //~ return w > p.w;
    //~ }
};
bool operator < (node a, node b) {
    return a.w > b.w;
}
void dijkstra (int s) {
    for (int i = 0; i < MAX; i++) {
        dis[i] = INF;
    }

    priority_queue<node>pq;
    pq.push (node (s, 0) );
    dis[s] = 0;

    while (!pq.empty() ) {
        node top = pq.top();
        int u = top.x;
        pq.pop();

        if (dis[u] != top.w) continue;

        int sz = adj[u].size();

        for (int i = 0; i < sz; i++) {
            int v = adj[u][i];
            int w = cost[u][i];

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push (node (v, dis[v]) );
            }
        }
    }
}
int main () {
    //~ __FastIO;
    // node and edge
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb (v);  // store the graph
        adj[v].pb (u);
        cost[u].pb (v);  // store the cost
        cost[v].pb (u);
    }

    int s, d;
    cin  >> s >> d;
    dijkstra (s);
    cout << dis[d] << "\n";
    return 0;
}
