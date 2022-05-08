#include <bits/stdc++.h>
using namespace std;
int main()
{
  pair<int, int> p[200000];
  int t;
  cin>>t;
  while(t--)
  {
     int a,b,k;
      long long c=0;
     map<int, int> ca,cb;
     cin>>a>>b>>k;
     for(int i = 0; i <k;i++)
	cin>>p[i].first, ca[p[i].first]++;
     for(int i = 0; i <k;i++)
	cin>>p[i].second, cb[p[i].second]++;
     for(int i=0; i<k;i++)
	c += k-ca[p[i].first]-cb[p[i].second]+1;
     cout << c/2<<endl;

  }
  return 0;
}
