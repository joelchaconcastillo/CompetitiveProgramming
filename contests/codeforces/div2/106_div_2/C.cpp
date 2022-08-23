#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t,n;
  cin >> t;
  while(t--)
  {
    cin>>n; 
    long long s=0, cntodd=n, cnteven=n, minv=1e18, mineven =1e18, minodd=1e18, c; 
    for(int i = 0; i < n; i++)
    {
	cin>>c;
	if((i%2) == 0)
	{
	  mineven =min(mineven, c);
	  cnteven--;
	}
	else
	{
	  minodd = min(minodd, c);
	  cntodd--;
	}
	s +=c; 
	if(i>0)
	minv = min(minv, s + mineven*(cnteven) + minodd*(cntodd));
    
    }
    cout <<minv<<endl;
  } 
  return 0;
}
