#include <bits/stdc++.h>
using namespace std;
string prod(string s1, string s2){
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int n1=s1.size(), n2=s2.size();
    string res="";
    for(int i = 0 ; i < n1; i++){
      int rem=0;
      for(int j = 0; j < n2; j++){
	 int prod=(s1[i]-'0')*(s2[j]-'0')+rem;
	  if(res.size()>i+j)
	    prod +=(res[i+j]-'0');
	  rem=prod/10;
	  int div=prod%10;
	  if(res.size()>i+j)res[i+j]=div+'0';
	  else res+=div+'0';
      }
      if(rem!=0){
	res += rem+'0';
      }
    }
    while(res.size()>1 && res.back()=='0')res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
int main(){
   string n1, n2;
   while(cin>>n1>>n2){
      cout << prod(n1, n2)<<endl;
   }
   return 0;
}
