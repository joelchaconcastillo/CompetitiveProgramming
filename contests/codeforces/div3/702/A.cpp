#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t, n;
  int data[100];
  cin>>t;
  while(t--)
  {
    cin >> n;
    for(int i = 0; i < n; i++) cin>>data[i];
    long long cont = 0;
    for(int i = 0; i < n-1; i++)
    {
       int M = max(data[i], data[i+1]);
       int m = min(data[i], data[i+1]);
	for(int i = m; 2*i < M; i*=2)cont++;
    }
    cout << cont <<endl; 
  }
  return 0;
}
