#include <bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
   unordered_map<int, unordered_map<int, int>> grid;
     pair<int,int>LL1, LL2, UR1, UR2;
     cin >> LL1.first>>LL1.second>>UR1.first>>UR1.second;
     cin >> LL2.first>>LL2.second>>UR2.first>>UR2.second;
     pair<int, int> P1(max(LL1.first, LL2.first), max(LL1.second, LL2.second)), P2(min(UR1.first, UR2.first), min(UR1.second, UR2.second));
     long long diff1=P2.first-P1.first;
     long long diff2=P2.second-P1.second;
     if( diff1<=0 || diff2<=0 )
	     cout<<"No Overlap"<<endl;
     else 
	     cout<< P1.first<<" "<<P1.second<<" "<<P2.first<<" "<<P2.second<<endl;
    if(t>0)cout<<endl;
   }
   return 0;
}
