#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  while( cin >> n)
  {
    vector<bool> cont(3, true);
    priority_queue<int> pq;
    stack<int> st;
    queue<int> q;
    int cq=0;
    for(int i = 0 ; i < n; i++)
    {
       int a, b;
       cin >> a >> b;
       if( a == 1) pq.push(b), st.push(b), q.push(b);
       else
       {
	  if( pq.empty()){cont[0]=false, cont[1]=false, cont[2]=false; continue;}
	  if(pq.top() != b ) cont[0] = false;
	  if(st.top() != b ) cont[1] = false;
	  if(q.front() != b ) cont[2] = false;
	  cq++;
	pq.pop(), st.pop(), q.pop();
       }
    } 
    if( cont[0] && !cont[1] && !cont[2] )  cout << "priority queue"<<endl;
    else if( !cont[0] && cont[1] && !cont[2] )  cout << "stack"<<endl;
    else if( !cont[0] && !cont[1] && cont[2])  cout << "queue"<<endl;
    else if( cont[0] || cont[1] || cont[2] ) cout << "not sure"<<endl;
    else if( !(cont[0] && cont[1] && cont[2]) ) cout << "impossible"<<endl;
  }
  return 0;
}
