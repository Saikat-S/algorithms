/***************************************************
 * Problem Name : Trie.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-01-14
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
struct TrieTree {
    TrieTree *child[27];
    bool isWord;

    TrieTree *create_node() {
        TrieTree *newNode = new TrieTree;
        newNode->isWord = false;

        for (int i = 0; i < 2; i++) {
            newNode->child[i] = NULL;
        }

        return newNode;
    }

    void insert (TrieTree *root, string key) {
        TrieTree *tmpNode = root;

        for (int i = 0; i < (int) key.size(); i++) {
            int indx = key[i] - 'a';

            if (tmpNode->child[indx] == NULL) {
                tmpNode->child[indx] = create_node();
            }

            tmpNode = tmpNode->child[indx];
        }

        tmpNode->isWord = true;
    }

    int search (TrieTree *root, string key) {
        TrieTree *tmpNode = root;

        for (int i = 0; i < (int) key.size(); i++) {
            int indx = key[i] - 'a';

            if (tmpNode->child[indx] != NULL) {
                tmpNode = tmpNode->child[indx];

            } else {
                return 0;
            }
        }

        if (tmpNode->isWord == true) {
            return 1;

        } else {
            return 0;
        }
    }

};
int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    TrieTree Trie;
    TrieTree *root = Trie.create_node();

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        Trie.insert (root, str);
    }

    int q;
    cin >> q;

    while (q--) {
        string str;
        cin >> str;
        int flag = Trie.search (root, str);

        if (flag == 1) {
            cout << str << " is found.\n";

        } else {
            cout << str << " is not found\n";
        }
    }

    return 0;
}
