#include <bits/stdc++.h>
int MAX_N = 2e7+13;
using namespace std;
int main()
{
  vector<int> simin(MAX_N), counter(MAX_N);
     simin[1]=1;
     for(int i = 2; i<MAX_N; i++)
     {
       if(simin[i]==0)
        for(int j = i; j <MAX_N;j+=i) if(simin[j]==0) simin[j]=i;
     }
     for(int  i = 2; i <MAX_N; i++) counter[i] = counter[i/simin[i]] + (simin[i] != simin[i/simin[i]]);
  int it, c,d,x;
  cin>>it;
  while(it--)
  {
     cin>>c>>d>>x;
     int cont = 0;
     for(int i = 1; i*i<=x;i++)
     {
        if(x%i !=0 ) continue;
	int k1 = x/i+d;
	if(k1 %c==0) cont += 1<<counter[k1/c];
	if(i*i==x)continue;
	int k2 = i+d;
	if(k2%c==0)cont +=1<<counter[k2/c];
     }
     cout << cont <<"\n";
  }
  return 0;
}
