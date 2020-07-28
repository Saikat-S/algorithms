/***************************************************
 * Problem Name : Persistent_Segment_Tree(linked_list).cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-07-28
 * Problem Type : Data Structure
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
int ar[MAX];

struct Node {
    int data;
    Node *left, *right;
    Node (int _data = 0, Node *l = NULL, Node *r = NULL) :
        data (_data), left (l), right (r) {}


    void build (int low, int high) {
        if (low == high) {
            data = ar[low];
            return;
        }

        left = new Node();
        right = new Node();
        int mid = (high + low) / 2;
        left-> build (low, mid);
        right-> build (mid + 1, high);
        data = left->data + right->data;
    }

    Node *update (int low, int high, int pos, int val) {
        if (pos > high || pos < low) {
            return this;
        }

        if (low == high) {
            Node *tmp = new Node (data, left, right);
            tmp->data += val;
            return tmp;
        }

        int mid = (high + low) / 2;
        Node *tmp = new Node (data);
        tmp->left = left->update (low, mid, pos, val);
        tmp->right = right->update (mid + 1, high, pos, val);
        tmp->data = tmp->left->data + tmp->right->data;
        return tmp;
    }
    int query (int low, int high, int qlow, int qhigh) {
        if (low > qhigh || high < qlow) {
            return 0;
        }

        if (qlow <= low && qhigh >= high) {
            return data;
        }

        int mid = (high + low) / 2;
        int a = left-> query (low, mid, qlow, qhigh);
        int b = right->query (mid + 1, high, qlow, qhigh);
        return (a + b);
    }
} *root[MAX];

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    root[0] = new Node();
    root[0]->build (0, n - 1);
    int q;
    cin >> q;
    int h = 1;

    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int id, pos, v;
            cin >> id >> pos >> v;
            pos--;
            root[h++] = root[id]->update (0, n - 1, pos, v);

        } else {
            int id, l, r;
            cin >> id >> l >> r;
            l--, r--;
            int res = root[id]->query (0, n - 1, l, r);
            cout << res << "\n";
        }
    }

    return 0;
}
// This code is the solution of
//~ https://www.spoj.com/problems/PSEGTREE/
//~ problem
