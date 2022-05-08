#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  int freq[300];
  cin>>t;
  while(t--)
  {
    string st;
    cin>>st;
    memset(freq, 0 , sizeof freq);
    for(int i = 0; i < st.size(); i++)
       freq[st[i]-'0']++;
    for(int i = 0; i < st.size()-1; i++)
    {
	int idx =st[i]-'0';
	if( freq[idx] ==1)cout << st[i];
	else if(freq[idx]>1 && st[i]>st[i+1])
	{
	    cout << st[i];
	    freq[idx]=0;
	}else freq[idx]--;
    }
    cout <<endl;
  }
  return 0;
}
