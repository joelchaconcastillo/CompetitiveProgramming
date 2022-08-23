#include <bits/stdc++.h>
using namespace std;
string memo[5001];
string sum(string a, string b)
{
   string s="";
   int c = 0, r = 0;
   while(!a.empty() || !b.empty())
   {
      if(!a.empty() && !b.empty())
        r = (int)(a.back()-'0') + (int)(b.back()-'0'), a.pop_back(), b.pop_back();
      else if(!a.empty())
        r = (int)(a.back()-'0'), a.pop_back();
      else if(!b.empty())
        r =(int)(b.back()-'0'), b.pop_back();
      r +=c;
      c = r/10; 
      s.push_back(r%10+'0');
   } 
   if(c != 0) s.push_back(c+'0');
   reverse(s.begin(), s.end());
   return s;
}
int main()
{
  int n, c=2;
  memo[0]="0";
  memo[1]="1";
  while(cin>>n)
  {
    cout << "The Fibonacci number for "<<n<<" is ";
   if( n >= c)
    {
       for(; c<=n; c++) memo[c] =  sum(memo[c-2], memo[c-1]);
    } 
	cout <<memo[n]<<endl;
  }
  return 0;
}
