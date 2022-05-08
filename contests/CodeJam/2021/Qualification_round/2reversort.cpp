#include<bits/stdc++.h>
using namespace std;
int d[100],d2[100], N, C;
int cost()
{
  int c=0;

  for(int i = 0; i < N; i++)d2[i]=d[i];
  for(int i = 0; i < N-1; i++)
   {
     pair<int, int>minv(1000000, -1);
     for(int j = i; j < N; j++)  minv = min(minv, make_pair(d2[j], j));
     if(minv.second!=i) c += minv.second-i+1, reverse(d2+i, d2+minv.second+1);
     else c++;
   }
  return c;
}
int main()
{
  int T;
  cin >>T;
  for(int ite = 1; ite <=T; ite++)
  {
     cin >>N >>C;
     bool found=false;
     for(int i = 1 ; i <=N; i++) d[i-1]=i;
     do
     {
cout << "cost.."<< cost()<<endl;
     for(int i = 0; i <N;i++)cout << d[i]<<" ";cout <<endl;
        if(cost() == C)found=true;
	if(found)break;
     }while(next_permutation(d, d+N));
     cout <<"Case #"<<ite<<": ";
     if(!found)cout<<"IMPOSSIBLE";
     else
     for(int i = 0; i <N;i++)cout << d[i]<<" ";
     cout <<endl;
  }
  return 0;
}
