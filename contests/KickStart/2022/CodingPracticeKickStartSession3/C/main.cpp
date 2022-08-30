#include <bits/stdc++.h>
using namespace std;
unordered_map<char, pair<int, int> > offset;
map<pair<int, int>,pair<int, int> > E, W, N, S;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b){
  return {a.first+b.first, a.second+b.second};
}
void assignDir(pair<int, int> next){

  auto tmp = next+offset['W'];
  while(W.find(tmp)!=W.end()) tmp = W[tmp];
  W[next]=tmp;

  tmp = next+offset['E'];
  while(E.find(tmp)!=E.end()) tmp = E[tmp];
  E[next]=tmp;

  tmp = next+offset['N'];
  while(N.find(tmp)!=N.end()) tmp = N[tmp];
  N[next]=tmp;

  tmp = next+offset['S'];
  while(S.find(tmp)!=S.end()) tmp = S[tmp];
  S[next]=tmp;
}
int main(){
   offset['E']={0, 1};
   offset['W']={0, -1};
   offset['N']={-1, 0};
   offset['S']={1, 0};
   int T, R, C, n, Sr, Sc;
   pair<int, int> pos;
   cin>>T;
   for(int t=1; t<=T; t++){
    E.clear(); W.clear(); N.clear(); S.clear();
    cin>>n>>R>>C>>pos.first>>pos.second;
    string dir;
    cin>>dir;
    E[pos]=pos+offset['E'];
    W[pos]=pos+offset['W'];
    N[pos]=pos+offset['N'];
    S[pos]=pos+offset['S'];
    for(auto i:dir){
       pair<int, int> next;
      if(i=='E'){ 
	next=E[pos];
	assignDir(next);
	W[next]=W[pos];
        E[pos]=E[next];
      }else if(i=='W'){
	next=W[pos];
	assignDir(next);
	E[next]=E[pos];
        W[pos]=W[next];
      }else if(i=='N'){
	next=N[pos];
	assignDir(next);
	S[next]=S[pos];
        N[pos]=N[next];
      }else if(i=='S'){
	next=S[pos];
	assignDir(next);
	N[next]=N[pos];
        S[pos]=S[next];
      }
      pos=next;
    }
    cout<<"Case #"<<t<<": "<< pos.first<< " "<<pos.second<<endl;
   } 
   return 0;
}
