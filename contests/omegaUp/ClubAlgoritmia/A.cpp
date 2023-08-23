#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int d, m, a;

  while(scanf("%d/%d/%d", &d, &m, &a)!=EOF){
  if(to_string(a).size()<=2){
     if(a<74)a += 2000;
     else a+=1900; 
  }
  printf("%d/%d/%d\n", d, m ,a);
  }
  // TODO: fixme.

  return 0;
}
