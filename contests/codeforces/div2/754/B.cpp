#include <bits/stdc++.h>
using namespace std;
bool isincreasing(string &s){
  for(int i = 0; i < s.size()-1; i++)
	  if(s[i]=='1' && s[i+1]=='0')return false;
  return true;
}
int main(){
   int T;
   cin>>T;
   while(T--){
     int n;
     cin>>n;
     string st;
     cin>>st;
     vector<set<int>>operations;
     while(!isincreasing(st)){
       int l=0, r=st.size()-1;
       set<int> op;
       while(l<r){
        while(l<r && st[l]=='0')l++;
        while(l<r && st[r]=='1')r--;
	if(l<r){
	   op.insert(l);
	   op.insert(r);
	   swap(st[l], st[r]);
	   l++, r--;
	}
       }
	if(!op.empty()) operations.push_back(op);
     }
     if(operations.empty()){
	     cout <<0<<endl;
	     continue;
     }
     cout << operations.size()<<endl;
     for(int i = 0; i < operations.size(); i++){
	     cout << operations[i].size()<<" ";
	     for(auto idx:operations[i])
		     cout << idx+1<<" ";
     }
     cout<<endl;
   }
   return 0;
}
