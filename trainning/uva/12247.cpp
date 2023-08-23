#include <bits/stdc++.h>
using namespace std;
bool checkfeasible(string &d){
      vector<char> st;
      int cntloses=0;
      for(int i = d.size()-1; i >=0; i--){
	 if(!st.empty() && d[i]=='B' && st.back()=='A'){
		 cntloses++;
		 st.pop_back();
	 }
	 else st.push_back(d[i]);
      }
      if(cntloses==2)return false;
      return true;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   vector<pair<int, char>>d={{0,'A'}, {1,'A'}, {2,'A'},{3,'B'},{4,'B'}};
   while(cin>>d[0].first>>d[1].first>>d[2].first>>d[3].first>>d[4].first){
      if(d[0].first==0 && d[1].first == 0 && d[2].first==0 && d[3].first==0 && d[4].first==0)break;
      sort(d.begin(), d.end());
      string cpy="";
      vector<bool>marked(200, false);
      vector<int> AAs;
      AAs.push_back(-1);
      for(int i=0; i < 5; i++){
	      cpy+=d[i].second;
	      marked[d[i].first]=true;
	      if(d[i].second=='A')AAs.push_back(i);
      }
      if(!checkfeasible(cpy)){
	      cout<<-1<<endl;
      }
      else{
	  int sol=-1;
	  for(int i=0; i<AAs.size();i++){
	     string try1=cpy;
	     try1.insert(AAs[i]+1, "B");
	     if(checkfeasible(try1)){
		 if(AAs[i]==-1)sol=1;
		 else sol=d[AAs[i]].first;
		 while(marked[sol])sol++;
		 break;
	     }
	  }
	  if(sol>52)cout<<-1<<endl;
	  else cout<<sol<<endl;
      }
      d={{0,'A'}, {1,'A'}, {2,'A'},{3,'B'},{4,'B'}};
   }
   return 0;
}
/*

 28 51 29 || 50 52  ----> 28 29 50* 51 52*
 -----------------
 28 29 51 || 50 52
 A  B  C     X  Y
 1) A B C X Y   Y
 2) A B X C Y   Y
 3) A X B Y C   Y
 4) X A Y B C   N
 5) X Y A B C   N
 6) A B X Y C   Y
 7) A X Y B C   N

A A B A B
A A A B B
B B A A A

#X>=1 && #Y>=2 sol = max feaseble A 
 ......


 * */
