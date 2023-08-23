/*

0-+
001 sign
011 bits

 * */
#include <bits/stdc++.h>
using namespace std;
struct Sentence{
   int sign=0, bits=0;
   Sentence(){
   }
   Sentence(string &st){
      sign=bits=0;
      for(int i = 0 ; i < st.size(); i++){
	  if(st[i]=='0'){
	    bits = (bits & ~(1<<i));
	    sign = (sign & ~(1<<i));
	  }else{
	     bits = (bits | (1<<i));
	     if(st[i]=='+') sign = sign|(1<<i);
	  }
      }
   }   
};
struct Patch{
   Sentence required, effect;
   int Cost;
};
pair<bool, int> tryNext(Patch &p, int state){
   int req = ((state^p.required.sign) & p.required.bits);
   if( req!=0 ) return {false, -1};
   return {true, state&(~p.effect.bits) | p.effect.sign};
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n, m, t=1;
   while(cin>>n >>m){
      if(n==0 && m==0)break;
      vector<Patch> data(m);
      for(int i = 0 ; i < m; i++){
	     cin>>data[i].Cost;
	     string tmp;
	     cin>>tmp;
	     Sentence req(tmp);
	     data[i].required = req;
	     cin>>tmp;
	     Sentence effect(tmp);
	     data[i].effect = effect;
      }
      vector<int> d((1<<n)+1, INT_MAX);
      set<pair<int, int>>pq;
      int start = (1<<n)-1;
      d[start]=0;
      pq.insert({0, start});
      while(!pq.empty()){
	      auto current = *pq.begin();
	      pq.erase(pq.begin());
	      if(d[current.second] < current.first)continue;
	      if(current.second==0)break;
	      for(int i=0; i < m; i++){
		 auto feasible = tryNext(data[i], current.second);
		 if(!feasible.first)continue;
		 auto to = feasible.second;
		 auto nextDist = current.first + data[i].Cost;
		 if(d[to] > nextDist){
		   pq.erase({d[to], to});
		   pq.insert({nextDist, to});
		   d[to]=nextDist;
		 }
	      }
      }
      cout << "Product "<< t<<endl;
      if(d[0]==INT_MAX){
	   cout<<"Bugs cannot be fixed."<<endl;
      }else{
	   cout <<"Fastest sequence takes "<<d[0]<<" seconds."<<endl;
      }
      cout<<endl;
      t++;
   }
   return 0;
}
