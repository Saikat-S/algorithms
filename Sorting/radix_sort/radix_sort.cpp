/***************************************************
 * Problem Name : radix_sort.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-12-02
 * Problem Type : sorting
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

int const range = 10;

void count_sort (int *ar, int n, int place) {
    int freq[range] = {0};
    int output[n + 3];

    for (int i = 0; i < n; i++) {
        freq[ (ar[i] / place) % range]++;
    }

    for (int i = 1; i < range; i++) {
        freq[i] += freq[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[freq[ (ar[i] / place) % range] - 1] = ar[i];
        freq[ (ar[i] / place) % range]--;
    }

    for (int i = 0; i < n; i++) {
        ar[i] = output[i];
    }
}

void radix_sort (int *ar, int n, int max_element) {
    int mul = 1;

    while (max_element) {
        count_sort (ar, n, mul);
        mul *= 10;
        max_element /= 10;
    }
}

int main () {
    //~ __FastIO;
    int n;
    int ar[MAX];
    cin >> n;
    int max_element = 0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        max_element = max (max_element, ar[i]);
    }

    radix_sort (ar, n, max_element);

    // sorted array
    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }

    nl;
    return 0;
}

//~ resources:
//~ https://www.hackerearth.com/practice/algorithms/sorting/radix-sort/tutorial/
