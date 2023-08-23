#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> contribution;

bool cmp(string &A, string &B){
   if( contribution[A[0]] < contribution[B[0]])return true;
   else if( contribution[A[0]] > contribution[B[0]])return false;
   else{
       if(contribution[A[1]]<=contribution[B[1]])return true;
       else return false;
   }
   return false;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
contribution['C']=1;
contribution['D']=2;
contribution['S']=3;
contribution['H']=4;
contribution['2']=5;
contribution['3']=6;
contribution['4']=7;
contribution['5']=8;
contribution['6']=9;
contribution['7']=10;
contribution['8']=11;
contribution['9']=12;
contribution['T']=13;
contribution['J']=14;
contribution['Q']=15;
contribution['K']=16;
contribution['A']=17;

   char dealer;
   unordered_map<char, int> rep;
   unordered_map<int, char> invrep;
   rep['S']=0;
   rep['W']=1;
   rep['N']=2;
   rep['E']=3;
   invrep[0]='S';
   invrep[1]='W';
   invrep[2]='N';
   invrep[3]='E';
   while(cin>>dealer){
	if(dealer=='#')break;
	string line1, line2;
	cin>>line1>>line2;
	auto line = line1+line2;
	vector<vector<string>>cards(4);
	int i = rep[dealer], j=0;
	while(j < line.size()){
	     i++;
	     i%=4;
	     cards[i].push_back(line.substr(j, 2));
	     j+=2;
	}
	for(int i = 0 ; i < 4; i++){
	   sort(cards[i].begin(), cards[i].end(), cmp);
	   cout << invrep[i]<<":";
	   for(int j = 0; j < cards[i].size(); j++){
		   cout << " "<<cards[i][j];
	   }
	   cout<<endl;
	}
   }
   return 0;
}
