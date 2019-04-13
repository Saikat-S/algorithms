/***************************************************
 * Problem name : Digit_DP.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2019-01-28
 * Problem type : Digit DP
 * Author name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
int n;
ll dp[20][2][2][2];
ll dpNum[20][2][2];
vector<int>A, B;
ll makeNumber (int pos, int isChoto, int isBoro) {
    if (pos == n) {
        return dpNum[pos][isChoto][isBoro] = 1;
    }

    if (dpNum[pos][isChoto][isBoro] != -1) {
        return dpNum[pos][isChoto][isBoro];
    }

    int low = 0, high = 9;

    if (isChoto == 0) {
        high = B[pos];
    }

    if (isBoro == 0) {
        low  = A[pos];
    }

    ll ans = 0;

    for (int i = low; i <= high; i++) {
        int new_isChoto = isChoto;
        int new_isBoro = isBoro;

        if (i < high) {
            new_isChoto = 1;
        }

        if (i > low) {
            new_isBoro = 1;
        }

        ans += makeNumber (pos + 1, new_isChoto, new_isBoro);
    }

    return dpNum[pos][isChoto][isBoro] = ans;
}
ll digitDP (int pos, int isChoto, int isBoro, int isSuru) {
    if (pos == n) return 0;

    if (dp[pos][isChoto][isBoro][isSuru] != -1) {
        return dp[pos][isChoto][isBoro][isSuru];
    }

    ll ans = 0;
    int low = 0, high = 9;

    if (isChoto == 0) {
        high = B[pos];
    }

    if (isBoro == 0) {
        low = A[pos];
    }

    for (int i = low; i <= high; i++) {
        int new_isChoto = isChoto;
        int new_isBoro = isBoro;
        int new_isSuru = isSuru;
        ll cnt = 0;

        if (i < high) {
            new_isChoto = 1;
        }

        if (i > low) {
            new_isBoro = 1;
        }

        if (i > 0) {
            new_isSuru = 1;
        }

        if (i == 0 && isSuru == 1) {
            //~ cnt = makeNumber (pos + 1, new_isChoto, new_isBoro);
            cnt = dpNum[pos + 1][new_isChoto][new_isBoro];
        }

        ans += cnt + digitDP (pos + 1, new_isChoto, new_isBoro, new_isSuru);
    }

    return dp[pos][isChoto][isBoro][isSuru] = ans;
}


ll solve (ll a, ll b) {
    A.clear(), B.clear();

    while (b > 0) {
        int rem = b % 10;
        B.pb (rem);
        b /= 10;
    }

    reverse (all (B) );

    while (a > 0) {
        int rem = a % 10;
        A.pb (rem);
        a /= 10;
    }

    n = (int) B.size();

    while ( (int) A.size() < n) {
        A.pb (0);
    }

    reverse (all (A) );
    SET (dpNum, -1);
    makeNumber (0, 0, 0);
    SET (dp, -1);
    ll ans = digitDP (0, 0, 0, 0);
    return ans;
}
int main () {
    //~ __FastIO;
    ll a, b;
    cin >> a >> b;
    ll ans = solve (a, b);

    if (a == 0) ans++;

    cout << ans << "\n";
    return 0;
}
//~ LOJ-1140 problem
//~ find how many zero between a and b
