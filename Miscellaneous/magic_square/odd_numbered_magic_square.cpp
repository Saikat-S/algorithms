/***************************************************
 * Algorithm name : Odd-Numbered Magic Square.cpp
 * Date           : 2018-04-20
 * Algorithm Type : Magic Square
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
#define MAX 105
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
int magic[MAX][MAX];
void oddMagicSquare(int n) {
    int i = n / 2;
    int j = n - 1;
    for (int num = 1; num <= n * n; ) {
        if (i == -1 && j == n) {
            i = 0;
            j = n - 2;
        } else {
            if (i < 0) {
                i = n - 1;
            }
            if ( j == n) {
                j = 0;
            }
        }
        if (magic[i][j] != 0) {
            i++;
            j = j - 2;
        } else {
            magic[i][j] = num++;
            i--;
            j++;
        }
    }

    printf("Odd Magic Square:\n");
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            printf("%3d ", magic[i][j]);
            sum += magic[i][j];
        }
        printf(" = %d\n", sum);
    }
}
int main () {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("Invalid input\n");
        return 0;
    }
    oddMagicSquare(n);
    return 0;
}
