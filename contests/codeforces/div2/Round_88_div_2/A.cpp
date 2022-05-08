#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
     long int n, m, k, z;
     cin >> n >> m >> k;
     z = n/k;
     if(m <= z) cout<<fixed << m <<endl;
     else
	{
	  long int rem = m-z;
	 long int a = rem/(k-1);
	  if( rem %(k-1) ) a++;
          cout<<fixed << z-a <<endl;
	}
  }
  return 0;
}
