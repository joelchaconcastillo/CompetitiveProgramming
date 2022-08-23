#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> blocks;
vector<int>pa;
int getParent(int idx){
   return (idx!=pa[idx])?(pa[idx]=getParent(pa[idx])):idx;
}
void getBack(int id){
   int idx=getParent(id);
   auto &row=blocks[idx];
   while(row.back()!= id){
     blocks[row.back()].push_back(row.back());
     pa[row.back()]=row.back();
     row.pop_back();
   }
}
/*
 *putting b on top of a
 * */
void pushBack(int a, int b){
    int parentA = getParent(a);
    int parentB = getParent(b);
    if(parentA==parentB)return;
    stack<int> tmp;
    while(blocks[parentB].back()!= b) tmp.push(blocks[parentB].back()), blocks[parentB].pop_back();
    tmp.push(blocks[parentB].back()), blocks[parentB].pop_back();
    while(!tmp.empty()) blocks[parentA].push_back(tmp.top()), pa[tmp.top()]=parentA, tmp.pop();
}
int main(){
   int n;
   cin>>n;
   for(int i = 0 ; i < n; i++) blocks.push_back({i}), pa.push_back(i);
   string command;
   while(cin>>command){
      if(command=="quit")break;
      int a, b;
      string action;
      cin>>a>>action>>b;
      if(a==b || getParent(a)==getParent(b))continue;
      if(command=="move" && action=="onto"){
	   getBack(a);
	   getBack(b);
	   pushBack(b, a);
      }
      else if(command=="move" && action=="over"){
	   getBack(a);
	   pushBack(b, a);
      }
      else if(command=="pile" && action=="onto"){
	   getBack(b);
	   pushBack(b,a);
      }
      else if(command=="pile" && action=="over"){
	   pushBack(b,a);
      }
   }
   for(int i = 0 ; i < n; i++){
      cout <<i<<":";
      for(auto ii:blocks[i]){
	      if(ii==blocks[i].front())cout<<" ";
	      cout<<ii;
	      if(ii!=blocks[i].back())cout<<" ";
      }
      cout<<endl;
   }

   return 0;
}
