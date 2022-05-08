#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;

  while(n--){
   string s;
   cin>>s;
   set<string> all;
   int N=s.size();
   for(int i = 0; i < N; i++){
      string current="";
      for(int j = 0; j  < N; j++)
	current +=s[(j+i)%N];
      all.insert(current);
   }
   cout << *(all.begin())<<endl;
  }
  return 0;
}
