#ifndef PREPROCESS
#define PREPROCESS
using namespace std::chrono; 
using namespace std;
auto start = high_resolution_clock::now();  
auto duration1 = duration_cast<seconds>(high_resolution_clock::now() - start); 

////DATA section
int D, I, S, V, F;
typedef vector<vector<pair<int,int> > > vvp;
struct vvpd
{
   vvp x;
   int f;
   vector<vector<int> > L,item;
   vector<bool> offlight;
   vector<int> fGroup;
};
struct strEdge
{
   strEdge(string _name, int _a, int _b, int _l):name(_name), a(_a),b(_b), l(_l) {}
   string name;
   int a,b,l;
};
//This data should be pre-processed
vector<vector<int> > Groups;
vector<strEdge> edgelist;
vector<vector<string>> strcarPath;
vector<int> oldIndex;
unordered_map<string, int> stId; 
vector<string> idSt;
vector<int> stlen, remlenCar;
vector<pair<int, int>> streetIdNodes; 
vector<vector<int> > inStreet, carPath;
int findp(int i, vector<int> &p){  return (i==p[i])?i:(p[i]=findp(p[i], p));};
void unionset(int i, int j, vector<int> &p, vector<int> &r)
{
   i = findp(i,p), j = findp(j, p);
   if( i == j) return;
   if( r[i] > r[j]) swap(i,j);
   if(r[i] == r[j]) r[j]++;
   p[i]=j;
}
void isolateGroups()
{
  vector<int> p(I, 0), r(I,0); 
  for(int i = 0; i < I;i++) p[i]=i;
  for(int i = 0; i < V; i++)
      for(int j = 0; j < carPath[i].size()-1; j++)
      {
	      int p1 = streetIdNodes[carPath[i][j]].first, p2 = streetIdNodes[carPath[i][j+1]].first;
	      unionset(p1, p2, p, r);
      }
  int nGroups = 0;
  vector<int> idg;
  for(int i = 0; i < I;i++) if(p[i]==i) idg.push_back(i), nGroups++;
  Groups.assign(nGroups, vector<int> ());
  cerr << "ngroups..."<<nGroups<<endl;
  for( int j = 0; j < idg.size(); j++)
  {
      unordered_set<int> nodes; 
      for(int i = 0; i < I; i++)
	 if( findp(i, p) == idg[j] ) nodes.insert(i);
      for(auto idx:nodes) Groups[j].push_back(idx);
  }
}
void cleanGraph()
{
  unordered_set<string> inPath;
  vector<strEdge> newEdgeList;
  for(int i = 0; i < V; i++)
    for(int j = 0; j < strcarPath[i].size(); j++)
    	inPath.insert(strcarPath[i][j]);

   vector<int> used(I, -1);
   oldIndex.assign(I,-1);
   I = 0;
   for(int i = 0; i < S;i++) //get only streets in paths..
	if( inPath.find(edgelist[i].name) != inPath.end())
	{
	   int tmp = edgelist[i].b;
	   if(used[edgelist[i].b] ==-1)  used[edgelist[i].b] = I++;
	    edgelist[i].b = used[edgelist[i].b];
	   oldIndex[edgelist[i].b]=tmp;
	   newEdgeList.push_back(edgelist[i]); 
	}
 S = inPath.size();
 cerr<< S << " " << I<<endl;
 cerr<<"original size: " << edgelist.size()<<" new size: " <<newEdgeList.size() << " " <<endl;
   idSt.assign(S, "");
   stlen.assign(S, 0);
   remlenCar.assign(V,0); 
   carPath.assign(V,vector<int>()); 
   streetIdNodes.assign(S, pair<int, int>());
   inStreet.assign(I, vector<int>());
   int cont = 0;
   for(int i = 0; i < S; i++)
   {
    int a=newEdgeList[i].a, b=newEdgeList[i].b, l=newEdgeList[i].l;
    string str=newEdgeList[i].name;
    stlen[i] = l;
    idSt[i] = str;
    stId[str]=i;
    streetIdNodes[i] = make_pair(b, a);
    inStreet[b].push_back(i);
   }
   for(int i = 0; i < V; i++)
   {
      for(int j = 0; j < strcarPath[i].size(); j++)
      {
        carPath[i].push_back(stId[strcarPath[i][j]]);
        if(j>0)
        remlenCar[i] += stlen[stId[strcarPath[i][j]]];
      }
   }
}
void read()
{
   cin >> D >> I >> S >> V >> F;

   strcarPath.resize(V);
   for(int i = 0; i < S; i++)
   {
    int a,b, l;
    string str;
    cin >> a >> b >> str>> l; 
    strEdge edg(str, a, b, l);
    edgelist.push_back(edg);
   }
   for(int i = 0; i < V; i++)
   {
      int s;
      cin >> s;
      for(int j = 0; j < s; j++)
      {
        string street;
	cin >> street;
	strcarPath[i].push_back(street);
      }
   }
  cleanGraph();
  isolateGroups();
}
void write(vvp &sol)
{
   //count non-zero streets..
   vector<vector<pair<string,int>>> result;
   vector<int> idnode;
   for(int i = 0; i < I; i++)
   {
      vector<pair<string,int>> vp;
      for(int j = 0; j < sol[i].size(); j++)
	if(sol[i][j].second>0) 
	   vp.push_back(make_pair(idSt[inStreet[i][sol[i][j].first]], sol[i][j].second));
      if(!vp.empty()) result.push_back(vp),  idnode.push_back(i);
   }
   cout << result.size()<<endl;
   for(int i = 0; i < result.size(); i++)
   {
      cout << oldIndex[idnode[i]] << endl;
      cout << result[i].size()<<endl;
      for(int j = 0; j < result[i].size(); j++)
      cout << result[i][j].first<< " " << result[i][j].second<<endl;
   }
}

/////////////////////////////////
//////////Data anaylisis////////
/////////////////////////////////
void upperboundScore()
{
  int sum = 0;
  for(int i = 0; i < V; i++)sum += (F+D-remlenCar[i]);
  cerr<< "Max score: "<<sum<<endl; 
}
void components()
{
  vector<int> p(S, 0), r(S,0); 
  for(int i = 0; i < S;i++) p[i]=i;
  for(int i = 0; i < V; i++)
  {
      for(int j = 0; j < carPath[i].size()-2; j++) unionset(carPath[i][j], carPath[i][j+1], p, r);
  } 
  int cont = 0;
  for(int i = 0; i < S;i++) if(p[i]==i) cont++;
  cerr<<cont<<endl;
}
#endif
