#include <bits/stdc++.h>
using namespace std;
int main()
{
 int T; 
 cin>>T;
 int i=1;
 while(T--)
 {
    long long s[3];
    cin>> s[0]>>s[1]>>s[2];
    cout<<"Case "<<i<<": ";
    sort(s, s+3);
      if(s[0]+s[1] <= s[2]|| s[0]<=0 ) cout << "Invalid\n";
      else if( s[0]==s[1] && s[1]==s[2]) cout <<"Equilateral\n";
      else if(s[0]==s[1] || s[1] == s[2]) cout <<"Isosceles\n";
      else if(s[0] != s[1] && s[1] != s[2]) cout << "Scalene\n";
      
    i++;
 }
}
