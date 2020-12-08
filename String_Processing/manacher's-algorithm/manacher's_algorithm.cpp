/***************************************************
 * Problem Name : manacher's_algorithm.cpp
 * Problem Link : Basic Code
 * Verdict      : done
 * Date         : 2020-12-05
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

//~ Given string str with length n. Find all the pairs (i,j) such that substring str[i...j] is a palindrome.

int d1[MAX]; // d1[i] = store the odd length subpalindrome of center i
int d2[MAX]; // d1[2] = store the even length subpalindrome of center i*

void manacher_algorithm (string str) {
    int n = (int) str.size();
    // for odd length
    int L = 0, R = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > R) ? 1 : min (d1[L + R - i], R - i + 1);

        while (0 <= i - k && i + k < n && str[i - k] == str[i + k]) {
            k++;
        }

        d1[i] = k--;

        if (i + k > R) {
            L = i - k;
            R = i + k;
        }
    }

    // for length even
    L = 0, R = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > R) ? 0 : min (d2[L + R - i + 1], d2[R - i + 1]);

        while (0 <= i - k - 1 && i + k < n && str[i - k - 1] == str[i + k]) {
            k++;
        }

        d2[i] = k--;

        if (i + k > R) {
            L = i - k - 1 ;
            R = i + k;
        }
    }
}

string  find_max_sub_palindrome (string str) {
    int n = (int) str.size();
    string res = "";
    int mx_len = 0;
    int id = -1;

    for (int i = 0; i < n; i++) {
        int tmp = d1[i] * 2 - 1;

        if (tmp > mx_len) {
            id = i;
            mx_len = tmp;
        }

        tmp = d2[i] * 2;

        if (tmp > mx_len) {
            id = i;
            mx_len = tmp;
        }
    }

    int i = id - (mx_len / 2);

    while (mx_len--) {
        res.pb (str[i++]);
    }

    return res;
}

int main () {
    //~ __FastIO;
    string str;
    cin >> str;
    manacher_algorithm (str);

    for (int i = 0; i < (int) str.size(); i++) {
        cout << d1[i] << " ";
    }

    nl;

    for (int i = 0; i < (int) str.size(); i++) {
        cout << d2[i] << " ";
    }

    nl;
    string res = find_max_sub_palindrome (str);
    //~ max sub palindrome of string S
    cout << res << "\n";
    return 0;
}
//~ input
//~ abababc


//~ resources
//~ https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
//~ https://cp-algorithms.com/string/manacher.html
