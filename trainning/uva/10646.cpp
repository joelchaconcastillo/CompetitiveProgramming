#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
     vector<string> cards(52);
     for(int i = 0; i <52; i++) cin>>cards[i];
     int jump=0, Y=0, idx=0;
     for(int i = 0 ; i < 3 ;i++){
	     int X = 0;
	     if(cards[idx][0] > '1' && cards[idx][0] <'9') X = cards[idx][0]-'0';
	     else X +=10;
	     idx++;
	     idx += (10-X);
	     Y +=X;
     }
     cout << "Case "<<t<<": "<< cards[idx+Y-1]<<endl;
   }
   return 0;
}
