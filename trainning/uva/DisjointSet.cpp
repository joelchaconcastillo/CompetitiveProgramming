#include <bits/stdc++.h>
using namespace std;
//Suppress some compilation warning messages (only for VC++ users)
#define _CRT_SECURE_NO_DEPRECATE
//Shortcuts for "common" data types in contests
typedef long long ll; //comments that are mixed in with code
typedef pair<int, int> ii; //are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 //1 billion, safer than 2B for Floyd Warshall's

// Common memset settings
//memset(memo, -1,  sizeof memo); //initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);     // to clear array of integers

//several shorcuts that are frequently used:
// ans = a ? b : c;
// ans +=val
// index = (index+1) %n;
// index = (index + n - 1) % n;
// int ans = (int) ((double)d + 0.5); //for rounding to nearest integer
// ans = min(ans, new_computation);  //min/max shortcut // alternative form but not used in this book: ans<?= new_computation
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000);
void initSet(int _size){ pset.resize(_size); REP(i, 0, _size - 1) pset[i]=1;}
int findSet(int i ){ return (pset[i]==i) ? i : (pset[i] = findSet(pset[i]));}
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j);}
bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
int main()
{

   return 0;
}
