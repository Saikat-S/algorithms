/***************************************************
 * Algorithm name : Breadth-first-search-basic.cpp                                                                             
 * Date           : 2018-04-24                         
 * Algorithm Type : Graph (Shortest Path)                               
 * Author Name    : Saikat Sharma
 * University     : CSE,MBSTU                     
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
//adj vector hold the graph
vector<int>adj[MAX];
//cost array hold the cost from source
int cost[MAX];
bool vis[MAX];

int bfs(int s, int d){
    queue<int>Q;
    vis[s] = true;
    cost[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i = 0; i<(int)adj[u].size(); i++){
            int v = adj[u][i];
            if(vis[v] == false){
                vis[v] = true;
                cost[v] = cost[u] + 1;
                Q.push(v);
            }
        }
    }
    return cost[d];
}
int main () {
    //number of node and edge
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        //make bidirectional adj. list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //input source and destination
    int s, d;
    scanf("%d %d", &s, &d);
    
    SET(vis, false);
    SET(cost, 0);
    int minCost = bfs(s, d);
    
    printf("From %d to %d cost = %d\n", s, d, minCost);

    return 0;
}
