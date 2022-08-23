#include <bits/stdc++.h>
using namespace std;
int main(){
   int N;
   cin>>N;
   unordered_map<char, int> freq;
   string st;
   getline(cin, st);
   while(N--){
     getline(cin, st);
     for(auto i:st){
	if( isalpha(i) && !isdigit(i)) freq[toupper(i)]++;
     }
   }
     vector<pair<int, char>> pp;
     for(auto ii:freq) pp.push_back({-ii.second, ii.first});
     sort(pp.begin(), pp.end());
     for(auto ii:pp)cout<< ii.second<<" "<<-ii.first<<endl;

   return 0;
}
