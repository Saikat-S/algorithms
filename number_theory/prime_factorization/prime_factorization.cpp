/***************************************************
 * Problem Name : prime_factorization.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-02-27
 * Problem Type : Number Theory
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

// find the prime factor of an integer

vector<int>prime, factors;
char mark[MAX];
void sieve (int n) {
    int sq = sqrt (n) + 1;
    mark[0] = mark[1] = 1;

    for (int i = 4; i <= n; i += 2) {
        mark[i] = 1;
    }

    for (int i = 3; i <= sq; i+=2) {
        for (int j = i * i; j <= n; j += (2 * i) ) {
            mark[j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!mark[i]) prime.pb (i);
    }
}
void prime_factorize (int n) {
    int sq = (int) sqrt (n);

    for (int i = 0; i < (int) prime.size() && prime[i] <= sq; i++) {
        if (mark[n] == 0) break;

        while (! (n % prime[i]) ) {
            n /= prime[i];
            factors.pb (prime[i]);
        }

        sq = (int) sqrt (n);
    }

    if (n != 1) {
        factors.pb (n);
    }
}

int main () {
    //~ __FastIO;
    sieve (MAX - 3);
    int n;
    cin >> n;
    prime_factorize (n);

    for (int i = 0; i < (int) factors.size(); i++) {
        cout << factors[i] << " ";
    }

    nl;
    return 0;
}
