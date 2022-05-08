#include<bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int my_lb(vector<int> &d, int v)
{
  int n = d.size();
  int idx = 0;
  for(int j = n/2 ;j >=1; j/=2)
  {
     while( j+idx < n && d[j+idx] < v) idx +=j;
  }
  if( idx+1 <n && d[idx] < v )
  idx++;
  return idx;
}
int my_lb2(vector<int> &d, int v)
{
  int n = d.size();
  int l=0, u=n, m;
  while(l<u )
  {
     m=(l+u)/2;
     if( v<=d[m] ) u = m;
     else  l = m+1;
  }
  return l;
}
int main()
{
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < n; i++){ int t;  cin >> t; A[i] -=t; }
  sort(A.begin(), A.end());
  long long int cont = 0;
  for(int i = 0; i < n; i++)
  {
    if(A[i] <=0) continue;
    //int p = lower_bound(A.begin(), A.end(), -A[i]+1)  - A.begin();
    int p = my_lb2(A, -A[i]+1);
    cont += i-p;
  }
  cout << cont <<endl;
    return 0;
}
