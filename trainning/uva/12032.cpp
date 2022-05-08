#include <bits/stdc++.h>

using namespace std;
int data[100000];
int T, n;
bool check(int k)
{
  if( k < data[0] ) return false; 
  if( k == data[0] ) k--;
  for(int i = 1; i < n; i++)
  {
    int dif = data[i]-data[i-1];
    if( dif > k ) return false;
    if( k == dif ) k--;
  } 
  return true;
}
int main()
{
  cin >> T;
  int t=1;
  while(T--)
  {
    cin >> n ;
    for(int i = 0; i < n; i++)
	cin >> data[i];
    int x = -1;
    for(int s=100001; s >= 1; s/=2)
       while( !check(x+s) ) x +=s;
    x++;
    cout<<"Case "<<t++<<": " << x<<endl; 
  }
  return 0;
}
