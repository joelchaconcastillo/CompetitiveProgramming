#include <bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t <=T; t++){
    string word, res="";
    cin>>word;
    int i = 0, n=word.size();
    while(i<n){
	res.push_back(word[i]);
	int j = i+1;
	while(j<n && word[i]==word[j])j++;
	if(j<n && word[i] < word[j])res.push_back(word[i]);
	i++;
    }
    cout << "Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}
