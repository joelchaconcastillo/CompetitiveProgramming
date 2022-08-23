#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   vector<int>deg(n, 0);
   pair<int,int> maxd(-1,-1);
   vector<pair<int,int> >edgelist;
   for(int i = 0; i < n-1; i++)
   {
	int x,y;
	cin >> x >>y;
	x--, y--;
	edgelist.push_back(make_pair(x,y));
	deg[x]++;
	deg[y]++;
	if( deg[x]>maxd.second)
	maxd = make_pair(x, deg[x]);
	if( deg[y]>maxd.second)
	maxd = make_pair(y, deg[y]);

   }
   int idx1=0, idx2=maxd.second;
   for(auto &p:edgelist)
   {
       if(p.first==maxd.first || p.second ==maxd.first)
	       cout <<idx1++<<endl;
       else
	       cout << idx2++<<endl;
   }	
   return 0;
}
