#include <bits/stdc++.h>
using namespace std;
int main(){
   string st;
   vector<string> group;
   vector<pair<int,int> > pp;
   int it=1;
   while(cin>>st){
      if(st=="9"){
       unordered_map<string,int> prefixes;
       sort(pp.begin(), pp.end());
       bool decod=true;
       for(auto i:pp){
  	    if(prefixes.find(group[i.second])!=prefixes.end()){
  	   	  decod=false;
  	   	  break;
  	    }
	    if(!decod)break;
  	    string pre="";
  	    for(auto j:group[i.second]){
  	   		pre+=j;
  	   		prefixes[pre]++;
  	    }
       }
	group.clear();
	pp.clear();
        if(decod)cout<<"Set "<<it<<" is immediately decodable\n";
	else cout << "Set "<<it<<" is not immediately decodable\n";
	it++;
      }
      else{
	      pp.push_back({-st.size(), group.size()});
	      group.push_back(st);
      }
   }
   return 0;
}
