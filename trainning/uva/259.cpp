#include <bits/stdc++.h>
#define SIZE 38
#define INF 1e9
using namespace std;
int s, t, f, mf, sumcap;
int W[SIZE*SIZE];
vector<vector<int> > edges;
vector<int> p;
void Augmented(int c, int flow)
{
   if(c == s){  f = flow;  return;}
   else if(p[c] != -1)
   {
     Augmented(p[c], min(flow, W[p[c]*SIZE + c]));
     W[p[c]*SIZE + c] -= f;
     W[c*SIZE + p[c]] += f;
   }
}
void Edmods_Karp()
{
  mf = 0;
  while(true)
 {
   f = 0;
   queue<int> q;
   bitset<SIZE> visited;
   visited.set(s);
   q.push(s);
   p.assign(SIZE, -1);
   visited.set(s);
   while(!q.empty()) //BFS..
   {
        int u = q.front();
	q.pop();
	if(u == t) break;
	for(int i = 0; i  < edges[u].size(); i++)
	{
	   int v = edges[u][i];
	   if(  W[u*SIZE + v] > 0 && !visited.test(v))
	   {
	     q.push(v);
	     visited.set(v);
	     p[v] = u;
	   }
	}
   }
    Augmented(t, INF); //getting a path...
    if( f == 0) break;
    mf += f;
 }
}
int main()
{
   s = 36;
   t = 37;
   char app;
   int cap;
   edges.assign(SIZE, vector<int> ());
   memset(W, 0, sizeof W);	
	for(int i=0; i <10; i++)
	   {
	      edges[i].push_back(t);
	      edges[t].push_back(i);
	      W[i*SIZE + t]=1;
	   }
   sumcap = 0;
  bool End=false;
   while(true)
   {
	if(scanf("%c", &app) == EOF)End=true;
	if( app == '\n' || End){
           
	   Edmods_Karp();
	   if(mf == sumcap)
	   {
	      for(int i =0; i < 10; i++)
 	      {
	        char c_PC='_';
	        for(int j = 10; j < 37; j++)
	        {
	           if(W[i*SIZE + j] == 1)
		   { c_PC = (char)(j-10+'A');
			break;}
	        }
	        printf("%c", c_PC);
	      }
	   }
	   else printf("!");
	   printf("\n");
    	if(End) break;
	edges.assign(SIZE, vector<int> ());
   	memset(W, 0, sizeof W);	
for(int i=0; i <10; i++)
	   {
	      edges[i].push_back(t);
	      edges[t].push_back(i);
	      W[i*SIZE + t]=1;
	   }
   	sumcap = 0;
	   continue;	
	}
        scanf("%d ", &cap);
	int idx_app = app -'A'+ 10;
	edges[s].push_back(idx_app);
	edges[idx_app].push_back(s);
	W[s*SIZE + idx_app] = cap;
	sumcap +=cap;
	char pc;
	while(true)
 	{
           scanf("%c", &pc);
	   if(pc==';')
	   {
           scanf("%c", &pc);
		break;
	   }
	   int idx_v = (pc)-'0';
	   edges[idx_app].push_back(idx_v);
	   edges[idx_v].push_back(idx_app);
	   W[idx_app*SIZE + idx_v] = 1;
	}
   }
   return 0;
}
