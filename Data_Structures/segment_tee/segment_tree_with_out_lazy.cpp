/***************************************************
 * Problem Name : segment_tree_with_out_lazy.cpp
 * Problem Link : basic code
 * Verdict      : done
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
int ar[MAX], tr[MAX * 4];

// build segmnet tree
void build (int node, int low, int high) {
    if (low == high) {
        tr[node] = ar[low];
        return ;
    }

    int mid = (low + high) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    build (left, low, mid);
    build (right, mid + 1, high);
    //~ tr[node] = min(tr[left], tr[right]); // for find min
    tr[node] = (tr[left] +  tr[right]);  // for find sum
}

// query to find l to r sum;
int query (int node, int low, int high, int qlow, int qhigh) {
    if (qlow > high || qhigh < low) {
        return 0;
    }

    if (qlow <= low && qhigh >= high ) {
        return tr[node];
    }

    int mid = (high + low) / 2;
    int left = node * 2 ;
    int right = node * 2 + 1;
    int a = query (left, low, mid, qlow, qhigh);
    int b = query (right, mid + 1, high, qlow, qhigh);
    return (a + b);
}

// update index i to value;
void update (int node, int low, int high, int i, int value) {
    if (i > high  || i < low) return ;

    if (low >= i && high <= i) {
        tr[node] = value;
        return ;
    }

    int mid = (low + high) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    update (left, low, mid, i, value);
    update (right, mid + 1, high, i, value);
    tr[node] = (tr[left] +  tr[right]);
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
            int indx, val;
            cin >> indx >> val;
            update (1, 0, n - 1, indx, val); // update indx index by val;
            ar[indx] = val;
        }
    }

    return 0;
}
