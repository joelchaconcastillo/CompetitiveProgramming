#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int Ai[MAX_N];
int main()
{
  int T, N, B;
  cin >> T;
  for(int t=1; t<=T; t++)
  {
     cin >> N >> B;
     for(int i = 0; i < N ; i++)
	cin >> Ai[i];
     sort(Ai,Ai+N);
     int cont = 0;
     for(int i = 0, sum=0; i < N; i++)
     {
	if(sum+Ai[i] > B)break;
	else sum +=Ai[i], cont++;
     }
     cout << "Case #"<<t<<": " << cont<<endl;
  }
  return 0;
}
