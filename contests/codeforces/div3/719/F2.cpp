#include <bits/stdc++.h>
using namespace std;
map<int, int> sol;
int main()
{
  int n, k;
  cin >> n >> k;
  while(k--)
  {
    int L = 0, R = n-1, t, s, z;
    cin>> t;
    while( L < R)
    {
        int M = (L+R)/2;
	if( sol.count(M)==0)
	{
	   cout << "? 1 "<<M+1<<endl;
	   cout.flush();
	   cin>>s;
	   z = M-s+1;
	   sol[M]=z;
	}
	z=sol[M];
	if(z<t) L=M+1;
	else R=M;
    }
    cout << "! " << L+1<<endl;
    //update sol
    auto start = sol.find(L);
    while(start != sol.end())
	start->second--, start++;
  }
  return 0;
}
