#include <bits/stdc++.h>
using namespace std;
int main(){
   string st1, st2;
   int T=0;
   while(getline(cin, st1) && getline(cin, st2)){
      int  n1=st1.size()+1, n2=st2.size()+1;
      vector<vector<int> > dp(n1, vector<int>(n2, INT_MAX));
      for(int i = 0; i < n1; i++)dp[i][0]=i;
      for(int i = 0; i < n2; i++)dp[0][i]=i;
      for(int i = 1; i < n1; i++){
         for(int j = 1; j < n2; j++){
	   int cost = (st1[i-1]==st2[j-1])?0:1;
           dp[i][j] = min(dp[i-1][j-1]+cost, dp[i][j]); //replace
           dp[i][j] = min(dp[i][j-1]+1, dp[i][j]); //insert in st1
           dp[i][j] = min(dp[i-1][j]+1, dp[i][j]); //remove in st2
	 }
      }
      vector<string> operations;
      vector<int> opt;
      pair<int, int> pos(n1-1, n2-1);
      while(pos.first>0 || pos.second>0){
	  int value = dp[pos.first][pos.second], rem = max(0, pos.first-pos.second);
	  int cost = (st1[pos.first-1]!=st2[pos.second-1])?1:0;
	  if(pos.first > 0 && pos.second > 0 && (dp[pos.first-1][pos.second-1]+cost) ==value){
	    if(cost)
	     operations.push_back(+"Replace "+to_string(pos.second)+","+st2[pos.second-1]);
	    pos={pos.first-1, pos.second-1};
	  }
	  else if(pos.second > 0 && (dp[pos.first][pos.second-1]+1) == value) 
	     operations.push_back("Insert "+to_string(pos.second)+","+st2[pos.second-1]), pos={pos.first, pos.second-1};
	  else if(pos.first > 0 && (dp[pos.first-1][pos.second]+1) == value)
	     operations.push_back("Delete "+to_string(pos.second+1)), pos={pos.first-1, pos.second};
      }
     if(T>0)
     cout<<endl;

      cout<<operations.size()<<endl;
     for(int i = operations.size()-1,j=1; i>=0; i--, j++){
	cout<<j<<" "<<operations[i]<<endl;
     }
     T++;
   }
   return 0;
}
