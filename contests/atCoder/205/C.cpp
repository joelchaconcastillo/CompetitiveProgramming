#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  int A, B, C;
  cin >>A>>B>>C;
  if(A<0 && C%2==0) A*=-1; 
  if(B<0 && C%2==0) B*=-1; 
  if( A > B) cout << ">"<<endl;
  else if( B > A) cout << "<"<<endl;
  else cout << "="<<endl;
	
  return 0;
}
