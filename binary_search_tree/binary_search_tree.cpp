/***************************************************
 * Problem Name : binary_search_tree.cpp
 * Problem Link : Basic Code
 * Verdict      : Done
 * Date         : 2020-06-02
 * Problem Type : Data Stucture - Binary Search Tree
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
struct BST_Node {
    int data;
    BST_Node *left, *right;

    // get a ned node
    BST_Node *get_node (int value) {
        BST_Node *pNode = (BST_Node *) malloc (sizeof (BST_Node) );
        pNode->data = value;
        pNode->left = NULL;
        pNode->right = NULL;
        return pNode;
    }

    // insert value in BST
    BST_Node *insert_bst (BST_Node *root, int value) {
        if (root == NULL) {
            return get_node (value);
        }

        if (value > root->data) {
            root->right = insert_bst (root->right, value);

        } else {
            root->left = insert_bst (root->left, value);
        }

        return root;
    }

    BST_Node *minValueNode (BST_Node *root) {
        BST_Node *tmpNode = root;

        while (tmpNode != NULL && tmpNode->left != NULL) {
            tmpNode = tmpNode->left;
        }

        return tmpNode;
    }

    BST_Node *delete_bst (BST_Node *root, int key) {
        if (root == NULL) return root;

        if (key > root->data) {
            root->right = delete_bst (root->right, key);

        } else if (key < root->data) {
            root->left = delete_bst (root->left, key);

        } else {
            if (root->left == NULL) {
                BST_Node *tmpNode = root->right;
                free (root);
                return tmpNode;

            } else if (root->right == NULL) {
                BST_Node *tmpNode = root->left;
                free (root);
                return tmpNode;

            } else {
                BST_Node *tmpNode = minValueNode (root->right);
                root->data = tmpNode->data;
                root->right = delete_bst (root->right, tmpNode->data);
            }
        }
    }

    // inorder search
    void inorder_search (BST_Node *root) {
        if (root == NULL) return;

        inorder_search (root->left);
        cout << root->data << "\n";
        inorder_search (root->right);
    }
    void preorder_search (BST_Node *root) {
        if (root == NULL) return;

        cout << root->data << "\n";
        inorder_search (root->left);
        inorder_search (root->right);
    }
    // find number of element in a BST;
    int numberOfElements (BST_Node *root) {
        if (root == NULL) {
            return 0;

        } else {
            int l = numberOfElements (root->left);
            int r = numberOfElements (root->right);
            int cnt = l + r + 1;
            return cnt;
        }
    }
    // height of a BST;
    int maxDepth (BST_Node *root) {
        if (root == NULL)
            return 0;
        else {
            int l = maxDepth (root->left);
            int r = maxDepth (root->right);
            int cnt;

            if (l > r) cnt = l;
            else cnt = r;

            return cnt + 1;
        }
    }

};

int main () {
    //~ __FastIO;
    // declare the BST_Node object
    BST_Node BST;
    // create the root
    BST_Node *root = NULL;
    // insert values
    root = BST.insert_bst (root, 50);
    BST.insert_bst (root, 30);
    BST.insert_bst (root, 20);
    BST.insert_bst (root, 40);
    BST.insert_bst (root, 70);
    BST.insert_bst (root, 60);
    BST.insert_bst (root, 80);
    // print the BST in inorder
    BST.inorder_search (root);
    return 0;
}
