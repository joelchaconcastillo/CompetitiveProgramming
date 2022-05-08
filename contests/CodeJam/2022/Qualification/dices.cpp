#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin>>T;
  for(int t =1; t<=T;t++){
     cout << "Case #"<<t<<": ";
     int N;
     cin>>N;
     vector<long long>dices(N);
     for(auto &i:dices)cin>>i;
     sort(dices.begin(), dices.end());
     int count = 0;
     for(int i=0; i <dices.size(); i++){
	if( dices[i]>=count+1) count++;
     }
     cout <<count<<endl;
  }
  return 0;
}
