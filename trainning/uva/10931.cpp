#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  while(cin>>N)
  {
     if(N==0) break;
     int p =0;
     string b = "";
     for(int i = 0; i < int(log(N)/log(2))+1;  i++)
     {
	bool v = ( N & (1<<i));
	if(v)p++;
 	b.push_back(v+'0');	
     }
     reverse(b.begin(), b.end());
     cout <<"The parity of "<<b <<" is "<<p<<" (mod 2)."<<endl;
  }
}
 

