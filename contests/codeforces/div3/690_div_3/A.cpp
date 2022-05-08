#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T, n, data[500];
  cin >> T;
  while(T--)
  {
    cin >> n;
    int idx=0;
    while(idx<n){ cin>>data[idx]; idx +=2;}
    idx = n-n%2-1;
    while(idx >=0){ cin>>data[idx]; idx -=2;}
    for(int i = 0; i < n; i++) cout << data[i]<< " "; 
   cout <<endl;
  }
  return 0;
}
