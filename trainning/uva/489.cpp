#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  int t1[300];
  while(cin >> T)
  {
     if(T==-1)break;
     cout << "Round "<<T<<endl;
     memset(t1, 0, sizeof t1);
	string ans, guess;
     cin >> ans;
     cin >> guess;
     int anscont = 0, guesscont=0, wc=0;
     for(int i = 0; i < ans.size(); i++)
     {
        if(t1[ans[i]]) continue;
	t1[ans[i]]=1;
	  anscont++;
     }
     
     for(int i = 0; i < guess.size() && wc < 7; i++)
     {
	if(t1[guess[i]]==1)
	{
	   guesscont++;
	   t1[guess[i]]=2;
	}
	else if(t1[guess[i]]==0)
	{
	 t1[guess[i]]=2;
	  wc++; 
	}
     }
     if(anscont == guesscont ) cout << "You win.\n";
     else
     {
	if(wc == 7 ) cout << "You lose.\n";
	else cout << "You chickened out.\n";
     }
  }
  return 0;
}
