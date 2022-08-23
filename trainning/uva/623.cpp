#include <bits/stdc++.h>
using namespace std;
string prod(string a, string b){
   string res="";
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());
   if(a.size()<b.size())swap(a, b);
   int n= a.size(), m=b.size(), rem=0;
   for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m; j++){
        int numA=a[i]-'0', numB=b[j]-'0', add=0;
	if(res.size()>i+j)add=res[i+j]-'0';
	int prod = numA*numB+rem+add;
	rem = prod/10;
	int sum=prod%10;
	if(res.size()<=i+j)res.push_back(sum+'0');
	else res[i+j]=sum+'0';
      }
      if(rem>0){
	if(res.size()<=i+m)res.push_back(rem+'0');
	else res[i+m]=rem+'0';
	rem=0;
      }
   }
   reverse(res.begin(), res.end());
   return res;
}
unordered_map<int, string> memo;
int main(){
   memo[0]="1";
   memo[1]="1";
   memo[2]="2";
   for(int i = 3; i <= 1000; i++){
     memo[i]=prod(to_string(i),memo[i-1]);
   }
   int n;
   while(cin>>n){
        cout<<n<<"!"<<endl;
	auto &st=memo[n];
	cout<<st<<endl;
//	 for(int i = 0 ; i < st.size(); i++){
//	    cout<<st[i];
//	    if((i+1)%80==0)cout<<endl;
//	 }
//	 if(st.size()%80!=0)cout<<endl;
   }
   return 0;
}
