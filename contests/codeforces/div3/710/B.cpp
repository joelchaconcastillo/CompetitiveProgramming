#include<bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
     string st;
     int n,k, score[51];
     cin>>n>>k>>st;
     for(int i = 0; i < n; i++)score[i]=10000;
     int i = 0;
     while(i<n && st[i]!='*')i++;
     if(i<n)score[i]=1;
     for(i++; i < n; i++)
	     if(st[i]=='*')
	 for(int j = max(0, i-k); j < i; j++) if(st[j]=='*') score[i]=min(score[i], score[j]+1);
     i=n-1;
     while(score[i]==10000) i--;
     cout << score[i]<<endl;
  }
}
