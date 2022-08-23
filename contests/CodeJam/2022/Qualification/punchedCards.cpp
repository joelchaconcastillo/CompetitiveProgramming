#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin>>T;
  for(int t =1; t<=T;t++){
     cout << "Case #"<<t<<":"<<endl;
     int R, C;
     cin>>R>>C;
     vector<string> card(R*2+1, string(C*2+1,'.'));
     for(int i = 0; i < R*2+1; i +=2)
	for(int j = 0; j <C*2+1; j+=2) card[i][j]='+';
      for(int i = 0; i < R*2+1; i +=2)
	for(int j = 1; j <C*2+1; j+=2) card[i][j]='-';
       for(int i = 1; i < R*2+1; i +=2)
	for(int j = 0; j <C*2+1; j+=2) card[i][j]='|';
     card[0][0]=card[0][1]=card[1][0]='.'; 
     for(int i = 0; i < R*2+1; i++){
	cout <<card[i]<<endl;
     }
  }
  return 0;
}
