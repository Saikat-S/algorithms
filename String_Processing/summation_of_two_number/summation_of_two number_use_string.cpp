/***************************************************
 * Problem Name : summation_of_two number_use string.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-06-03
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
#define MAX 100005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

/************************************ Code Start Here ******************************************************/
string add (string a, string b) {
    int al = a.size() - 1;
    int bl = b.size() - 1;
    int carry = 0;
    string result = "";

    while (al >= 0 && bl >= 0) {
        int temp = (int) (a[al] - '0') + (int) (b[bl] - '0') + carry ;
        carry = 0;

        if (temp > 9 ) {
            carry = 1;
            temp = temp - 10;
        }

        result += char (temp + '0');
        al--;
        bl--;
    }

    while (al >= 0) {
        int temp = (int) (a[al] - '0') + carry ;
        carry = 0;

        if (temp > 9) {
            carry = 1;
            temp = temp % 10;
        }

        result += char (temp + '0');
        al--;
    }

    while (bl >= 0) {
        int temp = (int) (b[bl] - '0') + carry ;
        carry = 0;

        if (temp > 9) {
            carry = 1;
            temp = temp % 10;
        }

        result += char (temp + '0');
        bl--;
    }

    if (carry) {
        result += "1";
    }

    reverse (result.begin(), result.end() );
    return result;
}

string trim (string a) { // for removing leading 0s
    string res = "";
    int i = 0;

    while (a[i] == '0') {
        i++;
    }

    int sz = a.size();

    for (; i < sz; i++) {
        res += a[i];
    }

    return res;
}
int main () {
    //~ __FastIO;
    string a, b;
    cin >> a >> b;
    string sum = trim (add (a, b) );
    cout << sum << "\n";
    return 0;
}

