#include <bits/stdc++.h>
using namespace std;
int main()
{
  int NCOWS, NCARS, NSHOWS;
  while(cin >> NCOWS >> NCARS >>NSHOWS)
  {
     cout << fixed<<setprecision(5) << (NCARS/((double)NCARS+NCOWS))*((NCARS-1.0)/((double)NCARS+NCOWS-NSHOWS-1.0)) + (NCOWS/((double)NCARS+NCOWS))*(NCARS/(NCARS+NCOWS-NSHOWS-1.0)) <<endl;
  }
  return 0;
}
