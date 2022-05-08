#include <bits/stdc++.h>
using namespace std;
int main()
{
 int ite;
 cin>> ite;
 for(int t = 1; t <= ite; t++)
 {
   int N;
   string c, p, ci;
   cin>>N;
   int cont = 0;
   for(int i = 0; i < N; i++)
   {
    cin >>ci;
    c=ci;
    if(i>0)
    {
      long long lp =stoll(p), lc=stoll(c);
      if(lp>=lc)
      {
       if(c.size() == p.size()) c+="0";
       else if(c.size() < p.size())
       {
         int k = p.size()-c.size();
         if(stoll(c+string(k, '0')) <= lp)
	 {
            if(stoll(c+string(k, '9')) <= lp) c =c+string(k+1,'0');
	    else
	       c = to_string(lp+1); 
	 }else c=c+string(k, '0');
       }
      }
    }
    cont += c.size()-ci.size();
    p=c;
   }
   cout << "Case #"<<t<<": "<<cont<<"\n";
 }
 return 0;
}
