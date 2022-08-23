#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  while(n--)
  {
     int t, cnt2=0, cnt3=0;
     cin >> t;
     while((t %2) ==0)
     {
    	t /=2;
	cnt2++; 
     }
     while((t %3) ==0)
     {
    	t /=3;
	cnt3++; 
     }
     if( t == 1 && cnt2 <= cnt3 )
	cout << cnt3*2 - cnt2 <<"\n";
     else
	cout << "-1\n";
  }
  return 0;
}

