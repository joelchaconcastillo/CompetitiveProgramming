#include <bits/stdc++.h>
using namespace std;
string sum(string &a, string &b){
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());
   if(a.size()<b.size())swap(a,b);
   int n1=a.size(), n2=b.size();
   string res="";
   int rem=0;
   for(int i = 0 ; i < n1; i++){
      int sum=a[i]-'0'+rem;
      if(i<b.size())sum+=b[i]-'0';
      res += (sum%10)+'0';
      rem=sum/10;
   }
   if(rem!=0)res += rem+'0';
   reverse(res.begin(), res.end());
   return res;
}
int main(){
  string st, res="0";
   while(cin >>st){
      res=sum(res, st); 
   }
   cout<<res<<endl;
   return 0;
}
