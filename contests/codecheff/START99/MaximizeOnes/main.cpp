#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
      int n;
      cin>>n;
      string st;
      cin>>st;
      int nOnes = 0;
      //edge cases..
      for(auto i:st) nOnes += (i=='1');
      if(n <=2 || nOnes==n || nOnes==0){
	cout << st<<endl;
	continue;
      }
      //can not be improved..
      string pat = "110";
      bool best=false;
      for(int i = 0 ; i < 3; i++){
	 bool inner=true;
	 for(int j = 0 ; j < n; j++){
	    if(st[j]!=pat[(i+j)%3]){
		    inner=false;
		    break;
	    }
	 }
	 if(inner){best=true;break;}
      }
      if(best){
         cout << st<<endl;
	 continue;
      }
      //edge cases extremes..
      for(int i = 1; i+1 <n; i++)st[i]='1';
      if(st.front()=='1' && st.back()=='1') st[1]='0';
      cout <<st<<endl;

   }
   return 0;
}
