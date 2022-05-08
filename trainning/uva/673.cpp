#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  string cad;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
  { 
    stack<char> st;
//   fgets(cad, 129, stdin);
    getline(cin, cad);
//    scanf("%s", cad);
   int l = cad.size();
   bool flag = true;
   for(int j = 0; j < l && flag; j++)
   { 
      if( cad[j] == '(' || cad[j] == '[') 
         st.push(cad[j]);
      else
      {
	if(st.empty()) flag=false;
	else if((st.top() == '(' && cad[j] !=')') || (st.top() == '[' && cad[j] !=']')) flag=false;
	else st.pop();
      }
   }
   if(!st.empty())flag=false;
   if(l==0)flag=true;
   if(flag) printf("Yes\n");
   else printf("No\n");

  }
  return 0;
}
