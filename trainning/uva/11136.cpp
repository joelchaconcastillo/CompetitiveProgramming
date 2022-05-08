#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
     if(n==0) break;
     int k, p;
     multiset<int> urn_min;
     multiset<int, greater<int> > urn_max;
     long long sum = 0;
     for(int j = 0; j < n; j++)
     {
        cin >>k;
        for(int i = 0; i < k; i++)
        {
           cin>>p, urn_min.insert(p), urn_max.insert(p);
        }
         int minv = *(urn_min.begin()), maxv=*(urn_max.begin());
         urn_min.erase(urn_min.find(minv));
         urn_min.erase(urn_min.find(maxv));
         urn_max.erase(urn_max.find(minv));
         urn_max.erase(urn_max.find(maxv));
         sum +=maxv-minv;
     }
     cout<<sum<<endl;
  }
  return 0;
}
