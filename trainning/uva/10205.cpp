#include <bits/stdc++.h>
using namespace std;
string values[] = {"2","3","4","5","6","7","8","9", "10","Jack","Queen","King", "Ace"};
string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
	   if(t>1)cout<<endl;
	   int n;
	   cin>>n;
	   vector<vector<int>>sh(n, vector<int>(52, 0));
	   for(int i = 0 ; i < n ; i++){
	      for(int j = 0 ; j < 52; j++){
		      cin>>sh[i][j];
		      sh[i][j]--;
	      }
	   }
	   string line;
	   getline(cin, line);
	   vector<int> track;
	   while(getline(cin, line)){
		   if(line=="")break;
		   int _to=stoi(line);
		   _to--;
		   track.push_back(_to);
           }
	   for(int i =0; i < 52; i++){
	      int k=i;
	      for(int j = track.size()-1; j>=0; j--){
		      k=sh[track[j]][k];
	      }
	      cout<<values[k%13]<<" of "<<suits[k/13]<< endl;
	   }
	}
   return 0;
}
