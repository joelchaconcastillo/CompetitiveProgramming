#include <bits/stdc++.h>
using namespace std;
int matching2(string &s, string &pattern){
   int m = pattern.size(), n = s.size();
   vector<int> prefix(m, 0);
   for(int i = 1; i < m; i++){
      int j = prefix[i-1];
      while(j>0 && pattern[i]!=pattern[j])j=prefix[j-1];
      if(pattern[i]==pattern[j])j++;
      prefix[i]=j;
   }
   int count = 0, j=0;
   for(int i = 0 ; i < n; i++){
      while(j>0 && s[i]!=pattern[j]) j=prefix[j-1];
      if(s[i]==pattern[j]) j++;
      count = max(j, count);
      if(j>=m)j=prefix[j-1];
   }
   return max(0, count-1);
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
     string st;
     cin>>st;
     string target=st;
     reverse(target.begin(), target.end());
     auto s = matching2(target, st);
     if(s >= st.size()) s =st.size()-1;
     for(int i = s; i >=0 ; i--)cout <<st[i];
	     cout <<endl;
   }
   return 0;
}
