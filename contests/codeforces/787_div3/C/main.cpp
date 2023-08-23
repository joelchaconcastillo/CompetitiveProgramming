#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     string st;
     cin>>st;
     st = "1"+st+"0";
     int n = st.size(), count=0;
     vector<int>l(n,-1), r(n,-1);
     for(int i = 0; i<n; i++){
	if(st[i]=='1')l[i]=1, r[i]=1;
	else if(st[i]=='0') l[i]=0, r[i]=0;
     }
     for(int i = 1; i < n; i++)if(l[i]==-1)l[i]=l[i-1];
     for(int i = n-2; i>=0; i--)if(r[i]==-1) r[i]=r[i+1];
     for(int i =1; i+1 <n; i++) if(l[i-1]!=r[i+1])count++;
     cout<<count<<endl;
   }
   return 0;
}
