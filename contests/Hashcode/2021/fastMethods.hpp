#ifndef FASTMETHODS
#define FASTMETHODS
////////////////////////////////
/////////////////Improvement-one
////////////////////////////////
void eval2(vvpd &sol)
{
   vector<queue<pair<int, int> > > stateStreet(S);
   vector<int> cStreet(V, 0);
   int score = 0;
   for(int i = 0; i < V; i++) stateStreet[carPath[i][0]].push(make_pair(0, i));
   for(int t = 0; t <= D; t++)
   {
      for(int i = 0; i < I; i++)
      {
       int greenStreet = sol.L[i][t];
	if(sol.offlight[i]) continue;
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
   }
   sol.f=score;
}
void evalComponent(vvpd &sol, int idGroup)
{
   vector<queue<pair<int, int> > > stateStreet(S);
   vector<int> cStreet(V, 0);
   int score = 0;
   for(int i = 0; i < V; i++)
	   stateStreet[carPath[i][0]].push(make_pair(0, i));//init waiting cars
   for(int t = 0; t <= D; t++)
   {
      for(int j = 0; j < Groups[idGroup].size(); j++)
      {
        int  i = Groups[idGroup][j];
       int greenStreet = sol.L[i][t];
	if(sol.offlight[i]) continue;
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
   }
   sol.fGroup[idGroup]=score;
}
void expandTime(vvpd &sol, int i)
{
      pair<int, int> stLight(0,0); //id_light-item
      sol.offlight[i] = false; //active light
      for(int j = 0; j <=D; j++)
      {
 	int cnt=0, size = sol.x[i].size();
	while(sol.x[i][stLight.first].second == 0 && cnt < size)stLight.first++, cnt++, stLight.first%=size;
	if( cnt == size) { sol.offlight[i]=true; break;}
	 sol.L[i][j]=inStreet[i][sol.x[i][stLight.first].first];
//	 sol.item[i][j]=stLight.first;
         stLight.second++;
	 if( stLight.second >= sol.x[i][stLight.first].second)
	    stLight.second=0, stLight.first++, stLight.first %= size;
      }
}
void randominit2(vvpd &sol)
{
    sol.x.assign(I,vector<pair<int,int>>());
    sol.L.assign(I, vector<int>(D+1,0));
    sol.offlight.assign(I, false);
    sol.fGroup.assign(Groups.size(), 0);
    for(int i = 0; i < I; i++)
    {
      for(int j = 0; j < (int)inStreet[i].size(); j++)
      {
	sol.x[i].push_back(make_pair(j,1));
	//sol[i].push_back(make_pair(j, rand()%D+1));
      }
      random_shuffle(sol.x[i].begin(), sol.x[i].end());
     expandTime(sol, i);
    }
    eval2(sol);
    int sum = 0;
    for(int i = 0; i < Groups.size(); i++) evalComponent(sol, i), sum +=sol.fGroup[i];
    cerr<<sol.f<< " "<<sum<<endl;
}
////////////////////////////////
// Fast local-search section..//
////////////////////////////////
void localsearchA(vvpd &sol, int maxite, int totaltime)
{
  vvpd current = sol;
  while(maxite-- && duration1.count() < totaltime)
  {
     int node = rand()%I;
     int item = rand()%sol.x[node].size();
     int i =rand()%10;
     current.x[node][item].second = i;
     expandTime(current, node);
     eval2(current);
     if(current.f > sol.f)
     { 
	sol.f = current.f, sol.x[node]=current.x[node], sol.L[node]=current.L[node];
     	cerr<< "Improved LSA: "<<maxite<< "t: "<<i<< " score: "<<sol.f<<" " << duration1.count() << endl;
	maxite +=100;
     }
     else current.f = sol.f, current.x[node] = sol.x[node], current.L[node]=sol.L[node];
     duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
  }
}
void localsearchB(vvpd &sol, int maxite, int totaltime)
{
  vvpd current = sol;
  while(maxite-- && duration1.count() < totaltime)
  {
     int node = rand()%I;
     int size = current.x[node].size();
     if( size <=1) continue;
     int a =  rand()%size, b = rand()%size;
     while(a==b) b = rand()%size;
     iter_swap(current.x[node].begin()+a, current.x[node].begin()+b);
     expandTime(current, node);
     eval2(current); 
     if(current.f > sol.f)
     {
	sol.f = current.f, sol.x[node]=current.x[node], sol.L[node]=current.L[node];
     	cerr<< "Improved LSB: "<<maxite<<" score: "<<sol.f<< " " << duration1.count() <<endl;
	maxite +=100;
     }
     else current.f = sol.f, current.x[node] = sol.x[node], current.L[node]=sol.L[node];
     duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
  }
}

void localsearchA(vvpd &sol, int maxite, int totaltime, int idGroup)
{
  vvpd current = sol;
  while(maxite-- && duration1.count() < totaltime)
  {
     int node = Groups[idGroup][rand()%Groups[idGroup].size()];
     int item = rand()%sol.x[node].size();
     int i =rand()%10;
     current.x[node][item].second = i;
     expandTime(current, node);
     evalComponent(current, idGroup); 
     if(current.fGroup[idGroup] > sol.fGroup[idGroup])
     { 
	sol.f += -sol.fGroup[idGroup]+current.fGroup[idGroup], sol.x[node]=current.x[node], sol.L[node]=current.L[node], sol.fGroup[idGroup] = current.fGroup[idGroup];
     	cerr<< "Improved LSA: "<<maxite<< "t: "<<i<< " score: "<<sol.f<<" " << duration1.count() << endl;
	maxite +=100;
     }
     else current.f = sol.f, current.x[node] = sol.x[node], current.L[node]=sol.L[node], current.fGroup[idGroup]=sol.fGroup[idGroup];

     duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
  }
}
void localsearchB(vvpd &sol, int maxite, int totaltime, int idGroup)
{
  vvpd current = sol;
  while(maxite-- && duration1.count() < totaltime)
  {
     int node = Groups[idGroup][rand()%Groups[idGroup].size()];
     int size = current.x[node].size();
     if( size <=1) continue;
     //random_shuffle(current.x[node].begin(), current.x[node].end());
     int a =  rand()%size, b = rand()%size;
     while(a==b) b = rand()%size;
     iter_swap(current.x[node].begin()+a, current.x[node].begin()+b);
     expandTime(current, node);
     //eval2(current); 
     evalComponent(current, idGroup); 
     if(current.fGroup[idGroup] > sol.fGroup[idGroup])
     {
	sol.f += -sol.fGroup[idGroup]+current.fGroup[idGroup], sol.x[node]=current.x[node], sol.L[node]=current.L[node], sol.fGroup[idGroup] = current.fGroup[idGroup];
     	cerr<< "Improved LSB: "<<maxite<<" score: "<<sol.f<< " " << duration1.count() <<endl;
	maxite +=500;
     }
     else current.f = sol.f, current.x[node] = sol.x[node], current.L[node]=sol.L[node], current.fGroup[idGroup]=sol.fGroup[idGroup];
     duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
  }
}

void localsearchA(vvpd &sol, int maxite, int totaltime, vector<int> &nodes)
{
  vvpd current = sol;
  while(maxite-- && duration1.count() < totaltime)
  {
     int node = nodes[rand()%nodes.size()];
     int item = rand()%sol.x[node].size();
     int i =rand()%15;
     current.x[node][item].second = i;
     expandTime(current, node);
     eval2(current);
     if(current.f > sol.f)
     { 
	sol.f = current.f, sol.x[node]=current.x[node], sol.L[node]=current.L[node];
     	cerr<< "Improved LSA: "<<maxite<< "t: "<<i<< " score: "<<sol.f<<" " << duration1.count() << endl;
	maxite +=10;
     }
     else current.f = sol.f, current.x[node] = sol.x[node], current.L[node]=sol.L[node];
     duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
  }
}
void localsearchB(vvpd &sol, int maxite, int totaltime, vector<int> &nodes)
{
  vvpd current = sol;
  while(maxite-- && duration1.count() < totaltime)
  {
     int node = nodes[rand()%nodes.size()];
     int size = current.x[node].size();
     if( size <=1) continue;
     int a =  rand()%size, b = rand()%size;
     while(a==b) b = rand()%size;
     iter_swap(current.x[node].begin()+a, current.x[node].begin()+b);
     expandTime(current, node);
     eval2(current); 
     if(current.f > sol.f)
     {
	sol.f = current.f, sol.x[node]=current.x[node], sol.L[node]=current.L[node];
     	cerr<< "Improved LSB: "<<maxite<<" score: "<<sol.f<< " " << duration1.count() <<endl;
	maxite +=100;
     }
     else current.f = sol.f, current.x[node] = sol.x[node], current.L[node]=sol.L[node];
     duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
  }
}
//////////////////////////////////////
void localsearchbyGroups(vvpd &sol, int totaltime)
{
   start = high_resolution_clock::now();  
   set<pair<int, int>>sizesG;
   for(int i = 0; i < Groups.size(); i++) sizesG.insert(make_pair(Groups[i].size(), i));
   while( duration1.count() < totaltime)
   {
	for(auto idGroup:sizesG)
	{
 //       localsearchA(sol, 50, totaltime, idGroup.second);
        localsearchB(sol, 50, totaltime, idGroup.second);
        duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
	cerr << sol.f<<endl;
	}
   }
}
void localsearchbyPaths(vvpd &sol, int totaltime)
{
   start = high_resolution_clock::now();  
   set<pair<int, int>> pathsbylen;
   vector<vector<int> > nodesbyPath(V);
   for(int i = 0; i < carPath.size(); i++) pathsbylen.insert(make_pair(-remlenCar[i], i));
   for(int i = 0; i < carPath.size(); i++)
      for(int j = 0; j < carPath[i].size(); j++)
	   nodesbyPath[i].push_back(streetIdNodes[carPath[i][j]].first);
   while( duration1.count() < totaltime)
   {
	for(auto idx:pathsbylen)
	{
//		if(idx.first <10)continue;
	  cerr<<idx.first<< ":" <<idx.second<<endl;
          localsearchB(sol, 100, totaltime, nodesbyPath[idx.second]);
          localsearchA(sol, 10, totaltime, nodesbyPath[idx.second]);
          duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
	  cerr << sol.f<<endl;
	}
   }
}
void localsearch(vvpd &sol, int totaltime)
{

   start = high_resolution_clock::now();  
   while( duration1.count() < totaltime)
   {
          localsearchA(sol, 100, totaltime);
          localsearchB(sol, 100, totaltime);
          duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 
	  cerr << sol.f<<endl;
   }
}
void initA(vvpd &sol)
{
    sol.x.resize(I);
    sol.L.resize(I, vector<int>(D+1,0));
    sol.item.resize(I, vector<int>(D+1,0));
    sol.offlight.resize(I, false);
    sol.fGroup.assign(Groups.size(), 0);
 for(int i = 0; i < I; i++)
    {
      for(int j = 0; j < (int)inStreet[i].size(); j++)
	sol.x[i].push_back(make_pair(j, 1));
      expandTime(sol, i);
    }

    for(int a = 0; a < 100; a++)
   {

    for(int i = 0; i < I; i++)
    {
      expandTime(sol, i);
    }
          vector<queue<pair<int, int> > > stateStreet(S);
       vector<int> cStreet(V, 0);
       for(int i = 0; i < V; i++) stateStreet[carPath[i][0]].push(make_pair(0, i));
       for(int t = 0; t <= D; t++)
       {
          for(int i = 0; i < I; i++)
          {
           int greenStreet = sol.L[i][t];
    	   if(sol.offlight[i]) continue;
           if(stateStreet[greenStreet].empty() || stateStreet[greenStreet].front().first > t) continue;
	   int waiting =  t - stateStreet[greenStreet].front().first;
	   if( waiting>0)
	   { 
		   int cyclesize =0;
		   for(int idx = 0; idx < sol.x[i].size(); idx++)cyclesize+=sol.x[i][idx].second;
		   int newt = waiting % cyclesize;
		   bool noset=false;
		   for(int idx = 0; idx < sol.x[i].size(); idx++)
			  if( sol.x[i][idx].second == newt) noset=true;
		   if(!noset)
		   {
			   cerr<<newt<<endl;
		   sol.x[i][sol.item[i][t]].second = newt;
		   t=D+1;
      		   expandTime(sol, i);
		   break;
		   }
	   }
           int car = stateStreet[greenStreet].front().second;
           stateStreet[greenStreet].pop();
           int nextStreet = carPath[car][cStreet[car]+1];
           if( cStreet[car] < carPath[car].size()-2)
    	      stateStreet[nextStreet].push(make_pair(t+stlen[nextStreet], car));
    	   cStreet[car]++;
          }  
       }
        cerr<<eval1(sol.x)<<endl;
//	cerr<<sol.f<<endl;
   }

}
#endif
