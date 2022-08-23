#include <bits/stdc++.h>
#define NN 1000
using namespace std;
unordered_map<int, unordered_map<int, bool> > adj;
int p[NN], r[NN];
void init()
{
   memset(r, 0, sizeof r);
   for(int i = 0; i < NN; i++) p[i] = i;
}
int findset(int i)
{
   if( i == p[i]) return i;
   return p[i] = findset(p[i]);
}
void unionset(int a, int b)
{
 int x=findset(a), y=findset(b);
 if( x == y ) return;
 if( r[x] < r[y])
 {
   p[x] = y;
 }
 else
 {
   if( r[x] == r[y] ) r[x]++;
   p[y] = x; 
 } 
}
bool sameset(int a, int b)
{
  return findset(a) == findset(b);
}
bool active[NN];
int main()
{
  int N, M;
  while(scanf("%d\n", &N) != EOF)
  {
     scanf("%d\n", &M);
     char c1,c2,c3;
     memset(active, 0, sizeof active);
	adj.clear();
//     init();
     scanf("%c%c%c\n", &c1, &c2, &c3);
     active[c1] = true;
     active[c2] = true;
     active[c3] = true;
//     unionset(c1, c2);	
//     unionset(c1, c3);	
     for(int i = 0; i < M; i++)
     {
 	char a,b;
    	scanf("%c%c\n",&a, &b); 
        adj[a][b] = true;
        adj[b][a] = true;
     }
     int totalcont = 3;
     int years = 0;
     while(true)
     {
       vector<int> toactive;
       for(auto r1 = adj.begin(); r1 != adj.end(); r1++)
       {
	  if(active[r1->first]) continue;
          int cont = 0;
          for(auto r2 = r1->second.begin(); r2 != r1->second.end(); r2++)
             if( active[r2->first]) cont++;
          if(cont >= 3) toactive.push_back(r1->first);
       }
	for(auto i = toactive.begin(); i != toactive.end(); i++)
	   active[*i] = true;
        totalcont += toactive.size();
	if(toactive.empty()) break;
	years++;
     }

     if(totalcont == N ) printf("WAKE UP IN, %d, YEARS\n", years);
	else printf("THIS BRAIN NEVER WAKES UP\n");
//     char skip[100];
//	scanf("%s\n", skip);
//	cout << skip<<endl;
  }
  return 0;
}
