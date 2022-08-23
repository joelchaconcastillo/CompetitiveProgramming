#include <bits/stdc++.h>
using namespace std;
int main(){
  map<int, int> count;
  int n;
  cin >>n;
  vector<int> A(n);
  for(int i = 0; i < n; i++)cin >>A[i], count[A[i]]++;
  long long npairs = 0;
  for(int i = 0; i <  n-1; i++)
  {
     count[A[i]]--;
     npairs += (n-i-1)-count[A[i]];
  }
  cout << npairs<<endl;
}
