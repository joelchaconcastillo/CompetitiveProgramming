#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> ai(n);
  for(int i = 0; i < n; i++)
	cin >> ai[i];
  long long sum = ai[n-1];

  int bef = max(ai[n-1]-1,0);
   
  for(int i = n-2; i >=0; i--)
  {
     int v = min(ai[i], bef);
     sum += v;
     bef = max(0,v-1);
  }
  cout << sum <<endl;
  
  return 0;
}
