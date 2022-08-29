#include <bits/stdc++.h>
using namespace std;
int T, N;
vector<string> res;
string C1;
void construct(string current, int maxs){
  if(!current.empty() && current.front()==C1.front())return;
  if(res.size()+1>=N)return;
  if(current.size()==maxs){
	res.push_back(current);
	return;
  }
  construct(current+'.', maxs);
  construct(current+'-', maxs);
}
int main(){
   cin>>T;
   for(int t=1; t<=T; t++){
      cin>>N;
      cin>>C1;
      res.clear();
      int k = ceil(log(N)/log(2))+1;
      construct("", k);
      cout<<"Case #"<<t<<":"<<endl;
      for(int i = 0; i+1 < N ;i++){
	cout<<res[i]<<endl;
      }
   }
   return 0;
}
