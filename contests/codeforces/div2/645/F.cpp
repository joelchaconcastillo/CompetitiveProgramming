#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<long long> A(n), B(n);
  for(int i = 0; i < n; i++) cin>>A[i];
  for(int i = 0; i < n; i++) cin>>B[i];
   if(n==1)
   {
     if(A[0]==B[0])cout<<"SMALL\n"<<0;
     else cout << "IMPOSSIBLE\n";
     return 0;
   }
   if(n==2)
   {
       long long nactions = 0;
       vector<pair<int, bool>>compress_ans;
       while(true)
       {
	 if(B[0]==0 || B[1]==0){cout <<"IMPOSSIBLE\n"; return 0;}
	 if(A==B) break;
         if(A[0]==B[1] && A[1]==B[0]){ compress_ans.push_back({1, false}); break;}
         if(B[0]==B[1]){cout << "IMPOSSIBLE\n"; return 0;}
         if(B[0]>B[1]) compress_ans.push_back({1, false}), swap(B[0], B[1]);

	 if(A[0] == B[0] && A[1]< B[1] && ((B[1]-A[1])%B[0]==0))
 	 {
	    long long rem = (B[1]-A[1])/B[0];
	    nactions += rem;
	    compress_ans.push_back({rem, 1});
	    break;
	 }
	 if(A[1] == B[0] && A[0]< B[1] && ((B[1]-A[0])%B[0]==0))
 	 {
	    long long rem = (B[1]-A[0])/B[0];
	    nactions += rem;
	    compress_ans.push_back({rem, 1});
	    compress_ans.push_back({1, 0});
	    break;
	 }
         nactions += B[1]/B[0];
	 compress_ans.push_back({B[1]/B[0], 1});
	 B[1] %=B[0];
       }
       if(nactions>2e5) cout << "BIG\n"<< nactions<<endl;
       else
       {
	 long long sum = 0;
	 for(auto i:compress_ans) sum+=i.first;
 	 cout << "SMALL\n"<< sum<<endl;
	 if(!compress_ans.empty())
	 {
 	  reverse(compress_ans.begin(), compress_ans.end());
	   for(auto i:compress_ans)
	   {
		for(int j = 0; j < i.first; j++)
		if(i.second) cout <<"P";
	 	else cout <<"R";
	   }
	 }
       }
       return 0;
   }
    string ans="";
    long long nactions=0;
    while(true)
    {
      if(A==B) break;
      reverse(B.begin(), B.end());
      if(A==B){ ans +="R"; break;}
      reverse(B.begin(), B.end());
      bool inc=false, dec=false, eqn=false;
      for(int i = 1; i < n; i++)
	if(B[i] < B[i-1]) dec=true;
	else if(B[i]>B[i-1]) inc=true;
	else eqn=true;
      if(eqn || (inc && dec)){cout << "IMPOSSIBLE\n"; return 0;}
      if(dec) ans +="R", reverse(B.begin(), B.end());

	vector<long long> tmp(n);
	tmp[0]=B[0];
        for(int i = 1; i < n ;i++)
        tmp[i] = B[i]-B[i-1];
        B=tmp;
	ans +="P";
      nactions++;
    }
    if(nactions > 2e5) cout << "BIG\n"<<nactions<<endl;
    else 
    {
	cout << "SMALL\n"<< ans.size()<<endl;
	if(!ans.empty())
	{
 	  reverse(ans.begin(), ans.end());
	  cout << ans<<endl;
	}
    }
  return 0;
}
