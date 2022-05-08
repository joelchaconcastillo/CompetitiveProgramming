#include <bits/stdc++.h>
using namespace std;
pair<double, double> tohours(string &st)
{
  double hours = 0.0;
  double km = 0;
  hours = (((st[0]-'0')*10)+(st[1]-'0'));
  hours += (((st[3]-'0')*10)+(st[4]-'0'))/60.0;
  hours += (((st[6]-'0')*10)+(st[7]-'0'))/3600.0;
  if( st.size() > 8 ) 
  {
    for(int idx =9; idx < st.size();idx++)
	if(isdigit(st[idx]))km = (km*10)+(st[idx]-'0');
  }
  return make_pair(hours, km);
}
int main()
{
  string in;
  double totalkm=0.0, c_speed =0.0, c_start_time=0.0;

  while(getline(cin, in))
  {
    pair<double, double> p = tohours(in);
    if(in.size() >8)
    {
     totalkm += (p.first-c_start_time)*c_speed;
     c_speed = p.second;
     c_start_time = p.first;
    }
    else
    {
     cout << in.substr(0, 8)<< " "<<fixed<<setprecision(2)<< totalkm+(p.first-c_start_time)*c_speed<< " km"<<endl;
    }
  }
  return 0;
}
