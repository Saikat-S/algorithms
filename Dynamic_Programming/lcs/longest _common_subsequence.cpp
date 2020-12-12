/***************************************************
 * Problem Name : longest _common_subsequence.cpp
 * Problem Link : Basic Code
 * Verdict      : Trying
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

//~ Give two string A and B find the 
//~ longest commonsubsequence

string A, B, res_lcs;
int dp[MAX][MAX];

int lcs(int i, int j) {
    if (A[i] == '\0' || B[j] == '\0') return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (A[i] == B[j]) ans = 1 + LCS(i + 1, j + 1);
    else {
        int val1 = LCS(i + 1, j);
        int val2 = LCS(i, j + 1);
        ans = max(val1, val2);
    }
    return dp[i][j] = ans;
}
void print_lcs(int i, int j) {
    if (A[i] == '\0' || B[j] == '\0') {
        cout << str << "\n";
        return ;
    }
    if (A[i] == B[j]) {
        str += A[i];
        print_lcs(i + 1, j + 1);
    } else {
        if (dp[i + 1][j] > dp[i][j + 1]) print_lcs(i + 1, j);
        else print_lcs(i, j + 1);
    }
}
int main () {
    //~ __FastIO;
    return 0;
}

