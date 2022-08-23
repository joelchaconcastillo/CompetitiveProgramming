#include <bits/stdc++.h>
#include<iostream>

using namespace std;
//Suppress some compilation warning messages (only for VC++ users)
//#define _CRT_SECURE_NO_DEPRECATE
//Shortcuts for "common" data types in contests
// Common memset settings
//memset(memo, -1,  sizeof memo); //initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);     // to clear array of integers

//several shorcuts that are frequently used:
// ans = a ? b : c;
// ans +=val
// index = (index+1) %n;
// index = (index + n - 1) % n;
// int ans = (int) ((double)d + 0.5); //for rounding to nearest integer
// ans = min(ans, new_computation);  //min/max shortcut // alternative form but not used in this book: ans<?= new_computation
#define INF 1000000000 //1 billion, safer than 2B for Floyd Warshall's
typedef long long ll; //comments that are mixed in with code
typedef pair<int, int> ii; //are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;


#include "SegmentTree.hpp"

int main()
{
   int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
   vi A(arr, arr+7);
   SegmentTree st(A);
   printf("RMQ(1, 3) = %d/n", st.rmq(1,3));
   printf("RMQ(4, 6) = %d/n", st.rmq(4,6));
   return 0;
}
