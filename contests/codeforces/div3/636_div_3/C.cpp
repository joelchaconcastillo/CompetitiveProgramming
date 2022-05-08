#include <bits/stdc++.h>
using namespace std;
long long sign(long long d)
{
 if(d>0) return 1;
 else return -1;
}
int main()
{
   int t;
   cin >>t;
   for(int a = 0; a < t; a++)
   {
	long long n;
   	cin >> n;
	long long sign_d=1, maxv = LONG_MIN, sum = 0;
	for(int i = 0; i < n; i++)
  	{
	  long long d;
	  cin >> d;
	  if(maxv == LONG_MIN) maxv =d;
	  if( sign(sign_d*d) >0) //same sign..
	     maxv = max(maxv, d);
	  else //different sign..
	  {
	     sign_d = sign(d);
	    if(i>0)
	     sum += maxv;
	     maxv = d;
  	  }
	}
	if(maxv != LONG_MIN)
	sum += maxv;
	cout << sum <<endl;	
   }
   return 0;
}
