#include <bits/stdc++.h>
#define MOD 1000000007
/*
 *
 * eqn: --> https://www.wolframalpha.com/input/?i=%28n*%28n%2B1%29%29-%28b%29%28b%2B1%29+-+%28n-a%29%28n-a%2B1%29%2B%28b-a%29%28b-a%2B1%29
 * */
using namespace std;
string st;
int n;
int main(){
   int T;
   cin >> T;
   for(int t=1; t<=T; t++){
	 cin>>n>>st;
       int idx=-1;
       long long s=0;
      for(int i = 0; i < n; i++){
         if(st[i]=='X' || st[i]=='O'){
	    if(idx==-1)idx=i;
	    else{
		if(st[i]!=st[idx])
		s = (long long)(s+(idx+1LL)*(n-i))%MOD;
		idx=i;
	    }
	 }
      }
      cout << "Case #"<<t<<": "<<s<<endl;
   }
   return 0;
}
