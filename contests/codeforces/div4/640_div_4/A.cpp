#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  { 
     int cont = 0;
     int n, p;
     cin >> n;
     p = floor(log(n)/log(10)+1);
     queue<int> st;
     for(int i = p; i >=1 ; i--)
     {
	int sum = (n /(int) pow(10,i-1))*pow(10,i-1);
	n -=sum;
	if( sum != 0)
	   st.push(sum);
     } 
	cout << st.size() <<endl;
        while(!st.empty()) {  cout << st.front() << " ";st.pop(); }
	cout << endl;
  }
  return 0;
}
