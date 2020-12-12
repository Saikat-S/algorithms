/***************************************************
 * Problem Name : longest_increasing_subsequence(nlogn).cpp
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

// find the LIS of array ar
// L[i] = max LIS until now if we pick ar[i] element

int L[MAX], I[MAX];
int LIS_NlogK (int n, int ar[]) {
    I[0] = -100000000;

    for (int i = 1; i <= n; i++) {
        I[i] = 100000000;
    }

    int Maxlen = 0;

    for (int i = 0; i < n; i++) {
        int low = 0, high = Maxlen, mid;

        while (high >= low) {
            mid = (low + high) / 2;

            if (I[mid] < ar[i]) {
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }

        I[low] = ar[i];
        L[i] = low;

        if (Maxlen < low) {
            Maxlen = low;
        }
    }

    return Maxlen;
}
void LIS_Solution (int ar[], int n) {
    vector<int>Sol;
    int i = 0;

    for (int j = 1 ; j < n; j++) {
        if (L[j] >= L[i]) {
            i = j;
        }
    }

    Sol.push_back (ar[i]);
    int top = i;

    for (int i = top - 1; i >= 0; i--) {
        if ( ar[i] < ar[top] && L[i] == L[top] - 1) {
            Sol.push_back (ar[i]);
            top = i;
        }
    }

    int sz = Sol.size();

    for (int i = sz - 1 ; i >= 0; i--) {
        cout << Sol[i] << " ";
    }

    nl;
}
int main () {
    //~ __FastIO;
    int n, ar[MAX];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int result = LIS_NlogK (n, ar);
    cout << "MAX Length is : " << result << "\n";
    LIS_Solution (ar, n);
    return 0;
}
/*
10
8 1 9 8 3 4 6 1 5 2
 */
//~ http://lightoj.com/article_show.php?article=1000
