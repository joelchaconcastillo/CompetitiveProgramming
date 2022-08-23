#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < N ; i++)
  {
   int Nfarmers;
   cin >> Nfarmers;
   long long sum = 0;
   for(int j = 0; j < Nfarmers; j++)
   {
	long long int size_farmyard, n_animals, friendless;
        cin >> size_farmyard >> n_animals >>  friendless; 
	sum += size_farmyard*friendless;
   }
   cout << sum <<endl;
  }
}
