#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,d,r;
  while(cin >> n >>d >>r && n && d &&r)
  {
     vector<int> morning(n), evening(n);
     
     for(int i = 0; i < n; i++)
	cin >> morning[i];
     for(int i = 0; i < n; i++)
	cin >> evening[i];
     sort(morning.begin(), morning.end());
     sort(evening.begin(), evening.end());
     int sum = 0;
     for(int i = 0; i < n; i++)
	sum += max(0, ((morning[i]+evening[n-(i+1)])-d)*r);
     cout << sum<<endl; 

  }
  return 0;
}
