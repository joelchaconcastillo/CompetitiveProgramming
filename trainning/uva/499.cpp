#include <bits/stdc++.h>
using namespace std;
int main()
{
  string in;
  int c[300];
  while(getline(cin, in))
  {
     memset(c, 0, sizeof c);
     priority_queue<pair<int, int> > pq;
     for(auto i:in)
     {
	if(!isalpha(i))continue;
	c[i]++;
        if(pq.empty())
	{
	   pq.push(make_pair(c[i], -i));
	}
        else if(c[i] > pq.top().first)
	{
	   pq = priority_queue<pair<int, int> > ();
	   pq.push(make_pair(c[i], -i));
	}
	else if(c[i] == pq.top().first)
	{
	   pq.push(make_pair(c[i], -i));
	}
     }
     int n = pq.top().first;
     while(!pq.empty()){ cout << (char)-pq.top().second; pq.pop();}
     cout <<" "<<n<<endl; 
  }
  return 0;
}
