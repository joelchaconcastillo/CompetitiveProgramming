#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ite;
  cin>>ite;
  while(ite--)
  {
   int a,b;
   int c[]={0,0};
   string s;
   cin>>c[0]>>c[1]>>s;
   int n = c[0]+c[1];
   bool ispa = true;
   for(int i = 0; i < n; i++)
   {
      if(s[i]=='?')s[i]=s[n-i-1]; 
      if(s[i]!='?') c[s[i]-'0']--;
      if(s[i] != '?' && s[n-i-1]!='?' && s[i]!=s[n-i-1]){ispa=0;break;}
   } 
   if(!ispa){cout << -1<<endl;continue;}
   for(int i = 0, j = n-1; i<=j; i++, j--)
   {
      if(s[i]!='?')continue;
      if(i == j) 
      {
	if(c[0]>0)s[i]='0';
	else if(c[1]>0)s[i]='1';
        c[s[i]-'0']--;
      }
      else
      {
        if(c[0]>1) s[i]=s[j]='0';
        else if(c[1]>1)s[i]=s[j]='1';
        c[s[i]-'0']-=2;
      }
   }
   if(c[0]!=0|| c[1]!=0)cout <<-1<<endl;
   else cout <<s<<endl;
  }
  return 0;
}
