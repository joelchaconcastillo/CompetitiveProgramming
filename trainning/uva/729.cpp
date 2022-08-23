#include <bits/stdc++.h>
using namespace std;
void comb(string st, int H, int N)
{
   if(st.size()==H)
   {
      if(N==0)cout << st<<endl;
	return;
   }
   comb(st+'0', H, N);
   comb(st+'1', H, N-1);
}
int main()
{
  int t;
  cin >>t;
  for(int k=0; k <t;k++)
  {
	if(k>0)cout << endl;
     int H, N;
     cin >>H>>N;
    // for(int i = 1;i < 1<<H;i++)
    // {
    //    if(__builtin_popcount(i)==N)
    //    {
    //      for(int x = H-1; x >=0 ; x--)
    //      {
    //        if(i & 1<<x)cout <<1;
    //    	else cout <<0;
    //      }
    //      cout <<endl;
    //    }
    // }
    comb("", H, N);
  }
  return 0;
}
