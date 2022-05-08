#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cout << "PERFECTION OUTPUT"<<endl;
  while(cin >> N)
  {
    if(N==0) break;
    int sum = 0;
    for(int i = 1; i<N; i++) if(N%i == 0) sum +=i;
    cout << right<<setw(5);
    if( sum > N)cout << N<< "  ABUNDANT"<<endl;
    else if(sum < N) cout << N<< "  DEFICIENT"<<endl;
    else cout<<N << "  PERFECT"<<endl;
  }
  cout <<"END OF OUTPUT"<<endl;
  return 0;
}
