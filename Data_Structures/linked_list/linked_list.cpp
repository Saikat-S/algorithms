/***************************************************
 * Problem Name : listed_list.cpp
 * Problem list : Basic Code
 * Verdict      : Done
 * Date         : 2020-12-25
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

struct Node {
    int data;
    struct Node *next;
};

class listEDLIST {
    public:
        Node *root;

        listEDLIST() {
            root = new Node();
            root->next = NULL;
        }

        Node *create_node (int val) {
            Node *new_node = new Node();
            new_node->data = val;
            new_node->next = NULL;
            return new_node;
        }

        void insert_node (int val) {
            Node *tmp = root;

            while (tmp->next != NULL) {
                tmp = tmp->next;
            }

            Node *new_n = create_node (val);
            tmp->next = new_n;
        }

        void insert_nth_index (int indx, int val) {
            Node *tmp = root;
            int cnt = 0;

            while (tmp->next != NULL) {
                cnt++;

                if (cnt == indx) {
                    Node *new_n = create_node (val);
                    new_n->next = tmp->next;
                    tmp->next = new_n;
                    break;
                }

                tmp = tmp->next;
            }
        }


        void print() {
            Node *tmp = root->next;
            cout << "List : ";

            while ( tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }

            nl;
        }
        void print_by_index (int indx) {
            Node *tmp = root->next;
            int val = -1;
            int id = 0;

            while (tmp != NULL) {
                id++;

                if (id == indx) {
                    val = tmp->data;
                }

                tmp = tmp->next;
            }

            if (val == -1) {
                cout << "index not found!\n";

            } else {
                cout << indx << " index value : " << val << "\n";
            }
        }

        void search_by_val (int val) {
            Node *tmp = root->next;
            int id = 0;
            bool chk = 0;

            while (tmp != NULL) {
                id++;

                if (tmp->data == val) {
                    chk = 1;
                    break;
                }

                tmp = tmp->next;
            }

            if (!chk) {
                cout << val << " not found!\n";

            } else {
                cout << val << " found is index " << id << '\n';
            }
        }

        void delete_by_val (int val) {
            Node *tmp = root;

            while (tmp->next != NULL) {
                if (tmp->next->data == val) {
                    Node *d_tmp = tmp->next;
                    tmp->next = tmp->next->next;
                    delete  d_tmp ;
                    break;
                }

                tmp = tmp->next;
            }

            cout << "delete " << val << "\n";
        }
        void delete_by_indx (int indx) {
            Node *tmp = root;
            int cnt = 0;

            while (tmp->next != NULL) {
                cnt++;

                if (cnt == indx) {
                    Node *d_tmp = tmp->next;
                    tmp->next = tmp->next->next;
                    delete  d_tmp ;
                    break;
                }

                tmp = tmp->next;
            }

            cout << "delete " << indx << "\n";
        }

        void revese_linklist() {
            Node *pre, *current, *nxt;
            current = root->next;
            pre = NULL;

            while (current != NULL) {
                nxt = current->next;
                current->next = pre;
                pre = current;
                current = nxt;
            }

            root->next = pre;
        }
        void reverseBetween (int m, int n) {
            if (m == n) return;

            Node *pre, *cur, *nxt;
            pre = NULL;
            cur = root->next;

            for (int i = 1; i < m; i++) {
                nxt = cur->next;
                pre = cur;
                cur = nxt;
            }

            Node *pre1 = pre;
            Node *cur1 = cur;
            int cnt = (n - m) + 1;

            while (cur != NULL) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
                cnt--;

                if (cnt <= 0) break;
            }

            if (m == 1) {
                root->next = pre;
                cur1->next = cur;

            } else {
                pre1->next = pre;
                cur1->next = cur;
            }
        }
};


int main () {
    //~ __FastIO;
    listEDLIST list;
    //~ // insert
    list.insert_node (1);
    list.insert_node (4);
    list.insert_node (2);
    list.insert_node (7);
    // print all
    list.print();
    //print by index
    list.print_by_index (2);
    list.print_by_index (5);
    list.print_by_index (1);
    list.print_by_index (4);
    //search by val
    list.search_by_val (2);
    list.search_by_val (3);
    list.search_by_val (1);
    // insert nth pos
    list.insert_nth_index (3, 10);
    list.print();
    list.insert_nth_index (1, 100);
    list.print();
    list.insert_nth_index (4, 200);
    list.print();
    //delete by value
    list.delete_by_val (200);
    list.print();
    //delete by indx
    list.delete_by_indx (6);
    list.print();
    //reverse linklist
    list.revese_linklist();
    list.print();
    //reverse linklist index m to n
    list.reverseBetween (1, 3);
    list.print();
    return 0;
}
