/***************************************************
 * Problem Name : longest_increasing_subsequence(n^2).cpp
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
int ar[MAX], next_index[MAX];
int dp[MAX], n;
int LIS (int pos) {
    if (dp[pos] != -1) {
        return dp[pos];
    }

    int ans = 0;

    for (int j = pos + 1; j < n; j++) {
        if (ar[j] > ar[pos]) {
            int res = LIS (j);

            if (res > ans) {
                ans = res;
                next_index[pos] = j;
            }
        }
    }

    return dp[pos] = ans + 1;
}

void find_LIS() {
    int ans = 0;
    SET (dp, -1);
    SET (next_index, -1);
    int start_index = -1;

    for (int i = 0; i < n; i++) {
        int res = LIS (i);

        if (res > ans) {
            ans = res;
            start_index = i;
        }
    }

    vector<int> lis;

    while (start_index != -1) {
        lis.push_back (ar[start_index]);
        start_index = next_index[start_index];
    }

    for (int i = 0; i < (int) lis.size(); i++) {
        cout << lis[i] << " ";
    }

    nl;
}
int main () {
    //~ __FastIO;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    find_LIS();
    return 0;
}
/*
10
8 1 9 8 3 4 6 1 5 2
 */
//~ http://www.shafaetsplanet.com/?p=3749
