#include <bits/stdc++.h>
using namespace std;
const long long MAX=2e9;
vector<int> humbles, factors={2,3,5,7};
map<long long, bool>dp;
void perm(long long c){
   if(c>MAX)return;
   if(dp[c])return;
   dp[c]=1;
   for(auto i:factors){
     perm(c*i);
   }
}
int main(){
   vector<int> humbles={1};
   perm(1); 
   for(auto i:dp) humbles.push_back(i.first);
   int n;
   while(cin>>n, n!=0){
	   cout<<"The "<<n;
   	   if(n%100 >10 && n%100<= 20) cout << "th";
	   else if(n%100<=10 || n%100>=21)
	   {
		if(n%10==1)cout << "st";
		else if(n%10==2)cout << "nd";
		else if(n%10==3)cout << "rd";
		else cout << "th";

	   }
	   cout <<" humble number is ";
	   cout <<humbles[n]<<"."<<endl;
   }
   return 0;
}
