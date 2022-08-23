#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     map<int, int> hash1; 
     set<int> sol;
     vector<int> f;
     int n, d;
     cin>>n;
     for(int i = 0; i < n; i++) cin>>d, hash1[d]++;
     for(auto &idx:hash1) f.push_back(idx.second), sol.insert(idx.second);
     if(sol.size()==1){cout << "0\n";continue;}
     int n2 = f.size();
     sort(f.begin(), f.end());
     vector<int>p(n2+1,0);
     p[0]=0;
     for(int i = 0; i < n2; i++) p[i+1] = p[i]+f[i];
     int minv = INT_MAX;
     for(int i = 0; i <n2; )
     {
	 int x = upper_bound(f.begin(), f.end(), f[i])-f.begin();
         minv = min(minv, p[i] + (p[n2]-p[x-1]) - (n2-x+1)*f[i] );
	 i=x;
     }
     cout << minv <<endl;
  }
  return 0;
}
