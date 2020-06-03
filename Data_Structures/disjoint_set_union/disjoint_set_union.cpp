/***************************************************
 * Problem Name : disjoint_set_union.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-06-03
 * Problem Type : Data Stucture - Disjoint Set Union (DSU) / Union Find
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
vector<int>par; // store the parent
vector<int>size; // store the child size

void init (int n) {
    par.resize (n + 1);
    size.resize (n + 1);

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        size[i] = 1;
    }
}
// find the parent of r
int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}

void make_set (int x, int y) {
    int u = find (x);
    int v = find (y);

    if (u != v) {
        if (size[u] < size[v]) swap (u, v);

        par[v] = u;
        size[u] += size[v];
    }
}


int main () {
    // we will answer some query that how many element are in this region.
    //~ __FastIO;
    int n, m;
    cin >> n >> m; // number of node and edge
    init (n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;   // 1 .... n node
        make_set (u, v);
    }

    int q;
    cin >> q;

    while (q--) {
        int u;
        cin >> u;
        int r = find (u);
        cout << size[r] << "\n";
    }

    return 0;
}
/* input
8 4
1 3
5 1
2 4
6 7
5
1
2
5
7
8
*/