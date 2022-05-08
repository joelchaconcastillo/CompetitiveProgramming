#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str_in;
  map<string, int> counter;
  int lambda = 0;
  while(getline(cin, str_in))
  {
     if( str_in == "****END_OF_TEXT****")
     {
         double sum = 0.0;
         for(auto i = counter.begin(); i != counter.end(); i++)
    	  sum += i->second*(log(lambda)/log(10) - log(i->second)/log(10) );
         double ET = sum/lambda;
         printf("%d %.1lf %0.lf\n", lambda, ET, (100*ET/(log(lambda)/log(10))));
	 lambda = 0;
	 counter.clear();
	continue;
     }
     else if(str_in == "****END_OF_INPUT****") break;

     string word;
     for(int i = 0; i < str_in.size(); i++)
     {
	if(str_in[i] == ',' || str_in[i] == '.' || str_in[i] == ':' || str_in[i]== ';' || str_in[i]=='!' || str_in[i] == '?' || str_in[i]=='"' || str_in[i] == '(' || str_in[i]==')' || str_in[i]==' ')
	{
	  if(!word.empty())
	  {
	    lambda++;
	    counter[word]++;
	    word.clear();
	  }
	}
	else 
	word.push_back(tolower(str_in[i]));
     }
     if(!word.empty())
     {
       lambda++;
       counter[word]++;
       word.clear();
     }
  } 
  return 0;
}
