#include <bits/stdc++.h>
using namespace std;
int main()
{
   int T;
   cin >> T;
   for(int i = 1; i <= T; i++)
   {
	int L, W, H;
	cin >> L >> W >> H;
	if(L <= 20 && W <= 20 && H <=20)
	{
	   //if( W<H || H < W)
	      cout << "Case "<<i<<": good"<<endl;
	  // else cout << "Case "<<i<<": bad"<<endl;
	}
	else cout << "Case "<<i<<": bad"<<endl;
   }
}
