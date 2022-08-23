#include <bits/stdc++.h>
using namespace std;

//vector<unsigned long long> AdjMat;
unsigned long long AdjMat[70];
unsigned long long V,E,all; int nS, mxS;
void rec(int i, unsigned long long used, int depth)
{
   if(used == all){
     nS++;
     mxS=max(mxS, depth);
   }
   else{
     for(int j = i; j < V; j++){
        if(!(used & (1LL<<j)) )
	  rec(j+1, used | AdjMat[j], depth+1);
     }
   }
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int nc;
   cin>>nc;
   while(nc--)
   {
      cin>>V>>E;
 //     AdjMat.assign(V, 0LL);
      mxS=nS=0;
      all=(1LL<<V)-1;
      for(int i = 0; i < V; i++) AdjMat[i] = (1LL<<i);//main diagonal 
      for(int i = 0; i < E; i++){
	int a, b;
        cin>> a >> b;
	AdjMat[a] |= (1LL<<b);
	AdjMat[b] |= (1LL<<a);
      }
      rec(0, 0LL, 0);
      cout << nS<<"\n"<<mxS<<endl;
   }
   return 0;
}
