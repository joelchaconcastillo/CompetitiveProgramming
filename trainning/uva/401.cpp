#include <bits/stdc++.h>
using namespace std;
bool reverseD(char &a, char &b)
{
  if(a == 'A'&& b == 'A') return true;
  if(a == 'E'&& b == '3') return true;
  if(a == 'H'&& b == 'H') return true;
  if(a == 'I'&& b == 'I') return true;
  if(a == 'J'&& b == 'L') return true;
  if(a == 'L'&& b == 'J') return true;
  if(a == 'M'&& b == 'M') return true;
  if(a == 'O'&& b == 'O') return true;
  if(a == 'S'&& b == '2') return true;
  if(a == 'T'&& b == 'T') return true;
  if(a == 'U'&& b == 'U') return true;
  if(a == 'V'&& b == 'V') return true;
  if(a == 'W'&& b == 'W') return true;
  if(a == 'X'&& b == 'X') return true;
  if(a == 'Y'&& b == 'Y') return true;
  if(a == 'Z'&& b == '5') return true;
  if(a == '1'&& b == '1') return true;
  if(a == '2'&& b == 'S') return true;
  if(a == '3'&& b == 'E') return true;
  if(a == '5'&& b == 'Z') return true;
  if(a == '8'&& b == '8') return true;
return false;
}
int main()
{
  string word;
 while(getline(cin, word))
 {
   bool palindrome = true, mirror = true;
   for(int i = 0; i <= word.size()/2; i++)
   {
     //check palindrome...	
   	if( word[i] != word[word.size()-i-1] ) palindrome = false; 
     //check mirror
   	if( !reverseD(word[i], word[word.size()-i-1]) ) mirror = false; 
     if( !palindrome && !mirror) break;
   } 	
   if( palindrome && mirror) cout << word << " -- is a mirrored palindrome."<<endl;
   else if( mirror && !palindrome) cout << word << " -- is a mirrored string."<<endl;
   else if( palindrome && !mirror) cout << word << " -- is a regular palindrome."<<endl;
   else if( !palindrome && !mirror) cout << word << " -- is not a palindrome."<<endl;
   cout << endl;
 }
}
