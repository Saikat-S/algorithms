/***************************************************
 * Problem Name : Sparse Table.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2019-09-16
 * Problem Type : Data Structure
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
#define MAX 100005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

/************************************ Code Start Here ******************************************************/
int ar[MAX]; // number of element and the array
int st[MAX][17]; // store pre calculate data index

// precomputation  sparse table
void build_st (int n) {
    // for 2^0 lenght from i index we store the actual array index
    for (int i = 0; i < n; i++) {
        st[i][0] = i;
    }

    // for j is equal 1 to log2(n)+1
    // the range [i, i + 2^j - 1] of length 2^j we splits in to
    // [i, i + 2^(j-1) - 1] and [i + 2^(j-1), i + 2^j - 1]
    for (int j = 1; j <= (1 << j); j++) {
        for (int i = 0; i + (1 << j)  <= n; i++) {
            int x = st[i][j - 1];
            int y = st[i + (1 << (j - 1) )][j - 1];

            if (ar[x] > ar[y]) {
                st[i][j] = y;

            } else {
                st[i][j] = x;
            }
        }
    }
}

// return the minimum index l to r
int query (int l, int r) {
    int len = (r - l + 1); // calculate l to r length
    int k = log2 (len);  // find the 2^k <= len
    // now l to r we can split it into [l, k] and [r - 2^k + 1, k]
    int x = st[l][k];
    int y = st[r - (1 << k) + 1][k];

    if (ar[x] > ar[y]) return y;
    else return x;
}

int main () {
    // in this problem we will find minimum number between a range l to r.
    // first we precalculalte our sparse table with O(N log N) complexity.
    // the we answer our query with O(1) complexity.
    //~ __FastIO;
    int n; // number of element in the array
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    build_st (n);
    int q; // number of query
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        int pos = query (l, r);
        cout << ar[pos] << "\n";
    }

    return 0;
}

// an easy problem LOJ 1082 - Array Queries
// http://lightoj.com/volume_showproblem.php?problem=1082
