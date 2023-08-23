#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
     long long n, m ,d;
     cin>>n>>m>>d;
     vector<long long> a(m, 0);
     for(int i = 0;  i < m; i++) cin>>a[i];
     a.insert(a.begin(), 1-d);
     a.push_back(n+1);
     long long min_cookies=INT_MAX;
     vector<long long>res;
     for(int i = 1; i <= m; i++){
         long long improvement = (a[i+1]-a[i-1]-1)/d - (a[i]-a[i-1]-1)/d - (a[i+1]-a[i]-1)/d;	
         if(improvement < min_cookies){ 
           min_cookies=improvement;
           res.clear();
         }
         if(improvement==min_cookies) res.push_back(a[i]);
     }
     for(int i=1; i <a.size(); i++) min_cookies += (a[i]-a[i-1]-1)/d; 
     min_cookies += a.size()-2;
     cout <<min_cookies-1<<" "<<res.size()<<endl;
     
   }
   return 0;
}
