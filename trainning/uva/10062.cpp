#include <bits/stdc++.h>
using namespace std;
int main(){
	string st;
  int ite=0;
  while(getline(cin, st)){
	  int N=1000;
	  if(ite>0)cout<<endl;
   vector<pair<int,int>> pp(N); 
   for(int i=0; i < N; i++)pp[i].second=-i;
   for(int i = 0; i < st.size(); i++){
       pp[st[i]].first++;
   }
   sort(pp.begin(), pp.end());
   for(auto ii:pp)
     if(ii.first>0)cout<<-ii.second<<" "<<ii.first<<endl;
   ite++;
  }

   return 0;
}



