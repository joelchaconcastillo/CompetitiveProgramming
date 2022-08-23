#include <bits/stdc++.h>
using namespace std;
int main(){
  int T,n;
  cin >> T;
  for(int t = 1; t <=T; t++){
   string st;
   cin >>n>>st;
   pair<char,int> state(' ', 0);
   int i=0;
   for(; i < st.size(); i++)
	if(st[i]!='F'){state=make_pair(st[i], 0); break;}
   for(; i < st.size(); i++){
      if(st[i]!=state.first && st[i]!='F'){
	      state=make_pair(st[i], state.second+1);
      }
   }
   cout << "Case #"<<t<<": "<<state.second<<endl;
  }
  return 0;
}
