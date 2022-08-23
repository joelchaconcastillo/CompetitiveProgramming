#include<bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int n,d;
    cin >>n;
    map<int, int> freq;
    for(int i = 0; i < n; i++) cin >>d, freq[d]++;
    priority_queue< pair<int, int> > pq;
    for(auto &idx:freq)
	pq.push(make_pair(idx.second, idx.first));
    int s=n;
    while(pq.size()>1)
    {
       pair<int, int> pp1 = pq.top();
       pq.pop();
       pair<int, int> pp2 = pq.top();
       pq.pop();
       pp1.first--;
       pp2.first--;
       s-=2;
       if(pp1.first>0)
       pq.push(make_pair(pp1.first, pp1.second)); 
       if(pp2.first>0)
       pq.push(make_pair(pp2.first, pp2.second)); 
    }
    cout << s<<endl;
  }
  return 0;
}
