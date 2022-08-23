#ifndef NAIVEMETHODS
#define NAIVEMETHODS
//Naive implementation//
void randominit1(vvp &sol)
{
    sol.resize(I);
    for(int i = 0; i < I; i++)
    {
      for(int j = 0; j < (int)inStreet[i].size(); j++)
      {
        sol[i].push_back(make_pair(j, rand()%2+1));
      }
      random_shuffle(sol[i].begin(), sol[i].end());
    }
}
/**
 *Improvement: pre-process and save the states in a matrix time vs light (just improves to the incremental evaluation)
 * */
void updateLights(vector<pair<int, int> > &stateLight, vvp &sol)
{
   for(int i = 0; i < I; i++)
   {
	if(stateLight[i].first == -1) continue;
	int cnt=0, size = sol[i].size();
	while(sol[i][stateLight[i].first].second == 0 && cnt < size)stateLight[i].first++, cnt++, stateLight[i].first%=size;
	stateLight[i].second++;
	if( stateLight[i].second >= sol[i][stateLight[i].first].second)
          stateLight[i].second=0, stateLight[i].first++, stateLight[i].first %= size;
   }
}
/**
 * Improvements: just check lights with waiting cars
 * */
int moveCars(vector<pair<int, int> > &stateLight, vector<queue<pair<int, int> > > &stateStreet, vector<int> &cStreet, vvp &sol, int t)
{
   int score = 0;
   for(int i = 0; i < I; i++)
   {
       int greenStreet = inStreet[i][sol[i][stateLight[i].first].first];
       if(stateLight[i].first == -1) continue;
       if(stateStreet[greenStreet].empty() || stateStreet[greenStreet].front().first > t) continue;
       int car = stateStreet[greenStreet].front().second;
       stateStreet[greenStreet].pop();
       int nextStreet = carPath[car][cStreet[car]+1];
       if( cStreet[car] == carPath[car].size()-2 && t+stlen[nextStreet] <= D)
	score += (F+(D-t-stlen[nextStreet])); 
       else
	stateStreet[nextStreet].push(make_pair(t+stlen[nextStreet], car));
	cStreet[car]++;
   }
   return score;
}
int eval1(vvp &sol)
{
   vector<pair<int, int> > stateLight(I, pair<int, int>(0, 0));
   //cars variables..
   vector<queue<pair<int, int> > > stateStreet(S);
   vector<int> cStreet(V, 0);
   int score = 0;
   for(int i = 0; i < V; i++)
	   stateStreet[carPath[i][0]].push(make_pair(0, i));//init waiting cars
   for(int i = 0; i < I; i++)
   {
	int cnt=0, size = sol[i].size();
	while(sol[i][stateLight[i].first].second == 0 && cnt < size)stateLight[i].first++, cnt++, stateLight[i].first%=size;
	if(cnt == size) stateLight[i].first = -1;
   }
   for(int t = 0; t <= D; t++)
   { 
       score += moveCars(stateLight, stateStreet, cStreet, sol, t);
       updateLights(stateLight, sol);
   }
 return score;
}



void localsearch1(vvp &sol, int ite) //local search by time
{
   int fit = eval1(sol);
   pair<int, vvp> current(fit, sol);
   while(ite--)
   {
     int node = rand()%I;
     int item = rand()%inStreet[node].size();
     int oldT = current.second[node][item].second;
     current.second[node][item].second = rand()%10;
     current.first = eval1(current.second);
      if( current.first > fit ) fit = current.first, sol[node][item].second =current.second[node][item].second, ite +=10;
      else current.second[node][item].second = oldT, current.first = fit;
      cerr <<current.first<< " "<< fit<<endl;
   }
}
void localsearch2(vvp &sol, int ite)//by order
{
   int fit = eval1(sol);
   pair<int, vvp> current(fit, sol);
   while(ite--)
   {
     int node = rand()%I;
     random_shuffle(current.second[node].begin(), current.second[node].end());
     current.first = eval1(current.second);
      if( current.first > fit ) fit = current.first, sol[node] =current.second[node], ite +=10;
      else current.second[node] = sol[node], current.first = fit;
      cerr <<current.first<< " "<< fit<<endl;
   }
}

#endif
