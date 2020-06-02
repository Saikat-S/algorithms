/***************************************************
 * Problem Name : segment_tree_with_lazy.cpp
 * Problem Link : Basic Code
 * Verdict      : Trying
 * Date         : 2020-06-02
 * Problem Type : Data Structure - Segment Tree
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
int ar[MAX], tr[MAX * 3], lazy[MAX * 3];

void build (int nod, int low, int high) {
    if (low > high) return ;

    if (low == high) {
        tr[nod] = ar[low];
        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    build (left, low, mid);
    build (right, mid + 1, high);
    tr[nod] = tr[left] + tr[right];
}
int query (int nod, int low, int high, int qlow, int qhigh) {
    if (low > high || low > qhigh || high < qlow) {
        return 0;
    }

    if (lazy[nod] != 0) {
        tr[nod] += (lazy[nod] * (high - low + 1) );

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low >= qlow && high <= qhigh) {
        return tr[nod];
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    int q1 = query (left, low, mid, qlow, qhigh);
    int q2 = query (right, mid + 1, high, qlow, qhigh);
    return q1 + q2;
}
void update (int nod, int low, int high, int qlow, int qhigh, int val) {
    if (low > high) return ;

    if (lazy[nod] != 0) {
        tr[nod] += (lazy[nod] * (high - low + 1) );

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low > qhigh || high < qlow) {
        return;
    }

    if (qlow >= low && high >= qhigh) {
        tr[nod] += (val * (high - low + 1) );

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] += val;
            lazy[right] += val;
        }

        return;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    update (left, low, mid, qlow, qhigh, val);
    update (right, mid + 1, high, qlow, qhigh, val);
    tr[nod] = tr[left] + tr[right];
}
int main () {
    //~ __FastIO;
    // number of element in the array;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    build (1, 0, n - 1);
    // number of query;
    int q;
    cin >> q;

    while (q--) {
        int c;
        cin >> c;

        if (c == 0) { // for query
            int l, r; // 0-based index
            cin >> l >> r;
            ll res = query (1, 0, n - 1, l, r);
            cout << res << "\n";

        } else { // for update
            int l, r, val;
            cin >> l >> r >> val;
            update (1, 0, n - 1, l, r, val); // update indx index by val;
        }
    }

    return 0;
}
