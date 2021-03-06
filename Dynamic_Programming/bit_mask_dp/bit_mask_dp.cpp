/***************************************************
 * Problem Name : bit_mask_dp.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-12-12
 * Problem Type : DP
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

int w[20][20];
int n;
int dp[ (1 << 15) + 2];

int Set (int N, int pos) {
    return N = (N | (1 << pos) );
}
int reset (int N, int pos) {
    return N = (N & ~ (1 << pos) );
}
bool check (int N, int pos) {
    return (bool) (N & (1 << pos) );
}

int call (int mask) {
    if (mask == (1 << n) - 1) return 0;

    if (dp[mask] != -1) return dp[mask];

    int mn = 1 << 28;

    for (int i = 0; i < n; i++) {
        if (check (mask, i) == 0) {
            int price = w[i][i];

            for (int j = 0; j < n; j++) {
                if (i != j and check (mask, j) != 0) {
                    price += w[i][j];
                }
            }

            int ret = price + call (Set (mask, i) );
            mn = min (mn, ret);
        }
    }

    return dp[mask] = mn;
}
int main() {
    //~ __FastIO;
    SET (dp, -1);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf ("%d", &w[i][j]);
        }
    }

    int ret = call (0);
    printf ("%d\n", ret);
    return 0;
}
