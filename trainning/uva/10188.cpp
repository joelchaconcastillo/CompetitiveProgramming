#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, cont=1;
  while(cin >>n && n!=0)
  {
     string st1="", st2="";
	     cin.ignore();
     for(int i = 0; i <n; i++)
     {
	  string t;
	  getline(cin, t);
	  st1+=t+"_";
     }
     int m;
     cin >>m;
     cin.ignore();
     for(int i = 0; i <m; i++)
     {
	  string t;
	  getline(cin, t);
	  st2+=t+"_";
     }
        bool ac=false, pe=false;
	string d1="",d2="";
	for(auto c:st1) if(c>='0' && c<='9') d1 +=c;//.push_back(c);
	for(auto c:st2) if(c>='0' && c<='9') d2 +=c;
	ac = (st1==st2);
	ac &= (m==n);
	pe=(d1==d2);
	
	if(ac) cout << "Run #"<<cont<<": Accepted"<<endl;
	else if(pe)  cout << "Run #"<<cont<<": Presentation Error"<<endl;
	else cout << "Run #"<<cont<<": Wrong Answer"<<endl;
     cont++;
  }
  return 0;
}
