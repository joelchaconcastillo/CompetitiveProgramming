#include <bits/stdc++.h>
using namespace std;

int main()
{
   string input;
   
   while( getline(cin, input))
   {
 	int totalScore = 0;
	int counting[1000] = {0};
	bool stopped[1000] = {false};
	//cases points...
	for(int i = 0; i < input.length(); i+=3)
	{
	   //checking score..
	   if(input[i] == 'A' ) totalScore +=4;
	   if(input[i] == 'K' ) totalScore +=3;
	   if(input[i] == 'Q' ) totalScore +=2;
	   if(input[i] == 'J' ) totalScore +=1;
	   counting[ input[i+1] ]++;
	}
	for(int i = 0; i < input.length(); i+=3)
	{
	   //checking score..
	   if(input[i] == 'K' && counting[input[i+1]] < 2 ) totalScore--;
	   else if(input[i] == 'K') stopped[input[i+1]] = true;
	   if(input[i] == 'Q' && counting[input[i+1]] < 3 ) totalScore--;
	   else if(input[i] == 'Q') stopped[input[i+1]] = true;
	   if(input[i] == 'J' && counting[input[i+1]] < 4 )  totalScore--;
	   if(input[i] == 'A') stopped[input[i+1]] = true;
	}
	int trumpscore = totalScore;
        ///non-trump-checking...
	if( counting['S'] == 2 ) totalScore++;
	if( counting['H'] == 2 ) totalScore++;
	if( counting['D'] == 2 ) totalScore++;
	if( counting['C'] == 2 ) totalScore++;
	if( counting['S'] <= 1 ) totalScore+=2;
	if( counting['H'] <= 1 ) totalScore+=2;
	if( counting['D'] <= 1 ) totalScore+=2;
	if( counting['C'] <= 1 ) totalScore+=2;

	//checking stopped..

	if( trumpscore >=16 && stopped['S'] && stopped['H'] && stopped['D'] && stopped['C']) printf("BID NO-TRUMP\n");
	else if(totalScore >=14)
	{

	  int sizelongestsuit = -1;
	  sizelongestsuit = max(sizelongestsuit, counting['S']);
	  sizelongestsuit = max(sizelongestsuit, counting['H']);
	  sizelongestsuit = max(sizelongestsuit, counting['D']);
	  sizelongestsuit = max(sizelongestsuit, counting['C']);

	  if( sizelongestsuit == counting['S'] ) printf("BID S\n");
	  else if(  sizelongestsuit == counting['H'])printf("BID H\n");
	  else if(  sizelongestsuit == counting['D'])printf("BID D\n");
	  else if( sizelongestsuit == counting['C']) printf("BID C\n");
	}
	else printf("PASS\n");


   }
}
