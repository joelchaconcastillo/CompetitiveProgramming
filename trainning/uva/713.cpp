#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--) 
  {
    string A, B;
    list<char> C;
    cin >> A >> B;
    //remove left zeros..

    //
    int rem = 0;
    for(int i = 0; i < max(A.size(), B.size()); i++)
    {
       int Ai = 0, Bi = 0;
       if(i < A.size()) Ai = A[i]-'0'; 
       if(i < B.size()) Bi = B[i]-'0'; 
       int st = (Ai + Bi + rem);
       rem = st/10;
       C.push_back(st%10+'0');
    } 
    if(rem != 0) C.push_back(rem+'0');
    while(!C.empty() && C.front() == '0') C.pop_front();
    for(auto i:C) cout <<i;
    cout << endl;
  }
}
