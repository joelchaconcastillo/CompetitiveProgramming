#include <bits/stdc++.h>
using namespace std;
int main(){
  int MAX_N=1000;
  vector<int> prime;
  vector<bool> isp(MAX_N+1, true);
  isp[0]=isp[1]=false;
  for(int i = 2; i <= MAX_N; i++){
	  if(!isp[i])continue;
    for(int j = i*i; j <= MAX_N; j+=i) isp[j]=false; 
    prime.push_back(i);
  }
  int tc=0, S, T;
  bool marked[1001];
  while(cin>>S>>T){
     if(S==0 && T==0)break;
     queue<pair<int, int> > q;
     q.push({S, 0});
     memset(marked, 0, sizeof marked);
     pair<int,int> minv(-1, INT_MAX);
//     unordered_map<int, bool>marked;
     while(!q.empty()){
        auto idx=q.front(); q.pop();
	if(idx.first>T)continue;
	if(idx.first == T){
	       	minv=idx;
		break;
	}

	for(auto i:prime){
	   if(i>=idx.first)break;
	   if(idx.first+i>T)continue;
	   if((idx.first%i) != 0)continue;
	   if(marked[idx.first+i]) continue;
	   marked[idx.first+i]=true;
	   q.push({idx.first+i, idx.second+1});
	}
     }
     tc++;
     cout<<"Case "<<tc<<": ";
     if(minv.second!= INT_MAX)cout<<minv.second<<endl;
     else cout <<-1<<endl;
  }
   return 0;
}
