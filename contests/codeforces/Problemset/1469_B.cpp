#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
    int r, b; //, rd[1000], br[1000];
    int maxr = -1000, maxb=-1000, d, s1=0, s2=0;
    cin >> r;
    for(int i = 0; i < r; i++)cin>>d, s1+=d,  maxr=max(s1, maxr);
    cin>>b;
    for(int i = 0; i < b; i++)cin>>d,s2+=d, maxb=max(s2, maxb);
    cout << max(0,max(maxr, max(maxb, maxr+maxb)))<<endl;
 }
 return 0;
 }
