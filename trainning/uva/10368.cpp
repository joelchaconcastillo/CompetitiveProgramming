#include <bits/stdc++.h>
using namespace std;
int GT(int a, int b, int p)
{
   if(a<b)swap(a,b);
   if(a%b ==0 || a/b>1) return p;
   return GT(b, a%b, 1-p);
}
int main()
{
  int a, b;
  while(cin >> a >>b)
  {
    if(a == 0 && b ==0) break;
    if(!(GT(a, b,0)%2))cout << "Stan wins"<<endl;
    else cout << "Ollie wins"<<endl;
  }
  return 0;
}
