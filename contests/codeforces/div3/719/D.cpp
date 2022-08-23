#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n, a[200000];
     map<int, long long> hash;
     cin>>n;
     for(int i = 0; i < n ; i++)
	    cin>>a[i], hash[a[i]-i+1]++;

     long long cont = 0;
     for(int i = 0; i < n ; i++)
     {
        hash[a[i]-i+1]--;
	cont+=hash[a[i]-i+1];
     }
     cout << cont <<endl;
  }
  return 0;
}
