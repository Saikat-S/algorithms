/***************************************************
 * Algorithm name : Doubly Even Magic Square.cpp
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
void printMagicSquare(int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            printf("%3d ", magic[i][j]);
            sum += magic[i][j];
        }
        printf(" = %d\n", sum);
    }
    nl;
}
void DoublyEvenMagicSquare(int n) {
    // insert 1 to n*n;
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magic[i][j] = num++;
        }
    }
    printf("1st Fill 1 to n*n:\n");
    printMagicSquare(n);
    // Fixed Top Left Corner:
    for (int i = 0; i < n / 4; i++) {
        for (int j = 0 ; j < n / 4; j++) {
            magic[i][j] = (n  * n  + 1) - magic[i][j];
        }
    }
    printf("Fixed Top Left Corner:\n");
    printMagicSquare(n);
    // Fixed Top Right Corner:
    for (int i = 0; i < n / 4; i++) {
        for (int j = 3 * (n / 4); j < n; j++) {
            magic[i][j] = (n  * n  + 1) - magic[i][j];
        }
    }
    printf("Fixed Top Right Corner:\n");
    printMagicSquare(n);
    // Fixed Bottom Left Corner:
    for (int i = 3 * n / 4; i < n; i++) {
        for (int j = 0; j < n / 4; j++) {
            magic[i][j] = (n  * n  + 1) - magic[i][j];
        }
    }
    printf("Fixed Bottom Left Corner:\n");
    printMagicSquare(n);
    // Fixed Bottom Right Corner:
    for (int i = 3 * n / 4; i < n; i++) {
        for (int j = 3 * n / 4; j < n; j++) {
            magic[i][j] = (n  * n  + 1) - magic[i][j];
        }
    }
    printf("Fixed Bottom Right Corner:\n");
    printMagicSquare(n);
    // Fixed Center :
    for (int i = n / 4; i < 3 * n / 4; i++) {
        for (int j = n / 4; j < 3 * n / 4; j++) {
            magic[i][j] = (n  * n  + 1) - magic[i][j];
        }
    }
    printf("Fixed Center & Final Doubly Even Magic Square:\n");
    printMagicSquare(n);
}
int main () {
    int n;
    scanf("%d", &n);
    if (n % 4 != 0) {
        printf("Invalid input\n");
        return 0;
    }
    DoublyEvenMagicSquare(n);
    return 0;
}
