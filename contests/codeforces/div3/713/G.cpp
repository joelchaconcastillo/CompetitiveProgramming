#include <bits/stdc++.h>
#define MAX_N 10000000
using namespace std;
int main()
{
  int ite;
  vector<int> data(MAX_N,0);
  cin>>ite;
  data[1]=1;
    for(int  i = 2; i < MAX_N; i++)
    {
        if((i%2)==0)
	  data[i] = i+data[i/2];
	else
	  data[i] = i+1;
    }
//	for(int j = i; j< MAX_N; j+=i) data[j]+=i;
  while(ite--)
  {
    int n;
    cin>>n;
    int idx=-1;
    for(int i = 1; i <=n && idx==-1; i++)
	    if( data[i]== n) idx=i;
    cout << idx<<endl;
  }
  return 0;
}
