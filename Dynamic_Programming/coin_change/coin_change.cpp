/***************************************************
 * Problem Name : coin_change.cpp
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
#define MAX 1005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

/************************************ Code Start Here ******************************************************/

// We have n coin and now we have to calculate
// number of minimum coin need to make weight

int n, weight;
int coin[MAX];
int dp[MAX][MAX];

int coin_change (int pos, int amount) {
    if (pos >= n) {
        if (amount == weight) return 1;
        else return 0;
    }

    int &res = dp[pos][amount];

    if (res != -1) {
        return res;
    }

    int res1 = 0, res2 = 0;

    // pick the pos coin
    if (amount + coin[pos] <= weight) {
        res1 = coin_change (pos, amount + coin[pos]);
    }

    // not pick the pos coin
    res2 = coin_change (pos + 1, amount);
    //~ return res = res1 | res2; ///check make or not...
    return res = res1 + res2; ///how many away...
}
int main () {
    //~ __FastIO;
    cin >> n >> weight;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    
    SET(dp, -1);

    int res = coin_change (0, 0);
    // number of coin need to make weight
    cout << res << "\n";
    return 0;
}
