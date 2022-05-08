#include <bits/stdc++.h>
using namespace std;
int main(){
  double N;
  cin >>N;
  int k=N*1.08;
  if(k<206)cout << "Yay!\n";
  else if(k>206)cout << ":(\n";
  else cout << "so-so\n";
  return 0;
}
