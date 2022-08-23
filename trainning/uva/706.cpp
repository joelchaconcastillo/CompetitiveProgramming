#include <bits/stdc++.h>
using namespace std;
int main()
{
  int s;
  string n;
  while(cin >> s >>n)
  {
	if(s == 0 && n[0] == '0'&& n.size()==1) break;
  //first row
        int cont = 0; 
       for(auto i:n)
	{
	   if(i=='1') for(int i = 0; i < s+2; i++) cout << " ";
	   else if(i=='0'||i=='2' || i == '3' || i == '5' || i== '6' || i=='7'|| i == '8' || i == '9') 
	   {
	     cout << " ";
	      for(int k = 0; k < s; k++)cout << "-";
	    cout << " ";
	   }
   	   else if(i=='4')
	   {
	    for(int k = 0; k < s+2; k++)cout << " ";
	   }
	 if(cont < n.size()-1) 
	  cout <<" ";
	  cont++;
	 }
	cout <<endl;
    for(int z = 0; z < s; z++)
    {
	cont = 0;
       for(auto i:n)
	{
	   if(i=='1' || i=='2' || i=='3' || i=='7') { for(int k = 0; k < s+1; k++) cout << " "; cout << "|";}
	   else if(i=='0' || i=='4' || i=='8' || i=='9') { cout <<"|"; for(int k = 0; k < s; k++) cout << " "; cout << "|";}
	   else if(i=='5' || i=='6') { cout <<"|"; for(int k = 0; k < s+1; k++) cout << " "; }
	 if(cont < n.size()-1) 
	  cout <<" ";
	  cont++;
	}
	cout <<endl;
     }

	cont = 0;
       for(auto i:n)
	{
	   if(i=='0' || i=='1'||i=='7') for(int i = 0; i < s+2; i++) cout << " ";
	   else if(i=='2' || i == '3' || i=='4' || i == '5' || i== '6'|| i == '8' || i == '9') 
	   {
	     cout << " ";
	      for(int k = 0; k < s; k++)cout << "-";
	    cout << " ";
	   }
	 if(cont < n.size()-1) 
	  cout <<" ";
	  cont++;
	 }
	cout << endl;
     for(int z = 0; z < s; z++)
    {
	cont = 0;
       for(auto i:n)
	{
	   if(i=='1' || i=='3' || i=='4' || i=='5' || i=='7'||i=='9') { for(int k = 0; k < s+1; k++) cout << " "; cout << "|";}
	   else if(i=='2' ) { cout <<"|"; for(int k = 0; k < s+1; k++) cout << " "; }
	   else if(i=='0' || i=='6' || i=='8') { cout <<"|"; for(int k = 0; k < s; k++) cout << " ";cout<<"|"; }
          if(cont < n.size()-1) 
	  cout <<" ";
	  cont++;

	}
   
	cout <<endl;
     }
	cont = 0;
    for(auto i:n)
	{
	   if(i=='1' || i=='4' || i=='7') for(int i = 0; i < s+2; i++) cout << " ";
	   else if(i=='0'|| i=='2' || i == '3' || i == '5' || i== '6'|| i == '8' || i == '9') 
	   {
	     cout << " ";
	      for(int k = 0; k < s; k++)cout << "-";
	    cout << " ";
	   }
	  if(cont < n.size()-1) 
	  cout <<" ";
	  cont++;
	 }
	cout <<endl<<endl;
  }
  return 0;
}
