#include <bits/stdc++.h>
using namespace std;
int main(){
   int num, idx=0;
   unordered_map<int, int> freq;
   vector<int> data;
   while(cin>>num){
     if(freq.find(num)==freq.end())
	data.push_back(num);
     freq[num]++;
   }
   for(auto i:data){
	cout <<i <<" "<<freq[i]<<endl;
   }
   return 0;
}
