#include<bits/stdc++.h>
using namespace std;
int p, q, r, s, t, u;
double g(double x)
{
   return fabs(p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
int main()
{
  while( cin >> p >> q >>r >>s >>t >> u)
  {
     double x=0.0, d=1;
     for(; d>= 1e-10; d/=2.0) 
	while( g(x+d) > g(x+d+1e-10) && x <=1 )x += d;

     x +=d;
     if( fabs(g(x)) <= 1e-4 )
	printf("%.4f\n", x);
     else cout << "No solution"<<endl;
  }
  return 0;
}

