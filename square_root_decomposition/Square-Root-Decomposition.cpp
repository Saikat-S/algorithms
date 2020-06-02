/***************************************************
 * Algorithm name : Square-Root-Decomposition.cpp
 * Date           : 2018-05-01
 * Algorithm Type : Data Structures
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
int ar[MAX];
int block[MAX];
int blockSz;
//inital the block value
void init(int sz){
    for(int i = 0; i<=sz; i++){
        block[i] = 0;
    }
}
void update(int i, int value){
    int id = i/blockSz;
    block[id] += value; 
}
int query(int L, int R){
    int l = L/blockSz;
    int r = R/blockSz;
    
    if(l == r){
        int sum = 0;
        for(int i = L; i<=R; i++){
            sum+=ar[i];
        }
        return sum;
    }
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = L; i < (l + 1)*blockSz; i++) {
        sum1 += ar[i];
    }
    for (int i = l + 1; i < r; i++) {
        sum2 +=  block[i];
    }
    for (int i = r * blockSz; i <= R; i++) {
        sum3 += ar[i];
    }
    return sum1+sum2+sum3;
    
}
int main () {
    int N, Q;
    //input number of element
    scanf("%d", &N);
    blockSz = sqrt(N);
    init(blockSz);
    for (int i = 0; i < N; i++) {
        scanf("%d", &ar[i]);
        update(i, ar[i]);
    }
    //input number of query
    scanf("%d", &Q);
    for (int q = 1; q <= Q; q++) {
        int l , r;
        scanf("%d %d", &l, &r);
        int sum = query(l-1, r-1);
        printf("%d\n", sum);
    }

    return 0;
}
