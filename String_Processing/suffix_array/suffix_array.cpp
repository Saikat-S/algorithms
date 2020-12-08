/***************************************************
 * Problem Name : suffix_array.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-12-07
 * Problem Type : String Precessing/ Data Structure
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

//~ p[i] is the index of the i-th substring (starting at i and with length 2k) in the sorted order
//~ c[i] corresponds to the equivalence class to which the substring belongs

void count_sort (vector<int> &p, vector<int> &c) {
    int n = (int) p.size();
    vector<int>cnt (n);

    for (auto x : c) {
        cnt[x]++;
    }

    vector<int> p_new (n);
    vector<int>pos (n);
    pos[0] = 0;

    for (int i = 1; i < n; i++) {
        pos[i]  = pos[i - 1] + cnt[i - 1];
    }

    for (auto x : p) {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }

    p = p_new;
}

vector<int> cyclic_sort (string const &str) {
    int n = (int) str.size();
    vector<int>p (n), c (n);
    //~ k = 0;
    vector<pair<char, int>> vec (n);

    for (int i = 0; i < n; i++) {
        vec[i] = {str[i], i};
    }

    sort (all (vec) );

    for (int i = 0; i < n; i++) {
        p[i] = vec[i].second;
    }

    c[p[0]] = 0;

    for (int i =  1; i < n; i++) {
        if (vec[i].first == vec[i - 1].first) {
            c[p[i]] = c[p[i - 1]];

        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    //~ transition part, k -> k+1;

    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort (p, c);
        vector<int>c_new (n);
        c_new[p[0]] = 0;

        for (int i =  1; i < n; i++) {
            pair<int, int> pre = {c[p[i - 1]], c[ (p[i - 1] + (1 << k) ) % n]};
            pair<int, int> now =  {c[p[i]], c[ (p[i] + (1 << k) ) % n]};

            if (pre == now) {
                c_new[p[i]] = c_new[p[i - 1]];

            } else {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }

        c = c_new;
    }

    return p;
}

void suffix_array (string str) {
    str += '$';
    vector<int>p = cyclic_sort (str);
    int n = (int) str.size();

    for (int i = 0; i < n; i++) {
        //~ cout << p[i]<< " " << str.substr(p[i], n-p[i]) << "\n";
        cout << p[i] << ' ';
    }

    nl;
}

int main () {
    //~ __FastIO;
    string str;
    cin >> str;
    suffix_array (str);
    return 0;
}

//~ resources:
//~ https://cp-algorithms.com/string/suffix-array.html
//~ https://codeforces.com/edu/course/2/lesson/2/1
