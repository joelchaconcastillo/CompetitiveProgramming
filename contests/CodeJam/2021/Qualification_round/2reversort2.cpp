#include<bits/stdc++.h>
using namespace std;
int d[101], N, C;
int main()
{
  int T;
  cin >>T;
  for(int ite = 1; ite <=T; ite++)
  {
    cin >>N >>C;
    for(int i = 1 ; i <=N; i++) d[i-1]=i;
    if(C < N-1 || C>(N*(N+1)/2 - 1)){cout<<"Case #"<<ite<<": IMPOSSIBLE"<<endl;continue;}

    int rem = C-N+1;
    for(int j = N-1; j>=0; j--)
    {
        int k = min(rem, N-1-j);
        rem -=k;
        reverse(d+j, d+j+k+1);
    } 
     cout <<"Case #"<<ite<<": ";
     for(int i = 0; i <N;i++)cout << d[i]<<" ";
     cout <<endl;
  }
  return 0;
}
