#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     long long n, d[100000];
     cin>>n;
     for(int i = 0; i < n; i++)cin>>d[i];
     if(n <=1){cout <<"1\n"; continue;}
     sort(d, d+n);
     set<pair<long long, int > > heap;
     for(int i = 0; i < n-1; i++) heap.insert(make_pair(d[i+1]-d[i], i+1));
     while(!heap.empty() && n>1 && heap.begin()->first < d[n-1])
     {
	heap.erase(make_pair(d[n-1]-d[n-2], n-1));
	n--;
     }
     cout << n <<endl;

  }
  return 0;
}
