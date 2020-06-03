/***************************************************
 * Problem Name : Binary_Index_Tree.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2018-10-02
 * Problem Type : Data Structure (BInary Index Tree)
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
#define MAX 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
int tree[MAX];

//~ for find Next id :
//~ 1)  2's complement the id
//~ 2) then AND(&) with id
//~ 3) then add(+) with id
int getNext (int id) {
    return id + (id & -id);
}

//~ for find Parent id :
//~ 1)  2's complement the id
//~ 2) then AND(&) with id
//~ 3) then sub(-) from id
int getPar (int id) {
    return id - (id & - id);
}
void update (int id, int n, int val) {
    while (id <= n) {
        tree[id] += val;
        id = getNext (id);
    }
}
int query (int id) {
    id++;
    int sum = 0;

    while (id > 0) {
        sum += tree[id];
        id = getPar (id);
    }

    return sum;
}
void build (int ar[], int n) {
    for (int i = 1 ; i <= n ; i++) {
        update (i, n, ar[i - 1]);
    }
}
int main () {
    //~ __FastIO;
    int n;
    int ar[MAX];
    cin >> n ;         // input number of elements

    for (int i = 0; i < n; i++) {
        cin >> ar[i];              // input element
    }

    build (ar, n);  // build the fenwick tree or binary index tree for sum
    int Q;
    cin >> Q;    // input number of query

    while (Q--) {
        int c, x, val;
        cin >> c;

        if (c == 1) {
            cin >> x >> val;              // input the update index and value
            update (x, n, val - ar[x]);   // update value in index x (0-base index)

        } else {
            cin >> x;                    // input the query index
            cout << query (x) << "\n";   // query for sum 0 to x(0-base index) index
        }
    }

    return 0;
}

