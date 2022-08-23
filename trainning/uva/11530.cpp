#include <bits/stdc++.h>
using namespace std;
int main(){
   unordered_map<char, int> dict;
   dict['a']=dict['d']=dict['g']=dict['j']=dict['m']=dict['p']=dict['t']=dict['w']=dict[' ']=1;
   dict['b']=dict['e']=dict['h']=dict['k']=dict['n']=dict['q']=dict['u']=dict['x']=2;
   dict['c']=dict['f']=dict['i']=dict['l']=dict['o']=dict['r']=dict['v']=dict['y']=3;
   dict['s']=dict['z']=4;
   int T;
   string st;
   cin>>T;
      getline(cin, st);
   for(int t=1; t<=T;t++){
      getline(cin, st);
      int res=0;
      for(auto i:st) res+=dict[i];
      cout<<"Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}
