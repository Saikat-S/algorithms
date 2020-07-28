/***************************************************
 * Problem Name : heap_sort.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-06-09
 * Problem Type : Sorting
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
int ar[MAX];
int total_node;
void max_heapify (int par) {
    int L = 2 * par;
    int R = 2 * par + 1;

    if (R <= total_node) {
        if (ar[R] >= ar[L] && ar[R] > ar[par]) {
            swap (ar[par], ar[R]);
            max_heapify (R);

        } else if (ar[L] >= ar[R] && ar[L] > ar[par]) {
            swap (ar[par], ar[L]);
            max_heapify (L);
        }

    } else if (L <= total_node) {
        if (ar[L] > ar[par]) {
            swap (ar[par], ar[L]);
            max_heapify (L);
        }
    }
}
void heapSort () {
    for (int i = total_node; i >= 1; i--) {
        swap (ar[1], ar[i]);
        total_node--;
        max_heapify (1);
    }
}
int main() {
    //~ __FastIO;
    cin >> total_node;
    int n = total_node;

    for (int i = 1; i <= total_node; i++) {
        cin >> ar[i];
    }

    for (int i = total_node / 2; i >= 1; i--) {
        max_heapify (i);
    }

    heapSort();

    for (int i = 1; i <= n; i++) {
        cout << ar[i] << ' ';
    }

    nl;
    return 0;
}
/*input :
8
2 5 3 6 8 7 9 4
*/
