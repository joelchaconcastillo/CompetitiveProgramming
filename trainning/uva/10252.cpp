#include <bits/stdc++.h>
using namespace std;
int main(){
   string s1, s2;
   while(getline(cin, s1) && getline(cin, s2)){
     string res="";
     unordered_map<char, int> f1,f2;
     for(auto i:s1) f1[i]++;
     for(auto i:s2) f2[i]++;
     for(auto i:f1) res += string(min(f2[i.first],i.second), i.first);
     sort(res.begin(), res.end());
     cout<<res<<endl;
   }
   return 0;
}
