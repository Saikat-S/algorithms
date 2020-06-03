/***************************************************
 * Problem name : Topological Sort Basic(indegree).cpp
 * OJ           : Practice
 * Result       : Done
 * Date         : 07-04-17
 * Problem Type : Graph(Toplogical Sort)
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define pii pair<int,int>
#define MAX 10000
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
int indegree[MAX], taken[MAX];
int list[MAX];
int N, cycle = 0;
string str[MAX];
void topsort() {
    for (int i = 1; i <= N; i++) {
        int j ;

        for (j = 1; i <= N; j++) {
            if (!indegree[j] && !taken[j]) {
                taken[j] = 1;
                list[i] = j;
                int sz = adj[j].size();

                for (int k = 0; k < sz; k++) {
                    indegree[adj[j][k]]--;
                }

                indegree[j]--;
                break;
            }
        }

        if (j == N) {
            cycle = 1;
            break;
        }
    }
}
int main () {
    int E;
    scanf ("%d %d", &N, &E);

    for (int i = 1; i <= E; i++) {
        int u, v;
        scanf ("%d %d", &u, &v);
        adj[u].push_back (v);
        indegree[v]++;
    }

    topsort();

    for (int i =  1; i <= N; i++) {
        printf ("%d ", list[i]);
    }

    return 0;
}

