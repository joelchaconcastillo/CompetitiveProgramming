#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int main()
{
  int it;
  long long c[MAX_N+1];
  cin >> it;
  while(it--)
  {
   int n;
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>c[i];
    long long sum=0, minv[2], bestscore=LLONG_MAX, rem[2];
    minv[0]=minv[1]=bestscore;
    rem[0]=rem[1]=n;
    for(int i = 1; i <= n; i++)
    {
       sum +=c[i];
       minv[i%2] = min(minv[i%2], c[i]);
       rem[i%2]--;
       if(i>1)
       bestscore = min(bestscore, sum + rem[0]*minv[0] + rem[1]*minv[1]);
    }
    cout << bestscore <<endl;
  }
  return 0;
}
