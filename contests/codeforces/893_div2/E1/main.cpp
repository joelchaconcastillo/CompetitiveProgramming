#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int f[maxn];
int get(int i){
   int ans = 0;
   for(i; i >= 0 ; i = (i&(i+1))-1) ans +=f[i];
   return ans;
}
void upd(int i, int x){
  for(;i<maxn; i = i | (i+1)) f[i]+=x;
}
int a[maxn], rev[maxn];
set<int>ids[maxn];
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   fill(rev, rev+maxn, -1);
   fill(a, a+maxn, -1);
   int q;
   cin>>q;
   int ptr=-1;
   vector<pair<int, int>>changes;
   while(q--){
	char l1;
	cin>>l1;
	if(l1=='+'){
		int x;
		cin>>x;
		int &val = a[ptr+1];
		int mem = val;
		if(val != -1){
		  if(!ids[val].empty()) upd(*ids[val].begin(), -1), ids[val].erase(ptr+1);
		  if(!ids[val].empty()) upd(*ids[val].begin(), 1);
		}
		val=x;
		if(val!=-1){
		  if(!ids[val].empty()) upd(*ids[val].begin(), -1);
		  ids[val].insert(ptr+1);
		  if(!ids[val].empty()) upd(*ids[val].begin(), 1);
		}
		ptr++;
		changes.push_back({1,mem});
	}else if(l1=='-'){
		int k;
		cin>>k;
		ptr -=k;
		changes.push_back({-1, k});
	}else if(l1=='!'){
		if(changes.back().first==1){
		   if(a[ptr]!=-1){
			  if(!ids[a[ptr]].empty()) upd(*ids[a[ptr]].begin(), -1), ids[a[ptr]].erase(ptr);
			  if(!ids[a[ptr]].empty()) upd(*ids[a[ptr]].begin(), 1);
		   }
		   a[ptr]=changes.back().second;
		   ptr--;
		   if(a[ptr+1]!=-1){
			  if(!ids[a[ptr+1]].empty())upd(*ids[a[ptr+1]].begin(), -1);
			  ids[a[ptr+1]].insert(ptr+1);
			  if(!ids[a[ptr+1]].empty()) upd(*ids[a[ptr+1]].begin(), 1);
		   }
		}else ptr +=changes.back().second;
		changes.pop_back();
	}else{
	     cout <<get(ptr)<<endl;
	}
   }
   return 0;
}
