/***************************************************
 * Problem Name : rabin_karp.cpp
 * Problem Link : Basic Code
 * Verdict      : done
 * Date         : 2020-12-04
 * Problem Type : String Processing
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

const int p = 31;
const int mod = 1e9 + 9;

vector<int> rabin_karp (string const &pat, string const &txt) {
    int P = (int) pat.size();
    int T = (int) txt.size();
    vector<ll>p_pow (max (P, T) );
    p_pow[0] = 1;

    for (int i = 1; i < (int) p_pow.size(); i++) {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    }

    vector<ll> hash (T + 1, 0);

    for (int i = 0; i < T; i++) {
        hash[i + 1] = (hash[i] + (txt[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    ll pat_hash = 0;

    for (int i = 0; i < P; i++) {
        pat_hash = (pat_hash + (pat[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    vector<int> occurences;

    for (int i = 0; i + P - 1 < T; i++) {
        ll cur_h = (hash[i + P] + mod - hash[i]) % mod;

        if (cur_h == pat_hash * p_pow[i] % mod) {
            occurences.push_back (i);
        }
    }

    return occurences;
}

int main () {
    //~ __FastIO;
    string pat, txt;
    cin >> txt >> pat;
    vector<int>res = rabin_karp (pat, txt);

    if ( (int) res.size() == 0) {
        cout << "Not Found\n";

    } else {
        for (int i = 0; i < (int) res.size(); i++) {
            cout << res[i] << " ";
        }

        nl;
    }

    return 0;
}


