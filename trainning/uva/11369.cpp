#include <bits/stdc++.h>
#define MAX_N 20000
using namespace std;
int main()
{
 int t, n, d[MAX_N];
 cin>>t;
 while(t--)
 {
    cin >> n;
    for(int i = 0; i < n; i++) cin>>d[i];
    sort(d, d+n);
    int maxc = 0, i=n-3;
    while(i >=0) maxc +=d[i], i-=3;
   cout << maxc <<endl;
   
 }
 return 0;
}
