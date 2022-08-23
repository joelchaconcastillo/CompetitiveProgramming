#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, t=1;
  while(cin>>n)
  {
    if(n==0) break;
    vector<pair<int, int> > d(n);
    for(int i = 0; i< n; i++)
    {
	int b,j;
	cin >>b >>j;
	d[i] = make_pair(-j, b);
    }
    sort(d.begin(), d.end());
    int t1=0, maxt=0;
    for(int i = 0; i < n; i++)
    {
       maxt=max(maxt, t1-d[i].first+d[i].second);
       t1 +=d[i].second;
    }
    cout <<"Case "<<t<<": "<< maxt<<endl;
    t++;
  }
  return 0;
}
