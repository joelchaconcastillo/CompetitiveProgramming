#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  int n, s[200000], q[200000];
  cin >> T;
  while(T--)
  {
     cin >>n;
     memset(s, 0, sizeof s);
     for(int i = 0; i < n; i++)
     {
	cin >> q[i];
	q[i]--;
	s[q[i]]=1;
     }
     priority_queue<int> pqmin;
     vector<int> maxv;
     for(int i = 0; i <n; i++) if(s[i]==0) pqmin.push(-i), maxv.push_back(i);
     cout << q[0]+1<< " ";
     for(int i = 1; i < n; i++)
     {
        if(q[i]==q[i-1]) cout << -pqmin.top()+1<<" ", pqmin.pop();
	else cout << q[i]+1<< " ";
     } 
     cout << endl; 
     cout << q[0]+1<< " ";
     for(int i = 1; i < n ;i++)
	    if(q[i]!=q[i-1])
	     cout << q[i]+1<< " ";
	    else
	    {
	       int idx = lower_bound(maxv.begin(), maxv.end(), q[i]) - maxv.begin();
		if(idx>0)
		{	
		   cout << maxv[idx-1]+1<< " ";
		   maxv.erase(maxv.begin()+idx-1);
		}

	    }
     cout << endl;
  }
  return 0;
}
