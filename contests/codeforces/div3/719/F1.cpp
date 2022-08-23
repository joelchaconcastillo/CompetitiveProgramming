#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, t;
  cin>>n >>t;
  while(t--)
  {
     int k, pos; //positiong of
     cin>>k;
     ///asking..
     int L = 0, R = n-1;
     while(L < R)
     {
        int M = (L+R)/2;
	cout << "? "<<1<<" "<<M+1<<endl;
	cout.flush();
	int nz, sum;
	cin >>sum;
	nz = M+1-sum;
	if(nz < k) L=M+1;
	else R=M;
     }
     pos = L+1;
     //put result forward..
     cout << "! "<<pos<<endl;
     cout.flush();
  }
  return 0;
}
