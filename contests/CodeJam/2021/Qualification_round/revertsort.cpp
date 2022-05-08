#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
  int T, d[100];
  cin >> T;
  for(int ite = 1; ite <= T; ite++)
  {
     int n, cost = 0;
    cin >>n;
   for(int i = 0; i < n; i++)cin>>d[i];

   for(int i = 0; i < n-1; i++)
   {
     pair<int, int>minv(1000000, -1);
     for(int j = i; j < n; j++)  minv = min(minv, make_pair(d[j], j));
     if(minv.second!=i) cost += minv.second-i+1, reverse(d+i, d+minv.second+1);
     else cost++;
   } 
   cout << "Case #"<<ite<<": "<<cost<<endl;
  }
  return 0;
}
