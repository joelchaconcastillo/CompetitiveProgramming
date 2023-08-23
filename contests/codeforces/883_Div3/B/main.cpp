#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin >> T;
   for(int t = 0; t < T; t++){
      vector<string> g(3,"");
      vector<unordered_map<char, int> > freq_line(8);
      for(int i = 0 ;i < 3; i++)cin>>g[i];
      for(int i = 0 ; i < 3; i++){
	   freq_line[0][g[i][i]]++;
	   freq_line[1][g[2-i][i]]++;
	 for(int j = 0 ; j < 3; j++){
	   freq_line[2+j][g[i][j]]++;
	   freq_line[5+j][g[j][i]]++;
	 }
      }
      char Winner='.';
      for(auto ii:freq_line){
	 for(auto jj:ii){
	   if(jj.second==3 && jj.first!='.'){
	     Winner=jj.first;
	     break;
	   }
	 }
	 if(Winner!='.')break;
      }
      if(Winner != '.') cout << Winner<<endl;
      else cout << "DRAW"<<endl;
   }
   return 0;
}
