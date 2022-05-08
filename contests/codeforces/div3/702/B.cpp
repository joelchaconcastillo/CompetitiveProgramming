#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long c1, c2, c3, t, n;
  cin>>t;
  while(t--)
  {
    c1 = c2 = c3 = 0; 
    cin >>n;
    for(int i = 0; i < n; i++)
    {
	 int d;
	 cin>>d;
	 if(d%3==0)c1++;
	 else if(d%3==1)c2++;
	 else if(d%3==2)c3++;
    }
    cout << max(c1-c3, max(c2-c1, c3-c2))<<endl;

  }
  return 0;
}
