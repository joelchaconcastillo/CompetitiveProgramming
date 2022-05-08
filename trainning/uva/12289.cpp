#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N;
   cin >> N;
   for(int i = 0; i < N; i++)
   {
      string word;
      cin >> word;
      if( word.size() == 5) cout << "3" <<endl;
      else 
	{
	 string word1 = "one";
	  int sum = 0;
	  for(int i = 0; i < 3; i++) if(word1[i]!=word[i]) sum++;
	  if(sum<=1) cout << "1" <<endl;
	  else cout << "2"<<endl;
	}
    
   }
}
