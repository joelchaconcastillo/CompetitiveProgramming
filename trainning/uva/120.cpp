#include <bits/stdc++.h>
using namespace std;
/*
   5 1 2 3 4
   4 3 2 1 5
   1 2 3 4 5
*/
int main(){
   string line;
   while(getline(cin, line)){
	if(line.empty())break;
      vector<int> pancakes;
      line+=' ';
      string word="";
      for(auto i:line){	
	if(i==' '){
	 if(!word.empty())
          pancakes.push_back(stoi(word));
	  word="";
	}
	else word+=i;
      }
      int n = pancakes.size();
      for(int i = 0 ; i < n; i++){
	cout<<pancakes[i];
	if(i+1<n)cout<<" ";
      }
      cout<<endl;
      for(int i =0; i < n; i++){
          pair<int, int> maxi(pancakes.front(), 0);
	  for(int j = 0; j+i < n;j++){
             maxi=max(maxi, {pancakes[j], j}); 
	  }
          if(maxi.second==n-i-1)continue;
          if(maxi.second!=0){
             cout<<n-maxi.second<<" ";
	     reverse(pancakes.begin(), pancakes.begin()+maxi.second+1);
	  }
	  cout<<i+1<<" ";
	  reverse(pancakes.begin(), pancakes.begin()+n-i);
      }
      cout<<0<<endl;
   }
   return 0;
}
