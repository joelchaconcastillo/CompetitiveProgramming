#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  int data[200000];
  cin >> t;
  while(t--)
  {
     int n, k, nPairs;
     cin >> n >> k;
     nPairs = n/2;
     vector<int> counter(2*k+1), freq(2*k+2);
     for(int i = 0; i < n; i++) cin >> data[i];
     for(int i = 0; i < nPairs; i++)
     {
 	 counter[data[i] + data[n-i-1]]++;
	 freq[min(data[i],data[n-i-1])+1]++;
	 freq[max(data[i],data[n-i-1])+k+1]--;
     }
     for(int i = 1; i <=2*k+1 ;i++)
	freq[i] += freq[i-1];
     int minv = INT_MAX;
     for(int i = 2; i <= 2*k ; i++)
        minv = min(minv, (nPairs-freq[i])*2 + (freq[i]-counter[i]));
    cout << minv<<endl;
     
  }
  return 0;
}
