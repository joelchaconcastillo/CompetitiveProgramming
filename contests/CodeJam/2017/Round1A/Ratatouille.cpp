#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_P 50
using namespace std;
int N,P, R[MAX_N], Q[MAX_N*MAX_P];

int main()
{
  int ite;
  cin>>ite;
  for(int it =1; it <=ite; it++)
  {
   cin>>N>>P;
   for(int i = 0; i < N; i++) cin >> R[i];
   for(int i = 0; i < N; i++)
     {
     for(int j = 0; j < P; j++)
	   cin>>Q[i*P+j];
	   sort(Q+i*P,Q+(i+1)*P);
     }
   
   vector<int> idx(N, 0);
   int total = 0, s=0;//services..
   while(s*9*R[0] <= 10*Q[P-1])
   {
      bool notOptions=false;
      for(int i = 0; i < N && !notOptions;i++)
      {
	while( idx[i] < P  && s*9*R[i]  >  Q[i*P + idx[i]]*10  )idx[i]++;
	notOptions = (idx[i] >=P);
      }
      if(notOptions) break;
      for(int i = 0; i < N && !notOptions; i++)
          if(  s*9*R[i] <= 10*Q[i*P+idx[i]] && s*11*R[i] >=10*Q[i*P+idx[i]]) continue;
          else notOptions=true;
      if(notOptions) s++;
      else
      { 
	  total++;
	  for(int i = 0; i < N ; i++)idx[i]++;
      }
   }
   cout << "Case #"<<it<<": "<<total<<"\n";

  } 
  return 0;
}
