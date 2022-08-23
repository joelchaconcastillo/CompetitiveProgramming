#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
 cin>>t;
 while(t--)
 {
    int n;
    cin >>n;
//    int B = n%2020;
//    int A = (n - 2021*B)/2020;
//    if( n%2021 == 0 || n%2020==0) cout <<"YES\n";
//    else if(A>=0 &&  (A*2020+B*2021==n) ) cout << "YES\n";
//    else cout <<"NO\n";
    if( n/2020 >= n%2020) cout << "YES\n";
    else cout << "NO\n";
 }	
  return 0;
}
