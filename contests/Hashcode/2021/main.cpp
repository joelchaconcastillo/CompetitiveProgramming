#include <bits/stdc++.h>
#include "tools.hpp"
#include "naiveMethods.hpp"
#include "fastMethods.hpp"
void infoProblem()
{
  upperboundScore();
  components();
}
int main()
{
  unsigned int s = time(0);
  srand(s);
  cerr<<"SEED: "<<s<<endl;
 // srand(1);
  read();
  infoProblem();
  vvpd sol;
  randominit2(sol);
//  initA(sol);
  cerr<< sol.f<< " " <<eval1(sol.x)<<endl;
 // //localsearchbyGroups(sol, 60*60*5);
  localsearchbyPaths(sol, 60*60*8);
 // localsearchbyPaths(sol, 20);
 // //localsearch(sol, 60);
  cerr<< sol.f<< " " <<eval1(sol.x)<<endl;
  write(sol.x);
  return 0;
}
