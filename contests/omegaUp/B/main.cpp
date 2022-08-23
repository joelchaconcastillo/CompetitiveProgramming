#include <bits/stdc++.h>
using namespace std;

int main(){
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   string word;
   cin>>word;
   map<char, int>f;
   map<char, char>nick;
   int n=word.size(), i=0, j=n-1, count = 0;
   for(int ii = 0; ii < n; ii++) f[word[ii]]++, nick[word[ii]]=word[ii];
      while(i<j){
        if(nick[word[i]] != nick[word[j]]){
           int ii=i, jj=j;
           if(f[nick[word[ii]]] < f[nick[word[jj]]]) swap(ii, jj);
           f[nick[word[jj]]] += f[nick[word[ii]]];
           count++;
           nick[word[ii]]=nick[word[jj]];
      }
      i++, j--;	   
   }
   cout <<count<<endl;
   /*
    *At the end I realized that this is the union-find disjoint set XD hahahahah
    * */
   return 0;
}
