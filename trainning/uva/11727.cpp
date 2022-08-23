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

int main()
{
   int T;
   scanf("%d",&T);
   for(int i = 0; i < T; i++)
   {
	int v1,v2, v3;
	scanf("%d %d %d", &v1, &v2, &v3);
	priority_queue< int > pq;
	pq.push(v1);
	pq.push(v2);
	pq.push(v3);
	pq.pop();
	printf("Case %d: %d\n", i+1, pq.top());
   }
   return 0;
}
