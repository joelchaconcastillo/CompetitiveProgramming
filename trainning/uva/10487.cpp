#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,c=1;
  while(cin>>n)
  {
	if(n==0)break;
     int data[1001];
     for(int i = 0; i < n ; i++) cin >> data[i];
     sort(data, data+n);
	cin>>m;
     cout << "Case "<<c<<":\n";
     for(int j = 0; j < m; j++)
     {
	int q;
	cin >>q;
	pair<int,int> best(INT_MAX, INT_MAX);
//	for(int i = 0; i < n-1; i++)
//	{
//	    int idx = lower_bound(data+i+1, data+n, q-data[i])-data;
//	    if(data[idx]==q-data[i]){best=make_pair(-1, q);break;}
//	    best = min(best, make_pair( abs(data[i]+data[idx]-q) , data[i]+data[idx])) ;
//	   if(idx>i+1)
//	    best = min(best, make_pair( abs(data[i]+data[idx-1]-q) , data[i]+data[idx-1])) ;
//	}
	int l=0, r=n-1;
        while(l<r)
        {
	   int prev=INT_MAX;
           while(l<r && data[l]+data[r] > q)
	   {
              best = min(best, make_pair( abs(data[l]+data[r]-q) , data[l]+data[r])) ;
	      r--;
	   }
	  if(l<r)
           best = min(best, make_pair( abs(data[l]+data[r]-q) , data[l]+data[r]));
	   l++;
        }
	cout << "Closest sum to "<<q<<" is "<<best.second<<"."<<endl;
     }
   c++;
  }
  return 0;
}
