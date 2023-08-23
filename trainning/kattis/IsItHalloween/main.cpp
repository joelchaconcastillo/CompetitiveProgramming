#include <bits/stdc++.h>
using namespace std;
int main(){
   string month;
   int day;
   cin>>month>>day;
   bool date1 = (month=="OCT" && day==31), date2=(month=="DEC" && day==25);
   if((date1)||(date2)) cout << "yup"<<endl;
   else cout<<"nope"<<endl;
   return 0;
}
