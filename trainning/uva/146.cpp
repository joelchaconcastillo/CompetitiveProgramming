#include <bits/stdc++.h>
using namespace std;
int main()
{
  string word;
  while(cin >> word, word[0]!= '#' )
  {
     if(next_permutation(word.begin(), word.end())) cout << word<<endl;
	else cout << "No Successor"<<endl;
  }
  return 0;
}
