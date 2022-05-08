#include <bits/stdc++.h>
using namespace std;

pair<int, int> d[100001];
int lazyunionL(int idxL)
{
   return (idxL==d[idxL].first)?idxL:(d[idxL].first=lazyunionL(d[idxL].first));
}
int lazyunionR(int idxR)
{
   return (idxR==d[idxR].second)?idxR: (d[idxR].second=lazyunionR(d[idxR].second));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int S, B;
  while(cin>>S>>B)
  {
    if(S==0 &&B == 0) break;
    for(int i =0; i <= S+1; i++) d[i].first = i-1, d[i].second=i+1;
    
    for(int i = 0; i < B; i++)
    {
	int L, R;
        cin >>L>>R;
	d[d[R].second].first=d[L].first;
	d[d[L].first].second = d[R].second;

       if( d[L].first ==0)cout << "* ";
	else cout << d[L].first<<" ";
	if(d[R].second==S+1)cout << "*\n";
	else cout << d[R].second<<"\n";
    }
    cout << "-"<<endl;
  }
  return 0;
}
