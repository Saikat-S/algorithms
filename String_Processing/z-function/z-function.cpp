/***************************************************
 * Problem Name : z-function.cpp
 * Problem Link : Basic Code
 * Verdict      : done
 * Date         : 2020-12-03
 * Problem Type : String
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
#define MAX 200005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

/************************************ Code Start Here ******************************************************/

// How many time a pattern occur in a text

int Z[MAX];
// Z[i] (i>0, Z[0]=0) is the value of maximum sub string that start from i
// and also a prefix of that string
void z_funtion (string str) {
    int n = (int) str.size();
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;

            while (R < n && str[R - L] == str[R]) {
                R++;
            }

            Z[i] = R - L;
            R--;

        } else {
            int k = i - L;

            if (Z[k] < R + i - 1) {
                Z[i] = Z[k];

            } else {
                L = i;

                while (R < n && str[R - L] == str[R]) {
                    R++;
                }

                Z[i] = R - L;
                R--;
            }
        }
    }
}


int main () {
    //~ __FastIO;
    string text, patten;
    cin >> text;
    cin >> patten;
    string str = patten + "$" + text;
    z_funtion (str);
    int cnt = 0;

    for (int i = (int) patten.size(); i < (int) str.size(); i++) {
        if (Z[i] == (int) patten.size() ) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
//~ resources
//~ https://ivanyu.me/blog/2013/10/15/z-algorithm/
//~ https://codeforces.com/blog/entry/3107
//~ https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/tutorial/
