#include <bits/stdc++.h>
using namespace std;
int main(){
 int T;
 cin>>T;
 while(T--){
   string s1, s;
   cin>>s1;
   cin>>s;
   vector<int> dic(1000, 0);
   for(int i = 0; i < s1.size(); i++)dic[s1[i]]=i;
   int score=0;
   for(int i = 0; i < s.size()-1; i++){
      score += abs(dic[s[i+1]]-dic[s[i]]);
   }
   cout << score<<endl;
  }
  return 0;
}
