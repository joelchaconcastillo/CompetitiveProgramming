#include <bits/stdc++.h>
using namespace std;
int N, Q, a[200000], t[200000];

int f(int x , int idx)
{
   if(t[idx] == 1) return x+a[idx];
   else if(t[idx]==2) return max(x, a[idx]);
   else  return min(x, a[idx]);
}
int main()
{
   map<pair<int, int>, int> mem;
   cin>>N;
   for(int i = 0; i < N ; i++) cin>>a[i]>>t[i];
   cin>>Q;
   for(int i = 0; i < Q; i++)
   {
      int x;
      cin>>x;
      for(int j = 0; j < N; j++)
	  if(mem.count(make_pair(x,j))!=0)x=mem[make_pair(x,j)];
      else x =mem[make_pair(x,j)]= f(x, j);
      cout << x<<endl;
   }
}
