#include <bits/stdc++.h>
using namespace std;
int main(){
   string st;
   while(getline(cin, st)){
      st+=' ';
      int n=st.size(); 
      string current="", res="";
      for(int i = 0 ; i < n; i++){
	 if(st[i]!=' ') current+=st[i];
	 else{
		 reverse(current.begin(), current.end());
		 res+=current+" ";
		 current="";
	 }
      }
      res.pop_back();
      cout<<res<<endl;
   }
   return 0;
}
