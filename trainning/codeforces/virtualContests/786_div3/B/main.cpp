#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   unordered_map<string, int> dic;
   int idx=1;
   for(char i='a'; i<='z'; i++){
      for(char j='a'; j<='z'; j++){
        if(i==j)continue;
	string s ="";
	s.push_back(i);
	s.push_back(j);
	dic[s]=idx;
	idx++;
      }
   }
   while(t--){
	string st;
	cin>>st;
	cout<<dic[st]<<endl;
   }
   return 0;
}
