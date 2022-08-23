#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int main()
{
 long long n, t;
 long long d[MAX_N];
 cin >> n >> t;
 d[0]= 0;
 for(int i = 1; i <= n; i++){ cin >>d[i]; d[i]+=d[i-1];}
 while(t--)
 {
   long long ai;
   cin >> ai;
   ai %=d[n];
   int idx = upper_bound(d, d+n+1, ai)-d;
   cout << idx<<endl;
 }
 return 0;
}
