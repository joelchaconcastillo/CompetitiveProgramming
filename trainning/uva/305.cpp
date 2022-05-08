#include <bits/stdc++.h>
using namespace std;
int k;
int mem[]={0,2,7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
//bool solve(int skip)
//{
//   vector<int> alive(2*k);
//   for(int i = 0; i < 2*k; i++)alive[i]=i;
//   int idx=(skip-1)%alive.size();
//   while(alive.size()>k)
//   {
//	if(alive[idx]<k)return false;
//       alive.erase(alive.begin()+idx);
//       idx = (idx+skip-1)%alive.size();
//   }
//   return true;
//}
bool solve(int skip)
{
   int s=2*k, idx=(skip-1)%s, i=0;
   for(; i < 2*k; i++)
   {
	if(idx<k)break;
       s--;
       idx = (idx+skip-1)%s;
   }
   return (i==k);
}
int main()
{
  int memo[20];
  memset(memo, 0,sizeof memo);
  while(cin>>k, k!=0)
  {
//	 cout << mem[k]<<endl; //this is cheating....
     if(memo[k]!=0)cout << memo[k]<<endl;
	else
     for(int i = k+1; ; i++)
	{
           if(solve(i)){memo[k]=i; cout << i<<endl;break;}
	}
  }
  return 0;
}
