#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   unordered_map<char, int> rep;
   rep['J']=1;
   rep['Q']=2;
   rep['K']=3;
   rep['A']=4;
   while(true){
      vector<deque<int>> decks(2);
      int turn=0;
      for(int i=0; i<52; i++, turn=!turn){
	     string tmp;
	     cin>>tmp;
	     if(tmp[0]=='#') return 0;
	     decks[turn].push_front(rep[tmp[1]]);
      }
      deque<int> game;
      bool cycle=false;
      while(!decks[turn].empty()){
	     int card = decks[turn].front(); decks[turn].pop_front();
	     game.push_back(card);
	     turn = !turn;
	     while(card){
		if(decks[turn].empty()){
		   cycle = false;
		   break;
		} else cycle=true;
		int incard = decks[turn].front(); decks[turn].pop_front();
		game.push_back(incard);
		if(incard) card = incard, turn=!turn;
		else card--;
	     }
	     if(cycle){
		cycle=false; turn=!turn;
		while(!game.empty())
		    decks[turn].push_back(game.front()), game.pop_front();
	     }
      }
      if(decks[0].empty())cout << 1<<" "<<setw(2)<< decks[1].size()<<endl;
      else cout << 2<<" "<<setw(2)<<decks[0].size()<<endl;
   }
   return 0;
}
