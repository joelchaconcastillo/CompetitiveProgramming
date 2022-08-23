#include <bits/stdc++.h>
using namespace std;
int main(){
    int M, n,m;
    cin>>M;
    while(M--){
      cin>>n>>m;
      set<pair<int, int> > inver;
      vector<string> data(m);
      for(int i = 0; i < m; i++){
	string word;
	cin>>word;	
	data[i]=word;
	vector<char> sorted;
        int nn=word.size(), total=0;
	for(int ii = 0 ; ii < nn; ii++){
	   auto it=upper_bound(sorted.begin(), sorted.end(), word[ii]);
	   int idx = it-sorted.begin();
	   total += sorted.size()-idx;
	   sorted.insert(it, word[ii]);
	}
	inver.insert({total, i});
      }
      for(auto i:inver)
	 cout<<data[i.second]<<endl;
      if(M>0)
      cout<<endl;
    }
    return 0;
}
