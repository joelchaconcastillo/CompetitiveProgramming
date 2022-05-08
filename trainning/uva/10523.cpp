#include <bits/stdc++.h>
using namespace std;
string strproduct(string A, string B)
{
  string res="";
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  for(int i = 0; i < A.size(); i++)
  {
    int c=0;
    string current = "";
    for(int j = 0; j < max(res.size(), B.size()); j++)
    {
       int prod = c;
	if(j<B.size()) prod += int(B[j]-'0')*int(A[i]-'0');
        if(j<res.size()) prod += int(res[j]-'0');
       current += char(prod%10+'0');
       c = prod/10;
    }
    if(c) current +=char(c+'0');
    B = '0'+B;
    res=current;
  }
  while(res.back()=='0') res.pop_back();
  reverse(res.begin(), res.end());
  return res;
}
string strsum(string &A, string B)
{
 reverse(A.begin(), A.end());
 reverse(B.begin(), B.end());
 string res="";
 int c=0;
 for(int i = 0; i < max(A.size(), B.size()); i++)
 {
    int sum = c;
    sum += (i<A.size())?(A[i]-'0'):0;
    sum += (i<B.size())?(B[i]-'0'):0;
    res = char((sum%10)+'0') + res;
    c = sum/10;
 }
 if(c) res = char(c+'0')+res;
 return res;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, A;
  while(cin>>N>>A)
  {
    string sum="0", prevAi="1", currentAi="", strA=to_string(A); 
    for(int i = 1; i <= N; i++)
    {
      currentAi= strproduct(prevAi, strA);
      sum = strsum(sum, strproduct(to_string(i), currentAi));
      prevAi=currentAi;
    }
    cout << sum<<endl;
  }
  return 0;
}
