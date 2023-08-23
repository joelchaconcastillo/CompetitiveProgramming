#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > priority(vector<string> &pl){
    map<int, int> fval;
    map<char, int> fsuit;
    bool isConsecutive=false;
    for(auto i:pl){
	fsuit[i[1]]++;
	int v = i[0]-'0';
	if(i[0]=='T') v =10;
	if(i[0]=='J') v =11;
	if(i[0]=='Q') v =12;
	if(i[0]=='K') v =13;
	if(i[0]=='A') v =14;
	fval[v]++;
    }
    vector<pair<int, int>>res;
    for(auto i:fval) res.push_back({i.second, i.first});
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    bool isC=true;
    bool twopairs=false;
    for(int i = 0 ; i < res.size() && isC; i++){
       if(res[i].first!=1) isC=false;
       if(i>0 && res[i-1].second-res[i].second!=1)isC=false;
    }
    if(res[0].first==2 && res[1].first==2)twopairs=true;
    if(isC && fsuit.size()==1) res.insert(res.begin(), {6, 10});
    else if(fsuit.size()==1) res.insert(res.begin(), {2, 40});
    else if(isC) res.insert(res.begin(), {2, 30});
    if(twopairs)res.insert(res.begin(), {2, 20});
    return res;
}
int main(){
   vector<string> player1(5), player2(5);
   while(cin>>player1[0]>>player1[1]>>player1[2]>>player1[3]>>player1[4]>>player2[0]>>player2[1]>>player2[2]>>player2[3]>>player2[4]){
      auto p1=priority(player1), p2=priority(player2);
      if(p1<p2)cout<<"White wins."<<endl;
      else if(p1>p2)cout<<"Black wins."<<endl;
      else cout<<"Tie."<<endl;
   }
   return 0;
}
