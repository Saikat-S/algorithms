/***************************************************
 * Problem Name : bitwise_sieve.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2018-12-06
 * Problem Type : Number Theory
 * Author Name  : Saikat Sharma
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
#define MAX 100000005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
#define max 100000000  // max prime number
#define lmt 10000      // sqrt(MAX)

unsigned flag[max / 64];
int prime[max], total;

#define chkC(n) (flag[n>>6] & (1<<((n>>1) & 31))) // checks if n is a composite (if correspondent bit is 1)
#define setC(n) (flag[n>>6] |= (1 <<((n>>1) & 31))) // sets n as a composite (by making correspondent bit 1)

void sieve() {
    unsigned i, j, k;
    flag[0] |= 0;

    for (i = 3; i < lmt; i += 2) {
        if (!chkC (i) ) {
            for (j = i * i, k = i << 1; j < max; j += k) {
                setC (j);
            }
        }
    }

    prime[ (j = 0)++] = 2;

    for (i = 3; i < max; i += 2) {
        if (!chkC (i) ) {
            prime[j++] = i;
            cout << prime[j - 1] << "\n";
        }
    }

    total = j - 1;
}
int main () {
    //~ __FastIO;
    sieve();
    return 0;
}

